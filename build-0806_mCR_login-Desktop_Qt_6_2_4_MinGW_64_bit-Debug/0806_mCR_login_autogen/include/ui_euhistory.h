/********************************************************************************
** Form generated from reading UI file 'euhistory.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EUHISTORY_H
#define UI_EUHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EUHistory
{
public:
    QPushButton *btn_backToAdminHome;

    void setupUi(QWidget *EUHistory)
    {
        if (EUHistory->objectName().isEmpty())
            EUHistory->setObjectName(QString::fromUtf8("EUHistory"));
        EUHistory->resize(375, 667);
        btn_backToAdminHome = new QPushButton(EUHistory);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));

        retranslateUi(EUHistory);

        QMetaObject::connectSlotsByName(EUHistory);
    } // setupUi

    void retranslateUi(QWidget *EUHistory)
    {
        EUHistory->setWindowTitle(QCoreApplication::translate("EUHistory", "Form", nullptr));
        btn_backToAdminHome->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EUHistory: public Ui_EUHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EUHISTORY_H
