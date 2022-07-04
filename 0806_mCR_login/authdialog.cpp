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
    UserAccount grabbedUser; // To store user data if checkUser authenticates
    if (usrn == "darth.vader@betrayal.com" && pass == "I'm Your Fath3r")
    {
        qDebug() << "You an ADMIN";
        return 42;      // User is immediately authenticated as admin
    }
    else
    {
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
            qDebug() << "The retrieved password from the db for " << usrn << " is " << retrievedPass;
            if (retrievedPass == pass)
            {
                // if the retrieved password for that username matches the password entered
                // Find the UID for that user who signed in
                // Return that UID
                int uid = checkUser.getCellValue(dbName,uidHeaderIndex,rowIndex).toInt();
                qDebug() << "The uid returned is " << uid;
                return uid;
            }
        }
    }
    // returns UID = 42 if admin, the rand UID assigne if auth pass & eu logged in,
    // and -1 if auth fail
    return -1;
}



void AuthDialog::on_btn_login_clicked()
{
    UserAccount grabbedUser; // To store user data if checkUser authenticates

    QString username = ui->lineEdit_inputEmail->text();
    QString pswd = ui->lineEdit_inputPass->text();

    // Verify if user exists in database and if password matches
    int loginSuccessUID = authUser(username, pswd, "dbPID"); // returns 0, 1, or 2 (admin)
    qDebug() << "The loginSuccessUID is " << loginSuccessUID;
    // Note: dbPID is mapped to appropriate filepath in handleCSV.cpp

    if (loginSuccessUID == 42)      // Credentials belong to admin
    {
        this->hide();
        QMessageBox::information(this, "Login", "Correct username and password."
                                                "\nAccess to Admin Panel granted");
        this->setResult(QDialog::Accepted);

        // Return userID 42 (reserved for admin)
        // userID 42 will SETWINDOW TO ADMIN PANEL *******
        // i.e. ui->invisibleLabelOnAdminPanel->setText("userID")
        HandleCSV checkAdmin;
        grabbedUser = checkAdmin.getUserAccount(loginSuccessUID);
        setLoggedInUserID(42);
        openMainAdminWindow();
    }
    else if (loginSuccessUID > 0 && loginSuccessUID != 42)     // End User recognised and authenticated
    {
        this->hide();
        QMessageBox::information(this, "Login", "Correct username and password."
                                                "\nWelcome to MyCovidRecord");
        this->setResult(QDialog::Accepted);
        HandleCSV checkUser;

        grabbedUser = checkUser.getUserAccount(loginSuccessUID);

        setLoggedInUserID(grabbedUser.getUserIDNumber());
    }
    else        // Username||password not found in database
    {
        QMessageBox::warning(this, "Login Invalid", "Incorrect Username and Password - Please try again");
        this->setResult(QDialog::Rejected);
    }
}

void AuthDialog::openMainAdminWindow()
{
    mainAdminWindow = new AdminHome();
    mainAdminWindow->show();
}


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
    bool passValidated = validatePasswordIsSecure(inputPass);
    if(emailInDB == true)
    {
        ui->lineEdit_inputRegEmail->inputRejected();
    }
    else if (emailInDB == false && emailValid == true && passValidated == true)
    {
        // User has met all criteria. Assign user a random userID
        int newID = assignID();
        qDebug() << newID << " is your new ID";
        setLoggedInUserID(newID);
        setLoggedInUserEmail(inputEmail);
        setLoggedInUserPass(inputPass);
        ui->lbl_emailExistsErr->show();
        // Redirect user to Step 1 of sign up
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        qDebug() << "Something went wrong in the authentication process.";
    }
}


//################################################################
// Registration functions that validate username and password
// used in above functions
//---------------------------------------------------------------
bool AuthDialog::validateEmailInUse(QString email)
{
    qDebug() << "Checking if Email " << email << " is unique";
    HandleCSV readEmails;
    // Getting index header for "userEmail"
    QStringList getAllEmails = readEmails.getColData("userEmail", "dbPID");
    // Check if email already exists in "dbPID"
    if (readEmails.rowIndexOfCellMatchingSearch(getAllEmails, email) < 0)
    {
        return false;
    }
    else{
        return true;    // User exists in db
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
//            atMarker = true;
            atCount = i;
            //Check for .
            for(int j = atCount + 2; j < email.size() - 1; j++){//start after the char after the @, ignore the last char
                if(email[j] == '.')
                {
                    ui->lbl_emailExistsErr->hide();
                    return true;
                }
            }
        }
    }
    ui->lineEdit_inputRegEmail->setStyleSheet("border-style: solid; border-color: #C00000; border-width: 1px; color: #C00000");
    ui->lbl_emailExistsErr->setStyleSheet("color: #C00000");
    ui->lbl_emailExistsErr->setText("Please enter a valid email address");
    ui->lbl_emailExistsErr->show();
    return false;
}


bool AuthDialog::validatePasswordIsSecure(QString password)
{
    qsizetype passSize = password.size();

    //Check password length and character inclusions
    bool lengthFlag = false;
    bool upperFlag = false;
    bool lowerFlag = false;
    bool numberFlag = false;
    if(passSize > 7)
    {
        lengthFlag = true;
    }

    for(int i = 0; i < passSize; i++)
    {
        if(password.at(i).isUpper())
        {
            upperFlag = true;
        }
        if(password.at(i).isLower())
        {
            lowerFlag = true;
        }
        if(password.at(i).isDigit())
        {
            numberFlag = true;
        }
    }
    ui->lbl_passCheck_charIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->lbl_passCheck_UppLowIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->lbl_passCheck_numIcon->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    if (lengthFlag == true)
    {
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
    if(lengthFlag == true && upperFlag == true && lowerFlag == true && numberFlag == true)
    {
        return true;
    }

    ui->lbl_passCheck_charIcon->show();
    ui->lbl_passCheck_UppLowIcon->show();
    ui->lbl_passCheck_numIcon->show();
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
    return ID;
}


//--------------------------
// User Error Messages
//--------------------------
void AuthDialog::on_lineEdit_inputRegEmail_inputRejected()
{
    // Note: Use #17A81A for green approvals and #C00000 for red rejects
    ui->lineEdit_inputRegEmail->setStyleSheet("border-style: solid; border-color: #C00000; border-width: 1px; color: #C00000");
    ui->lbl_emailExistsErr->setStyleSheet("color: #C00000");
    ui->lbl_emailExistsErr->setText("Email exists. Please enter a different email.");
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

//------------------------------------------
// Button/UI activated functions
//------------------------------------------

void AuthDialog::on_btn_nextTerms1_clicked()
{
    if (ui->checkBox_agreeTerms->isChecked() != true)
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->btn_nextTerms2->setDisabled(true);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
}


void AuthDialog::on_checkBox_agreeTerms2_stateChanged(int arg1)
{
    if (arg1 == 2)
    {
        ui->btn_nextTerms2->setDisabled(false);
    }
}


void AuthDialog::on_btn_nextTerms2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void AuthDialog::on_btn_nextDetails_clicked()
{
    if(ui->lineEdit_fname->text() == "" || ui->lineEdit_fname->text() == "Please enter your first name")
    {
        ui->lineEdit_fname->setFocus();
        ui->lineEdit_fname->setText("Please enter your first name");
    }
    else if (ui->lineEdit_lname->text() == "" || ui->lineEdit_lname->text() == "Please enter your last name")
    {
        ui->lineEdit_lname->setFocus();
        ui->lineEdit_lname->setText("Please enter your last name");
    }
    else
    {
        setLoggedInUserfName(ui->lineEdit_fname->text());
        setLoggedInUserlName(ui->lineEdit_lname->text());
        setLoggedInUserpName(ui->lineEdit_prefName->text());
        ui->stackedWidget->setCurrentIndex(5);
    }
}


void AuthDialog::on_btn_nextDetails_2_clicked()
{
    setLoggedInUserNHI(ui->lineEdit_nhi->text());
    setLoggedInUserPhone(ui->lineEdit_phone->text().toInt());
    ui->stackedWidget->setCurrentIndex(6);
    ui->label_accountCreatedMsg->hide();
    ui->progressBar->setValue(0);
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this, &AuthDialog::setValueProgress);
    timer->start(500);

    // Setup a new UserAccount object and set variables using constructor
    UserAccount newUser;
    newUser = UserAccount(getLoggedInUserID(),getLoggedInUserEmail(),
                          getLoggedInUserPass(),getLoggedInUserfName(),
                          getLoggedInUserlName(),getLoggedInUserpName(),
                          getLoggedInUserNHI(),getLoggedInUserPhone(),0,0,"notYetSet");

    // Open db and write new user into db
    HandleCSV CSVfile;
    CSVfile.writeToPIDCSV(newUser);

    // After 6 seconds, show "account created"
    QTimer::singleShot(6000,this,&AuthDialog::showAccountCreated);

    // After 8 seconds, redirect user to Login Page
    QTimer::singleShot(8000,this,&AuthDialog::redirectToLogin);

//    int timerInterval = timer->interval();
//    qDebug() << "The timer interval is " << timerInterval;
//    int timerID = timer->timerId();
//    qDebug() << "The timer ID is " << timerID;
}


void AuthDialog::setValueProgress()
{
    ui->progressBar->setValue(ui->progressBar->value()+10);
}

void AuthDialog::showAccountCreated()
{
    ui->label_accountCreatedMsg->show();
}

void AuthDialog::redirectToLogin()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//################################################
// Getters and setters
//-----------------------------------------------
int AuthDialog::getLoggedInUserID()
{
    return loggedInUserID;
}

void AuthDialog::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}

QString AuthDialog::getLoggedInUserEmail()
{
    return email;
}

void AuthDialog::setLoggedInUserEmail(QString email)
{
    this->email = email;
}

QString AuthDialog::getLoggedInUserPass()
{
    return pass;
}

void AuthDialog::setLoggedInUserPass(QString pass)
{
    this->pass = pass;
}

QString AuthDialog::getLoggedInUserfName()
{
    return fname;
}

void AuthDialog::setLoggedInUserfName(QString fname)
{
    this->fname = fname;
}

QString AuthDialog::getLoggedInUserlName()
{
    return lname;
}

void AuthDialog::setLoggedInUserlName(QString lname)
{
    this->lname = lname;
}

QString AuthDialog::getLoggedInUserpName()
{
    return pname;
}

void AuthDialog::setLoggedInUserpName(QString pname)
{
    this->pname = pname;
}

QString AuthDialog::getLoggedInUserNHI()
{
    return nhi;
}

void AuthDialog::setLoggedInUserNHI(QString nhi)
{
    this->nhi = nhi;
}

int AuthDialog::getLoggedInUserPhone()
{
    return ph;
}

void AuthDialog::setLoggedInUserPhone(int phone)
{
    this->ph = phone;
}
