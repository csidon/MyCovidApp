/********************************************************************************
** Form generated from reading UI file 'adminhome.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINHOME_H
#define UI_ADMINHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminHome
{
public:
    QLabel *lbl_headerBar;
    QPushButton *btn_issuesReported;
    QPushButton *btn_QRCodeRequests;
    QPushButton *btn_searchAndManageUsers;
    QLabel *lbl_numberOfQRCodeRequests;
    QLabel *lbl_numberOfIssuesReported;
    QLabel *lbl_kiaOra;
    QLabel *lbl_adminName;

    void setupUi(QWidget *AdminHome)
    {
        if (AdminHome->objectName().isEmpty())
            AdminHome->setObjectName(QString::fromUtf8("AdminHome"));
        AdminHome->setEnabled(true);
        AdminHome->resize(375, 667);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        AdminHome->setFont(font);
        lbl_headerBar = new QLabel(AdminHome);
        lbl_headerBar->setObjectName(QString::fromUtf8("lbl_headerBar"));
        lbl_headerBar->setGeometry(QRect(0, 0, 375, 63));
        lbl_headerBar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/appBanner.png);"));
        btn_issuesReported = new QPushButton(AdminHome);
        btn_issuesReported->setObjectName(QString::fromUtf8("btn_issuesReported"));
        btn_issuesReported->setGeometry(QRect(200, 170, 161, 201));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_issuesReported->sizePolicy().hasHeightForWidth());
        btn_issuesReported->setSizePolicy(sizePolicy);
        btn_issuesReported->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/adminErrorReports.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_QRCodeRequests = new QPushButton(AdminHome);
        btn_QRCodeRequests->setObjectName(QString::fromUtf8("btn_QRCodeRequests"));
        btn_QRCodeRequests->setGeometry(QRect(20, 170, 161, 201));
        sizePolicy.setHeightForWidth(btn_QRCodeRequests->sizePolicy().hasHeightForWidth());
        btn_QRCodeRequests->setSizePolicy(sizePolicy);
        btn_QRCodeRequests->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/adminQRCodeRequests.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_searchAndManageUsers = new QPushButton(AdminHome);
        btn_searchAndManageUsers->setObjectName(QString::fromUtf8("btn_searchAndManageUsers"));
        btn_searchAndManageUsers->setGeometry(QRect(20, 390, 341, 211));
        sizePolicy.setHeightForWidth(btn_searchAndManageUsers->sizePolicy().hasHeightForWidth());
        btn_searchAndManageUsers->setSizePolicy(sizePolicy);
        btn_searchAndManageUsers->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/adminSearchUsers.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_numberOfQRCodeRequests = new QLabel(AdminHome);
        lbl_numberOfQRCodeRequests->setObjectName(QString::fromUtf8("lbl_numberOfQRCodeRequests"));
        lbl_numberOfQRCodeRequests->setGeometry(QRect(70, 220, 61, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("arial")});
        lbl_numberOfQRCodeRequests->setFont(font1);
        lbl_numberOfQRCodeRequests->setStyleSheet(QString::fromUtf8("color: black;font-size: 100px;font-family: arial;"));
        lbl_numberOfQRCodeRequests->setAlignment(Qt::AlignCenter);
        lbl_numberOfIssuesReported = new QLabel(AdminHome);
        lbl_numberOfIssuesReported->setObjectName(QString::fromUtf8("lbl_numberOfIssuesReported"));
        lbl_numberOfIssuesReported->setGeometry(QRect(250, 220, 61, 81));
        lbl_numberOfIssuesReported->setFont(font1);
        lbl_numberOfIssuesReported->setStyleSheet(QString::fromUtf8("color: black;font-size: 100px;font-family: arial;"));
        lbl_numberOfIssuesReported->setAlignment(Qt::AlignCenter);
        lbl_kiaOra = new QLabel(AdminHome);
        lbl_kiaOra->setObjectName(QString::fromUtf8("lbl_kiaOra"));
        lbl_kiaOra->setGeometry(QRect(30, 90, 121, 61));
        lbl_kiaOra->setFont(font);
        lbl_kiaOra->setStyleSheet(QString::fromUtf8("color: black; font-size: 32px"));
        lbl_adminName = new QLabel(AdminHome);
        lbl_adminName->setObjectName(QString::fromUtf8("lbl_adminName"));
        lbl_adminName->setGeometry(QRect(150, 90, 201, 61));
        lbl_adminName->setFont(font);
        lbl_adminName->setStyleSheet(QString::fromUtf8("color: black; font-size: 32px"));

        retranslateUi(AdminHome);

        QMetaObject::connectSlotsByName(AdminHome);
    } // setupUi

    void retranslateUi(QWidget *AdminHome)
    {
        AdminHome->setWindowTitle(QCoreApplication::translate("AdminHome", "Form", nullptr));
        lbl_headerBar->setText(QString());
        btn_issuesReported->setText(QString());
        btn_QRCodeRequests->setText(QString());
        btn_searchAndManageUsers->setText(QString());
        lbl_numberOfQRCodeRequests->setText(QCoreApplication::translate("AdminHome", "0", nullptr));
        lbl_numberOfIssuesReported->setText(QCoreApplication::translate("AdminHome", "0", nullptr));
        lbl_kiaOra->setText(QCoreApplication::translate("AdminHome", "Kia Ora", nullptr));
        lbl_adminName->setText(QCoreApplication::translate("AdminHome", "Darth Vader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminHome: public Ui_AdminHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOME_H
