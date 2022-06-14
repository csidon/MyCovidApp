// Tick/Close icons created by Pixel perfect - Flaticon
#include "authdialog.h"
#include "ui_authdialog.h"


AuthDialog::AuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);
    hidePassCriteria();
    ui->lbl_emailExistsErr->hide();


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
    return -1;
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


void AuthDialog::on_btn_switchToSignup_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void AuthDialog::on_btn_switchToLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


//########################################################
// ACCOUNT CREATION methods
//------------------------------------------------------

void AuthDialog::on_btn_createAccount_clicked()
{
    showPassCriteria();
    QString inputEmail = ui->lineEdit_inputRegEmail->text();
    QString inputPass = ui->lineEdit_inputRegPass->text();

    bool emailInDB = validateEmailInUse(inputEmail);
    bool emailValid = validateEmailIsEmail(inputEmail);
    qDebug() << "Email in database? " << emailInDB << "\nEmail valid? " << emailValid;
    bool passValidated = validatePasswordIsSecure(inputPass);
    qDebug() << "Are you authenticated?? " << passValidated;
    if(emailInDB == true)
    {
        ui->lineEdit_inputRegEmail->inputRejected();
        qDebug() << "Email exists in database. Let user know";

    }
    else if (emailInDB == false && emailValid == true && passValidated == true)
    {
        // User has met all criteria. Assign user a random userID
        int newID = assignID();
        qDebug() << newID << " is your new ID";

        // Setup a new UserAccount object and set variables using constructor

        UserAccount newUser;
        newUser = UserAccount(newID,inputEmail,inputPass,"","","","",0,0,0,"" );

        // Open db and write new user into db
        HandleCSV CSVfile;
        CSVfile.writeToPIDCSV(newUser);

        // Redirect user to Login Page
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug() << "Something went wrong in the authentication process.";
    }
}


//#############################################################
// Registration functions that validate username and password
//------------------------------------------------------------
bool AuthDialog::validateEmailInUse(QString email)
{
    qDebug() << "Checking if Email " << email << " is unique";
    HandleCSV readEmails;
    // Getting index header for "userEmail"
    QStringList getAllEmails = readEmails.getColData("userEmail", "dbPID");
    // Check if email already exists in "dbPID"
    if (readEmails.rowIndexOfCellMatchingSearch(getAllEmails, email) < 0){
        return false;
    }
    else{
        return true;
    };
}

bool AuthDialog::validateEmailIsEmail(QString email)
{
    //Check that email has an @ symbol followed at some point by a dot, followed by more characters
    //Check for @ Symbol
    int atCount = 0;
    bool atMarker = false;
    for(int i = 1; i < email.size()-2; i++){//start at 1 because valid email addresses have at least one character, ignore last 2 characters
        if(email[i] == '@'){
            atMarker = true;
            qDebug() << "Has the @ symbol has been found in email? " << atMarker;
            atCount = i;
            //Check for .
            for(int j = atCount + 2; j < email.size() - 1; j++){//start after the char after the @, ignore the last char
                if(email[j] == '.'){
                    return true;
                }
            }
        }
    }
    return false;
}


bool AuthDialog::validatePasswordIsSecure(QString password)
{

    qsizetype passSize = password.size();

    qDebug() << "passSize is " << passSize;

    //Check password length and character inclusions
    bool lengthFlag = false;
    bool upperFlag = false;
    bool lowerFlag = false;
    bool numberFlag = false;
//    bool symbolFlag = false;
    if(passSize > 7)
    {
        lengthFlag = true;
    }

    for(int i = 0; i < passSize; i++)
    {
//        qDebug() << "you are in the LOOP";
        if(password.at(i).isUpper())
        {
            qDebug() << "Your password has an Upper Let!";
            upperFlag = true;
        }
        if(password.at(i).isLower())
        {
            lowerFlag = true;
        }
//            if(std::isdigit(password[i]))
        if(password.at(i).isDigit())
        {
            numberFlag = true;
        }
//        if(password[i].isSymbol())
//        {
//            symbolFlag = true;
//        }
    }


    ui->lbl_passCheck_charIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->lbl_passCheck_UppLowIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->lbl_passCheck_numIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
//    ui->lbl_passCheck_symIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    qDebug() << "LengthFlag is " << lengthFlag;
    if (lengthFlag == true)
    {
        qDebug() << "You have found the TRUE way";
        ui->lbl_passCheck_charIcon->setPixmap(QPixmap(":/images/greenCheck.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
    else
    {
        ui->lbl_passCheck_charIcon->setPixmap(QPixmap(":/images/redClose.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }

    if (upperFlag == true && lowerFlag == true)
    {
        ui->lbl_passCheck_UppLowIcon->setPixmap(QPixmap(":/images/greenCheck.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
    else
    {
        ui->lbl_passCheck_UppLowIcon->setPixmap(QPixmap(":/images/redClose.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }

    if (numberFlag == true)
    {
        ui->lbl_passCheck_numIcon->setPixmap(QPixmap(":/images/greenCheck.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
    else
    {
        ui->lbl_passCheck_numIcon->setPixmap(QPixmap(":/images/redClose.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }

//    if (symbolFlag == true)
//    {
//        ui->lbl_passCheck_symIcon->setPixmap(QPixmap(":/images/greenCheck.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
//    }
//    else
//    {
//        ui->lbl_passCheck_symIcon->setPixmap(QPixmap(":/images/redClose.ico").scaled(16, 16, Qt::IgnoreAspectRatio, Qt::FastTransformation));
//    }
    qDebug() << "Flag responses are upper " << upperFlag << "\nlower " << lowerFlag
             << "\nchars " << lengthFlag << "\nnum " << numberFlag ;

    if(lengthFlag == true && upperFlag == true && lowerFlag == true && numberFlag == true)
    {
        return true;
    }

    ui->lbl_passCheck_charIcon->show();
    ui->lbl_passCheck_UppLowIcon->show();
    ui->lbl_passCheck_numIcon->show();
//    ui->lbl_passCheck_symIcon->show();
    return false;
}


//-----------------------------------------------------
// Registration function assigns user a random UID
//-----------------------------------------------------
int AuthDialog::assignID()
{
    int ID = 0;
    bool freshID = false;
    while(freshID == false){
        ID = rand();
        freshID = true;
        HandleCSV checkID;
        QStringList allIDs = checkID.getColData("userIDNumber", "dbPID");
        for(int i = 0; i < allIDs.size(); i++){
            if(allIDs.at(i) == QString::number(ID)){
                freshID = false;
            }
        }
    }
//    this->setUserIDNumber(ID);
    return ID;
}

void AuthDialog::on_lineEdit_inputRegEmail_inputRejected()
{
    // Note: Use #17A81A for green approvals and #C00000 for red rejects
    ui->lineEdit_inputRegEmail->setStyleSheet("border-style: solid; border-color: #C00000; border-width: 1px; color: #C00000");
    ui->lbl_emailExistsErr->setStyleSheet("color: #C00000");
    ui->lbl_emailExistsErr->show();


}

void AuthDialog::hidePassCriteria()
{
    ui->lbl_passCriteria->hide();
    ui->lbl_passCheck_charIcon->hide();
    ui->lbl_passCheck_char_2->hide();
    ui->lbl_passCheck_num->hide();
    ui->lbl_passCheck_numIcon->hide();
    ui->lbl_passCheck_uppLow->hide();
    ui->lbl_passCheck_UppLowIcon->hide();
}

void AuthDialog::showPassCriteria()
{
    ui->lbl_passCriteria->show();
    ui->lbl_passCheck_charIcon->show();
    ui->lbl_passCheck_char_2->show();
    ui->lbl_passCheck_num->show();
    ui->lbl_passCheck_numIcon->show();
    ui->lbl_passCheck_uppLow->show();
    ui->lbl_passCheck_UppLowIcon->show();
}
