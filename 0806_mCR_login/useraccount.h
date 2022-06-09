#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <QVector>
#include "test.h"
#include "dose.h"


class UserAccount
{
private:
    int userIDNumber;
    std::string userEmail;
    std::string userPassword;
    std::string userFirstName;
    std::string userLastName;
    std::string userPreferredName;
    int userNHINumber;
    int userPhoneNumber;
    bool userVaccinationStatus;
    int userQRStatus;
    std::string userQRCodeAddress;

public:
    //Getters
    int getUserIDNumber();
    std::string getUserEmail();
    std::string getUserPassword();
    std::string getUserFirstName();
    std::string getUserLastName();
    std::string getUserPreferredName();
    int getUserNHINumber();
    int getUserPhoneNumber();
    bool getUserVaccinationStatus();
    int getUserQRStatus();
    std::string getUserQRCodeAddress();

    //Setters
    void setUserIDNumber(int IDNumber);
    void setUserEmail(std::string email);
    void setUserPassword(std::string password);
    void setUserFirstName(std::string firstName);
    void setUserLastName(std::string lastName);
    void setUserPreferredName(std::string preferredName);
    void setUserNHINumber(int NHINumber);
    void setUserPhoneNumber(int PhoneNumber);
    void setUserVaccinationStatus(bool VaccinationStatus);
    void setUserQRStatus(int QRStatus);
    void setUserQRCodeAddress(std::string QRCodeAddress);

    //Validators
    bool validateEmailInUse(std::string email);
    bool validateEmailIsEmail(std::string email);
    bool validatePasswordIsSecure(std::string password);

    //Functions
    UserAccount initialAccountSetup();
    void assignID();
    void requestQR();
    void assignQR();
    void addTest(Test newTest);
    void addDose(Dose newDose);
    void reportError();

    //Constructor
    UserAccount();
};

#endif // USERACCOUNT_H
