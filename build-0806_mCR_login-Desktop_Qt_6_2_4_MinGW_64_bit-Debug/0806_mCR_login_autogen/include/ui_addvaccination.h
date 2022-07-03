/********************************************************************************
** Form generated from reading UI file 'addvaccination.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVACCINATION_H
#define UI_ADDVACCINATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddVaccination
{
public:
    QLabel *lbl_topBar;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *lbl_dateOfTest;
    QSpinBox *spinBox_YY;
    QSpinBox *spinBox_DD;
    QPushButton *pushButton;
    QSpinBox *spinBox_MM;
    QComboBox *comboBox;
    QLabel *label_6;
    QWidget *page_2;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_DoT;
    QLabel *lbl_displayTestDate;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_tr;
    QLabel *lbl_displayTestRes;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_3;
    QTableView *tableView_test;
    QLabel *label_visualisingUserPID;
    QLabel *lbl_QRRequests_2;
    QPushButton *btn_backToAdminHome;

    void setupUi(QWidget *AddVaccination)
    {
        if (AddVaccination->objectName().isEmpty())
            AddVaccination->setObjectName(QString::fromUtf8("AddVaccination"));
        AddVaccination->resize(375, 667);
        lbl_topBar = new QLabel(AddVaccination);
        lbl_topBar->setObjectName(QString::fromUtf8("lbl_topBar"));
        lbl_topBar->setGeometry(QRect(0, -20, 381, 91));
        lbl_topBar->setPixmap(QPixmap(QString::fromUtf8(":/images/topBar.png")));
        stackedWidget = new QStackedWidget(AddVaccination);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 470, 476));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lbl_dateOfTest = new QLabel(page);
        lbl_dateOfTest->setObjectName(QString::fromUtf8("lbl_dateOfTest"));
        lbl_dateOfTest->setGeometry(QRect(24, 40, 331, 17));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(9);
        font.setBold(false);
        lbl_dateOfTest->setFont(font);
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
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 265, 330, 50));
        pushButton->setMinimumSize(QSize(0, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        pushButton->setFont(font2);
        spinBox_MM = new QSpinBox(page);
        spinBox_MM->setObjectName(QString::fromUtf8("spinBox_MM"));
        spinBox_MM->setGeometry(QRect(81, 70, 61, 30));
        spinBox_MM->setFont(font1);
        spinBox_MM->setMinimum(1);
        spinBox_MM->setMaximum(12);
        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(21, 170, 330, 50));
        comboBox->setMinimumSize(QSize(330, 41));
        comboBox->setFont(font1);
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(25, 136, 133, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        formLayout = new QFormLayout(page_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalSpacer_3 = new QSpacerItem(320, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_DoT = new QLabel(page_2);
        lbl_DoT->setObjectName(QString::fromUtf8("lbl_DoT"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        lbl_DoT->setFont(font3);
        lbl_DoT->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Arial\";"));
        lbl_DoT->setInputMethodHints(Qt::ImhNone);

        horizontalLayout->addWidget(lbl_DoT);

        lbl_displayTestDate = new QLabel(page_2);
        lbl_displayTestDate->setObjectName(QString::fromUtf8("lbl_displayTestDate"));
        lbl_displayTestDate->setFont(font3);
        lbl_displayTestDate->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Arial\";"));
        lbl_displayTestDate->setInputMethodHints(Qt::ImhNone);

        horizontalLayout->addWidget(lbl_displayTestDate);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbl_tr = new QLabel(page_2);
        lbl_tr->setObjectName(QString::fromUtf8("lbl_tr"));
        lbl_tr->setFont(font3);
        lbl_tr->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Arial\";"));
        lbl_tr->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_2->addWidget(lbl_tr);

        lbl_displayTestRes = new QLabel(page_2);
        lbl_displayTestRes->setObjectName(QString::fromUtf8("lbl_displayTestRes"));
        lbl_displayTestRes->setFont(font3);
        lbl_displayTestRes->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Arial\";"));
        lbl_displayTestRes->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_2->addWidget(lbl_displayTestRes);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_4);

        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, label);

        verticalSpacer_5 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(5, QFormLayout::LabelRole, verticalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setItalic(false);
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Arial\";"));

        verticalLayout->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setItalic(false);
        label_3->setFont(font6);
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font6);
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(label_5);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 41));

        verticalLayout->addWidget(pushButton_2);


        formLayout->setLayout(6, QFormLayout::SpanningRole, verticalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::LabelRole, verticalSpacer_6);

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
        lbl_QRRequests_2 = new QLabel(AddVaccination);
        lbl_QRRequests_2->setObjectName(QString::fromUtf8("lbl_QRRequests_2"));
        lbl_QRRequests_2->setGeometry(QRect(70, -2, 301, 61));
        lbl_QRRequests_2->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:20px;\n"
"font-family:arial;"));
        lbl_QRRequests_2->setAlignment(Qt::AlignCenter);
        btn_backToAdminHome = new QPushButton(AddVaccination);
        btn_backToAdminHome->setObjectName(QString::fromUtf8("btn_backToAdminHome"));
        btn_backToAdminHome->setGeometry(QRect(0, -2, 71, 61));
        btn_backToAdminHome->setStyleSheet(QString::fromUtf8("image: url(:/images/backArrow2.png);\n"
"background-color: rgba(255, 255, 255, 0);"));

        retranslateUi(AddVaccination);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddVaccination);
    } // setupUi

    void retranslateUi(QWidget *AddVaccination)
    {
        AddVaccination->setWindowTitle(QCoreApplication::translate("AddVaccination", "Form", nullptr));
        lbl_topBar->setText(QString());
        lbl_dateOfTest->setText(QCoreApplication::translate("AddVaccination", "Date of vaccination (DD/MM/YY)", nullptr));
        pushButton->setText(QCoreApplication::translate("AddVaccination", "SUBMIT", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AddVaccination", "Pfizer-BioNTech", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AddVaccination", "GlaxoSmithKline", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AddVaccination", "Novavax", nullptr));

        label_6->setText(QCoreApplication::translate("AddVaccination", "Select Manufacturer", nullptr));
        lbl_DoT->setText(QCoreApplication::translate("AddVaccination", "Date of test: ", nullptr));
        lbl_displayTestDate->setText(QCoreApplication::translate("AddVaccination", "[Test date]", nullptr));
        lbl_tr->setText(QCoreApplication::translate("AddVaccination", "Result: ", nullptr));
        lbl_displayTestRes->setText(QCoreApplication::translate("AddVaccination", "[Test result]", nullptr));
        label->setText(QCoreApplication::translate("AddVaccination", "Thank you for reporting your test results.", nullptr));
        label_2->setText(QCoreApplication::translate("AddVaccination", "What to do next", nullptr));
        label_3->setText(QCoreApplication::translate("AddVaccination", " - Monitor any COVID-19 symptoms and if they get worse,", nullptr));
        label_4->setText(QCoreApplication::translate("AddVaccination", "   call a healthcare provider or Healthline on 0800 358 5453", nullptr));
        label_5->setText(QCoreApplication::translate("AddVaccination", " - Continue to follow current health advice.", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddVaccination", "Back to homepage", nullptr));
        label_visualisingUserPID->setText(QCoreApplication::translate("AddVaccination", "Hidden page for visualising db", nullptr));
        lbl_QRRequests_2->setText(QCoreApplication::translate("AddVaccination", "Add Vaccination", nullptr));
        btn_backToAdminHome->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddVaccination: public Ui_AddVaccination {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVACCINATION_H
