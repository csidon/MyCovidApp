/********************************************************************************
** Form generated from reading UI file 'covidtestform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COVIDTESTFORM_H
#define UI_COVIDTESTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CovidTestForm
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_topBar;
    QPushButton *btn_backToAdminHome;
    QLabel *lbl_QRRequests;
    QWidget *page_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QLabel *lbl_email;
    QRadioButton *rBtn_testPos;
    QRadioButton *rBtn_testNeg;
    QPushButton *pushButton;
    QFrame *frame_affirm;
    QCheckBox *checkBox_affirmAccuracy;
    QPlainTextEdit *plainText_NoEdit_resultsAccuracy;
    QLabel *lbl_errSelectTerms;
    QSpinBox *spinBox_YY;
    QSpinBox *spinBox_MM;
    QSpinBox *spinBox_DD;
    QFrame *frame_errSelectResult;
    QLabel *lbl_errSelectResult;
    QWidget *page_4;

    void setupUi(QWidget *CovidTestForm)
    {
        if (CovidTestForm->objectName().isEmpty())
            CovidTestForm->setObjectName(QString::fromUtf8("CovidTestForm"));
        CovidTestForm->resize(375, 667);
        stackedWidget = new QStackedWidget(CovidTestForm);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 375, 61));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lbl_topBar = new QLabel(page);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(-2, -15, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        btn_backToAdminHome = new QPushButton(page);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, 0, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lbl_QRRequests = new QLabel(page);
        lbl_QRRequests->setObjectName(QString::fromUtf8("lbl_QRRequests"));
        lbl_QRRequests->setGeometry(QRect(70, 0, 301, 61));
        lbl_QRRequests->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:28px;\n"
"font-family:arial;"));
        lbl_QRRequests->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        stackedWidget_2 = new QStackedWidget(CovidTestForm);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 60, 371, 601));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        lbl_email = new QLabel(page_3);
        lbl_email->setObjectName(QString::fromUtf8("lbl_email"));
        lbl_email->setGeometry(QRect(20, 36, 331, 17));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(9);
        font.setBold(false);
        lbl_email->setFont(font);
        lbl_email->setInputMethodHints(Qt::ImhNone);
        rBtn_testPos = new QRadioButton(page_3);
        rBtn_testPos->setObjectName(QString::fromUtf8("rBtn_testPos"));
        rBtn_testPos->setGeometry(QRect(30, 137, 171, 26));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        rBtn_testPos->setFont(font1);
        rBtn_testNeg = new QRadioButton(page_3);
        rBtn_testNeg->setObjectName(QString::fromUtf8("rBtn_testNeg"));
        rBtn_testNeg->setGeometry(QRect(30, 183, 161, 20));
        rBtn_testNeg->setFont(font1);
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 410, 331, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        pushButton->setFont(font2);
        frame_affirm = new QFrame(page_3);
        frame_affirm->setObjectName(QString::fromUtf8("frame_affirm"));
        frame_affirm->setGeometry(QRect(20, 260, 331, 141));
        frame_affirm->setStyleSheet(QString::fromUtf8(""));
        frame_affirm->setFrameShape(QFrame::Box);
        frame_affirm->setFrameShadow(QFrame::Plain);
        frame_affirm->setLineWidth(0);
        checkBox_affirmAccuracy = new QCheckBox(frame_affirm);
        checkBox_affirmAccuracy->setObjectName(QString::fromUtf8("checkBox_affirmAccuracy"));
        checkBox_affirmAccuracy->setGeometry(QRect(10, 10, 301, 25));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(11);
        font3.setBold(true);
        checkBox_affirmAccuracy->setFont(font3);
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
        spinBox_YY = new QSpinBox(page_3);
        spinBox_YY->setObjectName(QString::fromUtf8("spinBox_YY"));
        spinBox_YY->setGeometry(QRect(142, 70, 61, 30));
        spinBox_YY->setFont(font1);
        spinBox_YY->setMinimum(21);
        spinBox_YY->setMaximum(23);
        spinBox_YY->setValue(21);
        spinBox_MM = new QSpinBox(page_3);
        spinBox_MM->setObjectName(QString::fromUtf8("spinBox_MM"));
        spinBox_MM->setGeometry(QRect(81, 70, 61, 30));
        spinBox_MM->setFont(font1);
        spinBox_MM->setMinimum(1);
        spinBox_MM->setMaximum(12);
        spinBox_DD = new QSpinBox(page_3);
        spinBox_DD->setObjectName(QString::fromUtf8("spinBox_DD"));
        spinBox_DD->setGeometry(QRect(20, 70, 61, 30));
        spinBox_DD->setFont(font1);
        spinBox_DD->setMinimum(1);
        spinBox_DD->setMaximum(31);
        frame_errSelectResult = new QFrame(page_3);
        frame_errSelectResult->setObjectName(QString::fromUtf8("frame_errSelectResult"));
        frame_errSelectResult->setGeometry(QRect(20, 120, 191, 121));
        frame_errSelectResult->setFrameShape(QFrame::StyledPanel);
        frame_errSelectResult->setFrameShadow(QFrame::Raised);
        lbl_errSelectResult = new QLabel(frame_errSelectResult);
        lbl_errSelectResult->setObjectName(QString::fromUtf8("lbl_errSelectResult"));
        lbl_errSelectResult->setGeometry(QRect(10, 98, 131, 20));
        lbl_errSelectResult->setFont(font2);
        lbl_errSelectResult->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        stackedWidget_2->addWidget(page_3);
        frame_errSelectResult->raise();
        lbl_email->raise();
        rBtn_testPos->raise();
        rBtn_testNeg->raise();
        pushButton->raise();
        frame_affirm->raise();
        spinBox_YY->raise();
        spinBox_MM->raise();
        spinBox_DD->raise();
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_2->addWidget(page_4);

        retranslateUi(CovidTestForm);

        QMetaObject::connectSlotsByName(CovidTestForm);
    } // setupUi

    void retranslateUi(QWidget *CovidTestForm)
    {
        CovidTestForm->setWindowTitle(QCoreApplication::translate("CovidTestForm", "Form", nullptr));
        lbl_topBar->setText(QString());
        btn_backToAdminHome->setText(QString());
        lbl_QRRequests->setText(QCoreApplication::translate("CovidTestForm", "Add Test Result", nullptr));
        lbl_email->setText(QCoreApplication::translate("CovidTestForm", "Date of test (DD/MM/YY)", nullptr));
        rBtn_testPos->setText(QCoreApplication::translate("CovidTestForm", "  Positive", nullptr));
        rBtn_testNeg->setText(QCoreApplication::translate("CovidTestForm", "  Negative", nullptr));
        pushButton->setText(QCoreApplication::translate("CovidTestForm", "SUBMIT", nullptr));
        checkBox_affirmAccuracy->setText(QCoreApplication::translate("CovidTestForm", "I confirm my results are accurate", nullptr));
        plainText_NoEdit_resultsAccuracy->setPlainText(QCoreApplication::translate("CovidTestForm", "These self-tested results are accurate to the best of my knowledge.\n"
"I understand that a false declaration can incur a fine of no more than NZ$5,000.", nullptr));
        lbl_errSelectTerms->setText(QCoreApplication::translate("CovidTestForm", "Please confirm that your test results are accurate", nullptr));
        lbl_errSelectResult->setText(QCoreApplication::translate("CovidTestForm", "Please select one", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CovidTestForm: public Ui_CovidTestForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COVIDTESTFORM_H
