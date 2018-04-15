// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?label=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.label == QString("Some Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?amount=100&label=Some Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("nyerium://P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?message=Some Example Address", &rv));
    QVERIFY(rv.address == QString("P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?req-message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?amount=1,000&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nyerium:P4sZQ6m6ja9pnzcuSzPbEWNh7q1nqEXAHz?amount=1,000.0&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
