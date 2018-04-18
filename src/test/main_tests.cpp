// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 120000000 * COIN; //To review EK

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 (10,000,000 NYEX) */ //EK was 60,001
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 10000000 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1; nHeight <= 45000; nHeight += 1) {
        /* PoW Phase One */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 200 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 45001; nHeight <= 250000; nHeight += 1) {
        /* PoW Phase Two */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 250 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 250001; nHeight <= 300000; nHeight += 1) {
        /* PoW Phase Two */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 180 * COIN);
        BOOST_CHECK(MoneyRange(nSubsidy));
        nSum += nSubsidy;
        BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
    }
    BOOST_CHECK(nSum == 6925000000000000ULL); // 69250000 total of (45000-1)*200 + (250000-45001+1)*250 etc
}

BOOST_AUTO_TEST_SUITE_END()
