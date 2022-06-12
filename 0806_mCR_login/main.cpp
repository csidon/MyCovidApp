#include "mainwindow.h"
#include "authdialog.h"
#include "useraccount.h"
#include "test.h"
#include "dose.h"
#include "handlecsv.h"
#include <QDebug>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

    // Set the app stylesheet
    QFile styleFile("../0806_mCR_login/Toolery.qss");
    styleFile.open(QFile::ReadOnly);
    QString tooleryFile = QLatin1String(styleFile.readAll());

    qApp->setStyleSheet(tooleryFile);

    HandleCSV testCSVFunctions;
    testCSVFunctions.returnCSVFilePath("dbTest");
    qDebug() << "You have finished returning CSV file path";
    int headerIn = testCSVFunctions.returnHeaderIndex("dbPID","userEmail");
    qDebug() << "Header int for userEmail is " << headerIn;
    testCSVFunctions.getColData("userLastName","dbPID");
    int rowInTest = testCSVFunctions.rowIndexOfCellMatchingSearch(testCSVFunctions.getColData("userFirstName","dbPID"),"Luciano");
    qDebug() << "Row index for Luciano is " << rowInTest;   // is row index correct..??
    QString cellValTest = testCSVFunctions.getCellValue("dbPID",6,1);
    qDebug() << "Cell value retrieved is " << cellValTest;


//    UserAccount extractedTestUser;
//    QStringList answer = readTest.getSpecificCell("userLastName", ":/database/dummyPID.csv");
//    qDebug() << answer;
//    extractedTestUser = extractedTestUser.getUserData(readTest.searchRowValue(answer,"Skywalker"));
//    qDebug() << QString::fromStdString(extractedTestUser.getUserEmail()) << extractedTestUser.validateEmailInUse(extractedTestUser.getUserEmail());
//    extractedTestUser.assignID();




    MainWindow w;
    w.show();

    AuthDialog authdialog;
    authdialog.setModal(true);
    authdialog.exec();

    return a.exec();
}