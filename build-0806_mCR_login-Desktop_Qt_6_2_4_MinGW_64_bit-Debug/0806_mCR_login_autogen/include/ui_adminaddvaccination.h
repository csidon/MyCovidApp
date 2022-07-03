/********************************************************************************
** Form generated from reading UI file 'adminaddvaccination.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINADDVACCINATION_H
#define UI_ADMINADDVACCINATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminAddVaccination
{
public:

    void setupUi(QWidget *AdminAddVaccination)
    {
        if (AdminAddVaccination->objectName().isEmpty())
            AdminAddVaccination->setObjectName(QString::fromUtf8("AdminAddVaccination"));
        AdminAddVaccination->resize(400, 300);

        retranslateUi(AdminAddVaccination);

        QMetaObject::connectSlotsByName(AdminAddVaccination);
    } // setupUi

    void retranslateUi(QWidget *AdminAddVaccination)
    {
        AdminAddVaccination->setWindowTitle(QCoreApplication::translate("AdminAddVaccination", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminAddVaccination: public Ui_AdminAddVaccination {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINADDVACCINATION_H
