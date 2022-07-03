/********************************************************************************
** Form generated from reading UI file 'testhistory.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTHISTORY_H
#define UI_TESTHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestHistory
{
public:
    QPushButton *btn_backToChoose;
    QLabel *lbl_currentPage;
    QLabel *lbl_background;
    QLabel *lbl_result_5;
    QPushButton *btn_pageLeft;
    QLabel *lbl_result_1;
    QLabel *lbl_date_6;
    QLabel *lbl_headingDate;
    QLabel *lbl_date_4;
    QLabel *lbl_headingResult;
    QLabel *lbl_result_4;
    QLabel *lbl_result_2;
    QLabel *lbl_topBar;
    QPushButton *btn_pageRight;
    QLabel *lbl_result_3;
    QLabel *lbl_date_2;
    QLabel *lbl_date_3;
    QLabel *lbl_date_5;
    QLabel *lbl_result_6;
    QLabel *lbl_date_1;

    void setupUi(QWidget *TestHistory)
    {
        if (TestHistory->objectName().isEmpty())
            TestHistory->setObjectName(QString::fromUtf8("TestHistory"));
        TestHistory->resize(375, 667);
        btn_backToChoose = new QPushButton(TestHistory);
        btn_backToChoose->setObjectName(QString::fromUtf8("btn_backToChoose"));
        btn_backToChoose->setGeometry(QRect(-10, 0, 71, 61));
        btn_backToChoose->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_currentPage = new QLabel(TestHistory);
        lbl_currentPage->setObjectName(QString::fromUtf8("lbl_currentPage"));
        lbl_currentPage->setGeometry(QRect(80, 600, 121, 20));
        lbl_currentPage->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:arial;\n"
"font-size:18px;"));
        lbl_background = new QLabel(TestHistory);
        lbl_background->setObjectName(QString::fromUtf8("lbl_background"));
        lbl_background->setGeometry(QRect(-10, 50, 381, 621));
        lbl_background->setStyleSheet(QString::fromUtf8("background-image:url(:/images/stripedBackground.png);"));
        lbl_result_5 = new QLabel(TestHistory);
        lbl_result_5->setObjectName(QString::fromUtf8("lbl_result_5"));
        lbl_result_5->setGeometry(QRect(70, 400, 161, 41));
        lbl_result_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_result_5->setWordWrap(false);
        btn_pageLeft = new QPushButton(TestHistory);
        btn_pageLeft->setObjectName(QString::fromUtf8("btn_pageLeft"));
        btn_pageLeft->setGeometry(QRect(230, 590, 41, 41));
        btn_pageLeft->setStyleSheet(QString::fromUtf8("image:url(:/images/pageLeft.png);"));
        lbl_result_1 = new QLabel(TestHistory);
        lbl_result_1->setObjectName(QString::fromUtf8("lbl_result_1"));
        lbl_result_1->setGeometry(QRect(70, 70, 161, 41));
        lbl_result_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_result_1->setWordWrap(false);
        lbl_date_6 = new QLabel(TestHistory);
        lbl_date_6->setObjectName(QString::fromUtf8("lbl_date_6"));
        lbl_date_6->setGeometry(QRect(270, 490, 91, 41));
        lbl_date_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_6->setWordWrap(false);
        lbl_headingDate = new QLabel(TestHistory);
        lbl_headingDate->setObjectName(QString::fromUtf8("lbl_headingDate"));
        lbl_headingDate->setGeometry(QRect(280, 0, 61, 61));
        lbl_headingDate->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        lbl_date_4 = new QLabel(TestHistory);
        lbl_date_4->setObjectName(QString::fromUtf8("lbl_date_4"));
        lbl_date_4->setGeometry(QRect(270, 320, 91, 41));
        lbl_date_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_4->setWordWrap(false);
        lbl_headingResult = new QLabel(TestHistory);
        lbl_headingResult->setObjectName(QString::fromUtf8("lbl_headingResult"));
        lbl_headingResult->setGeometry(QRect(60, 0, 211, 61));
        lbl_headingResult->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        lbl_result_4 = new QLabel(TestHistory);
        lbl_result_4->setObjectName(QString::fromUtf8("lbl_result_4"));
        lbl_result_4->setGeometry(QRect(70, 320, 161, 41));
        lbl_result_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_result_4->setWordWrap(false);
        lbl_result_2 = new QLabel(TestHistory);
        lbl_result_2->setObjectName(QString::fromUtf8("lbl_result_2"));
        lbl_result_2->setGeometry(QRect(70, 160, 161, 41));
        lbl_result_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_result_2->setWordWrap(false);
        lbl_topBar = new QLabel(TestHistory);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(0, -20, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_pageRight = new QPushButton(TestHistory);
        btn_pageRight->setObjectName(QString::fromUtf8("btn_pageRight"));
        btn_pageRight->setGeometry(QRect(290, 590, 41, 41));
        btn_pageRight->setStyleSheet(QString::fromUtf8("image: url(:/images/pageRight.png);"));
        lbl_result_3 = new QLabel(TestHistory);
        lbl_result_3->setObjectName(QString::fromUtf8("lbl_result_3"));
        lbl_result_3->setGeometry(QRect(70, 240, 161, 41));
        lbl_result_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_result_3->setWordWrap(false);
        lbl_date_2 = new QLabel(TestHistory);
        lbl_date_2->setObjectName(QString::fromUtf8("lbl_date_2"));
        lbl_date_2->setGeometry(QRect(270, 160, 91, 41));
        lbl_date_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_2->setWordWrap(false);
        lbl_date_3 = new QLabel(TestHistory);
        lbl_date_3->setObjectName(QString::fromUtf8("lbl_date_3"));
        lbl_date_3->setGeometry(QRect(270, 240, 91, 41));
        lbl_date_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_3->setWordWrap(false);
        lbl_date_5 = new QLabel(TestHistory);
        lbl_date_5->setObjectName(QString::fromUtf8("lbl_date_5"));
        lbl_date_5->setGeometry(QRect(270, 400, 91, 41));
        lbl_date_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_5->setWordWrap(false);
        lbl_result_6 = new QLabel(TestHistory);
        lbl_result_6->setObjectName(QString::fromUtf8("lbl_result_6"));
        lbl_result_6->setGeometry(QRect(70, 490, 161, 41));
        lbl_result_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_result_6->setWordWrap(false);
        lbl_date_1 = new QLabel(TestHistory);
        lbl_date_1->setObjectName(QString::fromUtf8("lbl_date_1"));
        lbl_date_1->setGeometry(QRect(270, 70, 91, 41));
        lbl_date_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_1->setWordWrap(false);
        lbl_topBar->raise();
        lbl_background->raise();
        lbl_currentPage->raise();
        lbl_result_5->raise();
        btn_pageLeft->raise();
        lbl_result_1->raise();
        lbl_date_6->raise();
        lbl_date_4->raise();
        lbl_result_4->raise();
        lbl_result_2->raise();
        btn_pageRight->raise();
        lbl_result_3->raise();
        lbl_date_2->raise();
        lbl_date_3->raise();
        lbl_date_5->raise();
        lbl_result_6->raise();
        lbl_date_1->raise();
        btn_backToChoose->raise();
        lbl_headingResult->raise();
        lbl_headingDate->raise();

        retranslateUi(TestHistory);

        QMetaObject::connectSlotsByName(TestHistory);
    } // setupUi

    void retranslateUi(QWidget *TestHistory)
    {
        TestHistory->setWindowTitle(QCoreApplication::translate("TestHistory", "Form", nullptr));
        btn_backToChoose->setText(QString());
        lbl_currentPage->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_background->setText(QString());
        lbl_result_5->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        btn_pageLeft->setText(QString());
        lbl_result_1->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_date_6->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_headingDate->setText(QCoreApplication::translate("TestHistory", "Date", nullptr));
        lbl_date_4->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_headingResult->setText(QCoreApplication::translate("TestHistory", " Test Result", nullptr));
        lbl_result_4->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_result_2->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_topBar->setText(QString());
        btn_pageRight->setText(QString());
        lbl_result_3->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_date_2->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_date_3->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_date_5->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_result_6->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
        lbl_date_1->setText(QCoreApplication::translate("TestHistory", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestHistory: public Ui_TestHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTHISTORY_H
