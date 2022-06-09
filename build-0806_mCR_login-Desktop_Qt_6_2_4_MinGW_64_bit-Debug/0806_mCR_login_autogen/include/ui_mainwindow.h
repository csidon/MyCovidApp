/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_menu;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *btn_requestQR;
    QPushButton *btn_reportRat;
    QPushButton *btn_accountDetails;
    QPushButton *btn_vaxHistory;
    QLabel *lbl_welcomeMsg;
    QLabel *lbl_reminderMsgLn1;
    QLabel *lbl_reminderMsgLn1_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(375, 667);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_menu = new QPushButton(centralwidget);
        btn_menu->setObjectName(QString::fromUtf8("btn_menu"));
        btn_menu->setGeometry(QRect(7, 6, 61, 51));
        btn_menu->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/menu_normal.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 375, 63));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/appBanner.png);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 190, 351, 431));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        btn_requestQR = new QPushButton(groupBox);
        btn_requestQR->setObjectName(QString::fromUtf8("btn_requestQR"));
        btn_requestQR->setGeometry(QRect(180, 10, 149, 189));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_requestQR->sizePolicy().hasHeightForWidth());
        btn_requestQR->setSizePolicy(sizePolicy);
        btn_requestQR->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/requestQR.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_reportRat = new QPushButton(groupBox);
        btn_reportRat->setObjectName(QString::fromUtf8("btn_reportRat"));
        btn_reportRat->setGeometry(QRect(20, 10, 149, 189));
        sizePolicy.setHeightForWidth(btn_reportRat->sizePolicy().hasHeightForWidth());
        btn_reportRat->setSizePolicy(sizePolicy);
        btn_reportRat->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/reportRat-02.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_accountDetails = new QPushButton(groupBox);
        btn_accountDetails->setObjectName(QString::fromUtf8("btn_accountDetails"));
        btn_accountDetails->setGeometry(QRect(180, 210, 149, 189));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_accountDetails->sizePolicy().hasHeightForWidth());
        btn_accountDetails->setSizePolicy(sizePolicy1);
        btn_accountDetails->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/accountDeetsBtn.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_vaxHistory = new QPushButton(groupBox);
        btn_vaxHistory->setObjectName(QString::fromUtf8("btn_vaxHistory"));
        btn_vaxHistory->setGeometry(QRect(20, 210, 149, 189));
        sizePolicy1.setHeightForWidth(btn_vaxHistory->sizePolicy().hasHeightForWidth());
        btn_vaxHistory->setSizePolicy(sizePolicy1);
        btn_vaxHistory->setStyleSheet(QString::fromUtf8("image: url(:/images/hompageIcons/vaxHistoryBtn.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_welcomeMsg = new QLabel(centralwidget);
        lbl_welcomeMsg->setObjectName(QString::fromUtf8("lbl_welcomeMsg"));
        lbl_welcomeMsg->setGeometry(QRect(35, 80, 281, 41));
        lbl_welcomeMsg->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        lbl_reminderMsgLn1 = new QLabel(centralwidget);
        lbl_reminderMsgLn1->setObjectName(QString::fromUtf8("lbl_reminderMsgLn1"));
        lbl_reminderMsgLn1->setGeometry(QRect(35, 130, 311, 21));
        lbl_reminderMsgLn1->setStyleSheet(QString::fromUtf8("font: 16pt \"Arial\";\n"
"font: 8pt \"Arial\";"));
        lbl_reminderMsgLn1_2 = new QLabel(centralwidget);
        lbl_reminderMsgLn1_2->setObjectName(QString::fromUtf8("lbl_reminderMsgLn1_2"));
        lbl_reminderMsgLn1_2->setGeometry(QRect(35, 160, 311, 21));
        lbl_reminderMsgLn1_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Arial\";\n"
"font: 8pt \"Arial\";"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        btn_menu->raise();
        groupBox->raise();
        lbl_welcomeMsg->raise();
        lbl_reminderMsgLn1->raise();
        lbl_reminderMsgLn1_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 375, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_menu->setText(QString());
        label->setText(QString());
        groupBox->setTitle(QString());
        btn_requestQR->setText(QString());
        btn_reportRat->setText(QString());
        btn_accountDetails->setText(QString());
        btn_vaxHistory->setText(QString());
        lbl_welcomeMsg->setText(QCoreApplication::translate("MainWindow", "Kia Ora Darth Vader", nullptr));
        lbl_reminderMsgLn1->setText(QCoreApplication::translate("MainWindow", "Reminder - You have a booster shot coming up.  ", nullptr));
        lbl_reminderMsgLn1_2->setText(QCoreApplication::translate("MainWindow", "Please book in by 4 June. May the 4th be with you.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
