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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EUHistory
{
public:
    QLabel *lbl_c19history;
    QLabel *lbl_euName;
    QLabel *lbl_nhi;
    QFrame *frame;
    QWidget *widget;

    void setupUi(QWidget *EUHistory)
    {
        if (EUHistory->objectName().isEmpty())
            EUHistory->setObjectName(QString::fromUtf8("EUHistory"));
        EUHistory->resize(375, 667);
        lbl_c19history = new QLabel(EUHistory);
        lbl_c19history->setObjectName(QString::fromUtf8("lbl_c19history"));
        lbl_c19history->setGeometry(QRect(60, 50, 211, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        lbl_c19history->setFont(font);
        lbl_c19history->setAlignment(Qt::AlignCenter);
        lbl_euName = new QLabel(EUHistory);
        lbl_euName->setObjectName(QString::fromUtf8("lbl_euName"));
        lbl_euName->setGeometry(QRect(10, 90, 341, 20));
        lbl_euName->setAlignment(Qt::AlignCenter);
        lbl_nhi = new QLabel(EUHistory);
        lbl_nhi->setObjectName(QString::fromUtf8("lbl_nhi"));
        lbl_nhi->setGeometry(QRect(20, 130, 341, 20));
        lbl_nhi->setAlignment(Qt::AlignCenter);
        frame = new QFrame(EUHistory);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 170, 331, 331));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 321, 331));

        retranslateUi(EUHistory);

        QMetaObject::connectSlotsByName(EUHistory);
    } // setupUi

    void retranslateUi(QWidget *EUHistory)
    {
        EUHistory->setWindowTitle(QCoreApplication::translate("EUHistory", "Form", nullptr));
        lbl_c19history->setText(QCoreApplication::translate("EUHistory", "COVID-19 History", nullptr));
        lbl_euName->setText(QCoreApplication::translate("EUHistory", "prefName fName lName", nullptr));
        lbl_nhi->setText(QCoreApplication::translate("EUHistory", "NHI: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EUHistory: public Ui_EUHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EUHISTORY_H
