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

int UserAccount::getUserNHINumber()
{
    return this->userNHINumber;
}

int UserAccount::getUserPhoneNumber()
{
    return this->userPhoneNumber;
}

bool UserAccount::getUserVaccinationStatus()
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

void UserAccount::setUserNHINumber(int NHINumber)
{
    this->userNHINumber = NHINumber;
}

void UserAccount::setUserPhoneNumber(int phoneNumber)
{
    this->userPhoneNumber = phoneNumber;
}

void UserAccount::setUserVaccinationStatus(bool vaccinationStatus)
{
    this->userVaccinationStatus = vaccinationStatus;
}

void UserAccount::setUserQRStatus(int QRStatus)
{
    this->userQRStatus = QRStatus;
}

void UserAccount::setUserQRCodeAddress(std::string QRCodeAddress){
    this->userQRCodeAddress = QRCodeAddress;
}

//Validators
bool UserAccount::validateEmailInUse(std::string email)
{
    //BUILD THIS - Check email against all emails in use for exact matches
    return true;
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
                symbolFlag = false;
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
   return newAccount;
}

void UserAccount::assignID()
{
    int ID = 0;
    while(bool freshID = false){
        ID = rand();
        //BUILD THIS - check id against IDs currently in use
        //randomized IDs helps with anonymity
        if(/*ID not in use, 1==1 as a stand-in for now*/ 1==1){
            freshID = true;
        }
    }
    this->setUserIDNumber(ID);
}

void UserAccount::requestQR()
{
    //BUILD THIS - Send a QR code requet to the admin side
}

void UserAccount::assignQR()
{
    //BUILD THIS - Associate a QR code with a user
}

void UserAccount::addTest(Test newTest)
{
    //BUILD THIS - add a test into the user's test vector and overwrite their test file with their current test vector;
}

void UserAccount::addDose (Dose newDose)
{
    //BUILD THIS - add a dose into the user's dose vector and overwrite their dose file with their current dose vector;
}

void UserAccount::reportError()
{
    //BUILD THIS - report an error, notify admin side, log report etc
}

//Constructor
UserAccount::UserAccount()
{
    userIDNumber = 0;
    userEmail = "";
    userPassword = "";
    userFirstName = "";
    userLastName = "";
    userPreferredName = "";
    userNHINumber = 0;
    userPhoneNumber = 0;
    userVaccinationStatus = 0;
    userQRStatus = 0;
    userQRCodeAddress = "";
}
