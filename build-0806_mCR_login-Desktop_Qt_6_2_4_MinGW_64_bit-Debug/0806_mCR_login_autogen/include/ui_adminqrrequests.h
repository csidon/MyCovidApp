/********************************************************************************
** Form generated from reading UI file 'adminqrrequests.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINQRREQUESTS_H
#define UI_ADMINQRREQUESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminQRRequests
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_topBar;
    QPushButton *btn_backToAdminHome;
    QLabel *lbl_QRRequests;
    QLabel *lbl_stripedBackground;
    QLabel *lbl_name_1;
    QLabel *lbl_name_2;
    QLabel *lbl_name_3;
    QLabel *lbl_name_4;
    QLabel *lbl_name_5;
    QLabel *lbl_name_6;
    QPushButton *btn_right;
    QPushButton *pushButton_2;
    QLabel *label;
    QWidget *page_2;

    void setupUi(QWidget *adminQRRequests)
    {
        if (adminQRRequests->objectName().isEmpty())
            adminQRRequests->setObjectName(QString::fromUtf8("adminQRRequests"));
        adminQRRequests->resize(375, 667);
        stackedWidget = new QStackedWidget(adminQRRequests);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 381, 671));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lbl_topBar = new QLabel(page);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_backToAdminHome = new QPushButton(page);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_QRRequests = new QLabel(page);
        lbl_QRRequests->setObjectName(QString::fromUtf8("lbl_QRRequests"));
        lbl_QRRequests->setGeometry(QRect(70, 0, 301, 61));
        lbl_QRRequests->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        lbl_stripedBackground = new QLabel(page);
        lbl_stripedBackground->setObjectName(QString::fromUtf8("lbl_stripedBackground"));
        lbl_stripedBackground->setGeometry(QRect(-150, -70, 671, 841));
        lbl_stripedBackground->setStyleSheet(QString::fromUtf8("image:url(:/images/stripedBackground.png);"));
        lbl_name_1 = new QLabel(page);
        lbl_name_1->setObjectName(QString::fromUtf8("lbl_name_1"));
        lbl_name_1->setGeometry(QRect(40, 90, 121, 31));
        lbl_name_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_2 = new QLabel(page);
        lbl_name_2->setObjectName(QString::fromUtf8("lbl_name_2"));
        lbl_name_2->setGeometry(QRect(40, 170, 121, 31));
        lbl_name_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_3 = new QLabel(page);
        lbl_name_3->setObjectName(QString::fromUtf8("lbl_name_3"));
        lbl_name_3->setGeometry(QRect(40, 250, 121, 31));
        lbl_name_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_4 = new QLabel(page);
        lbl_name_4->setObjectName(QString::fromUtf8("lbl_name_4"));
        lbl_name_4->setGeometry(QRect(40, 330, 121, 31));
        lbl_name_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_5 = new QLabel(page);
        lbl_name_5->setObjectName(QString::fromUtf8("lbl_name_5"));
        lbl_name_5->setGeometry(QRect(40, 420, 121, 31));
        lbl_name_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_6 = new QLabel(page);
        lbl_name_6->setObjectName(QString::fromUtf8("lbl_name_6"));
        lbl_name_6->setGeometry(QRect(40, 500, 121, 31));
        lbl_name_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        btn_right = new QPushButton(page);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        btn_right->setGeometry(QRect(300, 580, 41, 41));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 580, 41, 41));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 590, 81, 20));
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:arial;\n"
"font-size:18px;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(adminQRRequests);

        QMetaObject::connectSlotsByName(adminQRRequests);
    } // setupUi

    void retranslateUi(QWidget *adminQRRequests)
    {
        adminQRRequests->setWindowTitle(QCoreApplication::translate("adminQRRequests", "Form", nullptr));
        lbl_topBar->setText(QString());
        btn_backToAdminHome->setText(QString());
        lbl_QRRequests->setText(QCoreApplication::translate("adminQRRequests", "   QR Code Requests", nullptr));
        lbl_stripedBackground->setText(QString());
        lbl_name_1->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        lbl_name_2->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        lbl_name_3->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        lbl_name_4->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        lbl_name_5->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        lbl_name_6->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        btn_right->setText(QCoreApplication::translate("adminQRRequests", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adminQRRequests", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminQRRequests: public Ui_adminQRRequests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINQRREQUESTS_H
