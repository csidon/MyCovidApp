/********************************************************************************
** Form generated from reading UI file 'adminuserselected.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUSERSELECTED_H
#define UI_ADMINUSERSELECTED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminUserSelected
{
public:
    QLabel *lbl_topBar;
    QPushButton *btn_accountDetailsView;
    QLabel *lbl_usersName;
    QPushButton *btn_backToSearch;
    QPushButton *btn_testAdd;
    QPushButton *btn_vaxAdd;
    QPushButton *btn_accountDetailsEdit;

    void setupUi(QWidget *AdminUserSelected)
    {
        if (AdminUserSelected->objectName().isEmpty())
            AdminUserSelected->setObjectName(QString::fromUtf8("AdminUserSelected"));
        AdminUserSelected->resize(375, 667);
        lbl_topBar = new QLabel(AdminUserSelected);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_accountDetailsView = new QPushButton(AdminUserSelected);
        btn_accountDetailsView->setObjectName(QString::fromUtf8("btn_accountDetailsView"));
        btn_accountDetailsView->setGeometry(QRect(50, 130, 281, 61));
        lbl_usersName = new QLabel(AdminUserSelected);
        lbl_usersName->setObjectName(QString::fromUtf8("lbl_usersName"));
        lbl_usersName->setGeometry(QRect(70, 0, 241, 61));
        lbl_usersName->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:20px;\n"
"font-family:arial;"));
        btn_backToSearch = new QPushButton(AdminUserSelected);
        btn_backToSearch->setObjectName(QString::fromUtf8("btn_backToSearch"));
        btn_backToSearch->setGeometry(QRect(0, 0, 71, 61));
        btn_backToSearch->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_testAdd = new QPushButton(AdminUserSelected);
        btn_testAdd->setObjectName(QString::fromUtf8("btn_testAdd"));
        btn_testAdd->setGeometry(QRect(50, 400, 281, 61));
        btn_vaxAdd = new QPushButton(AdminUserSelected);
        btn_vaxAdd->setObjectName(QString::fromUtf8("btn_vaxAdd"));
        btn_vaxAdd->setGeometry(QRect(50, 310, 281, 61));
        btn_accountDetailsEdit = new QPushButton(AdminUserSelected);
        btn_accountDetailsEdit->setObjectName(QString::fromUtf8("btn_accountDetailsEdit"));
        btn_accountDetailsEdit->setGeometry(QRect(50, 220, 281, 61));
        lbl_topBar->raise();
        btn_accountDetailsView->raise();
        lbl_usersName->raise();
        btn_testAdd->raise();
        btn_vaxAdd->raise();
        btn_accountDetailsEdit->raise();
        btn_backToSearch->raise();

        retranslateUi(AdminUserSelected);

        QMetaObject::connectSlotsByName(AdminUserSelected);
    } // setupUi

    void retranslateUi(QWidget *AdminUserSelected)
    {
        AdminUserSelected->setWindowTitle(QCoreApplication::translate("AdminUserSelected", "Form", nullptr));
        lbl_topBar->setText(QString());
        btn_accountDetailsView->setText(QCoreApplication::translate("AdminUserSelected", "View Account, Tests, and Vaccinations", nullptr));
        lbl_usersName->setText(QCoreApplication::translate("AdminUserSelected", "    Choose an Option", nullptr));
        btn_backToSearch->setText(QString());
        btn_testAdd->setText(QCoreApplication::translate("AdminUserSelected", "Add a COVID-19 Test", nullptr));
        btn_vaxAdd->setText(QCoreApplication::translate("AdminUserSelected", "Add a Vaccination", nullptr));
        btn_accountDetailsEdit->setText(QCoreApplication::translate("AdminUserSelected", "Edit Account Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminUserSelected: public Ui_AdminUserSelected {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUSERSELECTED_H
