#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QStringList>
#include <QFile>
#include <QTextStream>

#include "useraccount.h"
#include "handlecsv.h"

namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT

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


private slots:
    void on_btn_login_clicked();

    void on_btn_switchToSignup_clicked();

    void on_btn_switchToLogin_clicked();

    void on_btn_createAccount_clicked();

    void on_lineEdit_inputRegEmail_inputRejected();

private:
    Ui::AuthDialog *ui;
};

#endif // AUTHDIALOG_H
