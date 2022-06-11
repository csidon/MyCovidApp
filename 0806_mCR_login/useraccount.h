#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <QVector>
#include "errorreport.h"
#include "test.h"
#include "dose.h"
#include <QStringList>
#include "readcsv.h"

class UserAccount
{
private:
    int userIDNumber;
    std::string userEmail;
    std::string userPassword;
    std::string userFirstName;
    std::string userLastName;
    std::string userPreferredName;
    std::string userNHINumber;
    int userPhoneNumber;
    int userVaccinationStatus;      // 0 = Unvaccinated, 1 = Partially vaccinated, 2 = Fully vaccinated
    int userQRStatus;               // 0 = Not requested, 1 = Requested but not uploaded, 2 = Uploaded
    std::string userQRCodeAddress;

public:
    //Getters
    int getUserIDNumber();
    std::string getUserEmail();
    std::string getUserPassword();
    std::string getUserFirstName();
    std::string getUserLastName();
    std::string getUserPreferredName();
    std::string getUserNHINumber();
    int getUserPhoneNumber();
    int getUserVaccinationStatus();
    int getUserQRStatus();
    std::string getUserQRCodeAddress();

    //Setters
    void setUserIDNumber(int IDNumber);
    void setUserEmail(std::string email);
    void setUserPassword(std::string password);
    void setUserFirstName(std::string firstName);
    void setUserLastName(std::string lastName);
    void setUserPreferredName(std::string preferredName);
    void setUserNHINumber(std::string NHINumber);
    void setUserPhoneNumber(int PhoneNumber);
    void setUserVaccinationStatus(int VaccinationStatus);
    void setUserQRStatus(int QRStatus);
    void setUserQRCodeAddress(std::string QRCodeAddress);

    //Validators
    bool validateEmailInUse(std::string email);
    bool validateEmailIsEmail(std::string email);
    bool validatePasswordIsSecure(std::string password);

    //Functions
    UserAccount initialAccountSetup();
    UserAccount getUserData(int row);

    void assignID();
    void requestQR();
    void assignQR();
    void addTest(Test testToStore);
    void addDose(Dose doseToStore);
    void reportError(ErrorReport reportToStore);


    //Constructor
    UserAccount();
    UserAccount(int uid, std::string email, std::string pswd, std::string fn,
                std::string ln, std::string pn, std::string nhi, int phone, int vaxstat,
                int qrstat, std::string qraddress);


};

#endif // USERACCOUNT_H
