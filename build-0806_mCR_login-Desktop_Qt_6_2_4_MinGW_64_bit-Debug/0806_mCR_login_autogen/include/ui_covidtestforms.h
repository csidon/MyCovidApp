/********************************************************************************
** Form generated from reading UI file 'covidtestforms.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COVIDTESTFORMS_H
#define UI_COVIDTESTFORMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CovidTestForms
{
public:
    QLabel *lbl_QRRequests;
    QLabel *lbl_topBar;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_dateOfTest;
    QSpinBox *spinBox_YY;
    QSpinBox *spinBox_DD;
    QRadioButton *rBtn_testNeg;
    QFrame *frame_errSelectResult;
    QLabel *lbl_errSelectResult;
    QPushButton *pushButton;
    QRadioButton *rBtn_testPos;
    QFrame *frame_affirm;
    QCheckBox *checkBox_affirmAccuracy;
    QPlainTextEdit *plainText_NoEdit_resultsAccuracy;
    QLabel *lbl_errSelectTerms;
    QSpinBox *spinBox_MM;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_DoT_2;
    QLabel *lbl_displayTestDate;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_tR;
    QLabel *lbl_displayTestRes;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QWidget *page_3;
    QTableView *tableView_test;
    QLabel *label_visualisingUserPID;
    QPushButton *btn_backToAdminHome;

    void setupUi(QWidget *CovidTestForms)
    {
        if (CovidTestForms->objectName().isEmpty())
            CovidTestForms->setObjectName(QString::fromUtf8("CovidTestForms"));
        CovidTestForms->resize(375, 667);
        lbl_QRRequests = new QLabel(CovidTestForms);
        lbl_QRRequests->setObjectName(QString::fromUtf8("lbl_QRRequests"));
        lbl_QRRequests->setGeometry(QRect(70, 8, 261, 45));
        lbl_QRRequests->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:20px;\n"
"font-family:arial;"));
        lbl_QRRequests->setAlignment(Qt::AlignCenter);
        lbl_topBar = new QLabel(CovidTestForms);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(0, -20, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        stackedWidget = new QStackedWidget(CovidTestForms);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 375, 450));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lbl_dateOfTest = new QLabel(page);
        lbl_dateOfTest->setObjectName(QString::fromUtf8("lbl_dateOfTest"));
        lbl_dateOfTest->setGeometry(QRect(20, 36, 331, 17));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        lbl_dateOfTest->setFont(font);
        lbl_dateOfTest->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        lbl_dateOfTest->setInputMethodHints(Qt::ImhNone);
        spinBox_YY = new QSpinBox(page);
        spinBox_YY->setObjectName(QString::fromUtf8("spinBox_YY"));
        spinBox_YY->setGeometry(QRect(142, 70, 61, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        spinBox_YY->setFont(font1);
        spinBox_YY->setMinimum(21);
        spinBox_YY->setMaximum(23);
        spinBox_YY->setValue(21);
        spinBox_DD = new QSpinBox(page);
        spinBox_DD->setObjectName(QString::fromUtf8("spinBox_DD"));
        spinBox_DD->setGeometry(QRect(20, 70, 61, 30));
        spinBox_DD->setFont(font1);
        spinBox_DD->setMinimum(1);
        spinBox_DD->setMaximum(31);
        rBtn_testNeg = new QRadioButton(page);
        rBtn_testNeg->setObjectName(QString::fromUtf8("rBtn_testNeg"));
        rBtn_testNeg->setGeometry(QRect(30, 183, 191, 31));
        rBtn_testNeg->setFont(font1);
        frame_errSelectResult = new QFrame(page);
        frame_errSelectResult->setObjectName(QString::fromUtf8("frame_errSelectResult"));
        frame_errSelectResult->setGeometry(QRect(20, 120, 251, 141));
        frame_errSelectResult->setFrameShape(QFrame::StyledPanel);
        frame_errSelectResult->setFrameShadow(QFrame::Raised);
        lbl_errSelectResult = new QLabel(frame_errSelectResult);
        lbl_errSelectResult->setObjectName(QString::fromUtf8("lbl_errSelectResult"));
        lbl_errSelectResult->setGeometry(QRect(10, 110, 131, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        lbl_errSelectResult->setFont(font2);
        lbl_errSelectResult->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 410, 331, 41));
        pushButton->setFont(font2);
        rBtn_testPos = new QRadioButton(page);
        rBtn_testPos->setObjectName(QString::fromUtf8("rBtn_testPos"));
        rBtn_testPos->setGeometry(QRect(30, 137, 171, 31));
        rBtn_testPos->setFont(font1);
        frame_affirm = new QFrame(page);
        frame_affirm->setObjectName(QString::fromUtf8("frame_affirm"));
        frame_affirm->setGeometry(QRect(20, 260, 331, 141));
        frame_affirm->setStyleSheet(QString::fromUtf8(""));
        frame_affirm->setFrameShape(QFrame::Box);
        frame_affirm->setFrameShadow(QFrame::Plain);
        frame_affirm->setLineWidth(0);
        checkBox_affirmAccuracy = new QCheckBox(frame_affirm);
        checkBox_affirmAccuracy->setObjectName(QString::fromUtf8("checkBox_affirmAccuracy"));
        checkBox_affirmAccuracy->setGeometry(QRect(10, 10, 301, 25));
        checkBox_affirmAccuracy->setFont(font);
        checkBox_affirmAccuracy->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        plainText_NoEdit_resultsAccuracy = new QPlainTextEdit(frame_affirm);
        plainText_NoEdit_resultsAccuracy->setObjectName(QString::fromUtf8("plainText_NoEdit_resultsAccuracy"));
        plainText_NoEdit_resultsAccuracy->setGeometry(QRect(30, 40, 291, 91));
        plainText_NoEdit_resultsAccuracy->setFont(font2);
        plainText_NoEdit_resultsAccuracy->setStyleSheet(QString::fromUtf8(""));
        plainText_NoEdit_resultsAccuracy->setFrameShape(QFrame::NoFrame);
        plainText_NoEdit_resultsAccuracy->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainText_NoEdit_resultsAccuracy->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainText_NoEdit_resultsAccuracy->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        plainText_NoEdit_resultsAccuracy->setReadOnly(true);
        lbl_errSelectTerms = new QLabel(frame_affirm);
        lbl_errSelectTerms->setObjectName(QString::fromUtf8("lbl_errSelectTerms"));
        lbl_errSelectTerms->setGeometry(QRect(10, 120, 331, 20));
        lbl_errSelectTerms->setFont(font2);
        lbl_errSelectTerms->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        spinBox_MM = new QSpinBox(page);
        spinBox_MM->setObjectName(QString::fromUtf8("spinBox_MM"));
        spinBox_MM->setGeometry(QRect(81, 70, 61, 30));
        spinBox_MM->setFont(font1);
        spinBox_MM->setMinimum(1);
        spinBox_MM->setMaximum(12);
        stackedWidget->addWidget(page);
        lbl_dateOfTest->raise();
        spinBox_YY->raise();
        spinBox_DD->raise();
        frame_errSelectResult->raise();
        pushButton->raise();
        rBtn_testPos->raise();
        frame_affirm->raise();
        spinBox_MM->raise();
        rBtn_testNeg->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbl_DoT_2 = new QLabel(page_2);
        lbl_DoT_2->setObjectName(QString::fromUtf8("lbl_DoT_2"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        lbl_DoT_2->setFont(font4);
        lbl_DoT_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));
        lbl_DoT_2->setInputMethodHints(Qt::ImhNone);
        lbl_DoT_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lbl_DoT_2);


        verticalLayout->addLayout(horizontalLayout_5);

        lbl_displayTestDate = new QLabel(page_2);
        lbl_displayTestDate->setObjectName(QString::fromUtf8("lbl_displayTestDate"));
        lbl_displayTestDate->setFont(font);
        lbl_displayTestDate->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        lbl_displayTestDate->setInputMethodHints(Qt::ImhNone);
        lbl_displayTestDate->setAlignment(Qt::AlignCenter);
        lbl_displayTestDate->setWordWrap(true);

        verticalLayout->addWidget(lbl_displayTestDate);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lbl_tR = new QLabel(page_2);
        lbl_tR->setObjectName(QString::fromUtf8("lbl_tR"));
        lbl_tR->setFont(font4);
        lbl_tR->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));
        lbl_tR->setInputMethodHints(Qt::ImhNone);
        lbl_tR->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lbl_tR);


        verticalLayout->addLayout(horizontalLayout_6);

        lbl_displayTestRes = new QLabel(page_2);
        lbl_displayTestRes->setObjectName(QString::fromUtf8("lbl_displayTestRes"));
        lbl_displayTestRes->setFont(font);
        lbl_displayTestRes->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        lbl_displayTestRes->setInputMethodHints(Qt::ImhNone);
        lbl_displayTestRes->setAlignment(Qt::AlignCenter);
        lbl_displayTestRes->setWordWrap(true);

        verticalLayout->addWidget(lbl_displayTestRes);

        verticalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);

        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(10);
        label_3->setFont(font5);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        label_3->setIndent(-1);

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font5);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 41));

        verticalLayout->addWidget(pushButton_2);


        verticalLayout_3->addLayout(verticalLayout);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        tableView_test = new QTableView(page_3);
        tableView_test->setObjectName(QString::fromUtf8("tableView_test"));
        tableView_test->setGeometry(QRect(20, 110, 331, 381));
        label_visualisingUserPID = new QLabel(page_3);
        label_visualisingUserPID->setObjectName(QString::fromUtf8("label_visualisingUserPID"));
        label_visualisingUserPID->setGeometry(QRect(30, 60, 331, 20));
        stackedWidget->addWidget(page_3);
        btn_backToAdminHome = new QPushButton(CovidTestForms);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(2, -5, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_topBar->raise();
        lbl_QRRequests->raise();
        btn_backToAdminHome->raise();
        stackedWidget->raise();

        retranslateUi(CovidTestForms);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CovidTestForms);
    } // setupUi

    void retranslateUi(QWidget *CovidTestForms)
    {
        CovidTestForms->setWindowTitle(QCoreApplication::translate("CovidTestForms", "Form", nullptr));
        lbl_QRRequests->setText(QCoreApplication::translate("CovidTestForms", "Add Test Result", nullptr));
        lbl_topBar->setText(QString());
        lbl_dateOfTest->setText(QCoreApplication::translate("CovidTestForms", "Date of test (DD/MM/YY)", nullptr));
        rBtn_testNeg->setText(QCoreApplication::translate("CovidTestForms", "  Negative", nullptr));
        lbl_errSelectResult->setText(QCoreApplication::translate("CovidTestForms", "Please select one", nullptr));
        pushButton->setText(QCoreApplication::translate("CovidTestForms", "SUBMIT", nullptr));
        rBtn_testPos->setText(QCoreApplication::translate("CovidTestForms", "  Positive", nullptr));
        checkBox_affirmAccuracy->setText(QCoreApplication::translate("CovidTestForms", "I confirm my results are accurate", nullptr));
        plainText_NoEdit_resultsAccuracy->setPlainText(QCoreApplication::translate("CovidTestForms", "These self-tested results are accurate to the best of my knowledge.\n"
"I understand that a false declaration can incur a fine of no more than NZ$5,000.", nullptr));
        lbl_errSelectTerms->setText(QCoreApplication::translate("CovidTestForms", "Please confirm that your test results are accurate", nullptr));
        label_4->setText(QCoreApplication::translate("CovidTestForms", "New vaccine data added", nullptr));
        label->setText(QCoreApplication::translate("CovidTestForms", "Thank you for reporting your test results.", nullptr));
        lbl_DoT_2->setText(QCoreApplication::translate("CovidTestForms", "Date of test:", nullptr));
        lbl_displayTestDate->setText(QCoreApplication::translate("CovidTestForms", "[Test date]", nullptr));
        lbl_tR->setText(QCoreApplication::translate("CovidTestForms", "Test result: ", nullptr));
        lbl_displayTestRes->setText(QCoreApplication::translate("CovidTestForms", "[Test result]", nullptr));
        label_2->setText(QCoreApplication::translate("CovidTestForms", "What to do next", nullptr));
        label_3->setText(QCoreApplication::translate("CovidTestForms", "Monitor any COVID-19 symptoms and if they get worse, call a healthcare provider or Healthline on 0800 358 5453", nullptr));
        label_5->setText(QCoreApplication::translate("CovidTestForms", "Continue to follow current health advice ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CovidTestForms", "BACK TO HOMEPAGE", nullptr));
        label_visualisingUserPID->setText(QCoreApplication::translate("CovidTestForms", "Hidden page for visualising db", nullptr));
        btn_backToAdminHome->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CovidTestForms: public Ui_CovidTestForms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COVIDTESTFORMS_H
