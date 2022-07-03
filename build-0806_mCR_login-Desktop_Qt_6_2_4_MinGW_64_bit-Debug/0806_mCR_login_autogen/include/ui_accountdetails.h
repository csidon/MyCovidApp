/********************************************************************************
** Form generated from reading UI file 'accountdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTDETAILS_H
#define UI_ACCOUNTDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountDetails
{
public:
    QLabel *lbl_chooseAnOption;
    QPushButton *btn_backToHome;
    QLabel *lbl_topBar;
    QLabel *lbl_fName;
    QLabel *lbl_lName;
    QLabel *lbl_pName;
    QLabel *lbl_Email;
    QLabel *lbl_phone;
    QLabel *lbl_NHI;
    QLabel *lbl_NHI_2;
    QLabel *lbl_userFName;
    QLabel *lbl_userLName;
    QLabel *lbl_userPName;
    QLabel *lbl_userEmail;
    QLabel *lbl_userPhone;
    QLabel *lbl_userNHI;

    void setupUi(QWidget *AccountDetails)
    {
        if (AccountDetails->objectName().isEmpty())
            AccountDetails->setObjectName(QString::fromUtf8("AccountDetails"));
        AccountDetails->resize(375, 667);
        lbl_chooseAnOption = new QLabel(AccountDetails);
        lbl_chooseAnOption->setObjectName(QString::fromUtf8("lbl_chooseAnOption"));
        lbl_chooseAnOption->setGeometry(QRect(70, 0, 301, 61));
        lbl_chooseAnOption->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        btn_backToHome = new QPushButton(AccountDetails);
        btn_backToHome->setObjectName(QString::fromUtf8("btn_backToHome"));
        btn_backToHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_topBar = new QLabel(AccountDetails);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(0, -20, 381, 101));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        lbl_fName = new QLabel(AccountDetails);
        lbl_fName->setObjectName(QString::fromUtf8("lbl_fName"));
        lbl_fName->setGeometry(QRect(50, 70, 101, 41));
        lbl_fName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_lName = new QLabel(AccountDetails);
        lbl_lName->setObjectName(QString::fromUtf8("lbl_lName"));
        lbl_lName->setGeometry(QRect(50, 150, 101, 41));
        lbl_lName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_pName = new QLabel(AccountDetails);
        lbl_pName->setObjectName(QString::fromUtf8("lbl_pName"));
        lbl_pName->setGeometry(QRect(50, 230, 161, 41));
        lbl_pName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_Email = new QLabel(AccountDetails);
        lbl_Email->setObjectName(QString::fromUtf8("lbl_Email"));
        lbl_Email->setGeometry(QRect(50, 310, 161, 41));
        lbl_Email->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_phone = new QLabel(AccountDetails);
        lbl_phone->setObjectName(QString::fromUtf8("lbl_phone"));
        lbl_phone->setGeometry(QRect(50, 390, 161, 41));
        lbl_phone->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_NHI = new QLabel(AccountDetails);
        lbl_NHI->setObjectName(QString::fromUtf8("lbl_NHI"));
        lbl_NHI->setGeometry(QRect(50, 470, 161, 41));
        lbl_NHI->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_NHI_2 = new QLabel(AccountDetails);
        lbl_NHI_2->setObjectName(QString::fromUtf8("lbl_NHI_2"));
        lbl_NHI_2->setGeometry(QRect(70, 580, 231, 81));
        lbl_NHI_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:16px;\n"
"color:#666666;"));
        lbl_NHI_2->setAlignment(Qt::AlignCenter);
        lbl_NHI_2->setWordWrap(true);
        lbl_userFName = new QLabel(AccountDetails);
        lbl_userFName->setObjectName(QString::fromUtf8("lbl_userFName"));
        lbl_userFName->setGeometry(QRect(80, 110, 271, 41));
        lbl_userFName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:22px;\n"
"color:black;"));
        lbl_userLName = new QLabel(AccountDetails);
        lbl_userLName->setObjectName(QString::fromUtf8("lbl_userLName"));
        lbl_userLName->setGeometry(QRect(80, 190, 271, 41));
        lbl_userLName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:22px;\n"
"color:black;"));
        lbl_userPName = new QLabel(AccountDetails);
        lbl_userPName->setObjectName(QString::fromUtf8("lbl_userPName"));
        lbl_userPName->setGeometry(QRect(80, 270, 271, 41));
        lbl_userPName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:22px;\n"
"color:black;"));
        lbl_userEmail = new QLabel(AccountDetails);
        lbl_userEmail->setObjectName(QString::fromUtf8("lbl_userEmail"));
        lbl_userEmail->setGeometry(QRect(80, 350, 271, 41));
        lbl_userEmail->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:22px;\n"
"color:black;"));
        lbl_userPhone = new QLabel(AccountDetails);
        lbl_userPhone->setObjectName(QString::fromUtf8("lbl_userPhone"));
        lbl_userPhone->setGeometry(QRect(80, 430, 271, 41));
        lbl_userPhone->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:22px;\n"
"color:black;"));
        lbl_userNHI = new QLabel(AccountDetails);
        lbl_userNHI->setObjectName(QString::fromUtf8("lbl_userNHI"));
        lbl_userNHI->setGeometry(QRect(80, 510, 271, 41));
        lbl_userNHI->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:22px;\n"
"color:black;"));
        lbl_topBar->raise();
        lbl_chooseAnOption->raise();
        btn_backToHome->raise();
        lbl_fName->raise();
        lbl_lName->raise();
        lbl_pName->raise();
        lbl_Email->raise();
        lbl_phone->raise();
        lbl_NHI->raise();
        lbl_NHI_2->raise();
        lbl_userFName->raise();
        lbl_userLName->raise();
        lbl_userPName->raise();
        lbl_userEmail->raise();
        lbl_userPhone->raise();
        lbl_userNHI->raise();

        retranslateUi(AccountDetails);

        QMetaObject::connectSlotsByName(AccountDetails);
    } // setupUi

    void retranslateUi(QWidget *AccountDetails)
    {
        AccountDetails->setWindowTitle(QCoreApplication::translate("AccountDetails", "Form", nullptr));
        lbl_chooseAnOption->setText(QCoreApplication::translate("AccountDetails", " Your Account Details", nullptr));
        btn_backToHome->setText(QString());
        lbl_topBar->setText(QString());
        lbl_fName->setText(QCoreApplication::translate("AccountDetails", "First Name:", nullptr));
        lbl_lName->setText(QCoreApplication::translate("AccountDetails", "Last Name:", nullptr));
        lbl_pName->setText(QCoreApplication::translate("AccountDetails", "Preferred Name:", nullptr));
        lbl_Email->setText(QCoreApplication::translate("AccountDetails", "Email:", nullptr));
        lbl_phone->setText(QCoreApplication::translate("AccountDetails", "Phone Number:", nullptr));
        lbl_NHI->setText(QCoreApplication::translate("AccountDetails", "NHI Number:", nullptr));
        lbl_NHI_2->setText(QCoreApplication::translate("AccountDetails", "If you need to change any of these details, plesae contact one of our administrators via Healthline (0800 611 116)", nullptr));
        lbl_userFName->setText(QCoreApplication::translate("AccountDetails", "First Name:", nullptr));
        lbl_userLName->setText(QCoreApplication::translate("AccountDetails", "Last Name:", nullptr));
        lbl_userPName->setText(QCoreApplication::translate("AccountDetails", "Preferred Name:", nullptr));
        lbl_userEmail->setText(QCoreApplication::translate("AccountDetails", "Email", nullptr));
        lbl_userPhone->setText(QCoreApplication::translate("AccountDetails", "Phone Number", nullptr));
        lbl_userNHI->setText(QCoreApplication::translate("AccountDetails", "NHI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountDetails: public Ui_AccountDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDETAILS_H
