#ifndef WHICHHISTORY_H
#define WHICHHISTORY_H

#include "accountdetails.h"
#include "testhistory.h"
#include "vaccinehistory.h"
#include <QWidget>

namespace Ui {
class WhichHistory;
}

class WhichHistory : public QWidget
{
    Q_OBJECT
private:
    int loggedInUser;
    VaccineHistory doseWindow;
    TestHistory testWindow;
    AccountDetails detailsWindow;
public:
    explicit WhichHistory(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~WhichHistory();

    int getLoggedInUser();
    void setLoggedInUser(int newLoggedInUser);

private slots:
    void on_btn_backToHome_clicked();

    void on_btn_vaxHistory_clicked();

    void on_btn_testHistory_clicked();

    void on_btn_accountDetails_clicked();

private:
    Ui::WhichHistory *ui;
};

#endif // WHICHHISTORY_H
