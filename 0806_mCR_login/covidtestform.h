#ifndef COVIDTESTFORM_H
#define COVIDTESTFORM_H

#include <QWidget>
#include <QDate>
#include "test.h"
#include <QString>
#include "handlecsv.h"

namespace Ui {
class CovidTestForm;
}

class CovidTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit CovidTestForm(QWidget *parent = nullptr);
    ~CovidTestForm();

    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);
    void writeToTestCSV(int uid, QString testDate, bool testRes);
    //, QString testRecDate


private slots:
    void on_pushButton_clicked();


private:
    int loggedInUserID;
    Ui::CovidTestForm *ui;
};

#endif // COVIDTESTFORM_H
