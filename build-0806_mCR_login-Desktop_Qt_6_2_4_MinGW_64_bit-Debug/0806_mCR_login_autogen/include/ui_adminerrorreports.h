/********************************************************************************
** Form generated from reading UI file 'adminerrorreports.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINERRORREPORTS_H
#define UI_ADMINERRORREPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminErrorReports
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_stripedBackground;
    QPushButton *btn_pageLeft;
    QLabel *lbl_report_1;
    QPushButton *btn_pageRight;
    QLabel *lbl_report_4;
    QPushButton *btn_view_4;
    QLabel *lbl_report_5;
    QLabel *lbl_currentPage;
    QPushButton *btn_view_2;
    QLabel *lbl_report_2;
    QLabel *lbl_report_3;
    QPushButton *btn_view_5;
    QLabel *lbl_topBar;
    QPushButton *btn_backToAdminHome;
    QLabel *lbl_report_6;
    QPushButton *btn_view_6;
    QLabel *lbl_QRRequests;
    QPushButton *btn_view_3;
    QPushButton *btn_view_1;
    QLabel *lbl_name_1;
    QLabel *lbl_name_2;
    QLabel *lbl_name_3;
    QLabel *lbl_name_4;
    QLabel *lbl_name_5;
    QLabel *lbl_name_6;
    QLabel *lbl_date_1;
    QLabel *lbl_date_2;
    QLabel *lbl_date_3;
    QLabel *lbl_date_4;
    QLabel *lbl_date_5;
    QLabel *lbl_date_6;
    QLabel *lbl_new_1;
    QLabel *lbl_new_2;
    QLabel *lbl_new_3;
    QLabel *lbl_new_4;
    QLabel *lbl_new_5;
    QLabel *lbl_new_6;
    QWidget *page_2;

    void setupUi(QWidget *AdminErrorReports)
    {
        if (AdminErrorReports->objectName().isEmpty())
            AdminErrorReports->setObjectName(QString::fromUtf8("AdminErrorReports"));
        AdminErrorReports->resize(375, 667);
        stackedWidget = new QStackedWidget(AdminErrorReports);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 381, 671));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lbl_stripedBackground = new QLabel(page);
        lbl_stripedBackground->setObjectName(QString::fromUtf8("lbl_stripedBackground"));
        lbl_stripedBackground->setGeometry(QRect(-150, -70, 671, 841));
        lbl_stripedBackground->setStyleSheet(QString::fromUtf8("image:url(:/images/stripedBackground.png);"));
        btn_pageLeft = new QPushButton(page);
        btn_pageLeft->setObjectName(QString::fromUtf8("btn_pageLeft"));
        btn_pageLeft->setGeometry(QRect(240, 580, 41, 41));
        btn_pageLeft->setStyleSheet(QString::fromUtf8("image:url(:/images/pageLeft.png);"));
        lbl_report_1 = new QLabel(page);
        lbl_report_1->setObjectName(QString::fromUtf8("lbl_report_1"));
        lbl_report_1->setGeometry(QRect(40, 100, 231, 31));
        lbl_report_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        btn_pageRight = new QPushButton(page);
        btn_pageRight->setObjectName(QString::fromUtf8("btn_pageRight"));
        btn_pageRight->setGeometry(QRect(300, 580, 41, 41));
        btn_pageRight->setStyleSheet(QString::fromUtf8("image: url(:/images/pageRight.png);"));
        lbl_report_4 = new QLabel(page);
        lbl_report_4->setObjectName(QString::fromUtf8("lbl_report_4"));
        lbl_report_4->setGeometry(QRect(40, 340, 231, 31));
        lbl_report_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        btn_view_4 = new QPushButton(page);
        btn_view_4->setObjectName(QString::fromUtf8("btn_view_4"));
        btn_view_4->setGeometry(QRect(-10, 300, 381, 81));
        btn_view_4->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        lbl_report_5 = new QLabel(page);
        lbl_report_5->setObjectName(QString::fromUtf8("lbl_report_5"));
        lbl_report_5->setGeometry(QRect(40, 430, 231, 31));
        lbl_report_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_currentPage = new QLabel(page);
        lbl_currentPage->setObjectName(QString::fromUtf8("lbl_currentPage"));
        lbl_currentPage->setGeometry(QRect(90, 590, 121, 20));
        lbl_currentPage->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:arial;\n"
"font-size:18px;"));
        btn_view_2 = new QPushButton(page);
        btn_view_2->setObjectName(QString::fromUtf8("btn_view_2"));
        btn_view_2->setGeometry(QRect(-10, 140, 381, 81));
        btn_view_2->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        lbl_report_2 = new QLabel(page);
        lbl_report_2->setObjectName(QString::fromUtf8("lbl_report_2"));
        lbl_report_2->setGeometry(QRect(40, 180, 231, 31));
        lbl_report_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        lbl_report_3 = new QLabel(page);
        lbl_report_3->setObjectName(QString::fromUtf8("lbl_report_3"));
        lbl_report_3->setGeometry(QRect(40, 260, 231, 31));
        lbl_report_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        btn_view_5 = new QPushButton(page);
        btn_view_5->setObjectName(QString::fromUtf8("btn_view_5"));
        btn_view_5->setGeometry(QRect(-10, 390, 381, 81));
        btn_view_5->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        lbl_topBar = new QLabel(page);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_backToAdminHome = new QPushButton(page);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_report_6 = new QLabel(page);
        lbl_report_6->setObjectName(QString::fromUtf8("lbl_report_6"));
        lbl_report_6->setGeometry(QRect(40, 510, 231, 31));
        lbl_report_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:24px;\n"
"color: black;"));
        btn_view_6 = new QPushButton(page);
        btn_view_6->setObjectName(QString::fromUtf8("btn_view_6"));
        btn_view_6->setGeometry(QRect(-10, 470, 381, 81));
        btn_view_6->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        lbl_QRRequests = new QLabel(page);
        lbl_QRRequests->setObjectName(QString::fromUtf8("lbl_QRRequests"));
        lbl_QRRequests->setGeometry(QRect(70, 0, 301, 61));
        lbl_QRRequests->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        btn_view_3 = new QPushButton(page);
        btn_view_3->setObjectName(QString::fromUtf8("btn_view_3"));
        btn_view_3->setGeometry(QRect(-10, 220, 381, 81));
        btn_view_3->setStyleSheet(QString::fromUtf8("background-color:  rgba(100,100,100,0);\n"
""));
        btn_view_1 = new QPushButton(page);
        btn_view_1->setObjectName(QString::fromUtf8("btn_view_1"));
        btn_view_1->setGeometry(QRect(-10, 60, 381, 81));
        btn_view_1->setStyleSheet(QString::fromUtf8("background-color:  rgba(255,255,255,0.1);\n"
""));
        lbl_name_1 = new QLabel(page);
        lbl_name_1->setObjectName(QString::fromUtf8("lbl_name_1"));
        lbl_name_1->setGeometry(QRect(40, 70, 251, 31));
        lbl_name_1->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;"));
        lbl_name_2 = new QLabel(page);
        lbl_name_2->setObjectName(QString::fromUtf8("lbl_name_2"));
        lbl_name_2->setGeometry(QRect(40, 150, 251, 31));
        lbl_name_2->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;"));
        lbl_name_3 = new QLabel(page);
        lbl_name_3->setObjectName(QString::fromUtf8("lbl_name_3"));
        lbl_name_3->setGeometry(QRect(40, 230, 251, 31));
        lbl_name_3->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;"));
        lbl_name_4 = new QLabel(page);
        lbl_name_4->setObjectName(QString::fromUtf8("lbl_name_4"));
        lbl_name_4->setGeometry(QRect(40, 310, 251, 31));
        lbl_name_4->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;"));
        lbl_name_5 = new QLabel(page);
        lbl_name_5->setObjectName(QString::fromUtf8("lbl_name_5"));
        lbl_name_5->setGeometry(QRect(40, 400, 251, 31));
        lbl_name_5->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;"));
        lbl_name_6 = new QLabel(page);
        lbl_name_6->setObjectName(QString::fromUtf8("lbl_name_6"));
        lbl_name_6->setGeometry(QRect(40, 480, 251, 31));
        lbl_name_6->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;"));
        lbl_date_1 = new QLabel(page);
        lbl_date_1->setObjectName(QString::fromUtf8("lbl_date_1"));
        lbl_date_1->setGeometry(QRect(310, 70, 51, 31));
        lbl_date_1->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;\n"
"text-align: right;"));
        lbl_date_2 = new QLabel(page);
        lbl_date_2->setObjectName(QString::fromUtf8("lbl_date_2"));
        lbl_date_2->setGeometry(QRect(310, 150, 51, 31));
        lbl_date_2->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;\n"
"text-align: right;"));
        lbl_date_3 = new QLabel(page);
        lbl_date_3->setObjectName(QString::fromUtf8("lbl_date_3"));
        lbl_date_3->setGeometry(QRect(310, 230, 51, 31));
        lbl_date_3->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;\n"
"text-align: right;"));
        lbl_date_4 = new QLabel(page);
        lbl_date_4->setObjectName(QString::fromUtf8("lbl_date_4"));
        lbl_date_4->setGeometry(QRect(310, 310, 51, 31));
        lbl_date_4->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;\n"
"text-align: right;"));
        lbl_date_5 = new QLabel(page);
        lbl_date_5->setObjectName(QString::fromUtf8("lbl_date_5"));
        lbl_date_5->setGeometry(QRect(310, 400, 51, 31));
        lbl_date_5->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;\n"
"text-align: right;"));
        lbl_date_6 = new QLabel(page);
        lbl_date_6->setObjectName(QString::fromUtf8("lbl_date_6"));
        lbl_date_6->setGeometry(QRect(310, 480, 51, 31));
        lbl_date_6->setStyleSheet(QString::fromUtf8("font-family: arial;\n"
"font-size: 14px;\n"
"color: black;\n"
"text-align: right;"));
        lbl_new_1 = new QLabel(page);
        lbl_new_1->setObjectName(QString::fromUtf8("lbl_new_1"));
        lbl_new_1->setGeometry(QRect(300, 100, 61, 31));
        lbl_new_1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/newMarker.png);"));
        lbl_new_2 = new QLabel(page);
        lbl_new_2->setObjectName(QString::fromUtf8("lbl_new_2"));
        lbl_new_2->setGeometry(QRect(300, 180, 61, 31));
        lbl_new_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/newMarker.png);"));
        lbl_new_3 = new QLabel(page);
        lbl_new_3->setObjectName(QString::fromUtf8("lbl_new_3"));
        lbl_new_3->setGeometry(QRect(300, 260, 61, 31));
        lbl_new_3->setStyleSheet(QString::fromUtf8("background-image:url(:/images/newMarker.png);"));
        lbl_new_4 = new QLabel(page);
        lbl_new_4->setObjectName(QString::fromUtf8("lbl_new_4"));
        lbl_new_4->setGeometry(QRect(300, 340, 61, 31));
        lbl_new_4->setStyleSheet(QString::fromUtf8("background-image:url(:/images/newMarker.png);"));
        lbl_new_5 = new QLabel(page);
        lbl_new_5->setObjectName(QString::fromUtf8("lbl_new_5"));
        lbl_new_5->setGeometry(QRect(300, 430, 61, 31));
        lbl_new_5->setStyleSheet(QString::fromUtf8("background-image:url(:/images/newMarker.png);"));
        lbl_new_6 = new QLabel(page);
        lbl_new_6->setObjectName(QString::fromUtf8("lbl_new_6"));
        lbl_new_6->setGeometry(QRect(300, 510, 61, 31));
        lbl_new_6->setStyleSheet(QString::fromUtf8("background-image:url(:/images/newMarker.png);"));
        stackedWidget->addWidget(page);
        lbl_stripedBackground->raise();
        btn_view_6->raise();
        btn_view_2->raise();
        btn_view_1->raise();
        btn_view_5->raise();
        btn_view_3->raise();
        btn_view_4->raise();
        lbl_report_2->raise();
        btn_pageLeft->raise();
        lbl_report_1->raise();
        btn_pageRight->raise();
        lbl_report_4->raise();
        lbl_report_5->raise();
        lbl_currentPage->raise();
        lbl_report_3->raise();
        lbl_topBar->raise();
        btn_backToAdminHome->raise();
        lbl_report_6->raise();
        lbl_QRRequests->raise();
        lbl_name_1->raise();
        lbl_name_2->raise();
        lbl_name_3->raise();
        lbl_name_4->raise();
        lbl_name_5->raise();
        lbl_name_6->raise();
        lbl_date_1->raise();
        lbl_date_2->raise();
        lbl_date_3->raise();
        lbl_date_4->raise();
        lbl_date_5->raise();
        lbl_date_6->raise();
        lbl_new_1->raise();
        lbl_new_2->raise();
        lbl_new_3->raise();
        lbl_new_4->raise();
        lbl_new_5->raise();
        lbl_new_6->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(AdminErrorReports);

        QMetaObject::connectSlotsByName(AdminErrorReports);
    } // setupUi

    void retranslateUi(QWidget *AdminErrorReports)
    {
        AdminErrorReports->setWindowTitle(QCoreApplication::translate("AdminErrorReports", "Form", nullptr));
        lbl_stripedBackground->setText(QString());
        btn_pageLeft->setText(QString());
        lbl_report_1->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        btn_pageRight->setText(QString());
        lbl_report_4->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        btn_view_4->setText(QString());
        lbl_report_5->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_currentPage->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        btn_view_2->setText(QString());
        lbl_report_2->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_report_3->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        btn_view_5->setText(QString());
        lbl_topBar->setText(QString());
        btn_backToAdminHome->setText(QString());
        lbl_report_6->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        btn_view_6->setText(QString());
        lbl_QRRequests->setText(QCoreApplication::translate("AdminErrorReports", "    Reported Issues", nullptr));
        btn_view_3->setText(QString());
        btn_view_1->setText(QString());
        lbl_name_1->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_name_2->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_name_3->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_name_4->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_name_5->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_name_6->setText(QCoreApplication::translate("AdminErrorReports", "TextLabel", nullptr));
        lbl_date_1->setText(QCoreApplication::translate("AdminErrorReports", "24/06", nullptr));
        lbl_date_2->setText(QCoreApplication::translate("AdminErrorReports", "24/06", nullptr));
        lbl_date_3->setText(QCoreApplication::translate("AdminErrorReports", "24/06", nullptr));
        lbl_date_4->setText(QCoreApplication::translate("AdminErrorReports", "24/06", nullptr));
        lbl_date_5->setText(QCoreApplication::translate("AdminErrorReports", "24/06", nullptr));
        lbl_date_6->setText(QCoreApplication::translate("AdminErrorReports", "24/06", nullptr));
        lbl_new_1->setText(QString());
        lbl_new_2->setText(QString());
        lbl_new_3->setText(QString());
        lbl_new_4->setText(QString());
        lbl_new_5->setText(QString());
        lbl_new_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdminErrorReports: public Ui_AdminErrorReports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINERRORREPORTS_H
