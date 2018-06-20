# NYERIUM The Cryptocurrency of Tomorrow

[![Build Status](https://travis-ci.org/nyerium-core/nyerium.svg?branch=master)](https://travis-ci.org/nyerium-core/nyerium) [![GitHub version](https://badge.fury.io/gh/nyerium-core%2Fnyerium.svg)](https://badge.fury.io/gh/nyerium-core%2Fnyerium)


## Nyerium Core integration/staging repository

Nyerium is an open source crypto-currency focused on fast private transactions with low transaction fees.  It utilizes a custom Proof of Stake protocol for securing its network and uses an innovative variable seesaw reward mechanism that dynamically balances 90% of its block reward size between masternodes, 10% for staking nodes, and 10% dedicated for budget proposals. Nyerium aims to achieve a decentralized sustainable crypto currency with near instant full-time private transactions, fair governance and community participation.
Key functionalities:
- Anonymized transactions using the [_Zerocoin Protocol_](http://www.nyerium.org/znye).
- Fast transactions featuring guaranteed zero confirmation transactions, we call it _SwiftX_.
- Decentralized blockchain voting utilizing Masternode technology to form a DAO. The blockchain will distribute monthly treasury funds based on successful proposals submitted by the community and voted on by the DAO.

More information at [nyerium.org](http://www.nyerium.org) Visit our ANN thread at [BitcoinTalk](https://bitcointalk.org/index.php?topic=4262979)

### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Max Coin Supply (PoW Phase)</td><td>1,600,000 NYEX</td></tr>
<tr><td>Max Coin Supply (PoS Phase)</td><td>120,000,000</td></tr>
<tr><td>Premine</td><td>10,000,000 NYEX*</td></tr>
</table>

### Reward Distribution

<table>
<th colspan=4>Genesis Block</th>
<tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr>
<tr><td>1</td><td>10,000,000 NYEX</td><td>Initial Pre-mine</td></tr>
</table>

### PoW Rewards Breakdown

<table>
<th>Block Height</th><th>Masternodes</th><th>Miner</th><th>Budget</th>
<tr><td>2-8000</td><td>80% (160 NYEX)</td><td>20% (40 NYEX)</td><td>N/A</td></tr>
</table>

### PoS Rewards Breakdown

<table>
<tr><td>Block Height</td><td>Total Reward</td><td>% MN Reward</td><td>% Staking Reward</td><td>% Governance</td></tr>
<tr><td>2-8001</td><td>200</td><td>85</td><td>15</td><td>0</td></tr>
<tr><td>8002-20000</td><td>250</td><td>85</td><td>15</td><td>0</td></tr>
<tr><td>20001-43200</td><td>100</td><td>80</td><td>20</td><td>0</td></tr>
<tr><td>43201-86400</td><td>50</td><td>90</td><td>10</td><td>0</td></tr>
<tr><td>86401-100000</td><td>60</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>100001-129600</td><td>40</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>129601-172800</td><td>30</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>172801-216000</td><td>20</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>216001-259200</td><td>15</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>259201-302400</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>302401-518400</td><td>5</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>518401-525600</td><td>100</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>525601-568800</td><td>40</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>568801-612000</td><td>30</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>612001-655200</td><td>20</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>655201-698400</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>698401-1049760</td><td>5</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1049761-1059760</td><td>120</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1059761-1102960</td><td>30</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1102961-1146160</td><td>20</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1146161-1189360</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1189361-1534960</td><td>5</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1534961-1576720</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1576721-1586720</td><td>150</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1586721-1629920</td><td>25</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1629921-1673120</td><td>20</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1673121-1716320</td><td>15</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1716321-1759520</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>1759521-2018720</td><td>5</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2018721-2061920</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2061921-2102240</td><td>15</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2102241-2114240</td><td>200</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2114241-2120240</td><td>80</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2120241-2163440</td><td>40</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2163441-2206640</td><td>20</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2206641-2249840</td><td>10</td><td>80</td><td>10</td><td>10</td></tr>
<tr><td>2249841-2627120</td><td>5</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>2627121-2630000</td><td>220</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>2630001-2673200</td><td>30</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>2673201-2716400</td><td>20</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>2716401-2759600</td><td>10</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>2759601-3148400</td><td>5</td><td>50</td><td>40</td><td>10</td></tr>
<tr><td>3148401-15558210</td><td>5</td><td>50</td><td>40</td><td>10</td></tr>

</table>


### IMPORTANT NOTICE!

1. Reward is in NYEX not in BTC or USD. Get more information from the Team on the discord channel https://discord.gg/btcEauv.
2. We are focus on long term goals for this project. Short term investors should be warry of  wide market fluctuations conditions
3. Don't put all your eggs in one basket and think of diversifying your portfolio. Don't invest all your life saving in crypto-currencies, unless you know and are willing to take the risk.
4. First time traders, should be particularly cautious and adopt basic crypto security (no help over Team Viewer) 
5. Don't fall for the FUD and the hype.
6. Reward indicated on Masternode Online and other masternode sites and purely indicative and should not be taken as investment advice.

The Nyerium Team
