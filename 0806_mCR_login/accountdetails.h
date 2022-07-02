#ifndef ACCOUNTDETAILS_H
#define ACCOUNTDETAILS_H

#include <QWidget>

namespace Ui {
class AccountDetails;
}

class AccountDetails : public QWidget
{
    Q_OBJECT
private:
    int loggedInUserID;
public:
    explicit AccountDetails(QWidget *parent = nullptr);
    ~AccountDetails();

    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);
    void setDisplay();

private slots:
    void on_btn_backToHome_clicked();

private:
    Ui::AccountDetails *ui;
};

#endif // ACCOUNTDETAILS_H
