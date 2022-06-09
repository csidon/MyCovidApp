/********************************************************************************
** Form generated from reading UI file 'authdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHDIALOG_H
#define UI_AUTHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AuthDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_mycovidrec;
    QLabel *lbl_nz;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_login;
    QLabel *lbl_email;
    QLineEdit *lineEdit_inputEmail;
    QLabel *lbl_password;
    QLineEdit *lineEdit_inputPass;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_forgotPass;
    QPushButton *btn_login;
    QPushButton *btn_signup;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AuthDialog)
    {
        if (AuthDialog->objectName().isEmpty())
            AuthDialog->setObjectName(QString::fromUtf8("AuthDialog"));
        AuthDialog->resize(375, 667);
        gridLayout = new QGridLayout(AuthDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(40, -1, 40, -1);
        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lbl_mycovidrec = new QLabel(AuthDialog);
        lbl_mycovidrec->setObjectName(QString::fromUtf8("lbl_mycovidrec"));
        lbl_mycovidrec->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        lbl_mycovidrec->setFont(font);
        lbl_mycovidrec->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Arial\";"));
        lbl_mycovidrec->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lbl_mycovidrec);

        lbl_nz = new QLabel(AuthDialog);
        lbl_nz->setObjectName(QString::fromUtf8("lbl_nz"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        lbl_nz->setFont(font1);
        lbl_nz->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        lbl_nz->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lbl_nz);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbl_login = new QLabel(AuthDialog);
        lbl_login->setObjectName(QString::fromUtf8("lbl_login"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(10);
        font2.setBold(true);
        lbl_login->setFont(font2);

        verticalLayout_2->addWidget(lbl_login);


        verticalLayout_4->addLayout(verticalLayout_2);

        lbl_email = new QLabel(AuthDialog);
        lbl_email->setObjectName(QString::fromUtf8("lbl_email"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(9);
        font3.setBold(false);
        lbl_email->setFont(font3);

        verticalLayout_4->addWidget(lbl_email);

        lineEdit_inputEmail = new QLineEdit(AuthDialog);
        lineEdit_inputEmail->setObjectName(QString::fromUtf8("lineEdit_inputEmail"));
        lineEdit_inputEmail->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_inputEmail->sizePolicy().hasHeightForWidth());
        lineEdit_inputEmail->setSizePolicy(sizePolicy);
        lineEdit_inputEmail->setMaximumSize(QSize(16777215, 40));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(14);
        lineEdit_inputEmail->setFont(font4);

        verticalLayout_4->addWidget(lineEdit_inputEmail);

        lbl_password = new QLabel(AuthDialog);
        lbl_password->setObjectName(QString::fromUtf8("lbl_password"));
        lbl_password->setFont(font3);

        verticalLayout_4->addWidget(lbl_password);

        lineEdit_inputPass = new QLineEdit(AuthDialog);
        lineEdit_inputPass->setObjectName(QString::fromUtf8("lineEdit_inputPass"));
        sizePolicy.setHeightForWidth(lineEdit_inputPass->sizePolicy().hasHeightForWidth());
        lineEdit_inputPass->setSizePolicy(sizePolicy);
        lineEdit_inputPass->setMaximumSize(QSize(16777215, 40));
        lineEdit_inputPass->setFont(font4);

        verticalLayout_4->addWidget(lineEdit_inputPass);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btn_forgotPass = new QPushButton(AuthDialog);
        btn_forgotPass->setObjectName(QString::fromUtf8("btn_forgotPass"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_forgotPass->sizePolicy().hasHeightForWidth());
        btn_forgotPass->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setItalic(false);
        btn_forgotPass->setFont(font5);
        btn_forgotPass->setLayoutDirection(Qt::RightToLeft);
        btn_forgotPass->setStyleSheet(QString::fromUtf8("font: 9pt \"Arial\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_forgotPass->setFlat(true);

        verticalLayout_3->addWidget(btn_forgotPass, 0, Qt::AlignLeft);

        btn_login = new QPushButton(AuthDialog);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(14);
        font6.setBold(true);
        btn_login->setFont(font6);

        verticalLayout_3->addWidget(btn_login);

        btn_signup = new QPushButton(AuthDialog);
        btn_signup->setObjectName(QString::fromUtf8("btn_signup"));
        sizePolicy1.setHeightForWidth(btn_signup->sizePolicy().hasHeightForWidth());
        btn_signup->setSizePolicy(sizePolicy1);
        btn_signup->setFont(font5);
        btn_signup->setLayoutDirection(Qt::RightToLeft);
        btn_signup->setStyleSheet(QString::fromUtf8("font: 9pt \"Arial\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_signup->setFlat(true);

        verticalLayout_3->addWidget(btn_signup);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_inputEmail, lineEdit_inputPass);
        QWidget::setTabOrder(lineEdit_inputPass, btn_login);
        QWidget::setTabOrder(btn_login, btn_forgotPass);
        QWidget::setTabOrder(btn_forgotPass, btn_signup);

        retranslateUi(AuthDialog);

        QMetaObject::connectSlotsByName(AuthDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthDialog)
    {
        AuthDialog->setWindowTitle(QCoreApplication::translate("AuthDialog", "Dialog", nullptr));
        lbl_mycovidrec->setText(QCoreApplication::translate("AuthDialog", "MyCovidRecord", nullptr));
        lbl_nz->setText(QCoreApplication::translate("AuthDialog", "New Zealand", nullptr));
        lbl_login->setText(QCoreApplication::translate("AuthDialog", "LOGIN", nullptr));
        lbl_email->setText(QCoreApplication::translate("AuthDialog", "Email", nullptr));
        lineEdit_inputEmail->setText(QString());
        lineEdit_inputEmail->setPlaceholderText(QString());
        lbl_password->setText(QCoreApplication::translate("AuthDialog", "Password", nullptr));
        lineEdit_inputPass->setText(QString());
        lineEdit_inputPass->setPlaceholderText(QString());
        btn_forgotPass->setText(QCoreApplication::translate("AuthDialog", "Forgot Password?", nullptr));
#if QT_CONFIG(shortcut)
        btn_forgotPass->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        btn_login->setText(QCoreApplication::translate("AuthDialog", "LOGIN", nullptr));
        btn_signup->setText(QCoreApplication::translate("AuthDialog", "Need an account? SIGN UP", nullptr));
#if QT_CONFIG(shortcut)
        btn_signup->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class AuthDialog: public Ui_AuthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHDIALOG_H
