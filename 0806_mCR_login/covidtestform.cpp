#include "covidtestform.h"
#include "ui_covidtestform.h"


CovidTestForm::CovidTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CovidTestForm)
{
    ui->setupUi(this);

    // This section retrieves the current date
    // and sets this as the QSpinBox default
    QDate date;
    //*testing
    QString yy = QString::number(ui->spinBox_YY->value() + 2000);
    QString mm = QString::number(ui->spinBox_MM->value());
    qDebug() << "Is this a string? " << yy + "-" + mm;
    //*testing

    auto thisDate = date.currentDate();
    int year = date.currentDate().year() - 2000;
    int month = date.currentDate().month();
    int day = date.currentDate().day();
    qDebug() << "The date retrieved is " << thisDate;
    ui->spinBox_YY->setValue(year);
    ui->spinBox_MM->setValue(month);
    ui->spinBox_DD->setValue(day);

    // Hides error labels to start
    ui->lbl_errSelectResult->hide();
    ui->lbl_errSelectTerms->hide();

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
    while (addResult == 0 || selTerms == 0)
    {
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
            int testResult = 0;
            ui->lbl_errSelectResult->hide();
            ui->frame_errSelectResult->setStyleSheet
                    ("#errSelectResult" "{ border: 0px;}");
            if (ui->rBtn_testNeg->isChecked() == true)
            {
                // Test result is negative
                collectTestInfo.setTestResult(0);
            }
            else collectTestInfo.setTestResult(1);

            addResult = 1;
        }
    }

    // Setting test dates
    QString yy = QString::number(ui->spinBox_YY->value()+2000);
    QString mm = QString::number(ui->spinBox_MM->value());
    QString dd = QString::number(ui->spinBox_DD->value());
    collectTestInfo.setTestDate(yy + "-" + mm+ "-" + dd);
    // Stored in YYYYMMDD for future sorting ease


//    QString thisDate = QDate::toString(today);
//    collectTestInfo.setTestRecDate(thisDate);
//    qDebug() << "This date registered is " << thisDate;
    qDebug() << "Is this a string? " << yy + "-" + mm+ "-" + dd;


    // ****Need to add current date***
    writeToTestCSV(getLoggedInUserID(),collectTestInfo.getTestDate(),
                   collectTestInfo.getTestResult());

}





