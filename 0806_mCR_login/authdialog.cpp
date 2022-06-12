#include "authdialog.h"
#include "ui_authdialog.h"

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

int AuthDialog::authUser(QString usrn, QString pass, QString dbName)    // Note db = dbName, not db's file path
{
    HandleCSV checkUser;
    if (usrn == "darth.vader@betrayal.com" && pass == "I'm Your Father")
    {
        return 42;      // User is immediately authenticated as admin
    }
    // Getting the headerIndex for different headers
    int passHeaderIndex = checkUser.returnHeaderIndex(dbName,"userPassword");
    int uidHeaderIndex = checkUser.returnHeaderIndex(dbName,"userIDNumber");

    // Getting all values in the "userEmail" column and storing it in a QStringList
    QStringList allUserEmailData = checkUser.getColData("userEmail", dbName);

    // Searching allUserEmailData in database for specified username
    // if username is found, store the row it was found in rowIndex
    // rowIndex will return -1 if username is not found
    int rowIndex = -1;

    rowIndex = checkUser.rowIndexOfCellMatchingSearch(allUserEmailData,usrn);
    if (rowIndex >=0)
    {
        // If username is found, check if password matches username
        // Getting the password for found username
        QString retrievedPass = checkUser.getCellValue(dbName,passHeaderIndex,rowIndex);
        if (retrievedPass == pass)
        {
            // if the retrieved password for that username matches the password entered
            // Find the UID for that user who signed in
            // Return that UID
            int uid = checkUser.getCellValue(dbName,uidHeaderIndex,rowIndex).toInt();
            return uid;
        }
    }

    // returns UID = 42 if admin, the rand UID assigne if auth pass & eu logged in,
    // and -1 if auth fail
}

void AuthDialog::on_btn_login_clicked()
{
    QString username = ui->lineEdit_inputEmail->text();
    QString pswd = ui->lineEdit_inputPass->text();

    int loginSuccessUID = authUser(username, pswd, "dbPID"); // returns 0, 1, or 2 (admin)
    // Note: dbPID is mapped to appropriate filepath in handleCSV.cpp

    if (loginSuccessUID == 42)      // Credentials belong to admin
    {
        this->hide();
        QMessageBox::information(this, "Login", "Correct username and password.\nAccess to Admin Panel granted");
        this->setResult(QDialog::Accepted);

        // Return userID 42 (reserved for admin)
        // userID 42 will SETWINDOW TO ADMIN PANEL *******
        // i.e. ui->invisibleLabelOnAdminPanel->setText("userID")
    }
    else if (loginSuccessUID > 0)     // End User recognised and authenticated
    {
        this->hide();
        QMessageBox::information(this, "Login", "Correct username and password.\nWelcome to MyCovidRecord");
        this->setResult(QDialog::Accepted);

        // Set UID in ui->invisibleLabelOnEU->setText()
    }
    else        // Username||password not found in database
    {
        QMessageBox::warning(this, "Login Invalid", "Incorrect Username and Password - Please try again");
        this->setResult(QDialog::Rejected);
    }
}



//    if (username == "darth.vader@betrayal.com" && pswd == "I'm Your Father")
//    {
//        this->hide();
//        QMessageBox::information(this, "Login", "Correct username and password.\nAccess to Admin Panel granted");
//        this->setResult(QDialog::Accepted);

//        // ***** NEED TO FIND A WAY TO SETWINDOW TO ADMIN PANEL *******
//    }
//    else if (username == "luke@skywalker.com" && pswd == "uh oh")
//    {
//        this->hide();
//        QMessageBox::information(this, "Login", "Correct username and password.\nWelcome to MyCovidRecord");
//        this->setResult(QDialog::Accepted);
//    }
//    else
//    {
//        QMessageBox::warning(this, "Login Invalid", "Incorrect Username and Password - Please try again");
//        this->setResult(QDialog::Rejected);
//    }

//}

