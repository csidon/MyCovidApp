#ifndef ADMINUSERSELECTED_H
#define ADMINUSERSELECTED_H

#include "covidtestforms.h"
#include "editdetails.h"
#include "euhistory.h"
#include "addvaccination.h"
#include <QWidget>

namespace Ui {
class AdminUserSelected;
}

class AdminUserSelected : public QWidget
{
    Q_OBJECT
private:
    int selectedUserID;
    editDetails editDetailsWindow;
    EUHistory *euHistoryWindow;
    CovidTestForms *covidTestWindow;
    AddVaccination *addVaxWindow;


public:
    explicit AdminUserSelected(QWidget *parent = nullptr);
    ~AdminUserSelected();

    int getSelectedUserID();
    void setSelectedUserID(int newSelectedUserID);
    void setTitleText();

private slots:
    void on_btn_backToSearch_clicked();

    void on_btn_accountDetailsView_clicked();

    void on_btn_accountDetailsEdit_clicked();

    void on_btn_testAdd_clicked();

    void on_btn_vaxAdd_clicked();

private:
    Ui::AdminUserSelected *ui;
};

#endif // ADMINUSERSELECTED_H
