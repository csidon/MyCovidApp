#include "whichhistory.h"
#include "testhistory.h"
#include "ui_whichhistory.h"
#include "vaccinehistory.h"

int WhichHistory::getLoggedInUser()
{
    return loggedInUser;
}

void WhichHistory::setLoggedInUser(int newLoggedInUser)
{
    loggedInUser = newLoggedInUser;
}

WhichHistory::WhichHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::WhichHistory)
{
    setLoggedInUser(loggedInUserID);
    testWindow.setLoggedInUser(loggedInUserID);
    doseWindow.setLoggedInUser(loggedInUserID);
    detailsWindow.setLoggedInUserID(loggedInUserID);
    ui->setupUi(this);
}

WhichHistory::~WhichHistory()
{
    delete ui;
}

void WhichHistory::on_btn_backToHome_clicked()
{
    this->close();
}

void WhichHistory::on_btn_vaxHistory_clicked()
{
    doseWindow.show();
    doseWindow.setDisplayedDoses();
    doseWindow.setPageNumbersDisplay();
}


void WhichHistory::on_btn_testHistory_clicked()
{   
    testWindow.show();
    testWindow.setDisplayedTests();
    testWindow.setPageNumbersDisplay();
}


void WhichHistory::on_btn_accountDetails_clicked()
{
    detailsWindow.show();
    detailsWindow.setDisplay();
}

