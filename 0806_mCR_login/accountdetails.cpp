#include "accountdetails.h"
#include "handlecsv.h"
#include "ui_accountdetails.h"
#include "useraccount.h"

int AccountDetails::getLoggedInUserID()
{
    return loggedInUserID;
}

void AccountDetails::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}

void AccountDetails::setDisplay()
{
    HandleCSV readUser;
    UserAccount loggedInUser = readUser.getUserAccount(loggedInUserID);
    ui->lbl_userFName->setText(loggedInUser.getUserFirstName());
    ui->lbl_userLName->setText(loggedInUser.getUserLastName());
    ui->lbl_userPName->setText(loggedInUser.getUserPreferredName());
    ui->lbl_userEmail->setText(loggedInUser.getUserEmail());
    ui->lbl_userNHI->setText(loggedInUser.getUserNHINumber());
    ui->lbl_userPhone->setText(QString::number(loggedInUser.getUserPhoneNumber()));
}

AccountDetails::AccountDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountDetails)
{
    ui->setupUi(this);
}

AccountDetails::~AccountDetails()
{
    delete ui;
}

void AccountDetails::on_btn_backToHome_clicked()
{
    close();
}

