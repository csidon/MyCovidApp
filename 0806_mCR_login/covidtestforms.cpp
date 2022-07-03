#include "covidtestforms.h"
#include "ui_covidtestforms.h"

CovidTestForms::CovidTestForms(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::CovidTestForms)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setLoggedInUserID(loggedInUserID);

    // This section retrieves the current date
    // and sets this as the QSpinBox default

    //*testing
//    QString yy = QString::number(ui->spinBox_YY->value() + 2000);
//    QString mm = QString::number(ui->spinBox_MM->value());
//    qDebug() << "Is this a string? " << yy + "-" + mm;
    //*testing


    // Setting the date on the spinbox to today's date as a default
    QDate date;
    auto thisDate = date.currentDate();
    int year = date.currentDate().year() - 2000;
    int month = date.currentDate().month();
    int day = date.currentDate().day();
    qDebug() << "The date retrieved is " << thisDate;
    qDebug() << "What is the year printed without modification? " << date.currentDate().year();
    ui->spinBox_YY->setValue(year);
    ui->spinBox_MM->setValue(month);
    ui->spinBox_DD->setValue(day);

    // Hides error labels to start
    ui->lbl_errSelectResult->hide();
    ui->lbl_errSelectTerms->hide();
}

CovidTestForms::~CovidTestForms()
{
    delete ui;
}
int CovidTestForms::getLoggedInUserID()
{
    return loggedInUserID;
}

void CovidTestForms::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}


void CovidTestForms::on_pushButton_clicked()
{
    // Used to capture test results
    Test collectTestInfo;

    // When clicking submit, get the current date as an int form (YYYYMMDD) <-- Stored as testRecDate in MasterTests
    // Then get the GUI's spinbox date
    QDate date;

    int year = date.currentDate().year();
    int month = date.currentDate().month();
    int day = date.currentDate().day();
    int thisDate = (year * 10000) + (month * 100) + day;
    qDebug() << "thisDate is an INTEGER registered as " << thisDate;

    int yy = (ui->spinBox_YY->value() + 2000) * 10000;
    int mm = ui->spinBox_MM->value() * 1000;
    int dd = ui->spinBox_DD->value();
    int retrievedTestDate = yy + mm + dd;
    collectTestInfo.setTestDate(retrievedTestDate);
    qDebug() << "retrievedTestDate is an INTEGER registered as " << retrievedTestDate;


    //----------------------------------------------------------
    // Checks that the user has selected a test result
    // and has accepted the terms and conditions.
    // Throws error messages if this criteria is not fulfilled
    //-------
    ui->frame_affirm->setObjectName("readTerms");
    ui->frame_errSelectResult->setObjectName("errSelectResult");
    // Flags to check if results and terms are entered
    int addResult = 0;
    int selTerms = 0;

    // Providing user error messages if they have not acknowledged
    // terms or selected a positive/negative result
    if (ui->checkBox_affirmAccuracy->checkState()==false)
    {
        ui->frame_affirm->setStyleSheet("#readTerms "
                                        "{ border: 2px solid #FFCC01; }");
        ui->lbl_errSelectTerms->show();     // Shows error message
    }
    else    // hides error if showing, and flags error message as read
    {
        ui->frame_affirm->setStyleSheet("#readTerms "
                                        "{ border: 0px; }");
        ui->lbl_errSelectTerms->hide();
        selTerms = 1;
    }
    //--- User has not selected a test result
    if(ui->rBtn_testNeg->isChecked() == false
            && ui->rBtn_testPos->isChecked() == false)
    {
        ui->lbl_errSelectResult->show();
        ui->frame_errSelectResult->setStyleSheet
                ("#errSelectResult" "{ border: 2px solid #FFCC01; }");
        addResult = 0;
    }
    else
    {
        ui->lbl_errSelectResult->hide();
        ui->frame_errSelectResult->setStyleSheet
                ("#errSelectResult" "{ border: 0px;}");

        // If the user selected negative, set TestResult as false
        // otherwise set as True
        if (ui->rBtn_testNeg->isChecked() == true)
        {
            // Test result is negative
            collectTestInfo.setTestResult(false);
        }
        else collectTestInfo.setTestResult(true);

        addResult = 1;
    }

    // If the user has entered both the results and acknowledged the terms
    // collect all info into QString
    if(addResult == 1 && selTerms == 1)
    {
        collectTestInfo.setTestRecDate(thisDate);
        collectTestInfo.setTestDate(retrievedTestDate);
        qDebug() << "LoggedInUserID is: " << getLoggedInUserID();
        collectTestInfo.setTestUserID(getLoggedInUserID());

        // Checks to make sure all test data is stored
        qDebug() << "CSV Test Date is: " << collectTestInfo.getTestDate();
        qDebug() << "CSV Recorded Date is: " << collectTestInfo.getTestRecDate();
        qDebug() << "CSV Results are: " << collectTestInfo.getTestResult();
        qDebug() << "CSV user ID  is: " << collectTestInfo.getTestUserID();

//        // Retrieving the user's input test date from ui
//        QString yy = QString::number(ui->spinBox_YY->value()+2000);
//        QString mm = QString::number(ui->spinBox_MM->value());
//        QString dd = QString::number(ui->spinBox_DD->value());
//        QString retrievedTestDate = yy + "-" + mm+ "-" + dd;
//        collectTestInfo.setTestDate(retrievedTestDate);
//        int yy = ui->spinBox_YY->value() * 100000;
//        int mm = ui->spinBox_MM->value() * 1000;
//        int dd = ui->spinBox_DD->value();
//        int retrievedTestDate = yy + mm + dd;


        // Stored in YYYYMMDD for future sorting ease
//        qDebug() << "Is this a string? " << yy + "-" + mm+ "-" + dd;


        UserAccount newTest;
        newTest.addTest(collectTestInfo);
        ui->stackedWidget->setCurrentIndex(1);
        // #******* you need to set this to display the right collected date later!!****
//        ui->lbl_displayTestDate->setText(collectTestInfo.getTestDate());
        if (collectTestInfo.getTestResult() == true)
        {
            ui->lbl_displayTestRes->setText("Positive");
        }
        else
        {
            ui->lbl_displayTestRes->setText("Negative");
        }
    }
}

void CovidTestForms::on_pushButton_2_clicked()
{
    this->close();
}


void CovidTestForms::on_btn_backToAdminHome_clicked()
{
    this->close();
}

