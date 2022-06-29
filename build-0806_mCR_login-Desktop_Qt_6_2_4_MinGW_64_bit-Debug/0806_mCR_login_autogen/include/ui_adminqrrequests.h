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
    QPushButton *btn_pageRight;
    QPushButton *btn_pageLeft;
    QLabel *lbl_currentPage;
    QPushButton *btn_assign_1;
    QPushButton *btn_assign_2;
    QPushButton *btn_assign_3;
    QPushButton *btn_assign_4;
    QPushButton *btn_assign_5;
    QPushButton *btn_assign_6;

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
        lbl_name_1->setGeometry(QRect(40, 90, 331, 31));
        lbl_name_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_2 = new QLabel(page);
        lbl_name_2->setObjectName(QString::fromUtf8("lbl_name_2"));
        lbl_name_2->setGeometry(QRect(40, 170, 331, 31));
        lbl_name_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_3 = new QLabel(page);
        lbl_name_3->setObjectName(QString::fromUtf8("lbl_name_3"));
        lbl_name_3->setGeometry(QRect(40, 250, 331, 31));
        lbl_name_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_4 = new QLabel(page);
        lbl_name_4->setObjectName(QString::fromUtf8("lbl_name_4"));
        lbl_name_4->setGeometry(QRect(40, 330, 331, 31));
        lbl_name_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_5 = new QLabel(page);
        lbl_name_5->setObjectName(QString::fromUtf8("lbl_name_5"));
        lbl_name_5->setGeometry(QRect(40, 420, 331, 31));
        lbl_name_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_name_6 = new QLabel(page);
        lbl_name_6->setObjectName(QString::fromUtf8("lbl_name_6"));
        lbl_name_6->setGeometry(QRect(40, 500, 331, 31));
        lbl_name_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        btn_pageRight = new QPushButton(page);
        btn_pageRight->setObjectName(QString::fromUtf8("btn_pageRight"));
        btn_pageRight->setGeometry(QRect(300, 580, 41, 41));
        btn_pageRight->setStyleSheet(QString::fromUtf8("image: url(:/images/pageRight.png);"));
        btn_pageLeft = new QPushButton(page);
        btn_pageLeft->setObjectName(QString::fromUtf8("btn_pageLeft"));
        btn_pageLeft->setGeometry(QRect(240, 580, 41, 41));
        btn_pageLeft->setStyleSheet(QString::fromUtf8("image:url(:/images/pageLeft.png);"));
        lbl_currentPage = new QLabel(page);
        lbl_currentPage->setObjectName(QString::fromUtf8("lbl_currentPage"));
        lbl_currentPage->setGeometry(QRect(90, 590, 121, 20));
        lbl_currentPage->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:arial;\n"
"font-size:18px;"));
        btn_assign_1 = new QPushButton(page);
        btn_assign_1->setObjectName(QString::fromUtf8("btn_assign_1"));
        btn_assign_1->setGeometry(QRect(-10, 60, 381, 81));
        btn_assign_1->setStyleSheet(QString::fromUtf8("background-color:  rgba(255,255,255,0.1);\n"
""));
        btn_assign_2 = new QPushButton(page);
        btn_assign_2->setObjectName(QString::fromUtf8("btn_assign_2"));
        btn_assign_2->setGeometry(QRect(-10, 140, 381, 81));
        btn_assign_2->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        btn_assign_3 = new QPushButton(page);
        btn_assign_3->setObjectName(QString::fromUtf8("btn_assign_3"));
        btn_assign_3->setGeometry(QRect(-10, 220, 381, 81));
        btn_assign_3->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        btn_assign_4 = new QPushButton(page);
        btn_assign_4->setObjectName(QString::fromUtf8("btn_assign_4"));
        btn_assign_4->setGeometry(QRect(-10, 300, 381, 81));
        btn_assign_4->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        btn_assign_5 = new QPushButton(page);
        btn_assign_5->setObjectName(QString::fromUtf8("btn_assign_5"));
        btn_assign_5->setGeometry(QRect(-10, 390, 381, 81));
        btn_assign_5->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        btn_assign_6 = new QPushButton(page);
        btn_assign_6->setObjectName(QString::fromUtf8("btn_assign_6"));
        btn_assign_6->setGeometry(QRect(-10, 470, 381, 81));
        btn_assign_6->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        stackedWidget->addWidget(page);
        lbl_topBar->raise();
        lbl_QRRequests->raise();
        lbl_stripedBackground->raise();
        lbl_name_1->raise();
        lbl_name_2->raise();
        lbl_name_3->raise();
        lbl_name_4->raise();
        lbl_name_5->raise();
        lbl_name_6->raise();
        btn_pageRight->raise();
        btn_pageLeft->raise();
        lbl_currentPage->raise();
        btn_backToAdminHome->raise();
        btn_assign_2->raise();
        btn_assign_3->raise();
        btn_assign_4->raise();
        btn_assign_5->raise();
        btn_assign_6->raise();
        btn_assign_1->raise();

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
        btn_pageRight->setText(QString());
        btn_pageLeft->setText(QString());
        lbl_currentPage->setText(QCoreApplication::translate("adminQRRequests", "TextLabel", nullptr));
        btn_assign_1->setText(QString());
        btn_assign_2->setText(QString());
        btn_assign_3->setText(QString());
        btn_assign_4->setText(QString());
        btn_assign_5->setText(QString());
        btn_assign_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminQRRequests: public Ui_adminQRRequests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINQRREQUESTS_H
