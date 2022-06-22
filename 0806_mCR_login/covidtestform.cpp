#include "covidtestform.h"
#include "ui_covidtestform.h"
#include "useraccount.h"


CovidTestForm::CovidTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CovidTestForm)
{
    ui->setupUi(this);




}

CovidTestForm::~CovidTestForm()
{
    delete ui;
}

int CovidTestForm::getLoggedInUserID()
{
    return loggedInUserID;
}

void CovidTestForm::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}

void CovidTestForm::writeToTestCSV(int uid, QString testDate, bool testRes)
//, QString testRecDate
{
    HandleCSV csvFile;
    QString filePath = csvFile.returnCSVFilePath("dbTest");
    qDebug() << "File path passsed to writeToTestCSV is " <<  filePath;

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        qDebug() << file.isOpen() << "error " << file.errorString();
    }
    else
    {
        qDebug() << "Is dbTest open?: " << file.isOpen();

        // Streaming info back into db
        QTextStream stream(&file);
        stream << testDate << "," << testRes << "," << uid << "\n";
        //<< "," << testRecDate
    }


    file.close();
}

void CovidTestForm::on_pushButton_clicked()
{
    QDate date;
    QDate thisDate = date.currentDate();

    // Used to capture test results
    Test collectTestInfo;

    ui->frame_affirm->setObjectName("readTerms");
    ui->frame_errSelectResult->setObjectName("errSelectResult");
    int addResult = 0;
    int selTerms = 0;

    // Providing user error messages if they have not acknowledged
    // terms or selected a positive/negative result
    if (ui->checkBox_affirmAccuracy->checkState()==false)
    {
        ui->frame_affirm->setStyleSheet("#readTerms "
                                        "{ border: 2px solid #FFCC01; }");
        ui->lbl_errSelectTerms->show();
    }
    else
    {
        ui->frame_affirm->setStyleSheet("#readTerms "
                                        "{ border: 0px; }");
        ui->lbl_errSelectTerms->hide();
        selTerms = 1;
    }
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
        // Converting thisDate to QString
        QString testInDate = thisDate.toString("yyyy-MM-dd");
        qDebug() << "The testInDate recorded is " << testInDate;
        collectTestInfo.setTestRecDate(testInDate);

        // Retrieving the user's input test date from ui
        QString yy = QString::number(ui->spinBox_YY->value()+2000);
        QString mm = QString::number(ui->spinBox_MM->value());
        QString dd = QString::number(ui->spinBox_DD->value());
        QString retrievedTestDate = yy + "-" + mm+ "-" + dd;
        collectTestInfo.setTestDate(retrievedTestDate);
        // Stored in YYYYMMDD for future sorting ease
        qDebug() << "Is this a string? " << yy + "-" + mm+ "-" + dd;

        qDebug() << "LoggedInUserID is: " << getLoggedInUserID();
        collectTestInfo.setTestUserID(getLoggedInUserID());


        qDebug() << "CSV Test Date is: " << collectTestInfo.getTestDate();
        qDebug() << "CSV Recorded Date is: " << collectTestInfo.getTestRecDate();
        qDebug() << "CSV Results are: " << collectTestInfo.getTestResult();
        qDebug() << "CSV user ID  is: " << collectTestInfo.getTestUserID();


        UserAccount newTest;
        newTest.addTest(collectTestInfo);
        ui->stackedWidget->setCurrentIndex(1);

    }


    // Setting test dates




//    QString thisDate = QDate::toString(today);
//    collectTestInfo.setTestRecDate(thisDate);
//    qDebug() << "This date registered is " << thisDate;



    // ****Need to add current date***
//    writeToTestCSV(getLoggedInUserID(),collectTestInfo.getTestDate(),
//                   collectTestInfo.getTestResult());


//    UserAccount newUser;
//    newUser = UserAccount(newID,inputEmail,inputPass,"","","","",0,0,0,"" );

//    // Open db and write new user into db
//    HandleCSV CSVfile;
//    CSVfile.writeToPIDCSV(newUser);

}





