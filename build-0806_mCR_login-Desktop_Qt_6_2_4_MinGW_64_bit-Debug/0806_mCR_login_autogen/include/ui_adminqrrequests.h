/********************************************************************************
** Form generated from reading UI file 'adminqrrequests.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINQRREQUESTS_H
#define UI_ADMINQRREQUESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminQRRequests
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_topBar;
    QPushButton *btn_backToAdminHome;
    QLabel *lbl_QRRequests;
    QWidget *page_2;

    void setupUi(QWidget *adminQRRequests)
    {
        if (adminQRRequests->objectName().isEmpty())
            adminQRRequests->setObjectName(QString::fromUtf8("adminQRRequests"));
        adminQRRequests->resize(375, 667);
        stackedWidget = new QStackedWidget(adminQRRequests);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 381, 671));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lbl_topBar = new QLabel(page);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_backToAdminHome = new QPushButton(page);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_QRRequests = new QLabel(page);
        lbl_QRRequests->setObjectName(QString::fromUtf8("lbl_QRRequests"));
        lbl_QRRequests->setGeometry(QRect(70, 0, 301, 61));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(adminQRRequests);

        QMetaObject::connectSlotsByName(adminQRRequests);
    } // setupUi

    void retranslateUi(QWidget *adminQRRequests)
    {
        adminQRRequests->setWindowTitle(QCoreApplication::translate("adminQRRequests", "Form", nullptr));
        lbl_topBar->setText(QString());
        btn_backToAdminHome->setText(QString());
        lbl_QRRequests->setText(QCoreApplication::translate("adminQRRequests", "QR Code Requests", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminQRRequests: public Ui_adminQRRequests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINQRREQUESTS_H
