/********************************************************************************
** Form generated from reading UI file 'displaymyqrcode.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYMYQRCODE_H
#define UI_DISPLAYMYQRCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayMyQRCode
{
public:
    QLabel *lbl_background;
    QPushButton *btn_backToHome;
    QLabel *lbl_QR;
    QLabel *lbl_name;

    void setupUi(QWidget *DisplayMyQRCode)
    {
        if (DisplayMyQRCode->objectName().isEmpty())
            DisplayMyQRCode->setObjectName(QString::fromUtf8("DisplayMyQRCode"));
        DisplayMyQRCode->resize(375, 667);
        DisplayMyQRCode->setStyleSheet(QString::fromUtf8(""));
        lbl_background = new QLabel(DisplayMyQRCode);
        lbl_background->setObjectName(QString::fromUtf8("lbl_background"));
        lbl_background->setGeometry(QRect(0, 0, 375, 667));
        lbl_background->setStyleSheet(QString::fromUtf8("background-image:url(:/images/displayQRCode.png)"));
        btn_backToHome = new QPushButton(DisplayMyQRCode);
        btn_backToHome->setObjectName(QString::fromUtf8("btn_backToHome"));
        btn_backToHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_QR = new QLabel(DisplayMyQRCode);
        lbl_QR->setObjectName(QString::fromUtf8("lbl_QR"));
        lbl_QR->setGeometry(QRect(60, 250, 251, 251));
        lbl_QR->setScaledContents(true);
        lbl_name = new QLabel(DisplayMyQRCode);
        lbl_name->setObjectName(QString::fromUtf8("lbl_name"));
        lbl_name->setGeometry(QRect(40, 140, 301, 71));
        lbl_name->setStyleSheet(QString::fromUtf8("font-family:arial;\n"
"font-size:18px;\n"
"color:black;"));
        lbl_name->setWordWrap(true);

        retranslateUi(DisplayMyQRCode);

        QMetaObject::connectSlotsByName(DisplayMyQRCode);
    } // setupUi

    void retranslateUi(QWidget *DisplayMyQRCode)
    {
        DisplayMyQRCode->setWindowTitle(QCoreApplication::translate("DisplayMyQRCode", "Form", nullptr));
        lbl_background->setText(QString());
        btn_backToHome->setText(QString());
        lbl_QR->setText(QString());
        lbl_name->setText(QCoreApplication::translate("DisplayMyQRCode", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayMyQRCode: public Ui_DisplayMyQRCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYMYQRCODE_H
