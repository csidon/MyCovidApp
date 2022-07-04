#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QTimer>

#include "useraccount.h"
#include "handlecsv.h"
#include "mainwindow.h"
#include <QObject>
#include "adminhome.h"


namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT

private:
    int loggedInUserID = 0;
    Ui::AuthDialog *ui;
    AdminHome *mainAdminWindow;
    QString email = "";
    QString pass = "";
    QString fname = "";
    QString lname = "";
    QString pname = "";
    QString nhi = "";
    int ph = 0;


public:
    explicit AuthDialog(QWidget *parent = nullptr);
    ~AuthDialog();

    // Authentication functions
    int authUser(QString usrn, QString pass, QString dbName);


    // Account creation & validation functions
    //-- User Error messages--
    void hidePassCriteria();
    void showPassCriteria();
    bool validateEmailInUse(QString email);
    bool validateEmailIsEmail(QString email);
    bool validatePasswordIsSecure(QString password);
    int assignID();

    // Getters and setters
    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);
    QString getLoggedInUserEmail();
    void setLoggedInUserEmail(QString email);
    QString getLoggedInUserPass();
    void setLoggedInUserPass(QString pass);
    QString getLoggedInUserfName();
    void setLoggedInUserfName(QString fname);
    QString getLoggedInUserlName();
    void setLoggedInUserlName(QString lname);
    QString getLoggedInUserpName();
    void setLoggedInUserpName(QString pname);
    QString getLoggedInUserNHI();
    void setLoggedInUserNHI(QString nhi);
    int getLoggedInUserPhone();
    void setLoggedInUserPhone(int phone);

public slots:
    void on_btn_login_clicked();
    void openMainAdminWindow();
    void setValueProgress();
    void showAccountCreated();
    void redirectToLogin();


private slots:
    void on_btn_switchToSignup_clicked();
    void on_btn_switchToLogin_clicked();
    void on_btn_createAccount_clicked();
    void on_lineEdit_inputRegEmail_inputRejected();

    void on_btn_nextTerms1_clicked();
    void on_checkBox_agreeTerms2_stateChanged(int arg1);
    void on_btn_nextTerms2_clicked();
    void on_btn_nextDetails_clicked();
    void on_btn_nextDetails_2_clicked();

signals:
    void sendUIDSignal(int uid);
};

#endif // AUTHDIALOG_H
