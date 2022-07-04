#include "useraccount.h"

//Validators
bool UserAccount::validateEmailInUse(QString email)
{
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

bool UserAccount::validateEmailIsEmail(QString email)
{
    //Check that email has an @ symbol followed at some point by a dot, followed by more characters
    //Check for @ Symbol
    int atCount = 0;
    bool atMarker = false;
    for(int i = 1; i < sizeof(email)-2; i++){//start at 1 because valid email addresses have at least one character, ignore last 2 characters
        if(email[i] == '@'){
            atCount = i;
            //Check for .
            for(int j = atCount + 2; j < sizeof(email) - 1; j++){//start after the char after the @, ignore the last char
                if(email[j] == '.'){
                    return true;
                }
            }
        }
    }
    return false;
}



// Assigns a new user a unique random UID
void UserAccount::assignID()
{
    int ID = 0;
    bool freshID = false;
    while(freshID == false){
        ID = rand()+1;
        //In use already?
        freshID = true;
        HandleCSV checkID;
        QStringList allIDs = checkID.getColData("userIDNumber", "dbPID");
        for(int i = 0; i < allIDs.size(); i++){
            if(allIDs.at(i) == QString::number(ID)){
                freshID = false;
            }
        }
    }
    this->setUserIDNumber(ID);
}

void UserAccount::requestQR()
{
    //adds User's ID to a file of users with outstanding QR Requests and updates the variable that controls which QR button they see
    HandleCSV grabPath;
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = grabPath.returnCSVFilePath("dbQRRequests");

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile QRCodeRequests{filepath};
        if(QRCodeRequests.open(QIODevice::ReadWrite| QIODevice::Append))
        {
            QTextStream stream(&QRCodeRequests);
            stream << this->getUserIDNumber() << "\n";
        }
        QRCodeRequests.close();
    }
}


void UserAccount::addTest(Test testToStore)
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    //Store in personal file
    QString filepath = "database/UserTests/" + QString::number(testToStore.getTestUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile testFile{filepath};
        if(testFile.open(QIODevice::ReadWrite| QIODevice::Append))
        {
            QTextStream stream(&testFile);
            stream << testToStore.getTestDate() << "," << testToStore.getTestResult() << "," << testToStore.getTestUserID() << "," << testToStore.getTestRecDate() << "\n";
        }
        testFile.close();
    }

    // Storing in MasterTests db
    HandleCSV grabPath;
    QString switchFilePath = grabPath.returnCSVFilePath("dbTest");

    QFile masterTests(switchFilePath);
    if(masterTests.open(QIODevice::ReadWrite| QIODevice::Append))
    {
        QTextStream stream(&masterTests);
        stream << testToStore.getTestDate() << "," << testToStore.getTestResult() << "," << testToStore.getTestUserID() << "," << testToStore.getTestRecDate() << "\n";
    }
    masterTests.close();
}

void UserAccount::addDose (Dose doseToStore)
{
    //Stores dose with user id in user's file and master file
    doseToStore.setDoseUserID(doseToStore.getDoseUserID());

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = "database/UserDoses/" + QString::number(doseToStore.getDoseUserID()) + ".csv";

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile doseFile{filepath};

        if(doseFile.open(QIODevice::ReadWrite| QIODevice::Append)){
            QTextStream stream(&doseFile);
            stream << doseToStore.getDoseDate() << "," << doseToStore.getDoseManufacturer() << "," << doseToStore.getDoseUserID() << "," << doseToStore.getDoseIsNew() << "\n";
        }
        doseFile.close();

        HandleCSV grabPath;
        QString switchFilePath = grabPath.returnCSVFilePath("dbDose");
        QFile masterDoses{switchFilePath};
        if(masterDoses.open(QIODevice::ReadWrite| QIODevice::Append)){
            QTextStream stream(&masterDoses);
            stream << doseToStore.getDoseDate() << "," << doseToStore.getDoseManufacturer() << "," << doseToStore.getDoseUserID() << "," << doseToStore.getDoseIsNew() << "\n";

        }
        masterDoses.close();
    }
}


//###############################################
// Constructors
//----------------------------------------------


UserAccount::UserAccount(int uid, QString email = "", QString pswd = "",
                         QString fn = "", QString ln = "", QString pn = "",
                         QString nhi ="", int phone = 0, int vaxstat = 0, int qrstat = 0, QString qraddress = "")
{
    userIDNumber = uid;
    userEmail = email;
    userPassword = pswd;
    userFirstName = fn;
    userLastName = ln;
    userPreferredName = pn;
    userNHINumber = nhi;
    userPhoneNumber = phone;
    userVaccinationStatus = vaxstat;
    userQRStatus = qrstat;
    userQRCodeAddress = qraddress;
}

UserAccount::UserAccount()
{
    userIDNumber = 0;
    userEmail = "";
    userPassword = "";
    userFirstName = "";
    userLastName = "";
    userPreferredName = "";
    userNHINumber = "";
    userPhoneNumber = 0;
    userVaccinationStatus = 0;
    userQRStatus = 0;
    userQRCodeAddress = "";
}

//################################################
// Getters and setters
//-----------------------------------------------

int UserAccount::getUserIDNumber()
{
    return this->userIDNumber;
}

QString UserAccount::getUserEmail()
{
    return this->userEmail;
}

QString UserAccount::getUserPassword()
{
    return this->userPassword;
}

QString UserAccount::getUserFirstName()
{
    return this->userFirstName;
}

QString UserAccount::getUserLastName()
{
    return this->userLastName;
}

QString UserAccount::getUserPreferredName()
{
    return this->userPreferredName;
}

QString UserAccount::getUserNHINumber()
{
    return this->userNHINumber;
}

int UserAccount::getUserPhoneNumber()
{
    return this->userPhoneNumber;
}

int UserAccount::getUserVaccinationStatus()
{
    return this->userVaccinationStatus;
}

int UserAccount::getUserQRStatus()
{
    return this->userQRStatus;
}

QString UserAccount::getUserQRCodeAddress(){
    return this->userQRCodeAddress;
}

//Setters
void UserAccount::setUserIDNumber(int IDNumber)
{
    this->userIDNumber = IDNumber;
}

void UserAccount::setUserEmail(QString email)
{
   this->userEmail = email;
}

void UserAccount::setUserPassword(QString password)
{
   this->userPassword = password;
}

void UserAccount::setUserFirstName(QString firstName)
{
   this->userFirstName = firstName;
}

void UserAccount::setUserLastName(QString lastName)
{
   this->userLastName = lastName;
}

void UserAccount::setUserPreferredName(QString preferredName)
{
   this->userPreferredName = preferredName;
}

void UserAccount::setUserNHINumber(QString NHINumber)
{
    this->userNHINumber = NHINumber;
}

void UserAccount::setUserPhoneNumber(int phoneNumber)
{
    this->userPhoneNumber = phoneNumber;
}

void UserAccount::setUserVaccinationStatus(int vaccinationStatus)
{
    this->userVaccinationStatus = vaccinationStatus;
}

void UserAccount::setUserQRStatus(int QRStatus)
{
    this->userQRStatus = QRStatus;

    // UserQRStatus codes are 0 for not requested, 1 for requested but not uploaded, 2 for uploaded
}

void UserAccount::setUserQRCodeAddress(QString QRCodeAddress){
    this->userQRCodeAddress = QRCodeAddress;
}
