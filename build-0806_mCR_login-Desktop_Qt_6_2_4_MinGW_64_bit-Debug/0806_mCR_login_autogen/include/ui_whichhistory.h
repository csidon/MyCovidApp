/********************************************************************************
** Form generated from reading UI file 'whichhistory.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHICHHISTORY_H
#define UI_WHICHHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WhichHistory
{
public:
    QLabel *lbl_topBar;
    QPushButton *btn_backToHome;
    QLabel *lbl_chooseAnOption;
    QPushButton *btn_accountDetails;
    QPushButton *btn_vaxHistory;
    QPushButton *btn_testHistory;

    void setupUi(QWidget *WhichHistory)
    {
        if (WhichHistory->objectName().isEmpty())
            WhichHistory->setObjectName(QString::fromUtf8("WhichHistory"));
        WhichHistory->resize(375, 667);
        lbl_topBar = new QLabel(WhichHistory);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_backToHome = new QPushButton(WhichHistory);
        btn_backToHome->setObjectName(QString::fromUtf8("btn_backToHome"));
        btn_backToHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_chooseAnOption = new QLabel(WhichHistory);
        lbl_chooseAnOption->setObjectName(QString::fromUtf8("lbl_chooseAnOption"));
        lbl_chooseAnOption->setGeometry(QRect(70, 0, 301, 61));
        lbl_chooseAnOption->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        btn_accountDetails = new QPushButton(WhichHistory);
        btn_accountDetails->setObjectName(QString::fromUtf8("btn_accountDetails"));
        btn_accountDetails->setGeometry(QRect(50, 410, 281, 61));
        btn_vaxHistory = new QPushButton(WhichHistory);
        btn_vaxHistory->setObjectName(QString::fromUtf8("btn_vaxHistory"));
        btn_vaxHistory->setGeometry(QRect(50, 300, 281, 61));
        btn_testHistory = new QPushButton(WhichHistory);
        btn_testHistory->setObjectName(QString::fromUtf8("btn_testHistory"));
        btn_testHistory->setGeometry(QRect(50, 190, 281, 61));

        retranslateUi(WhichHistory);

        QMetaObject::connectSlotsByName(WhichHistory);
    } // setupUi

    void retranslateUi(QWidget *WhichHistory)
    {
        WhichHistory->setWindowTitle(QCoreApplication::translate("WhichHistory", "Form", nullptr));
        lbl_topBar->setText(QString());
        btn_backToHome->setText(QString());
        lbl_chooseAnOption->setText(QCoreApplication::translate("WhichHistory", "    Choose an Option", nullptr));
        btn_accountDetails->setText(QCoreApplication::translate("WhichHistory", "Your Account Details", nullptr));
        btn_vaxHistory->setText(QCoreApplication::translate("WhichHistory", "Your Past COVID-19 Vaccinations", nullptr));
        btn_testHistory->setText(QCoreApplication::translate("WhichHistory", "Your Past COVID-19 Test Results", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WhichHistory: public Ui_WhichHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHICHHISTORY_H
