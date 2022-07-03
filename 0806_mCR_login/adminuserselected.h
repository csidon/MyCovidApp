#ifndef ADMINUSERSELECTED_H
#define ADMINUSERSELECTED_H

#include "accountdetails.h"
#include "adminaddvaccination.h"
#include "editdetails.h"
#include "testhistory.h"
#include "vaccinehistory.h"
#include <QWidget>

namespace Ui {
class AdminUserSelected;
}

class AdminUserSelected : public QWidget
{
    Q_OBJECT
private:
    int selectedUserID;
    VaccineHistory vaxHistoryWindow;
    TestHistory testHistoryWindow;
    AccountDetails detailsWindow;
    editDetails editDetailsWindow;
    AdminAddVaccination addVaxWindow;

public:
    explicit AdminUserSelected(QWidget *parent = nullptr);
    ~AdminUserSelected();

    int getSelectedUserID();
    void setSelectedUserID(int newSelectedUserID);
    void setTitleText();

private slots:
    void on_btn_backToSearch_clicked();

    void on_btn_testHistoryView_clicked();

    void on_btn_vaxHistoryView_clicked();

    void on_btn_accountDetailsView_clicked();

    void on_btn_accountDetailsEdit_clicked();

private:
    Ui::AdminUserSelected *ui;
};

#endif // ADMINUSERSELECTED_H
