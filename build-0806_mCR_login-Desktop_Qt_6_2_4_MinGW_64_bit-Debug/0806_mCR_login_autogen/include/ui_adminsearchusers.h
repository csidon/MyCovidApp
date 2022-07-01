/********************************************************************************
** Form generated from reading UI file 'adminsearchusers.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSEARCHUSERS_H
#define UI_ADMINSEARCHUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminSearchUsers
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_stripedBackground;
    QPushButton *btn_pageLeft;
    QLabel *lbl_topBar;
    QPushButton *btn_pageRight;
    QPushButton *btn_backToAdminHome;
    QLabel *lbl_currentPage;
    QTextEdit *textEdit_searchBar;
    QPushButton *btn_search;
    QLabel *lbl_foundName_1;
    QLabel *lbl_foundName_2;
    QLabel *lbl_foundName_3;
    QLabel *lbl_foundName_4;
    QLabel *lbl_foundName_5;
    QLabel *lbl_foundName_6;
    QWidget *page_2;

    void setupUi(QWidget *AdminSearchUsers)
    {
        if (AdminSearchUsers->objectName().isEmpty())
            AdminSearchUsers->setObjectName(QString::fromUtf8("AdminSearchUsers"));
        AdminSearchUsers->resize(375, 667);
        stackedWidget = new QStackedWidget(AdminSearchUsers);
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
        lbl_topBar = new QLabel(page);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_pageRight = new QPushButton(page);
        btn_pageRight->setObjectName(QString::fromUtf8("btn_pageRight"));
        btn_pageRight->setGeometry(QRect(300, 580, 41, 41));
        btn_pageRight->setStyleSheet(QString::fromUtf8("image: url(:/images/pageRight.png);"));
        btn_backToAdminHome = new QPushButton(page);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_currentPage = new QLabel(page);
        lbl_currentPage->setObjectName(QString::fromUtf8("lbl_currentPage"));
        lbl_currentPage->setGeometry(QRect(90, 590, 121, 20));
        lbl_currentPage->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:arial;\n"
"font-size:18px;"));
        textEdit_searchBar = new QTextEdit(page);
        textEdit_searchBar->setObjectName(QString::fromUtf8("textEdit_searchBar"));
        textEdit_searchBar->setGeometry(QRect(80, 10, 221, 41));
        textEdit_searchBar->setStyleSheet(QString::fromUtf8("font-size:18px;"));
        btn_search = new QPushButton(page);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setGeometry(QRect(310, 0, 61, 61));
        btn_search->setStyleSheet(QString::fromUtf8("image:url(:/images/searchIcon.png);\n"
"background-color:rgba(255, 255, 255, 0);"));
        lbl_foundName_1 = new QLabel(page);
        lbl_foundName_1->setObjectName(QString::fromUtf8("lbl_foundName_1"));
        lbl_foundName_1->setGeometry(QRect(10, 70, 351, 61));
        lbl_foundName_1->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_foundName_2 = new QLabel(page);
        lbl_foundName_2->setObjectName(QString::fromUtf8("lbl_foundName_2"));
        lbl_foundName_2->setGeometry(QRect(10, 160, 351, 61));
        lbl_foundName_2->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_foundName_3 = new QLabel(page);
        lbl_foundName_3->setObjectName(QString::fromUtf8("lbl_foundName_3"));
        lbl_foundName_3->setGeometry(QRect(10, 240, 351, 61));
        lbl_foundName_3->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_foundName_4 = new QLabel(page);
        lbl_foundName_4->setObjectName(QString::fromUtf8("lbl_foundName_4"));
        lbl_foundName_4->setGeometry(QRect(10, 320, 351, 61));
        lbl_foundName_4->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_foundName_5 = new QLabel(page);
        lbl_foundName_5->setObjectName(QString::fromUtf8("lbl_foundName_5"));
        lbl_foundName_5->setGeometry(QRect(10, 400, 351, 61));
        lbl_foundName_5->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_foundName_6 = new QLabel(page);
        lbl_foundName_6->setObjectName(QString::fromUtf8("lbl_foundName_6"));
        lbl_foundName_6->setGeometry(QRect(10, 490, 351, 61));
        lbl_foundName_6->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        stackedWidget->addWidget(page);
        lbl_stripedBackground->raise();
        btn_pageLeft->raise();
        lbl_topBar->raise();
        btn_pageRight->raise();
        lbl_currentPage->raise();
        btn_backToAdminHome->raise();
        textEdit_searchBar->raise();
        btn_search->raise();
        lbl_foundName_1->raise();
        lbl_foundName_2->raise();
        lbl_foundName_3->raise();
        lbl_foundName_4->raise();
        lbl_foundName_5->raise();
        lbl_foundName_6->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(AdminSearchUsers);

        QMetaObject::connectSlotsByName(AdminSearchUsers);
    } // setupUi

    void retranslateUi(QWidget *AdminSearchUsers)
    {
        AdminSearchUsers->setWindowTitle(QCoreApplication::translate("AdminSearchUsers", "Form", nullptr));
        lbl_stripedBackground->setText(QString());
        btn_pageLeft->setText(QString());
        lbl_topBar->setText(QString());
        btn_pageRight->setText(QString());
        btn_backToAdminHome->setText(QString());
        lbl_currentPage->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
        textEdit_searchBar->setPlaceholderText(QCoreApplication::translate("AdminSearchUsers", "Enter first or last name...", nullptr));
        btn_search->setText(QString());
        lbl_foundName_1->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
        lbl_foundName_2->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
        lbl_foundName_3->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
        lbl_foundName_4->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
        lbl_foundName_5->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
        lbl_foundName_6->setText(QCoreApplication::translate("AdminSearchUsers", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSearchUsers: public Ui_AdminSearchUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSEARCHUSERS_H
