// Copyright (c) 2011-2013 The Bitcoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p2563 = uint256("0x0000025b0ff48d41ee5d92eedb7eadeadc7a55d23ffbee8e46c98eb55783cd53");
    uint256 p4092 = uint256("0xad30656e6236cb1d8c6598e5ea81a12ab090b2ce25db8ba17b98e1cd3a59a82b");
    BOOST_CHECK(Checkpoints::CheckBlock(2563, p2563));
    BOOST_CHECK(Checkpoints::CheckBlock(4092, p4092)); //ek


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(2563, p4092));
    BOOST_CHECK(!Checkpoints::CheckBlock(4092, p2563));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(2563+1, p4092));
    BOOST_CHECK(Checkpoints::CheckBlock(4092+1, p2563));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 4092);
}

BOOST_AUTO_TEST_SUITE_END()
