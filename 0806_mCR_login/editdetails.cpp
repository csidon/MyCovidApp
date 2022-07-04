#include "editdetails.h"
#include "ui_editdetails.h"

//Getter
int editDetails::getSelectedUserID()
{
    return selectedUserID;
}
//Setter
void editDetails::setSelectedUserID(int newSelectedUserID)
{
    selectedUserID = newSelectedUserID;
}

//Display details
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

//Taks current text and saves it to PID
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
    //Notify success
    QMessageBox::information(this, "User updated", "New info saved to server");
    close();//Return to menu
}


void editDetails::on_btn_backToHome_clicked()
{
    close();
}

