#include "adminerrorreports.h"
#include "adminhome.h"
#include "adminqrrequests.h"
#include "adminsearchusers.h"
#include "mainwindow.h"
#include "authdialog.h"
#include "useraccount.h"
#include "test.h"
#include "dose.h"
#include "handlecsv.h"
#include "covidtestforms.h"
#include "euhistory.h"
#include "addvaccination.h"


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

    int loggedInUserID = 0;        // Initialising.. user hasn't logged in

    AuthDialog authdialog;
    authdialog.setModal(true);
    authdialog.exec();
    loggedInUserID = authdialog.getLoggedInUserID();

    MainWindow w = MainWindow(nullptr, loggedInUserID);
    w.setLoggedInUserID(loggedInUserID);

    if (loggedInUserID !=42 && loggedInUserID > 0)
    {
        qDebug() << "You Are NOT an admin";
        w.show();
    }
     return a.exec();
}

