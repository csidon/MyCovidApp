#include "mainwindow.h"
#include "authdialog.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the app stylesheet
    QFile file("../0806_mCR_login/Toolery.qss");
    file.open(QFile::ReadOnly);
    QString tooleryFile = QLatin1String(file.readAll());

    qApp->setStyleSheet(tooleryFile);


    MainWindow w;
    w.show();

    AuthDialog authdialog;
    authdialog.setModal(true);
    authdialog.exec();


    return a.exec();
}
