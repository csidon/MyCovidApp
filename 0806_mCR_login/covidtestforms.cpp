#include "covidtestforms.h"
#include "ui_covidtestforms.h"

CovidTestForms::CovidTestForms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CovidTestForms)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

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

//    //Test TableWidget, for overwriting function that's WIP
//    ui->stackedWidget->setCurrentIndex(2);
//    UserAccount testUser;
//    updatePID(1089, testUser);

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

void CovidTestForms::updatePID(int uid, UserAccount updateUser)
{
    //Open dbPID for reading and search for UID
    HandleCSV grabpath;
    QStandardItemModel *model = new QStandardItemModel;

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = grabpath.returnCSVFilePath("dbPID");
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Writing to " << QDir::currentPath();
        QFile f{filepath};
        qDebug() << "Filepath is " << filepath;
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Is the file open? " << f.isOpen();
            qDebug() << "File error: " << f.error();
            qDebug() << "Error string: " << f.errorString();
        }
        else
        {
             // First find the row with the UID
            QStringList allUserIDs = grabpath.getColData("userIDNumber","dbPID");
            qDebug() << "Checking this list:" << allUserIDs;

            // Searching all uids in retrieved QStringList for target uid
            int userFoundInRowIndex = grabpath.rowIndexOfCellMatchingSearch(allUserIDs,QString::number(uid));
            if (userFoundInRowIndex <0)
            {
                qDebug() << "User with uid " << uid << " not found";
            }
            else        // UID found
            {
                qDebug() << "User " << uid << " has been found in rowIndex: " << userFoundInRowIndex;
                // Copy database to QTableView for manipulation
                int lineindex = 0;
                QTextStream in(&f);     // Read to text stream
                while (!in.atEnd())
                {
                    qDebug() << "The file is open. Starting to read...";
                    QString fileLine = in.readLine().trimmed();
                    QStringList lineToken = fileLine.split(",");
                    for (int j = 0; j < lineToken.size(); j++)
                    {
                        QString value = lineToken.at(j);
                        QStandardItem *item = new QStandardItem(value);
                        model->setItem(lineindex, j, item);
                    }
                    lineindex++;
                }
                f.close();
            }
            ui->tableView_test->setModel(model);

            // Copy out the user's data
            UserAccount copiedOldUser = grabpath.getUserAccount(uid);

            // Delete line in QTableView
            model->removeRow(userFoundInRowIndex);
            copiedOldUser.setUserQRStatus(5);
//            QStringList data;
//            QList <auto> list;
//            list.append(copiedOldUser.getUserPreferredName());
//            list.append(copiedOldUser.getUserEmail());
//            list.append(copiedOldUser.getUserLastName());
//            data << /*copiedOldUser.getUserPreferredName() << copiedOldUser.getUserEmail() << copiedOldUser.getUserFirstName()*/;
            model->appendRow(new QStandardItem("Name, yada, yada"));
            qDebug() << "If this works, the gui should reflect the new user info appended to the end of the QTableView";
            // Figure out how to write information as a QList and appendRow
            // Then figure out how to overwrite everything back to the file


        }

    }

}


void CovidTestForms::on_pushButton_clicked()
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
        ui->lbl_displayTestDate->setText(collectTestInfo.getTestDate());
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

