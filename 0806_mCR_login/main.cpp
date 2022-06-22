#include "adminhome.h"
#include "adminqrrequests.h"
#include "mainwindow.h"
#include "authdialog.h"
#include "useraccount.h"
#include "test.h"
#include "dose.h"
#include "handlecsv.h"
#include "covidtestform.h"
#include <QDebug>
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QObject>
#include <QTextStream>
#include <QString>
#include <QStandardPaths>


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

    // Set application name
    a.setApplicationName("MyCovidApp");




    // Set the app stylesheet
    QFile styleFile(":/Toolery.qss");
    styleFile.open(QFile::ReadOnly);
    QString tooleryFile = QLatin1String(styleFile.readAll());

    qApp->setStyleSheet(tooleryFile);

    int loggedInUserID = 0;

     HandleCSV testCSVFunctions;
    qDebug() << testCSVFunctions.returnCSVFilePath("dbPID");
   qDebug() << "You have finished returning CSV file path";
    int headerIn = testCSVFunctions.returnHeaderIndex("dbPID","userEmail");
    qDebug() << "Header int for userEmail is " << headerIn;
    testCSVFunctions.getColData("userLastName","dbPID");
    int rowInTest = testCSVFunctions.rowIndexOfCellMatchingSearch(testCSVFunctions.getColData("userFirstName","dbPID"),"Luciano");
    qDebug() << "Row index for Luciano is " << rowInTest;   // is row index correct..??
    QString cellValTest = testCSVFunctions.getCellValue("dbPID",6,2);
    qDebug() << "Cell value retrieved is " << cellValTest;
    UserAccount testUser;
    testUser = testCSVFunctions.getUserAccount("woo@kie.com");
    qDebug() << "The test user wookie's NHI number is " << testUser.getUserNHINumber();
    testUser = testCSVFunctions.getUserAccount(234523);
    qDebug() << "The test user with UID 234523 is " << testUser.getUserFirstName();

    UserAccount fakeUser;
    fakeUser = UserAccount(98989,"please@work.com","asdQW123!","Pretty","Please","IcingSugar","PS1234",0220131234,0,0,"");

    HandleCSV writeTest;
    writeTest.writeToPIDCSV(fakeUser);

    Test fakeTest;
    fakeTest.setTestDate("15-06-22");
    fakeTest.setTestRecDate("22-06-22");
    fakeTest.setTestResult(false);
    fakeTest.setTestUserID(19);
    fakeUser.addTest(fakeTest);


//    Test Dose Storage
//    Dose testDose;
//    testDose.setDoseDate(220614);
//    testDose.setDoseManufacturer(1);
//    UserAccount testUser;
//    testUser.setUserIDNumber(4842);
//    testUser.addDose(testDose);


//    AuthDialog authdialog;
//    authdialog.setModal(true);
//    authdialog.exec();
//    loggedInUserID = authdialog.getLoggedInUserID();

    //MainWindow w = MainWindow(nullptr, loggedInUserID);
    //w.show();
    //w.setLoggedInUserID(loggedInUserID);


//    CovidTestForm covidTests;
//    covidTests.show();
//    covidTests.setLoggedInUserID(loggedInUserID);




//    AdminQRRequests adminQRRequests;
//    adminQRRequests.show();


    //AdminHome adminHome;
    //adminHome.show();
//    adminQRRequests viewQRRequests;
//    viewQRRequests.show();



    return a.exec();
}

