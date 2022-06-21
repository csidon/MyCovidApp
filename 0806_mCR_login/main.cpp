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


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

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
    QString cellValTest = testCSVFunctions.getCellValue("dbPID",6,1);
    qDebug() << "Cell value retrieved is " << cellValTest;


    //Test Dose Storage
//    Dose testDose;
//    testDose.setDoseDate(220614);
//    testDose.setDoseManufacturer(1);
//    UserAccount testUser;
//    testUser.setUserIDNumber(484);
//    testUser.addDose(testDose);


    //AuthDialog authdialog;
    //authdialog.setModal(true);
    //authdialog.exec();
    //loggedInUserID = authdialog.getLoggedInUserID();

    //MainWindow w = MainWindow(nullptr, loggedInUserID);
    //w.show();
    //w.setLoggedInUserID(loggedInUserID);


//    CovidTestForm covidTests;
//    covidTests.show();
//    covidTests.setLoggedInUserID(loggedInUserID);

    AdminQRRequests adminQRRequests;
    adminQRRequests.show();


    //AdminHome adminHome;
    //adminHome.show();
//    adminQRRequests viewQRRequests;
//    viewQRRequests.show();



    return a.exec();
}

