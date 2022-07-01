#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <QVector>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QDateTime>

#include "handlecsv.h"
#include "errorreport.h"
#include "errorreport.h"
#include "test.h"
#include "dose.h"

class UserAccount
{
private:
    int userIDNumber;
    QString userEmail;
    QString userPassword;
    QString userFirstName;
    QString userLastName;
    QString userPreferredName;
    QString userNHINumber;
    int userPhoneNumber;
    int userVaccinationStatus;      // 0 = Unvaccinated, 1 = Partially vaccinated, 2 = Fully vaccinated
    int userQRStatus;               // 0 = Not requested, 1 = Requested but not uploaded, 2 = Uploaded
    QString userQRCodeAddress;

public:
    //Getters
    int getUserIDNumber();
    QString getUserEmail();
    QString getUserPassword();
    QString getUserFirstName();
    QString getUserLastName();
    QString getUserPreferredName();
    QString getUserNHINumber();
    int getUserPhoneNumber();
    int getUserVaccinationStatus();
    int getUserQRStatus();
    QString getUserQRCodeAddress();

    //Setters
    void setUserIDNumber(int IDNumber);
    void setUserEmail(QString email);
    void setUserPassword(QString password);
    void setUserFirstName(QString firstName);
    void setUserLastName(QString lastName);
    void setUserPreferredName(QString preferredName);
    void setUserNHINumber(QString NHINumber);
    void setUserPhoneNumber(int PhoneNumber);
    void setUserVaccinationStatus(int VaccinationStatus);
    void setUserQRStatus(int QRStatus);
    void setUserQRCodeAddress(QString QRCodeAddress);

    //Validators
    bool validateEmailInUse(QString email);
    bool validateEmailIsEmail(QString email);
    bool validatePasswordIsSecure(QString password);

    //Functions
    void assignID();
    void requestQR();
    void addTest(Test testToStore);
    void addDose(Dose doseToStore);


    //Constructor
    UserAccount();
    UserAccount(int uid, QString email, QString pswd, QString fn,
                QString ln, QString pn, QString nhi, int phone, int vaxstat,
                int qrstat, QString qraddress);


};

#endif // USERACCOUNT_H
