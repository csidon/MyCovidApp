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


void AdminUserSelected::on_btn_testHistoryView_clicked()
{
    testHistoryWindow.setLoggedInUser(selectedUserID);
    testHistoryWindow.setDisplayedTests();
    testHistoryWindow.show();
}


void AdminUserSelected::on_btn_vaxHistoryView_clicked()
{
    vaxHistoryWindow.setLoggedInUser(selectedUserID);
    vaxHistoryWindow.setDisplayedDoses();
    vaxHistoryWindow.show();
}


void AdminUserSelected::on_btn_accountDetailsView_clicked()
{
    detailsWindow.setLoggedInUserID(selectedUserID);
    detailsWindow.setDisplay();
    detailsWindow.show();
}

