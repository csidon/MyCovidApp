#include "useraccount.h"

//Getters
int UserAccount::getUserIDNumber()
{
    return this->userIDNumber;
}

std::string UserAccount::getUserEmail()
{
    return this->userEmail;
}

std::string UserAccount::getUserPassword()
{
    return this->userPassword;
}

std::string UserAccount::getUserFirstName()
{
    return this->userFirstName;
}

std::string UserAccount::getUserLastName()
{
    return this->userLastName;
}

std::string UserAccount::getUserPreferredName()
{
    return this->userPreferredName;
}

std::string UserAccount::getUserNHINumber()
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

std::string UserAccount::getUserQRCodeAddress(){
    return this->userQRCodeAddress;
}

//Setters
void UserAccount::setUserIDNumber(int IDNumber)
{
    this->userIDNumber = IDNumber;
}

void UserAccount::setUserEmail(std::string email)
{
   this->userEmail = email;
}

void UserAccount::setUserPassword(std::string password)
{
   this->userPassword = password;
}

void UserAccount::setUserFirstName(std::string firstName)
{
   this->userFirstName = firstName;
}

void UserAccount::setUserLastName(std::string lastName)
{
   this->userLastName = lastName;
}

void UserAccount::setUserPreferredName(std::string preferredName)
{
   this->userPreferredName = preferredName;
}

void UserAccount::setUserNHINumber(std::string NHINumber)
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

void UserAccount::setUserQRCodeAddress(std::string QRCodeAddress){
    this->userQRCodeAddress = QRCodeAddress;
}

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

bool UserAccount::validateEmailIsEmail(std::string email)
{
    //Check that email has an @ symbol followed at some point by a dot, followed by more characters
    //Check for @ Symbol
    int atCount = 0;
    bool atMarker = false;
    for(int i = 1; i < sizeof(email)-2; i++){//start at 1 because valid email addresses have at least one character, ignore last 2 characters
        if(email[i] == '@'){
            atMarker = true;
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

bool UserAccount::validatePasswordIsSecure(std::string password)
{
    //Check password length and character inclusions
    bool upperFlag = false;
    bool lowerFlag = false;
    bool numberFlag = false;
    bool symbolFlag = false;
    if(sizeof(password) > 7){
        for(int i = 0; i > sizeof(password); i++){
            if(std::isupper(password[i])){
                upperFlag = true;
            }
            if(std::islower(password[i])){
                lowerFlag = true;
            }
            if(std::isdigit(password[i])){
                numberFlag = true;
            }
            if(!std::isdigit(password[i]) && !std::isalpha(password[i])){
                symbolFlag = true;
            }
        }
        if(upperFlag == true && lowerFlag == true && numberFlag == true && symbolFlag == true){
            return true;
        }
    }
    return false;
}

UserAccount UserAccount::initialAccountSetup()
{
   UserAccount newAccount;
   //BUILD THIS store values in new account, then append the account to the account files
   //Probably this should be a void with a UserAccount as an argument; will rebuild once the communication with frontend is clear
   return newAccount;
}

//UserAccount UserAccount::getUserData(int row)
//{
//    UserAccount extractedUser;

//    QFile file(":/database/dummyPID.csv");
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "File did not open";
//        return extractedUser;
//    }
//    int i = 0;
//    do
//    {
//        file.readLine();
//        i++;
//    } while (i < row);
//    QString extractedRow = file.readLine().trimmed();
//    QStringList rowValues = extractedRow.split(',');


//    extractedUser = UserAccount(rowValues[0].toInt(), rowValues[1].toStdString(), rowValues[2].toStdString(), rowValues[3].toStdString(),
//                rowValues[4].toStdString(), rowValues[5].toStdString(), rowValues[6].toStdString(), rowValues[7].toInt(), rowValues[8].toInt(),
//                rowValues[9].toInt(), rowValues[10].toStdString());

//    return extractedUser;
//}


// ******* MOVE TO AUTHDIALOG FILE
// Assigns a new user a unique random UID
void UserAccount::assignID()
{
    int ID = 0;
    bool freshID = false;
    while(freshID == false){
        ID = rand();
        freshID = true;
        HandleCSV checkID;
        QStringList allIDs = checkID.getColData("userIDNumber", ":/database/dummyPID.csv");
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
    QFile QRCodeRequests(":/database/QRCodeRequests.csv");
    if(QRCodeRequests.open(QIODevice::ReadWrite| QIODevice::Append)){
        QTextStream stream(&QRCodeRequests);
        stream << this->getUserIDNumber();
    }
    QRCodeRequests.close();
}

void UserAccount::assignQR()
{
    //BUILD THIS - Associate a QR code with a user
    // --- PSEUDOCODE/commenting---
    // Function grabs a random QR code JPEG in "QR Code Generator" folder
    // Moves JPEG from "QR Code Generator" folder to "Active User Data" folder
    // Renames JPEG to [UID]+[YYMMDD].jpg
    // Adds new JPEG path to the respective userID's QRCodeAddress
}

void UserAccount::addTest(Test testToStore)
{
    testToStore.setTestUserID(this->getUserIDNumber());
    QFile doses(":/database/UserTests" + QString::number(this->getUserIDNumber()) + ".csv");
    if(doses.open(QIODevice::ReadWrite| QIODevice::Append)){
        QTextStream stream(&doses);
        stream << testToStore.getTestDate() << "," << testToStore.getTestResult() << "," << testToStore.getTestUserID() << "," << testToStore.getTestIsNew();
    }
    doses.close();
    QFile masterTests(":/database/MasterTests.csv");
    if(masterTests.open(QIODevice::ReadWrite| QIODevice::Append)){
        QTextStream stream(&masterTests);
        stream << testToStore.getTestDate() << "," << testToStore.getTestResult() << "," << testToStore.getTestUserID() << "," << testToStore.getTestIsNew();
    }
    masterTests.close();
}

void UserAccount::addDose (Dose doseToStore)
{
    doseToStore.setDoseUserID(this->getUserIDNumber());
    QFile doses(":/database/UserDoses" + QString::number(this->getUserIDNumber()) + ".csv");
    if(doses.open(QIODevice::ReadWrite| QIODevice::Append)){
        QTextStream stream(&doses);
        stream << doseToStore.getDoseDate() << "," << doseToStore.getDoseManufacturer() << "," << doseToStore.getDoseUserID() << "," << doseToStore.getDoseIsNew();
    }
    doses.close();
    QFile masterDoses(":/database/MasterDoses.csv");
    if(masterDoses.open(QIODevice::ReadWrite| QIODevice::Append)){
        QTextStream stream(&masterDoses);
        stream << doseToStore.getDoseDate() << "," << doseToStore.getDoseManufacturer() << "," << doseToStore.getDoseUserID() << "," << doseToStore.getDoseIsNew();
    }
    masterDoses.close();
}

void UserAccount::reportError(ErrorReport reportToStore)
{
    reportToStore.setSender(this->getUserIDNumber());
    QFile reports(":/database/ErrorReports.csv");
    if(reports.open(QIODevice::ReadWrite| QIODevice::Append)){
        QTextStream stream(&reports);
        stream << QString::fromStdString(reportToStore.getTitle()) << "," << QString::fromStdString(reportToStore.getText()) << "," << reportToStore.getDate() << "," << reportToStore.getSender() << "," << reportToStore.getIsNew();
    };
    reports.close();
}


//###############################################
// Constructors
//----------------------------------------------
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

UserAccount::UserAccount(int uid = 0, std::string email = "", std::string pswd = "",
                         std::string fn = "", std::string ln = "", std::string pn = "",
                         std::string nhi ="", int phone = 0, int vaxstat = 0, int qrstat = 0, std::string qraddress = "")
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
