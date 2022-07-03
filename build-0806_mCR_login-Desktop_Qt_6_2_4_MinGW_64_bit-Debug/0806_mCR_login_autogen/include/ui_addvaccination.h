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
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_DoV;
    QLabel *lbl_displayVaxDate;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_dM;
    QLabel *lbl_displayVaxManuf;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_2;
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
        stackedWidget->setGeometry(QRect(0, 60, 375, 476));
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
        comboBox->setGeometry(QRect(21, 170, 330, 41));
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
        verticalSpacer_3 = new QSpacerItem(320, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer_3);

        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, label);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_DoV = new QLabel(page_2);
        lbl_DoV->setObjectName(QString::fromUtf8("lbl_DoV"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        lbl_DoV->setFont(font4);
        lbl_DoV->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));
        lbl_DoV->setInputMethodHints(Qt::ImhNone);
        lbl_DoV->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbl_DoV);


        verticalLayout->addLayout(horizontalLayout);

        lbl_displayVaxDate = new QLabel(page_2);
        lbl_displayVaxDate->setObjectName(QString::fromUtf8("lbl_displayVaxDate"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        lbl_displayVaxDate->setFont(font5);
        lbl_displayVaxDate->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        lbl_displayVaxDate->setInputMethodHints(Qt::ImhNone);
        lbl_displayVaxDate->setAlignment(Qt::AlignCenter);
        lbl_displayVaxDate->setWordWrap(true);

        verticalLayout->addWidget(lbl_displayVaxDate);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbl_dM = new QLabel(page_2);
        lbl_dM->setObjectName(QString::fromUtf8("lbl_dM"));
        lbl_dM->setFont(font4);
        lbl_dM->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));
        lbl_dM->setInputMethodHints(Qt::ImhNone);
        lbl_dM->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbl_dM);


        verticalLayout->addLayout(horizontalLayout_2);

        lbl_displayVaxManuf = new QLabel(page_2);
        lbl_displayVaxManuf->setObjectName(QString::fromUtf8("lbl_displayVaxManuf"));
        lbl_displayVaxManuf->setFont(font5);
        lbl_displayVaxManuf->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        lbl_displayVaxManuf->setInputMethodHints(Qt::ImhNone);
        lbl_displayVaxManuf->setAlignment(Qt::AlignCenter);
        lbl_displayVaxManuf->setWordWrap(true);

        verticalLayout->addWidget(lbl_displayVaxManuf);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 41));

        verticalLayout->addWidget(pushButton_2);


        formLayout->setLayout(4, QFormLayout::SpanningRole, verticalLayout);

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
        lbl_QRRequests_2->setGeometry(QRect(70, -2, 251, 61));
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
        label->setText(QCoreApplication::translate("AddVaccination", "New vaccine data added", nullptr));
        lbl_DoV->setText(QCoreApplication::translate("AddVaccination", "Date vaccinated:", nullptr));
        lbl_displayVaxDate->setText(QCoreApplication::translate("AddVaccination", "[Test date]", nullptr));
        lbl_dM->setText(QCoreApplication::translate("AddVaccination", "Manufacturer: ", nullptr));
        lbl_displayVaxManuf->setText(QCoreApplication::translate("AddVaccination", "[Test result]", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddVaccination", "BACK TO HOMEPAGE", nullptr));
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
