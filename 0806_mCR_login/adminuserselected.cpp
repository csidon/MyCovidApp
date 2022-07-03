#include "adminuserselected.h"
#include "handlecsv.h"
#include "ui_adminuserselected.h"
#include "useraccount.h"

int AdminUserSelected::getSelectedUserID()
{
    return selectedUserID;
}

void AdminUserSelected::setSelectedUserID(int newSelectedUserID)
{
    selectedUserID = newSelectedUserID;
}

void AdminUserSelected::setTitleText()
{
    HandleCSV readUser;
    UserAccount selectedUser = readUser.getUserAccount(getSelectedUserID());
    ui->lbl_usersName->setText(selectedUser.getUserFirstName() + " " + selectedUser.getUserLastName());
}

AdminUserSelected::AdminUserSelected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminUserSelected)
{
    ui->setupUi(this);
}

AdminUserSelected::~AdminUserSelected()
{
    delete ui;
}

void AdminUserSelected::on_btn_backToSearch_clicked()
{
    close();
}



void AdminUserSelected::on_btn_accountDetailsView_clicked()
{
    euHistoryWindow = new EUHistory(nullptr, selectedUserID);
    euHistoryWindow->show();
}


void AdminUserSelected::on_btn_accountDetailsEdit_clicked()
{
    editDetailsWindow.setSelectedUserID(selectedUserID);
    editDetailsWindow.displayCurrentDetails();
    editDetailsWindow.show();
}


void AdminUserSelected::on_btn_testAdd_clicked()
{
    covidTestWindow = new CovidTestForms(nullptr, selectedUserID);
    covidTestWindow->show();
}


void AdminUserSelected::on_btn_vaxAdd_clicked()
{
    addVaxWindow = new AddVaccination(nullptr, selectedUserID);
    addVaxWindow->show();
}

