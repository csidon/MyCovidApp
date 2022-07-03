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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthDialog
{
public:
    QAction *actioncheck;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_mycovidrec;
    QLabel *lbl_nz;
    QLabel *lbl_login;
    QLabel *lbl_email;
    QLineEdit *lineEdit_inputEmail;
    QLabel *lbl_password;
    QLineEdit *lineEdit_inputPass;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_forgotPass;
    QPushButton *btn_login;
    QPushButton *btn_switchToSignup;
    QSpacerItem *verticalSpacer;
    QWidget *page_reg;
    QGridLayout *gridLayout;
    QLabel *lbl_regEmail;
    QLabel *lbl_regPass;
    QLineEdit *lineEdit_inputRegPass;
    QSpacerItem *verticalSpacer_5;
    QLabel *lbl_register;
    QVBoxLayout *verticalLayout_7;
    QPushButton *btn_regForgotPass;
    QLabel *lbl_passCriteria;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_passCheck_charIcon;
    QLabel *lbl_passCheck_char_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_passCheck_UppLowIcon;
    QLabel *lbl_passCheck_uppLow;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_passCheck_numIcon;
    QLabel *lbl_passCheck_num;
    QPushButton *btn_createAccount;
    QPushButton *btn_switchToLogin;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *lbl_mycovidrec_reg;
    QLabel *lbl_nz_reg;
    QLineEdit *lineEdit_inputRegEmail;
    QLabel *lbl_emailExistsErr;
    QWidget *page_2;
    QLabel *label;
    QCheckBox *checkBox_agreeTerms;
    QLabel *label_2;
    QPushButton *btn_nextTerms1;
    QWidget *page_3;
    QPushButton *btn_nextTerms2;
    QCheckBox *checkBox_agreeTerms2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *page_4;
    QLabel *label_6;
    QPushButton *btn_nextDetails;
    QLabel *label_enterDetails;
    QLabel *label_enterDetails_2;
    QLineEdit *lineEdit_fname;
    QLabel *label_enterDetails_3;
    QLineEdit *lineEdit_lname;
    QLabel *label_enterDetails_4;
    QLineEdit *lineEdit_prefName;
    QWidget *page_5;
    QLabel *label_enterDetails_5;
    QPushButton *btn_nextDetails_2;
    QLabel *label_enterDetails_6;
    QLabel *label_enterDetails_7;
    QLineEdit *lineEdit_phone;
    QLabel *label_enterDetails_8;
    QLabel *label_7;
    QLineEdit *lineEdit_nhi;
    QWidget *page_6;
    QLabel *label_8;
    QLabel *label_accountCreatedMsg;
    QProgressBar *progressBar;

    void setupUi(QDialog *AuthDialog)
    {
        if (AuthDialog->objectName().isEmpty())
            AuthDialog->setObjectName(QString::fromUtf8("AuthDialog"));
        AuthDialog->resize(375, 667);
        actioncheck = new QAction(AuthDialog);
        actioncheck->setObjectName(QString::fromUtf8("actioncheck"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncheck->setIcon(icon);
        gridLayout_2 = new QGridLayout(AuthDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(AuthDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lbl_mycovidrec = new QLabel(page);
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

        lbl_nz = new QLabel(page);
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


        verticalLayout->addLayout(verticalLayout_5);

        lbl_login = new QLabel(page);
        lbl_login->setObjectName(QString::fromUtf8("lbl_login"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(10);
        font2.setBold(true);
        lbl_login->setFont(font2);

        verticalLayout->addWidget(lbl_login);

        lbl_email = new QLabel(page);
        lbl_email->setObjectName(QString::fromUtf8("lbl_email"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(9);
        font3.setBold(false);
        lbl_email->setFont(font3);

        verticalLayout->addWidget(lbl_email);

        lineEdit_inputEmail = new QLineEdit(page);
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

        verticalLayout->addWidget(lineEdit_inputEmail);

        lbl_password = new QLabel(page);
        lbl_password->setObjectName(QString::fromUtf8("lbl_password"));
        lbl_password->setFont(font3);

        verticalLayout->addWidget(lbl_password);

        lineEdit_inputPass = new QLineEdit(page);
        lineEdit_inputPass->setObjectName(QString::fromUtf8("lineEdit_inputPass"));
        sizePolicy.setHeightForWidth(lineEdit_inputPass->sizePolicy().hasHeightForWidth());
        lineEdit_inputPass->setSizePolicy(sizePolicy);
        lineEdit_inputPass->setMaximumSize(QSize(16777215, 40));
        lineEdit_inputPass->setFont(font4);
        lineEdit_inputPass->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lineEdit_inputPass->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_inputPass);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btn_forgotPass = new QPushButton(page);
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

        btn_login = new QPushButton(page);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setMinimumSize(QSize(0, 45));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(14);
        font6.setBold(true);
        btn_login->setFont(font6);

        verticalLayout_3->addWidget(btn_login);

        btn_switchToSignup = new QPushButton(page);
        btn_switchToSignup->setObjectName(QString::fromUtf8("btn_switchToSignup"));
        sizePolicy1.setHeightForWidth(btn_switchToSignup->sizePolicy().hasHeightForWidth());
        btn_switchToSignup->setSizePolicy(sizePolicy1);
        btn_switchToSignup->setFont(font5);
        btn_switchToSignup->setLayoutDirection(Qt::RightToLeft);
        btn_switchToSignup->setStyleSheet(QString::fromUtf8("font: 9pt \"Arial\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_switchToSignup->setFlat(true);

        verticalLayout_3->addWidget(btn_switchToSignup);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page);
        page_reg = new QWidget();
        page_reg->setObjectName(QString::fromUtf8("page_reg"));
        gridLayout = new QGridLayout(page_reg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl_regEmail = new QLabel(page_reg);
        lbl_regEmail->setObjectName(QString::fromUtf8("lbl_regEmail"));
        lbl_regEmail->setFont(font3);

        gridLayout->addWidget(lbl_regEmail, 3, 0, 1, 2);

        lbl_regPass = new QLabel(page_reg);
        lbl_regPass->setObjectName(QString::fromUtf8("lbl_regPass"));
        lbl_regPass->setFont(font3);

        gridLayout->addWidget(lbl_regPass, 6, 0, 1, 2);

        lineEdit_inputRegPass = new QLineEdit(page_reg);
        lineEdit_inputRegPass->setObjectName(QString::fromUtf8("lineEdit_inputRegPass"));
        sizePolicy.setHeightForWidth(lineEdit_inputRegPass->sizePolicy().hasHeightForWidth());
        lineEdit_inputRegPass->setSizePolicy(sizePolicy);
        lineEdit_inputRegPass->setMaximumSize(QSize(16777215, 40));
        lineEdit_inputRegPass->setFont(font4);

        gridLayout->addWidget(lineEdit_inputRegPass, 7, 0, 2, 3);

        verticalSpacer_5 = new QSpacerItem(20, 36, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_5, 0, 2, 1, 1);

        lbl_register = new QLabel(page_reg);
        lbl_register->setObjectName(QString::fromUtf8("lbl_register"));
        lbl_register->setFont(font2);

        gridLayout->addWidget(lbl_register, 2, 0, 1, 2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        btn_regForgotPass = new QPushButton(page_reg);
        btn_regForgotPass->setObjectName(QString::fromUtf8("btn_regForgotPass"));
        sizePolicy1.setHeightForWidth(btn_regForgotPass->sizePolicy().hasHeightForWidth());
        btn_regForgotPass->setSizePolicy(sizePolicy1);
        btn_regForgotPass->setFont(font5);
        btn_regForgotPass->setLayoutDirection(Qt::RightToLeft);
        btn_regForgotPass->setStyleSheet(QString::fromUtf8("font: 9pt \"Arial\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_regForgotPass->setFlat(true);

        verticalLayout_7->addWidget(btn_regForgotPass, 0, Qt::AlignLeft);

        lbl_passCriteria = new QLabel(page_reg);
        lbl_passCriteria->setObjectName(QString::fromUtf8("lbl_passCriteria"));

        verticalLayout_7->addWidget(lbl_passCriteria);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lbl_passCheck_charIcon = new QLabel(page_reg);
        lbl_passCheck_charIcon->setObjectName(QString::fromUtf8("lbl_passCheck_charIcon"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbl_passCheck_charIcon->sizePolicy().hasHeightForWidth());
        lbl_passCheck_charIcon->setSizePolicy(sizePolicy2);
        lbl_passCheck_charIcon->setMinimumSize(QSize(30, 30));
        lbl_passCheck_charIcon->setMaximumSize(QSize(30, 30));
        lbl_passCheck_charIcon->setBaseSize(QSize(10, 0));

        horizontalLayout_6->addWidget(lbl_passCheck_charIcon);

        lbl_passCheck_char_2 = new QLabel(page_reg);
        lbl_passCheck_char_2->setObjectName(QString::fromUtf8("lbl_passCheck_char_2"));

        horizontalLayout_6->addWidget(lbl_passCheck_char_2);


        verticalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbl_passCheck_UppLowIcon = new QLabel(page_reg);
        lbl_passCheck_UppLowIcon->setObjectName(QString::fromUtf8("lbl_passCheck_UppLowIcon"));
        sizePolicy2.setHeightForWidth(lbl_passCheck_UppLowIcon->sizePolicy().hasHeightForWidth());
        lbl_passCheck_UppLowIcon->setSizePolicy(sizePolicy2);
        lbl_passCheck_UppLowIcon->setMinimumSize(QSize(30, 30));
        lbl_passCheck_UppLowIcon->setMaximumSize(QSize(30, 30));
        lbl_passCheck_UppLowIcon->setBaseSize(QSize(10, 0));

        horizontalLayout_5->addWidget(lbl_passCheck_UppLowIcon);

        lbl_passCheck_uppLow = new QLabel(page_reg);
        lbl_passCheck_uppLow->setObjectName(QString::fromUtf8("lbl_passCheck_uppLow"));

        horizontalLayout_5->addWidget(lbl_passCheck_uppLow);


        verticalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_passCheck_numIcon = new QLabel(page_reg);
        lbl_passCheck_numIcon->setObjectName(QString::fromUtf8("lbl_passCheck_numIcon"));
        sizePolicy2.setHeightForWidth(lbl_passCheck_numIcon->sizePolicy().hasHeightForWidth());
        lbl_passCheck_numIcon->setSizePolicy(sizePolicy2);
        lbl_passCheck_numIcon->setMinimumSize(QSize(30, 30));
        lbl_passCheck_numIcon->setMaximumSize(QSize(30, 30));
        lbl_passCheck_numIcon->setBaseSize(QSize(10, 0));

        horizontalLayout->addWidget(lbl_passCheck_numIcon);

        lbl_passCheck_num = new QLabel(page_reg);
        lbl_passCheck_num->setObjectName(QString::fromUtf8("lbl_passCheck_num"));

        horizontalLayout->addWidget(lbl_passCheck_num);


        verticalLayout_9->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout_9);

        btn_createAccount = new QPushButton(page_reg);
        btn_createAccount->setObjectName(QString::fromUtf8("btn_createAccount"));
        btn_createAccount->setMinimumSize(QSize(0, 45));
        btn_createAccount->setFont(font6);

        verticalLayout_7->addWidget(btn_createAccount);

        btn_switchToLogin = new QPushButton(page_reg);
        btn_switchToLogin->setObjectName(QString::fromUtf8("btn_switchToLogin"));
        sizePolicy1.setHeightForWidth(btn_switchToLogin->sizePolicy().hasHeightForWidth());
        btn_switchToLogin->setSizePolicy(sizePolicy1);
        btn_switchToLogin->setFont(font5);
        btn_switchToLogin->setLayoutDirection(Qt::RightToLeft);
        btn_switchToLogin->setStyleSheet(QString::fromUtf8("font: 9pt \"Arial\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_switchToLogin->setFlat(true);

        verticalLayout_7->addWidget(btn_switchToLogin);

        verticalSpacer_6 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_7->addItem(verticalSpacer_6);


        gridLayout->addLayout(verticalLayout_7, 10, 0, 1, 3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lbl_mycovidrec_reg = new QLabel(page_reg);
        lbl_mycovidrec_reg->setObjectName(QString::fromUtf8("lbl_mycovidrec_reg"));
        lbl_mycovidrec_reg->setMaximumSize(QSize(16777215, 30));
        lbl_mycovidrec_reg->setFont(font);
        lbl_mycovidrec_reg->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Arial\";"));
        lbl_mycovidrec_reg->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(lbl_mycovidrec_reg);

        lbl_nz_reg = new QLabel(page_reg);
        lbl_nz_reg->setObjectName(QString::fromUtf8("lbl_nz_reg"));
        lbl_nz_reg->setFont(font1);
        lbl_nz_reg->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        lbl_nz_reg->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(lbl_nz_reg);


        gridLayout->addLayout(verticalLayout_8, 1, 0, 1, 3);

        lineEdit_inputRegEmail = new QLineEdit(page_reg);
        lineEdit_inputRegEmail->setObjectName(QString::fromUtf8("lineEdit_inputRegEmail"));
        lineEdit_inputRegEmail->setEnabled(true);
        sizePolicy.setHeightForWidth(lineEdit_inputRegEmail->sizePolicy().hasHeightForWidth());
        lineEdit_inputRegEmail->setSizePolicy(sizePolicy);
        lineEdit_inputRegEmail->setMaximumSize(QSize(16777215, 40));
        lineEdit_inputRegEmail->setFont(font4);

        gridLayout->addWidget(lineEdit_inputRegEmail, 4, 0, 1, 3);

        lbl_emailExistsErr = new QLabel(page_reg);
        lbl_emailExistsErr->setObjectName(QString::fromUtf8("lbl_emailExistsErr"));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Arial")});
        lbl_emailExistsErr->setFont(font7);

        gridLayout->addWidget(lbl_emailExistsErr, 5, 0, 1, 3);

        stackedWidget->addWidget(page_reg);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, 30, 411, 111));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/signUp1.png);"));
        checkBox_agreeTerms = new QCheckBox(page_2);
        checkBox_agreeTerms->setObjectName(QString::fromUtf8("checkBox_agreeTerms"));
        checkBox_agreeTerms->setGeometry(QRect(47, 160, 241, 26));
        checkBox_agreeTerms->setFont(font2);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 180, 260, 311));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/signUpTerms.png);"));
        btn_nextTerms1 = new QPushButton(page_2);
        btn_nextTerms1->setObjectName(QString::fromUtf8("btn_nextTerms1"));
        btn_nextTerms1->setGeometry(QRect(220, 500, 86, 45));
        btn_nextTerms1->setMinimumSize(QSize(0, 45));
        btn_nextTerms1->setFont(font7);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        btn_nextTerms2 = new QPushButton(page_3);
        btn_nextTerms2->setObjectName(QString::fromUtf8("btn_nextTerms2"));
        btn_nextTerms2->setGeometry(QRect(220, 550, 86, 45));
        btn_nextTerms2->setMinimumSize(QSize(0, 45));
        btn_nextTerms2->setFont(font7);
        checkBox_agreeTerms2 = new QCheckBox(page_3);
        checkBox_agreeTerms2->setObjectName(QString::fromUtf8("checkBox_agreeTerms2"));
        checkBox_agreeTerms2->setGeometry(QRect(50, 224, 241, 26));
        checkBox_agreeTerms2->setFont(font2);
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 226, 260, 311));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/images/signUpTerms.png);"));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-10, 30, 411, 111));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/signUp1.png);"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(-30, 140, 391, 391));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/images/signUpTermsHighlight.png);"));
        stackedWidget->addWidget(page_3);
        label_5->raise();
        label_3->raise();
        btn_nextTerms2->raise();
        checkBox_agreeTerms2->raise();
        label_4->raise();
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(-10, 30, 411, 111));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/images/signUp2.png);"));
        btn_nextDetails = new QPushButton(page_4);
        btn_nextDetails->setObjectName(QString::fromUtf8("btn_nextDetails"));
        btn_nextDetails->setGeometry(QRect(220, 477, 86, 45));
        btn_nextDetails->setMinimumSize(QSize(0, 45));
        btn_nextDetails->setFont(font7);
        label_enterDetails = new QLabel(page_4);
        label_enterDetails->setObjectName(QString::fromUtf8("label_enterDetails"));
        label_enterDetails->setGeometry(QRect(51, 170, 151, 20));
        label_enterDetails->setFont(font2);
        label_enterDetails_2 = new QLabel(page_4);
        label_enterDetails_2->setObjectName(QString::fromUtf8("label_enterDetails_2"));
        label_enterDetails_2->setGeometry(QRect(51, 210, 151, 20));
        label_enterDetails_2->setFont(font3);
        lineEdit_fname = new QLineEdit(page_4);
        lineEdit_fname->setObjectName(QString::fromUtf8("lineEdit_fname"));
        lineEdit_fname->setGeometry(QRect(50, 230, 261, 40));
        lineEdit_fname->setMinimumSize(QSize(0, 40));
        lineEdit_fname->setMaximumSize(QSize(16777215, 40));
        label_enterDetails_3 = new QLabel(page_4);
        label_enterDetails_3->setObjectName(QString::fromUtf8("label_enterDetails_3"));
        label_enterDetails_3->setGeometry(QRect(51, 290, 151, 20));
        label_enterDetails_3->setFont(font3);
        lineEdit_lname = new QLineEdit(page_4);
        lineEdit_lname->setObjectName(QString::fromUtf8("lineEdit_lname"));
        lineEdit_lname->setGeometry(QRect(50, 310, 261, 40));
        lineEdit_lname->setMinimumSize(QSize(0, 40));
        lineEdit_lname->setMaximumSize(QSize(16777215, 40));
        label_enterDetails_4 = new QLabel(page_4);
        label_enterDetails_4->setObjectName(QString::fromUtf8("label_enterDetails_4"));
        label_enterDetails_4->setGeometry(QRect(51, 380, 151, 20));
        label_enterDetails_4->setFont(font3);
        lineEdit_prefName = new QLineEdit(page_4);
        lineEdit_prefName->setObjectName(QString::fromUtf8("lineEdit_prefName"));
        lineEdit_prefName->setGeometry(QRect(50, 400, 261, 40));
        lineEdit_prefName->setMinimumSize(QSize(0, 40));
        lineEdit_prefName->setMaximumSize(QSize(16777215, 40));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_enterDetails_5 = new QLabel(page_5);
        label_enterDetails_5->setObjectName(QString::fromUtf8("label_enterDetails_5"));
        label_enterDetails_5->setGeometry(QRect(47, 350, 281, 81));
        label_enterDetails_5->setFont(font3);
        label_enterDetails_5->setStyleSheet(QString::fromUtf8("image: url(:/images/signUpPhoneRec.png);"));
        btn_nextDetails_2 = new QPushButton(page_5);
        btn_nextDetails_2->setObjectName(QString::fromUtf8("btn_nextDetails_2"));
        btn_nextDetails_2->setGeometry(QRect(220, 477, 86, 45));
        btn_nextDetails_2->setMinimumSize(QSize(0, 45));
        btn_nextDetails_2->setFont(font7);
        label_enterDetails_6 = new QLabel(page_5);
        label_enterDetails_6->setObjectName(QString::fromUtf8("label_enterDetails_6"));
        label_enterDetails_6->setGeometry(QRect(51, 290, 161, 20));
        label_enterDetails_6->setFont(font3);
        label_enterDetails_7 = new QLabel(page_5);
        label_enterDetails_7->setObjectName(QString::fromUtf8("label_enterDetails_7"));
        label_enterDetails_7->setGeometry(QRect(51, 210, 171, 20));
        label_enterDetails_7->setFont(font3);
        lineEdit_phone = new QLineEdit(page_5);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(50, 310, 261, 40));
        lineEdit_phone->setMinimumSize(QSize(0, 40));
        lineEdit_phone->setMaximumSize(QSize(16777215, 40));
        label_enterDetails_8 = new QLabel(page_5);
        label_enterDetails_8->setObjectName(QString::fromUtf8("label_enterDetails_8"));
        label_enterDetails_8->setGeometry(QRect(51, 170, 151, 20));
        label_enterDetails_8->setFont(font2);
        label_7 = new QLabel(page_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(-10, 30, 411, 111));
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(:/images/signUp3.png);"));
        lineEdit_nhi = new QLineEdit(page_5);
        lineEdit_nhi->setObjectName(QString::fromUtf8("lineEdit_nhi"));
        lineEdit_nhi->setGeometry(QRect(50, 230, 261, 40));
        lineEdit_nhi->setMinimumSize(QSize(0, 40));
        lineEdit_nhi->setMaximumSize(QSize(16777215, 40));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_8 = new QLabel(page_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(-10, 100, 371, 391));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/images/accountCreationIP.png);"));
        label_accountCreatedMsg = new QLabel(page_6);
        label_accountCreatedMsg->setObjectName(QString::fromUtf8("label_accountCreatedMsg"));
        label_accountCreatedMsg->setGeometry(QRect(-10, 100, 371, 391));
        label_accountCreatedMsg->setStyleSheet(QString::fromUtf8("image: url(:/images/accountCreationComplete.png);"));
        progressBar = new QProgressBar(page_6);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(70, 490, 211, 35));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        stackedWidget->addWidget(page_6);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_inputEmail, lineEdit_inputPass);
        QWidget::setTabOrder(lineEdit_inputPass, btn_login);
        QWidget::setTabOrder(btn_login, btn_forgotPass);
        QWidget::setTabOrder(btn_forgotPass, btn_switchToSignup);
        QWidget::setTabOrder(btn_switchToSignup, lineEdit_inputRegEmail);
        QWidget::setTabOrder(lineEdit_inputRegEmail, lineEdit_inputRegPass);
        QWidget::setTabOrder(lineEdit_inputRegPass, btn_createAccount);
        QWidget::setTabOrder(btn_createAccount, btn_regForgotPass);
        QWidget::setTabOrder(btn_regForgotPass, btn_switchToLogin);
        QWidget::setTabOrder(btn_switchToLogin, checkBox_agreeTerms);
        QWidget::setTabOrder(checkBox_agreeTerms, btn_nextTerms1);
        QWidget::setTabOrder(btn_nextTerms1, checkBox_agreeTerms2);
        QWidget::setTabOrder(checkBox_agreeTerms2, btn_nextTerms2);
        QWidget::setTabOrder(btn_nextTerms2, lineEdit_fname);
        QWidget::setTabOrder(lineEdit_fname, lineEdit_lname);
        QWidget::setTabOrder(lineEdit_lname, lineEdit_prefName);
        QWidget::setTabOrder(lineEdit_prefName, btn_nextDetails);
        QWidget::setTabOrder(btn_nextDetails, lineEdit_nhi);
        QWidget::setTabOrder(lineEdit_nhi, lineEdit_phone);
        QWidget::setTabOrder(lineEdit_phone, btn_nextDetails_2);

        retranslateUi(AuthDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AuthDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthDialog)
    {
        AuthDialog->setWindowTitle(QCoreApplication::translate("AuthDialog", "Dialog", nullptr));
        actioncheck->setText(QCoreApplication::translate("AuthDialog", "check", nullptr));
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
        btn_switchToSignup->setText(QCoreApplication::translate("AuthDialog", "Need an account? SIGN UP", nullptr));
#if QT_CONFIG(shortcut)
        btn_switchToSignup->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        lbl_regEmail->setText(QCoreApplication::translate("AuthDialog", "Email", nullptr));
        lbl_regPass->setText(QCoreApplication::translate("AuthDialog", "Password", nullptr));
        lineEdit_inputRegPass->setText(QString());
        lineEdit_inputRegPass->setPlaceholderText(QString());
        lbl_register->setText(QCoreApplication::translate("AuthDialog", "REGISTER", nullptr));
        btn_regForgotPass->setText(QCoreApplication::translate("AuthDialog", "Forgot Password?", nullptr));
#if QT_CONFIG(shortcut)
        btn_regForgotPass->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        lbl_passCriteria->setText(QCoreApplication::translate("AuthDialog", "Password criteria:", nullptr));
        lbl_passCheck_charIcon->setText(QString());
        lbl_passCheck_char_2->setText(QCoreApplication::translate("AuthDialog", "8 - 20 characters", nullptr));
        lbl_passCheck_UppLowIcon->setText(QString());
        lbl_passCheck_uppLow->setText(QCoreApplication::translate("AuthDialog", "Upper & lowercase letters", nullptr));
        lbl_passCheck_numIcon->setText(QString());
        lbl_passCheck_num->setText(QCoreApplication::translate("AuthDialog", "Number(s)", nullptr));
        btn_createAccount->setText(QCoreApplication::translate("AuthDialog", "CREATE ACCOUNT", nullptr));
        btn_switchToLogin->setText(QCoreApplication::translate("AuthDialog", "Have an account? LOG IN", nullptr));
#if QT_CONFIG(shortcut)
        btn_switchToLogin->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        lbl_mycovidrec_reg->setText(QCoreApplication::translate("AuthDialog", "MyCovidRecord", nullptr));
        lbl_nz_reg->setText(QCoreApplication::translate("AuthDialog", "New Zealand", nullptr));
        lineEdit_inputRegEmail->setText(QString());
        lineEdit_inputRegEmail->setPlaceholderText(QString());
        lbl_emailExistsErr->setText(QCoreApplication::translate("AuthDialog", "Email exists. Please enter a different email.", nullptr));
        label->setText(QString());
        checkBox_agreeTerms->setText(QCoreApplication::translate("AuthDialog", " Please agree to continue", nullptr));
        label_2->setText(QString());
        btn_nextTerms1->setText(QCoreApplication::translate("AuthDialog", "NEXT >", nullptr));
        btn_nextTerms2->setText(QCoreApplication::translate("AuthDialog", "NEXT >", nullptr));
        checkBox_agreeTerms2->setText(QCoreApplication::translate("AuthDialog", " Please agree to continue", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        btn_nextDetails->setText(QCoreApplication::translate("AuthDialog", "NEXT >", nullptr));
        label_enterDetails->setText(QCoreApplication::translate("AuthDialog", "Enter your details", nullptr));
        label_enterDetails_2->setText(QCoreApplication::translate("AuthDialog", "First name", nullptr));
        label_enterDetails_3->setText(QCoreApplication::translate("AuthDialog", "Last name", nullptr));
        label_enterDetails_4->setText(QCoreApplication::translate("AuthDialog", "Preferred name", nullptr));
        label_enterDetails_5->setText(QString());
        btn_nextDetails_2->setText(QCoreApplication::translate("AuthDialog", "NEXT >", nullptr));
        label_enterDetails_6->setText(QCoreApplication::translate("AuthDialog", "Phone (recommended)", nullptr));
        label_enterDetails_7->setText(QCoreApplication::translate("AuthDialog", "NHI number (optional)", nullptr));
        label_enterDetails_8->setText(QCoreApplication::translate("AuthDialog", "Enter your details", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_accountCreatedMsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AuthDialog: public Ui_AuthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHDIALOG_H
