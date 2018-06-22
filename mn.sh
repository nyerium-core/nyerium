#!/bin/bash

TMP_FOLDER=$(mktemp -d)
CONFIG_FILE='nyerium.conf'
CONFIGFOLDER='.nyerium'
NYEX_DAEMON='nyeriumd'
NYEX_CLI='nyerium-cli'
NYEX_PATH='/usr/local/bin/'
NYEX_REPO='https://github.com/nyerium-core/nyerium.git'
NYEX_TGZ='https://github.com/nyerium-core/nyerium/releases/download/v1.0.1.0/nyerium-1.0.1.0-x64-linux-tar.gz'
NYEX_ZIP=$(echo $NYEX_TGZ | awk -F'/' '{print $NF}')
NYEX_NAME='nyerium'
NYEX_PORT=57418
NYEX_RPC_PORT=57419

NODEIP=$(curl -s4 icanhazip.com)


RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'


function compile_node() {
  echo -e "Prepare to compile $NYEX_NAME"
  git clone $NYEX_REPO $TMP_FOLDER >/dev/null 2>&1
  compile_error
  cd $TMP_FOLDER
  chmod +x ./autogen.sh 
  ./autogen.sh -j3
  compile_error
  ./configure
  compile_error
  make -j3
  compile_error
  make install
  compile_error
  strip $NYEX_PATH$NYEX_DAEMON $NYEX_PATH$NYEX_CLI
  cd - >/dev/null 2>&1
  rm -rf $TMP_FOLDER >/dev/null 2>&1
  clear
}

function download_node() {
  echo -e "Prepare to download $NYEX_NAME binaries"
  cd ~
  wget -qO- $NYEX_TGZ | sudo tar xvz -C /usr/local/bin/
  compile_error
  rm -r $TMP_FOLDER >/dev/null 2>&1
  clear
}

function ask_permission() {
 echo -e "${YELLOW}Please confirm that you want to install or compile$ $NYEX_NAME binaries on his server.${NC}."
 echo -e "Type ${GREEN}YES${NC} if you want to use precompiled binaries, or ${RED}NO${NC} if you want to compile them on your server"
 echo -e "Press ${GREEN}ENTER${NC} to continue, if you dont understand this!"
 read -e ANS
}

function configure_systemd() {
  cat << EOF > /etc/systemd/system/$NYEX_NAME.service
[Unit]
Description=$NYEX_NAME service
After=network.target
[Service]
User=root
Group=root
Type=forking
#PIDFile=$CONFIGFOLDER/$NYEX_NAME.pid
ExecStart=$NYEX_PATH$NYEX_DAEMON -daemon
ExecStop=-$NYEX_PATH$NYEX_CLI stop
Restart=always
PrivateTmp=true
TimeoutStopSec=120s
TimeoutStartSec=120s
StartLimitInterval=120s
StartLimitBurst=5
[Install]
WantedBy=multi-user.target
EOF

  systemctl daemon-reload
  sleep 3
  systemctl start $NYEX_NAME.service
  systemctl enable $NYEX_NAME.service >/dev/null 2>&1

  if [[ -z "$(ps axo cmd:100 | egrep $NYEX_DAEMON)" ]]; then
    echo -e "${RED}$NYEX_NAME is not running${NC}, please investigate. You should start by running the following commands as root:"
    echo -e "${GREEN}systemctl start $NYEX_NAME.service"
    echo -e "systemctl status $NYEX_NAME.service"
    echo -e "less /var/log/syslog${NC}"
    exit 1
  fi
}


function create_config() {
  mkdir $CONFIGFOLDER >/dev/null 2>&1
  RPCUSER=$(tr -cd '[:alnum:]' < /dev/urandom | fold -w10 | head -n1)
  RPCPASSWORD=$(tr -cd '[:alnum:]' < /dev/urandom | fold -w22 | head -n1)
  cat << EOF > $CONFIGFOLDER/$CONFIG_FILE
rpcuser=$RPCUSER
rpcpassword=$RPCPASSWORD
rpcallowip=127.0.0.1
rpcport=57419
listen=1
server=1
daemon=1
port=$NYEX_PORT
EOF
}

function create_key() {
  echo -e "Press Enter to generate your ${RED}$NYEX_NAME Masternode Private Key${NC}. Or paste your ${RED}Masternode Private Key${NC} below:"
  read -e NYEXKEY
  if [[ -z "$NYEXKEY" ]]; then
  $NYEX_PATH$NYEX_DAEMON -daemon
  sleep 30
  if [ -z "$(ps axo cmd:100 | grep $NYEX_DAEMON)" ]; then
   echo -e "${RED}$NYEX_NAME server couldn not start. Check /var/log/syslog for errors.{$NC}"
   exit 1
  fi
  NYEXKEY=$($NYEX_PATH$NYEX_CLI masternode genkey)
  if [ "$?" -gt "0" ];
    then
    echo -e "${RED}Wallet not fully loaded. Let us wait and try again to generate the Private Key${NC}"
    sleep 30
    NYEXKEY=$($NYEX_PATH$NYEX_CLI masternode genkey)
  fi
  $NYEX_PATH$NYEX_CLI stop
fi
clear
}

function update_config() {
  sed -i 's/daemon=1/daemon=0/' $CONFIGFOLDER/$CONFIG_FILE
  cat << EOF >> $CONFIGFOLDER/$CONFIG_FILE
logintimestamps=1
maxconnections=256
#bind=$NODEIP
masternode=1
externalip=$NODEIP:$NYEX_PORT
masternodeaddr=$NODEIP:$NYEX_PORT
masternodeprivkey=$NYEXKEY
EOF
}


function enable_firewall() {
  echo -e "Installing and setting up firewall to allow ingress on port ${GREEN}$NYEX_PORT${NC}"
  ufw allow $NYEX_PORT/tcp comment "$NYEX_NAME MN port" >/dev/null
  ufw allow ssh comment "SSH" >/dev/null 2>&1
  ufw limit ssh/tcp >/dev/null 2>&1
  ufw default allow outgoing >/dev/null 2>&1
  echo "y" | ufw enable >/dev/null 2>&1
}



function get_ip() {
  declare -a NODE_IPS
  for ips in $(netstat -i | awk '!/Kernel|Iface|lo/ {print $1," "}')
  do
    NODE_IPS+=($(curl --interface $ips --connect-timeout 2 -s4 icanhazip.com))
  done

  if [ ${#NODE_IPS[@]} -gt 1 ]
    then
      echo -e "${GREEN}More than one IP. Please type 0 to use the first IP, 1 for the second and so on...${NC}"
      INDEX=0
      for ip in "${NODE_IPS[@]}"
      do
        echo ${INDEX} $ip
        let INDEX=${INDEX}+1
      done
      read -e choose_ip
      NODEIP=${NODE_IPS[$choose_ip]}
  else
    NODEIP=${NODE_IPS[0]}
  fi
}


function compile_error() {
if [ "$?" -gt "0" ];
 then
  echo -e "${RED}Failed to compile $NYEX_NAME. Please investigate.${NC}"
  exit 1
fi
}


function checks() {
if [[ $(lsb_release -d) != *16.04* ]]; then
  echo -e "${RED}You are not running Ubuntu 16.04. Installation is cancelled.${NC}"
  exit 1
fi

if [[ $EUID -ne 0 ]]; then
   echo -e "${RED}$0 must be run as root.${NC}"
   exit 1
fi

if [ -n "$(pidof $NYEX_DAEMON)" ] || [ -e "$NYEX_DAEMOM" ] ; then
  echo -e "${RED}$NYEX_NAME is already installed.${NC}"
  exit 1
fi
}

function prepare_system() {
echo -e "Prepare the system to install ${GREEN}$NYEX_NAME${NC} master node."
apt-get update >/dev/null 2>&1
DEBIAN_FRONTEND=noninteractive apt-get update > /dev/null 2>&1
DEBIAN_FRONTEND=noninteractive apt-get -o Dpkg::Options::="--force-confdef" -o Dpkg::Options::="--force-confold" -y -qq upgrade >/dev/null 2>&1
apt install -y software-properties-common >/dev/null 2>&1
echo -e "${GREEN}Adding bitcoin PPA repository"
apt-add-repository -y ppa:bitcoin/bitcoin >/dev/null 2>&1
echo -e "Installing required packages, it may take some time to finish.${NC}"
apt-get update >/dev/null 2>&1
apt-get install -y -o Dpkg::Options::="--force-confdef" -o Dpkg::Options::="--force-confold" make software-properties-common \
build-essential libtool autoconf libssl-dev libboost-dev libboost-chrono-dev libboost-filesystem-dev libboost-program-options-dev \
libboost-system-dev libboost-test-dev libboost-thread-dev sudo automake git wget curl libdb4.8-dev bsdmainutils libdb4.8++-dev \
libminiupnpc-dev libgmp3-dev ufw pkg-config libevent-dev  libdb5.3++ libzmq5 >/dev/null 2>&1
if [ "$?" -gt "0" ];
  then
    echo -e "${RED}Not all required packages were installed properly. Try to install them manually by running the following commands:${NC}\n"
    echo "apt-get update"
    echo "apt -y install software-properties-common"
    echo "apt-add-repository -y ppa:bitcoin/bitcoin"
    echo "apt-get update"
    echo "apt install -y make build-essential libtool software-properties-common autoconf libssl-dev libboost-dev libboost-chrono-dev libboost-filesystem-dev \
libboost-program-options-dev libboost-system-dev libboost-test-dev libboost-thread-dev sudo automake git curl libdb4.8-dev \
bsdmainutils libdb4.8++-dev libminiupnpc-dev libgmp3-dev ufw fail2ban pkg-config libevent-dev libzmq5"
 exit 1
fi

clear
}

function create_swap() {
 echo -e "Checking if swap space is needed."
 PHYMEM=$(free -g|awk '/^Mem:/{print $2}')
 SWAP=$(free -g|awk '/^Swap:/{print $2}')
 if [ "$PHYMEM" -lt "2" ] && [ -n "$SWAP" ]
  then
    echo -e "${GREEN}Server is running with less than 2G of RAM without SWAP, creating 2G swap file.${NC}"
    SWAPFILE=$(mktemp)
    dd if=/dev/zero of=$SWAPFILE bs=1024 count=2M
    chmod 600 $SWAPFILE
    mkswap $SWAPFILE
    swapon -a $SWAPFILE
 else
  echo -e "${GREEN}Server running with at least 2G of RAM, no swap needed.${NC}"
 fi
 clear
}


function important_information() {
 echo
 echo -e "================================================================================================================================"
 echo -e "$NYEX_NAME Masternode is up and running listening on port ${GREEN}$NYEX_PORT${NC}."
# echo -e "Configuration file is: ${GREEN}$CONFIGFOLDER/$CONFIG_FILE${NC}"
 echo -e "Start: ${GREEN}systemctl start $NYEX_NAME.service${NC}"
 echo -e "Stop: ${GREEN}systemctl stop $NYEX_NAME.service${NC}"
 echo -e "VPS_IP:PORT ${GREEN}$NODEIP:$NYEX_PORT${NC}"
 echo -e "MASTERNODE PRIVATEKEY is: ${GREEN}$NYEXKEY${NC}"
 echo -e "Please check ${GREEN}$NYEX_NAME${NC} is running with the following command: ${GREEN}nyerium-cli getinfo{NC}"
 echo -e "================================================================================================================================"
}

function setup_node() {
  get_ip
  create_config
  create_key
  update_config
  enable_firewall
  important_information
  configure_systemd
}


##### Main #####
clear

checks
prepare_system
ask_permission
if [[ "$ANS" == "YES" ]] || [[ "$ANS" == "" ]]; then
  download_node
else
  create_swap
  compile_node
fi
setup_node
