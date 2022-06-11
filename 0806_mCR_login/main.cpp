#include "mainwindow.h"
#include "authdialog.h"
#include "useraccount.h"
#include "test.h"
#include "dose.h"
#include "readcsv.h"
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

    ReadCSV readTest;
    UserAccount extractedTestUser;
    QStringList answer = readTest.getSpecificCell("userLastName", ":/database/dummyPID.csv");
    qDebug() << answer;
    extractedTestUser = extractedTestUser.getUserData(readTest.searchRowValue(answer,"Skywalker"));
    qDebug() << QString::fromStdString(extractedTestUser.getUserEmail()) << extractedTestUser.validateEmailInUse(extractedTestUser.getUserEmail());
    extractedTestUser.assignID();




    MainWindow w;
    w.show();

    AuthDialog authdialog;
    authdialog.setModal(true);
    authdialog.exec();

    return a.exec();
}
