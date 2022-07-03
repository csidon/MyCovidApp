/********************************************************************************
** Form generated from reading UI file 'editdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDETAILS_H
#define UI_EDITDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editDetails
{
public:
    QPushButton *btn_backToHome;
    QLabel *lbl_fName;
    QLabel *lbl_phone;
    QLabel *lbl_pName;
    QLabel *lbl_topBar;
    QLabel *lbl_Email;
    QLabel *lbl_NHI;
    QLabel *lbl_lName;
    QLabel *lbl_editDetails;
    QLineEdit *lineEdit_firstName;
    QLineEdit *lineEdit_lastName;
    QLineEdit *lineEdit_preferredName;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_NHI;
    QPushButton *btn_submit;

    void setupUi(QWidget *editDetails)
    {
        if (editDetails->objectName().isEmpty())
            editDetails->setObjectName(QString::fromUtf8("editDetails"));
        editDetails->resize(375, 667);
        btn_backToHome = new QPushButton(editDetails);
        btn_backToHome->setObjectName(QString::fromUtf8("btn_backToHome"));
        btn_backToHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_fName = new QLabel(editDetails);
        lbl_fName->setObjectName(QString::fromUtf8("lbl_fName"));
        lbl_fName->setGeometry(QRect(50, 70, 101, 41));
        lbl_fName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_phone = new QLabel(editDetails);
        lbl_phone->setObjectName(QString::fromUtf8("lbl_phone"));
        lbl_phone->setGeometry(QRect(50, 390, 161, 41));
        lbl_phone->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_pName = new QLabel(editDetails);
        lbl_pName->setObjectName(QString::fromUtf8("lbl_pName"));
        lbl_pName->setGeometry(QRect(50, 230, 161, 41));
        lbl_pName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_topBar = new QLabel(editDetails);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(0, -20, 381, 101));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        lbl_Email = new QLabel(editDetails);
        lbl_Email->setObjectName(QString::fromUtf8("lbl_Email"));
        lbl_Email->setGeometry(QRect(50, 310, 161, 41));
        lbl_Email->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_NHI = new QLabel(editDetails);
        lbl_NHI->setObjectName(QString::fromUtf8("lbl_NHI"));
        lbl_NHI->setGeometry(QRect(50, 470, 161, 41));
        lbl_NHI->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_lName = new QLabel(editDetails);
        lbl_lName->setObjectName(QString::fromUtf8("lbl_lName"));
        lbl_lName->setGeometry(QRect(50, 150, 101, 41));
        lbl_lName->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:#444444;"));
        lbl_editDetails = new QLabel(editDetails);
        lbl_editDetails->setObjectName(QString::fromUtf8("lbl_editDetails"));
        lbl_editDetails->setGeometry(QRect(80, 0, 221, 61));
        lbl_editDetails->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:20px;\n"
"font-family:arial;"));
        lineEdit_firstName = new QLineEdit(editDetails);
        lineEdit_firstName->setObjectName(QString::fromUtf8("lineEdit_firstName"));
        lineEdit_firstName->setGeometry(QRect(50, 110, 281, 31));
        lineEdit_lastName = new QLineEdit(editDetails);
        lineEdit_lastName->setObjectName(QString::fromUtf8("lineEdit_lastName"));
        lineEdit_lastName->setGeometry(QRect(50, 190, 281, 31));
        lineEdit_preferredName = new QLineEdit(editDetails);
        lineEdit_preferredName->setObjectName(QString::fromUtf8("lineEdit_preferredName"));
        lineEdit_preferredName->setGeometry(QRect(50, 270, 281, 31));
        lineEdit_email = new QLineEdit(editDetails);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(50, 350, 281, 31));
        lineEdit_phone = new QLineEdit(editDetails);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(50, 430, 281, 31));
        lineEdit_NHI = new QLineEdit(editDetails);
        lineEdit_NHI->setObjectName(QString::fromUtf8("lineEdit_NHI"));
        lineEdit_NHI->setGeometry(QRect(50, 510, 281, 31));
        btn_submit = new QPushButton(editDetails);
        btn_submit->setObjectName(QString::fromUtf8("btn_submit"));
        btn_submit->setGeometry(QRect(90, 580, 171, 41));
        lbl_topBar->raise();
        btn_backToHome->raise();
        lbl_fName->raise();
        lbl_phone->raise();
        lbl_pName->raise();
        lbl_Email->raise();
        lbl_NHI->raise();
        lbl_lName->raise();
        lbl_editDetails->raise();
        lineEdit_firstName->raise();
        lineEdit_lastName->raise();
        lineEdit_preferredName->raise();
        lineEdit_email->raise();
        lineEdit_phone->raise();
        lineEdit_NHI->raise();
        btn_submit->raise();

        retranslateUi(editDetails);

        QMetaObject::connectSlotsByName(editDetails);
    } // setupUi

    void retranslateUi(QWidget *editDetails)
    {
        editDetails->setWindowTitle(QCoreApplication::translate("editDetails", "Form", nullptr));
        btn_backToHome->setText(QString());
        lbl_fName->setText(QCoreApplication::translate("editDetails", "First Name:", nullptr));
        lbl_phone->setText(QCoreApplication::translate("editDetails", "Phone Number:", nullptr));
        lbl_pName->setText(QCoreApplication::translate("editDetails", "Preferred Name:", nullptr));
        lbl_topBar->setText(QString());
        lbl_Email->setText(QCoreApplication::translate("editDetails", "Email:", nullptr));
        lbl_NHI->setText(QCoreApplication::translate("editDetails", "NHI Number:", nullptr));
        lbl_lName->setText(QCoreApplication::translate("editDetails", "Last Name:", nullptr));
        lbl_editDetails->setText(QCoreApplication::translate("editDetails", " Edit Account Details", nullptr));
        btn_submit->setText(QCoreApplication::translate("editDetails", "Update Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editDetails: public Ui_editDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDETAILS_H
