/********************************************************************************
** Form generated from reading UI file 'vaccinehistory.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACCINEHISTORY_H
#define UI_VACCINEHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VaccineHistory
{
public:
    QLabel *lbl_topBar;
    QLabel *lbl_headingManufacturer;
    QPushButton *btn_backToChoose;
    QLabel *lbl_background;
    QPushButton *btn_pageRight;
    QLabel *lbl_currentPage;
    QPushButton *btn_pageLeft;
    QLabel *lbl_type_1;
    QLabel *lbl_date_1;
    QLabel *lbl_type_2;
    QLabel *lbl_date_2;
    QLabel *lbl_type_3;
    QLabel *lbl_date_3;
    QLabel *lbl_type_4;
    QLabel *lbl_date_4;
    QLabel *lbl_type_5;
    QLabel *lbl_date_5;
    QLabel *lbl_type_6;
    QLabel *lbl_date_6;
    QLabel *lbl_headingDate;

    void setupUi(QWidget *VaccineHistory)
    {
        if (VaccineHistory->objectName().isEmpty())
            VaccineHistory->setObjectName(QString::fromUtf8("VaccineHistory"));
        VaccineHistory->resize(375, 667);
        lbl_topBar = new QLabel(VaccineHistory);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        lbl_headingManufacturer = new QLabel(VaccineHistory);
        lbl_headingManufacturer->setObjectName(QString::fromUtf8("lbl_headingManufacturer"));
        lbl_headingManufacturer->setGeometry(QRect(70, 0, 211, 61));
        lbl_headingManufacturer->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        btn_backToChoose = new QPushButton(VaccineHistory);
        btn_backToChoose->setObjectName(QString::fromUtf8("btn_backToChoose"));
        btn_backToChoose->setGeometry(QRect(0, 0, 71, 61));
        btn_backToChoose->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_background = new QLabel(VaccineHistory);
        lbl_background->setObjectName(QString::fromUtf8("lbl_background"));
        lbl_background->setGeometry(QRect(0, 60, 381, 621));
        lbl_background->setStyleSheet(QString::fromUtf8("background-image:url(:/images/stripedBackground.png);"));
        btn_pageRight = new QPushButton(VaccineHistory);
        btn_pageRight->setObjectName(QString::fromUtf8("btn_pageRight"));
        btn_pageRight->setGeometry(QRect(300, 600, 41, 41));
        btn_pageRight->setStyleSheet(QString::fromUtf8("image: url(:/images/pageRight.png);"));
        lbl_currentPage = new QLabel(VaccineHistory);
        lbl_currentPage->setObjectName(QString::fromUtf8("lbl_currentPage"));
        lbl_currentPage->setGeometry(QRect(90, 610, 121, 20));
        lbl_currentPage->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:arial;\n"
"font-size:18px;"));
        btn_pageLeft = new QPushButton(VaccineHistory);
        btn_pageLeft->setObjectName(QString::fromUtf8("btn_pageLeft"));
        btn_pageLeft->setGeometry(QRect(240, 600, 41, 41));
        btn_pageLeft->setStyleSheet(QString::fromUtf8("image:url(:/images/pageLeft.png);"));
        lbl_type_1 = new QLabel(VaccineHistory);
        lbl_type_1->setObjectName(QString::fromUtf8("lbl_type_1"));
        lbl_type_1->setGeometry(QRect(80, 80, 161, 41));
        lbl_type_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_type_1->setWordWrap(false);
        lbl_date_1 = new QLabel(VaccineHistory);
        lbl_date_1->setObjectName(QString::fromUtf8("lbl_date_1"));
        lbl_date_1->setGeometry(QRect(280, 80, 91, 41));
        lbl_date_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_1->setWordWrap(false);
        lbl_type_2 = new QLabel(VaccineHistory);
        lbl_type_2->setObjectName(QString::fromUtf8("lbl_type_2"));
        lbl_type_2->setGeometry(QRect(80, 170, 161, 41));
        lbl_type_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_type_2->setWordWrap(false);
        lbl_date_2 = new QLabel(VaccineHistory);
        lbl_date_2->setObjectName(QString::fromUtf8("lbl_date_2"));
        lbl_date_2->setGeometry(QRect(280, 170, 91, 41));
        lbl_date_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_2->setWordWrap(false);
        lbl_type_3 = new QLabel(VaccineHistory);
        lbl_type_3->setObjectName(QString::fromUtf8("lbl_type_3"));
        lbl_type_3->setGeometry(QRect(80, 250, 161, 41));
        lbl_type_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_type_3->setWordWrap(false);
        lbl_date_3 = new QLabel(VaccineHistory);
        lbl_date_3->setObjectName(QString::fromUtf8("lbl_date_3"));
        lbl_date_3->setGeometry(QRect(280, 250, 91, 41));
        lbl_date_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_3->setWordWrap(false);
        lbl_type_4 = new QLabel(VaccineHistory);
        lbl_type_4->setObjectName(QString::fromUtf8("lbl_type_4"));
        lbl_type_4->setGeometry(QRect(80, 330, 161, 41));
        lbl_type_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_type_4->setWordWrap(false);
        lbl_date_4 = new QLabel(VaccineHistory);
        lbl_date_4->setObjectName(QString::fromUtf8("lbl_date_4"));
        lbl_date_4->setGeometry(QRect(280, 330, 91, 41));
        lbl_date_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_4->setWordWrap(false);
        lbl_type_5 = new QLabel(VaccineHistory);
        lbl_type_5->setObjectName(QString::fromUtf8("lbl_type_5"));
        lbl_type_5->setGeometry(QRect(80, 410, 161, 41));
        lbl_type_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_type_5->setWordWrap(false);
        lbl_date_5 = new QLabel(VaccineHistory);
        lbl_date_5->setObjectName(QString::fromUtf8("lbl_date_5"));
        lbl_date_5->setGeometry(QRect(280, 410, 91, 41));
        lbl_date_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_5->setWordWrap(false);
        lbl_type_6 = new QLabel(VaccineHistory);
        lbl_type_6->setObjectName(QString::fromUtf8("lbl_type_6"));
        lbl_type_6->setGeometry(QRect(80, 500, 161, 41));
        lbl_type_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_type_6->setWordWrap(false);
        lbl_date_6 = new QLabel(VaccineHistory);
        lbl_date_6->setObjectName(QString::fromUtf8("lbl_date_6"));
        lbl_date_6->setGeometry(QRect(280, 500, 91, 41));
        lbl_date_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_date_6->setWordWrap(false);
        lbl_headingDate = new QLabel(VaccineHistory);
        lbl_headingDate->setObjectName(QString::fromUtf8("lbl_headingDate"));
        lbl_headingDate->setGeometry(QRect(290, 0, 61, 61));
        lbl_headingDate->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        lbl_background->raise();
        lbl_topBar->raise();
        lbl_headingManufacturer->raise();
        btn_backToChoose->raise();
        btn_pageRight->raise();
        lbl_currentPage->raise();
        btn_pageLeft->raise();
        lbl_type_1->raise();
        lbl_date_1->raise();
        lbl_type_2->raise();
        lbl_date_2->raise();
        lbl_type_3->raise();
        lbl_date_3->raise();
        lbl_type_4->raise();
        lbl_date_4->raise();
        lbl_type_5->raise();
        lbl_date_5->raise();
        lbl_type_6->raise();
        lbl_date_6->raise();
        lbl_headingDate->raise();

        retranslateUi(VaccineHistory);

        QMetaObject::connectSlotsByName(VaccineHistory);
    } // setupUi

    void retranslateUi(QWidget *VaccineHistory)
    {
        VaccineHistory->setWindowTitle(QCoreApplication::translate("VaccineHistory", "Form", nullptr));
        lbl_topBar->setText(QString());
        lbl_headingManufacturer->setText(QCoreApplication::translate("VaccineHistory", " Manufacurer", nullptr));
        btn_backToChoose->setText(QString());
        lbl_background->setText(QString());
        btn_pageRight->setText(QString());
        lbl_currentPage->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        btn_pageLeft->setText(QString());
        lbl_type_1->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_date_1->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_type_2->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_date_2->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_type_3->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_date_3->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_type_4->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_date_4->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_type_5->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_date_5->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_type_6->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_date_6->setText(QCoreApplication::translate("VaccineHistory", "TextLabel", nullptr));
        lbl_headingDate->setText(QCoreApplication::translate("VaccineHistory", "Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VaccineHistory: public Ui_VaccineHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACCINEHISTORY_H
