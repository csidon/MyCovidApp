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
    QFile file("../0806_mCR_login/Toolery.qss");
    file.open(QFile::ReadOnly);
    QString tooleryFile = QLatin1String(file.readAll());

    qApp->setStyleSheet(tooleryFile);

    ReadCSV readTest;
    UserAccount extractedTestUser;
    QStringList answer = readTest.getSpecificCell("userLastName");
    qDebug() << answer;
    extractedTestUser = extractedTestUser.getRowData(readTest.searchRowValue(answer,"Skywalker"));
    qDebug() << QString::fromStdString(extractedTestUser.getUserEmail());




    MainWindow w;
    w.show();

    AuthDialog authdialog;
    authdialog.setModal(true);
    authdialog.exec();

    return a.exec();
}
