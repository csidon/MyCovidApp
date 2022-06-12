#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

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


    // Registration + auth functions

private slots:
    void on_btn_login_clicked();

private:
    Ui::AuthDialog *ui;
};

#endif // AUTHDIALOG_H
