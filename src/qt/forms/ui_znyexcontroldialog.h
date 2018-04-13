/********************************************************************************
** Form generated from reading UI file 'znyexcontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZNYEXCONTROLDIALOG_H
#define UI_ZNYEXCONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZNyexControlDialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *labelQuantity;
    QLabel *labelQuantity_int;
    QLabel *labelZNyex;
    QLabel *labelZNyex_int;
    QPushButton *pushButtonAll;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ZNyexControlDialog)
    {
        if (ZNyexControlDialog->objectName().isEmpty())
            ZNyexControlDialog->setObjectName(QStringLiteral("ZNyexControlDialog"));
        ZNyexControlDialog->resize(681, 410);
        ZNyexControlDialog->setMinimumSize(QSize(681, 384));
        QFont font;
        font.setFamily(QStringLiteral("Ara Hamah 1982"));
        font.setPointSize(14);
        ZNyexControlDialog->setFont(font);
        gridLayout = new QGridLayout(ZNyexControlDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelQuantity = new QLabel(ZNyexControlDialog);
        labelQuantity->setObjectName(QStringLiteral("labelQuantity"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelQuantity);

        labelQuantity_int = new QLabel(ZNyexControlDialog);
        labelQuantity_int->setObjectName(QStringLiteral("labelQuantity_int"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelQuantity_int);

        labelZNyex = new QLabel(ZNyexControlDialog);
        labelZNyex->setObjectName(QStringLiteral("labelZNyex"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelZNyex);

        labelZNyex_int = new QLabel(ZNyexControlDialog);
        labelZNyex_int->setObjectName(QStringLiteral("labelZNyex_int"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelZNyex_int);

        pushButtonAll = new QPushButton(ZNyexControlDialog);
        pushButtonAll->setObjectName(QStringLiteral("pushButtonAll"));

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButtonAll);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(ZNyexControlDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QStringLiteral("Confirmations"));
        __qtreewidgetitem->setText(2, QStringLiteral("zNyex Public ID"));
        __qtreewidgetitem->setText(1, QStringLiteral("Denomination"));
        __qtreewidgetitem->setText(0, QStringLiteral("Select"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(0, 250));
        treeWidget->setFont(font);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSortingEnabled(true);
        treeWidget->setColumnCount(5);
        treeWidget->header()->setDefaultSectionSize(100);

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(ZNyexControlDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(ZNyexControlDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ZNyexControlDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ZNyexControlDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ZNyexControlDialog);
    } // setupUi

    void retranslateUi(QDialog *ZNyexControlDialog)
    {
        ZNyexControlDialog->setWindowTitle(QApplication::translate("ZNyexControlDialog", "Select zNyex to Spend", Q_NULLPTR));
        labelQuantity->setText(QApplication::translate("ZNyexControlDialog", "Quantity", Q_NULLPTR));
        labelQuantity_int->setText(QApplication::translate("ZNyexControlDialog", "0", Q_NULLPTR));
        labelZNyex->setText(QApplication::translate("ZNyexControlDialog", "zNyex", Q_NULLPTR));
        labelZNyex_int->setText(QApplication::translate("ZNyexControlDialog", "0", Q_NULLPTR));
        pushButtonAll->setText(QApplication::translate("ZNyexControlDialog", "Select/Deselect All", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("ZNyexControlDialog", "Is Spendable", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZNyexControlDialog: public Ui_ZNyexControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZNYEXCONTROLDIALOG_H
