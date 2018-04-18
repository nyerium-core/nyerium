#!/usr/bin/python
# Copyright 2014 BitPay, Inc.
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
#import ptvsd
# ptvsd.enable_attach('my_secret')
# ptvsd.wait_for_attach()
import os
import bctest
import buildenv

if __name__ == '__main__':
	bctest.bctester(os.getcwd() + "/test/data",
			"bitcoin-util-test.json",buildenv)

#	bctest.bctester("/mnt/d/difftool/nye_good/src/test/data", "bitcoin-util-test.json", buildenv)

