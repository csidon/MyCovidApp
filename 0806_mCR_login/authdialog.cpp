#include "authdialog.h"
#include "ui_authdialog.h"
#include <QMessageBox>

AuthDialog::AuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);
}

AuthDialog::~AuthDialog()
{
    delete ui;
}

void AuthDialog::on_btn_login_clicked()
{
    QString username = ui->lineEdit_inputEmail->text();
    QString pswd = ui->lineEdit_inputPass->text();

    if (username == "darth.vader@betrayal.com" && pswd == "I'm Your Father")
    {
        this->hide();
        QMessageBox::information(this, "Login", "Correct username and password.\nAccess to Admin Panel granted");
        this->setResult(QDialog::Accepted);

        // ***** NEED TO FIND A WAY TO SETWINDOW TO ADMIN PANEL *******
    }
    else if (username == "luke@skywalker.com" && pswd == "uh oh")
    {
        this->hide();
        QMessageBox::information(this, "Login", "Correct username and password.\nWelcome to MyCovidRecord");
        this->setResult(QDialog::Accepted);
    }
    else
    {
        QMessageBox::warning(this, "Login Invalid", "Incorrect Username and Password - Please try again");
        this->setResult(QDialog::Rejected);
    }

}

