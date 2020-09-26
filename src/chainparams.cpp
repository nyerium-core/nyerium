// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2020 The PIVX developers
// Copyright (c) 2018-2020 The Nyerium developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "chainparamsseeds.h"
#include "consensus/merkle.h"
#include "util.h"
#include "utilstrencodings.h"

#include <boost/assign/list_of.hpp>

#include <assert.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock.SetNull();
    genesis.nVersion = nVersion;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of the genesis coinbase cannot
 * be spent as it did not originally exist in the database.
 *
 * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
 *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
 *   vMerkleTree: e0028e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "25 April 2018, The chancellor is at it again with a better token. Car bump NYE";
    const CScript genesisOutputScript = CScript() << ParseHex("04a0339ee97d36bb216e86017c9fd4f696f93989371f1a579edbd28e958de8e41b64bcbf9511b42a62c9416e5d64212f2fa9db262d85a45e7fb5f83e73ea620c01") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256S("00000849fd3704944ef2ef374f70d79dcc3fd58ac29dc459114aa8b0788378f3"))
    (41, uint256S("000008a019d98868a739449fbae61d542bc084ed8ae3cb877c5c5b8f813554d8"))
    (5000, uint256S("fc2d1aff0b9f4348ee720f1c5c634c75cfc30b528bd2530bae5d5d54eecac3ed"))
    (7999, uint256S("71a890c048d99659ad9a1156302370c1b94438ac099a3b26dab31dd1e42aa87a"))
    (20002, uint256S("af7dd70e8f5e4cfff5de664fb0d629fe81d1ce7461a86f2f7fefb7572232e6d0"))
    (60000, uint256S("2e4db31c55c99c3e0ccf1afcf4c7e209c330c3ab8beb5705f911e04feba0ca14"))
    (70015, uint256S("59f52323e8cf1a5f3bef64ce06f2518ac93cd82a6b46dcc0ad76f6c027618add"))
    (80000, uint256S("bced4db2a98e39a64391c12cc2d3aac8f732da3d8e7918afb114846c438f8750"))
    (90002, uint256S("283c8a9a9b47bf1db1e6c2d043f155c402457679c0fadbacdf6037116883a913"));

    // (259201, uint256S("1c9121bf9329a6234bfd1ea2d91515f19cd96990725265253f4b164283ade5dd"))
    // (424998, uint256S("f31e381eedb0ed3ed65fcc98cc71f36012bee32e8efd017c4f9fb0620fd35f6b"))
    // (616764, uint256S("29dd0bd1c59484f290896687b4ffb6a49afa5c498caf61967c69a541f8191557")) //first block to use new modifierV1
    // (623933, uint256S("c7aafa648a0f1450157dc93bd4d7448913a85b7448f803b4ab970d91fc2a7da7"))
    // (791150, uint256S("8e76f462e4e82d1bd21cb72e1ce1567d4ddda2390f26074ffd1f5d9c270e5e50"))
    // (795000, uint256S("4423cceeb9fd574137a18733416275a70fdf95283cc79ad976ca399aa424a443"))
    // (863787, uint256S("5b2482eca24caf2a46bb22e0545db7b7037282733faa3a42ec20542509999a64"))
    // (863795, uint256S("2ad866818c4866e0d555181daccc628056216c0db431f88a825e84ed4f469067"))
    // (863805, uint256S("a755bd9a22b63c70d3db474f4b2b61a1f86c835b290a081bb3ec1ba2103eb4cb"))
    // (867733, uint256S("03b26296bf693de5782c76843d2fb649cb66d4b05550c6a79c047ff7e1c3ae15"))
    // (879650, uint256S("227e1d2b738b6cd83c46d1d64617934ec899d77cee34336a56e61b71acd10bb2"))
    // (895400, uint256S("7796a0274a608fac12d400198174e50beda992c1d522e52e5b95b884bc1beac6"))  //block that serial# range is enforced
    // (895991, uint256S("d53013ed7ea5c325b9696c95e07667d6858f8ff7ee13fecfa90827bf3c9ae316"))  //network split here
    // (908000, uint256S("202708f8c289b676fceb832a079ff6b308a28608339acbf7584de533619d014d"))
    // (1142400, uint256S("98aff9d605bf123247f98b1e3a02567eb5799d208d78ec30fb89737b1c1f79c5"))
    // (1679090, uint256S("f747ce055ba1b12e1f2e842bd480bc647210799359cb2e553ab292065e3419d6")) //!< First block with a "wrapped" serial spend
    // (1686229, uint256S("bb42bf1e886a7c23474634c90893dd3d68a6ccbfea4ac92a98da5cad0c6a6cb7")) //!< Last block in the "wrapped" serial attack range
    // (1778954, uint256S("0d3241268264a2908d6babf00d9cd1ffb83d93d7bb4e428820127fe227c2029c")) //!< Network split here
    // (1788528, uint256S("ea9243ff8fc079fdd7a04f11fac415de4d98e1bb0dc38db6f79f8f8bbfdbe496")) //!< Network split here
    // (2153200, uint256S("14e477e597d24549cac5e59d97d32155e6ec2861c1003b42d0566f9bf39b65d5")) //!< First v7 block
    // (2356049, uint256S("62e80d8e193bca84655fb78893b20f54a79f2d71124c4ea37b7ef51a0d5451c4")) //!< Network split here
    // (2365700, uint256S("b5d0beead57735539abc2db2b0b08cd65db3e5928efd3c3bf3182d5bf013f36c")); //!< Nyerium v4.1.1 enforced

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1532759414, // * UNIX timestamp of last checkpoint block
    179353,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the UpdateTip debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0, uint256S("0x001"));
    // (1016800, uint256S("6ae7d52092fd918c8ac8d9b1334400387d3057997e6e927a88e57186dc395231"))
    // (1106100, uint256S("c54b3e7e8b710e4075da1806adf2d508ae722627d5bcc43f594cf64d5eef8b30")) //!< zc public spend activation height
    // (1112700, uint256S("2ad8d507dbe3d3841b9f8a29c3878d570228e9361c3e057362d7915777bbc849"))
    // (1347000, uint256S("30c173ffc09a13f288bf6e828216107037ce5b79536b1cebd750a014f4939882")) //!< First v7 block
    // (1608352, uint256S("34a1ae222b2794f34b13e87b34c6ab1b0849c80c372ca0070ceab77a83534f15")); //!< Nyerium v4.1.1 enforced
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1527171315,
    0,
    20};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256S("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1527171315,
    0,
    0};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";

        genesis = CreateGenesisBlock(1527171315, 795796, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000849fd3704944ef2ef374f70d79dcc3fd58ac29dc459114aa8b0788378f3"));
        assert(genesis.hashMerkleRoot == uint256S("0x1fa76a782dd8eee188cfbe0653fdf81bfd5c105f808bd5c9a42e23cb77635802"));

        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.powLimit   = ~UINT256_ZERO >> 20;   // Nyerium starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nBudgetCycleBlocks = 43200;       // approx. 1 every 30 days
        consensus.nBudgetFeeConfirmations = 6;      // Number of confirmations for the finalization fee
        consensus.nCoinbaseMaturity = 10;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMasternodeCountDrift = 20;       // num of MN we allow the see-saw payments to be off by
        consensus.nMaxMoneyOut = 120000000 * COIN;
        consensus.nPoolMaxTransactions = 3;
        consensus.nProposalEstablishmentTime = 60 * 60 * 24;    // must be at least a day old to make it into a budget
        consensus.nStakeMinAge = 3 * 60 * 60;
        consensus.nStakeMinDepth = 600;
        consensus.nTargetTimespan = 1 * 60;
        consensus.nTargetTimespanV2 = 1 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        // spork keys
        consensus.strSporkPubKey = "0432f6a8c71a7efbe34caf81e0f832afd88a87e2a916cf2afbd98b10b615ddeed2e88c6ec6b9ec8f027e75b214af990982711f470fd799af723d72318d2d76dc9a";
        consensus.strSporkPubKeyOld = "0432f6a8c71a7efbe34caf81e0f832afd88a87e2a916cf2afbd98b10b615ddeed2e88c6ec6b9ec8f027e75b214af990982711f470fd799af723d72318d2d76dc9a";
        consensus.nTime_EnforceNewSporkKey = 1527171315;    //!> August 26, 2019 11:00:00 PM GMT
        consensus.nTime_RejectOldSporkKey = 2069538800;     //!> September 26, 2019 11:00:00 PM GMT

        // height-based activations
        consensus.height_last_ZC_AccumCheckpoint = 1;
        consensus.height_last_ZC_WrappedSerials = 99999;
        consensus.height_start_InvalidUTXOsCheck = 0;
        consensus.height_start_ZC_InvalidSerials = 0;
        consensus.height_start_ZC_SerialRangeCheck = 1;
        consensus.height_ZC_RecalcAccumulators = ~1;

        // validation by-pass
        consensus.nNyeriumBadBlockTime = 2071401614;    // Skip nBit validation of Block 259201 per PR #915
        consensus.nNyeriumBadBlockBits = 0x00000001; //0x1c056dac;    // Skip nBit validation of Block 259201 per PR #915

        // Zerocoin-related params
        consensus.ZC_Modulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.ZC_MaxPublicSpendsPerTx = 637;    // Assume about 220 bytes each input
        consensus.ZC_MaxSpendsPerTx = 7;            // Assume about 20kb each input
        consensus.ZC_MinMintConfirmations = 20;
        consensus.ZC_MinMintFee = 1 * CENT;
        consensus.ZC_MinStakeDepth = 200;
        consensus.ZC_TimeStart = 1533366360;    // October 17, 2017 4:30:00 AM
        consensus.ZC_WrappedSerialsSupply = 0 * COIN;   // zerocoin supply at height_last_ZC_WrappedSerials

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight           = 8000; //259201;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight        = 999999999; //615800;
        consensus.vUpgrades[Consensus::UPGRADE_ZC].nActivationHeight            = 100000; //863787;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].nActivationHeight         = 999999999; //1153160;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight         = 999999999; //1808634;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].nActivationHeight     = 999999999; //1880000;
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].nActivationHeight          = 999999999; //1967000;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight          = 999999999; //2153200;
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;

        consensus.vUpgrades[Consensus::UPGRADE_ZC].hashActivationBlock =
                uint256S("0x5da4457503b4f58c7f9aabbf244adcb5d0cd579accf923ff38985c8522f310f6");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].hashActivationBlock =
                uint256S("0x001");

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x6a;
        pchMessageStart[1] = 0x4b;
        pchMessageStart[2] = 0x4c;
        pchMessageStart[3] = 0x5d;
        nDefaultPort = 57418;

        // Note that of those with the service bits flag, most only support a subset of possible options
        vSeeds.push_back(CDNSSeedData("35.154.221.49", "35.154.221.49"));           // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("167.99.200.1", "167.99.200.1"));             // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("13.127.206.177", "13.127.206.177"));         // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("138.68.189.150", "138.68.189.150"));         // Primary DNS Seeder

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 53);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 8);
        base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 63);     // starting with 'S'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0xbc).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }

};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";

        genesis = CreateGenesisBlock(1527171315, 795796, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock   ==  uint256S("0x00000849fd3704944ef2ef374f70d79dcc3fd58ac29dc459114aa8b0788378f3"));
        assert(genesis.hashMerkleRoot       ==  uint256S("0x1fa76a782dd8eee188cfbe0653fdf81bfd5c105f808bd5c9a42e23cb77635802"));

        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.powLimit   = ~UINT256_ZERO >> 20;   // Nyerium starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nBudgetCycleBlocks = 144;         // approx 10 cycles per day
        consensus.nBudgetFeeConfirmations = 3;      // (only 8-blocks window for finalization on testnet)
        consensus.nCoinbaseMaturity = 15;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMasternodeCountDrift = 4;        // num of MN we allow the see-saw payments to be off by
        consensus.nMaxMoneyOut = 120000000 * COIN;
        consensus.nPoolMaxTransactions = 2;
        consensus.nProposalEstablishmentTime = 60 * 5;  // at least 5 min old to make it into a budget
        consensus.nStakeMinAge = 3 * 60 * 60;
        consensus.nStakeMinDepth = 100;
        consensus.nTargetTimespan = 1 * 60;
        consensus.nTargetTimespanV2 = 1 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        // spork keys
        consensus.strSporkPubKey = "04e1af59b5298e695ccfe4cc59600d3b2f00d97183f3c9ef12097bef0a0d4232cb696da0deace6982a416cc0ae77bdb904422f04ff8eccb5b99d370ce8ad7ee710";
        consensus.strSporkPubKeyOld = "04e1af59b5298e695ccfe4cc59600d3b2f00d97183f3c9ef12097bef0a0d4232cb696da0deace6982a416cc0ae77bdb904422f04ff8eccb5b99d370ce8ad7ee710";
        consensus.nTime_EnforceNewSporkKey = 1566860400;    //!> August 26, 2019 11:00:00 PM GMT
        consensus.nTime_RejectOldSporkKey = 1569538800;     //!> September 26, 2019 11:00:00 PM GMT

        // height based activations
        consensus.height_last_ZC_AccumCheckpoint = 1106090;
        consensus.height_last_ZC_WrappedSerials = -1;
        consensus.height_start_InvalidUTXOsCheck = 999999999;
        consensus.height_start_ZC_InvalidSerials = 999999999;
        consensus.height_start_ZC_SerialRangeCheck = 1;
        consensus.height_ZC_RecalcAccumulators = 999999999;

        // validation by-pass
        consensus.nNyeriumBadBlockTime = 2089001494; // Skip nBit validation of Block 201 per PR #915
        consensus.nNyeriumBadBlockBits = 0x1e0a20bd; // Skip nBit validation of Block 201 per PR #915

        // Zerocoin-related params
        consensus.ZC_Modulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.ZC_MaxPublicSpendsPerTx = 637;    // Assume about 220 bytes each input
        consensus.ZC_MaxSpendsPerTx = 7;            // Assume about 20kb each input
        consensus.ZC_MinMintConfirmations = 20;
        consensus.ZC_MinMintFee = 1 * CENT;
        consensus.ZC_MinStakeDepth = 200;
        consensus.ZC_TimeStart = 1528254417;
        consensus.ZC_WrappedSerialsSupply = 0;   // WrappedSerials only on main net

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight           = 201;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight        = 51197;
        consensus.vUpgrades[Consensus::UPGRADE_ZC].nActivationHeight            = 201576;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].nActivationHeight         = 444020;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight         = 851019;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].nActivationHeight     = 1106100;
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].nActivationHeight          = 1214000;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight          = 1347000;
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;

        consensus.vUpgrades[Consensus::UPGRADE_ZC].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].hashActivationBlock =
                uint256S("0x001");

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */

        pchMessageStart[0] = 0x4f;
        pchMessageStart[1] = 0x7e;
        pchMessageStart[2] = 0x6d;
        pchMessageStart[3] = 0xbc;
        nDefaultPort = 55150;

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        //vSeeds.push_back(CDNSSeedData("13.127.26.220", "13.127.26.220", true));
        //vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "nyerium-testnet.seed.fuzzbawls.pw", true));
        //vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "nyerium-testnet.seed2.fuzzbawls.pw", true));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 112); // Testnet nyerium addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet nyerium script addresses start with '8' or '9'
        base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 73);     // starting with 'W'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet nyerium BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet nyerium BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet nyerium BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";

        genesis = CreateGenesisBlock(1527171315, 795796, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000849fd3704944ef2ef374f70d79dcc3fd58ac29dc459114aa8b0788378f3"));
        assert(genesis.hashMerkleRoot == uint256S("0x1fa76a782dd8eee188cfbe0653fdf81bfd5c105f808bd5c9a42e23cb77635802"));

        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.powLimit   = ~UINT256_ZERO >> 20;   // Nyerium starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nBudgetCycleBlocks = 144;         // approx 10 cycles per day
        consensus.nBudgetFeeConfirmations = 3;      // (only 8-blocks window for finalization on regtest)
        consensus.nCoinbaseMaturity = 100;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMasternodeCountDrift = 4;        // num of MN we allow the see-saw payments to be off by
        consensus.nMaxMoneyOut = 120000000 * COIN;
        consensus.nPoolMaxTransactions = 2;
        consensus.nProposalEstablishmentTime = 60 * 5;  // at least 5 min old to make it into a budget
        consensus.nStakeMinAge = 0;
        consensus.nStakeMinDepth = 2;
        consensus.nTargetTimespan = 1 * 60;
        consensus.nTargetTimespanV2 = 1 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        /* Spork Key for RegTest:
        WIF private key: 932HEevBSujW2ud7RfB1YF91AFygbBRQj3de3LyaCRqNzKKgWXi
        private key hex: bd4960dcbd9e7f2223f24e7164ecb6f1fe96fc3a416f5d3a830ba5720c84b8ca
        Address: yCvUVd72w7xpimf981m114FSFbmAmne7j9
        */
        consensus.strSporkPubKey = "04e1af59b5298e695ccfe4cc59600d3b2f00d97183f3c9ef12097bef0a0d4232cb696da0deace6982a416cc0ae77bdb904422f04ff8eccb5b99d370ce8ad7ee710";
        consensus.strSporkPubKeyOld = "";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // height based activations
        consensus.height_last_ZC_AccumCheckpoint = 310;     // no checkpoints on regtest
        consensus.height_last_ZC_WrappedSerials = -1;
        consensus.height_start_InvalidUTXOsCheck = 999999999;
        consensus.height_start_ZC_InvalidSerials = 999999999;
        consensus.height_start_ZC_SerialRangeCheck = 300;
        consensus.height_ZC_RecalcAccumulators = 999999999;

        // Zerocoin-related params
        consensus.ZC_Modulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.ZC_MaxPublicSpendsPerTx = 637;    // Assume about 220 bytes each input
        consensus.ZC_MaxSpendsPerTx = 7;            // Assume about 20kb each input
        consensus.ZC_MinMintConfirmations = 10;
        consensus.ZC_MinMintFee = 1 * CENT;
        consensus.ZC_MinStakeDepth = 10;
        consensus.ZC_TimeStart = 0;                 // not implemented on regtest
        consensus.ZC_WrappedSerialsSupply = 0;

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight           = 251;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight        = 251;
        consensus.vUpgrades[Consensus::UPGRADE_ZC].nActivationHeight            = 300;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_V2].nActivationHeight         = 300;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight         =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_ZC_PUBLIC].nActivationHeight     = 400;
        consensus.vUpgrades[Consensus::UPGRADE_V3_4].nActivationHeight          = 251;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight          =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_V5_DUMMY].nActivationHeight       = 300;

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */

        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nDefaultPort = 55158;

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }

    void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
    {
        assert(idx > Consensus::BASE_NETWORK && idx < Consensus::MAX_NETWORK_UPGRADES);
        consensus.vUpgrades[idx].nActivationHeight = nActivationHeight;
    }
};
static CRegTestParams regTestParams;

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
{
    regTestParams.UpdateNetworkUpgradeParameters(idx, nActivationHeight);
}
