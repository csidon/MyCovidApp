#include "editdetails.h"
#include "handlecsv.h"
#include "ui_editdetails.h"
#include "useraccount.h"

int editDetails::getSelectedUserID()
{
    return selectedUserID;
}

void editDetails::setSelectedUserID(int newSelectedUserID)
{
    selectedUserID = newSelectedUserID;
}

void editDetails::displayCurrentDetails()
{
    HandleCSV getDetails;
    UserAccount selectedUser = getDetails.getUserAccount(getSelectedUserID());
    ui->lineEdit_firstName->setText(selectedUser.getUserFirstName());
    ui->lineEdit_lastName->setText(selectedUser.getUserLastName());
    ui->lineEdit_preferredName->setText(selectedUser.getUserPreferredName());
    ui->lineEdit_email->setText(selectedUser.getUserEmail());
    ui->lineEdit_NHI->setText(selectedUser.getUserNHINumber());
    ui->lineEdit_phone->setText(QString::number(selectedUser.getUserPhoneNumber()));
}

editDetails::editDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editDetails)
{
    ui->setupUi(this);
}

editDetails::~editDetails()
{
    delete ui;
}

void editDetails::on_btn_submit_clicked()
{
    HandleCSV updateUser;
    UserAccount updatedUser = updateUser.getUserAccount(getSelectedUserID());
    updatedUser.setUserFirstName(ui->lineEdit_firstName->text());
    updatedUser.setUserLastName(ui->lineEdit_lastName->text());
    updatedUser.setUserPreferredName(ui->lineEdit_preferredName->text());
    updatedUser.setUserEmail(ui->lineEdit_email->text());
    updatedUser.setUserNHINumber(ui->lineEdit_NHI->text());
    updatedUser.setUserPhoneNumber(ui->lineEdit_phone->text().toInt());
    updateUser.updatePID(updatedUser);
}

