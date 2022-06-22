#ifndef COVIDTESTFORMS_H
#define COVIDTESTFORMS_H

#include <QWidget>
#include <QDate>
#include "test.h"
#include <QString>
#include "handlecsv.h"
#include "useraccount.h"
#include <QStandardItemModel>
#include <QStandardPaths>


namespace Ui {
class CovidTestForms;
}

class CovidTestForms : public QWidget
{
    Q_OBJECT

public:
    explicit CovidTestForms(QWidget *parent = nullptr);
    ~CovidTestForms();
    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);
//    void writeToTestCSV(int uid, QString testDate, bool testRes, QString testRecDate);
    void updatePID(int uid, UserAccount updateUser);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_backToAdminHome_clicked();

private:
    int loggedInUserID;
    Ui::CovidTestForms *ui;
};

#endif // COVIDTESTFORMS_H
