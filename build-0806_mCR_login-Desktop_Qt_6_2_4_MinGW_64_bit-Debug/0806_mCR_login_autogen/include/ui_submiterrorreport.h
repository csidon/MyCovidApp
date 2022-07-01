/********************************************************************************
** Form generated from reading UI file 'submiterrorreport.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBMITERRORREPORT_H
#define UI_SUBMITERRORREPORT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubmitErrorReport
{
public:
    QDateEdit *dateEdit;
    QLabel *lbl_background;
    QPushButton *btn_backToHome;
    QLabel *lbl_reportAnError;
    QLabel *lbl_instructions;
    QLabel *lbl_subject;
    QLineEdit *lineEdit_title;
    QLabel *lbl_date;
    QLabel *lbl_description;
    QTextEdit *textEdit;
    QPushButton *btn_submit;

    void setupUi(QWidget *SubmitErrorReport)
    {
        if (SubmitErrorReport->objectName().isEmpty())
            SubmitErrorReport->setObjectName(QString::fromUtf8("SubmitErrorReport"));
        SubmitErrorReport->resize(375, 667);
        dateEdit = new QDateEdit(SubmitErrorReport);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(20, 240, 121, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:black;\n"
"font-family:arial;"));
        dateEdit->setDateTime(QDateTime(QDate(2021, 12, 31), QTime(0, 0, 0)));
        dateEdit->setDate(QDate(2021, 12, 31));
        lbl_background = new QLabel(SubmitErrorReport);
        lbl_background->setObjectName(QString::fromUtf8("lbl_background"));
        lbl_background->setGeometry(QRect(0, 0, 375, 667));
        lbl_background->setStyleSheet(QString::fromUtf8("background-image:url(:/images/reportAnIssueBackground.png);"));
        btn_backToHome = new QPushButton(SubmitErrorReport);
        btn_backToHome->setObjectName(QString::fromUtf8("btn_backToHome"));
        btn_backToHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_reportAnError = new QLabel(SubmitErrorReport);
        lbl_reportAnError->setObjectName(QString::fromUtf8("lbl_reportAnError"));
        lbl_reportAnError->setGeometry(QRect(70, 0, 301, 61));
        lbl_reportAnError->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        lbl_instructions = new QLabel(SubmitErrorReport);
        lbl_instructions->setObjectName(QString::fromUtf8("lbl_instructions"));
        lbl_instructions->setGeometry(QRect(50, 70, 271, 51));
        lbl_instructions->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:16px;\n"
"color:black;"));
        lbl_instructions->setAlignment(Qt::AlignCenter);
        lbl_instructions->setWordWrap(true);
        lbl_subject = new QLabel(SubmitErrorReport);
        lbl_subject->setObjectName(QString::fromUtf8("lbl_subject"));
        lbl_subject->setGeometry(QRect(10, 120, 61, 31));
        lbl_subject->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:16px;\n"
"color:black;"));
        lbl_subject->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_subject->setWordWrap(true);
        lineEdit_title = new QLineEdit(SubmitErrorReport);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));
        lineEdit_title->setGeometry(QRect(20, 150, 331, 41));
        lineEdit_title->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;\n"
"border:1px solid black;\n"
"background-color:white;"));
        lbl_date = new QLabel(SubmitErrorReport);
        lbl_date->setObjectName(QString::fromUtf8("lbl_date"));
        lbl_date->setGeometry(QRect(10, 200, 131, 31));
        lbl_date->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:16px;\n"
"color:black;"));
        lbl_date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_date->setWordWrap(true);
        lbl_description = new QLabel(SubmitErrorReport);
        lbl_description->setObjectName(QString::fromUtf8("lbl_description"));
        lbl_description->setGeometry(QRect(10, 280, 111, 31));
        lbl_description->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:16px;\n"
"color:black;"));
        lbl_description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_description->setWordWrap(true);
        textEdit = new QTextEdit(SubmitErrorReport);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 320, 331, 271));
        textEdit->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        btn_submit = new QPushButton(SubmitErrorReport);
        btn_submit->setObjectName(QString::fromUtf8("btn_submit"));
        btn_submit->setGeometry(QRect(120, 610, 131, 41));
        lbl_background->raise();
        dateEdit->raise();
        btn_backToHome->raise();
        lbl_reportAnError->raise();
        lbl_instructions->raise();
        lbl_subject->raise();
        lineEdit_title->raise();
        lbl_date->raise();
        lbl_description->raise();
        textEdit->raise();
        btn_submit->raise();

        retranslateUi(SubmitErrorReport);

        QMetaObject::connectSlotsByName(SubmitErrorReport);
    } // setupUi

    void retranslateUi(QWidget *SubmitErrorReport)
    {
        SubmitErrorReport->setWindowTitle(QCoreApplication::translate("SubmitErrorReport", "Form", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("SubmitErrorReport", "yyyy/MM/dd", nullptr));
        lbl_background->setText(QString());
        btn_backToHome->setText(QString());
        lbl_reportAnError->setText(QCoreApplication::translate("SubmitErrorReport", "     Report an Error", nullptr));
        lbl_instructions->setText(QCoreApplication::translate("SubmitErrorReport", "Please be as detailed as possible to aid us in the troubleshooting process", nullptr));
        lbl_subject->setText(QCoreApplication::translate("SubmitErrorReport", "Subject:", nullptr));
        lbl_date->setText(QCoreApplication::translate("SubmitErrorReport", "Date Encountered:", nullptr));
        lbl_description->setText(QCoreApplication::translate("SubmitErrorReport", "Description:", nullptr));
        btn_submit->setText(QCoreApplication::translate("SubmitErrorReport", "Submit Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubmitErrorReport: public Ui_SubmitErrorReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBMITERRORREPORT_H
