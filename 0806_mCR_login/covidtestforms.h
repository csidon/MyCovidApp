#ifndef COVIDTESTFORMS_H
#define COVIDTESTFORMS_H

#include <QWidget>
#include <QDate>
#include <QString>
#include <QStandardItemModel>
#include <QStandardPaths>

#include "handlecsv.h"
#include "useraccount.h"
#include "test.h"

namespace Ui {
class CovidTestForms;
}

class CovidTestForms : public QWidget
{
    Q_OBJECT
private:
    int loggedInUserID;
    Ui::CovidTestForms *ui;
public:
    explicit CovidTestForms(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~CovidTestForms();
    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_backToAdminHome_clicked();


};

#endif // COVIDTESTFORMS_H
