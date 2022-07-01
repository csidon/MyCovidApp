#include "submiterrorreport.h"
#include "handlecsv.h"
#include "qdir.h"
#include "ui_submiterrorreport.h"

int SubmitErrorReport::getLoggedInUser()
{
    return loggedInUser;
}

void SubmitErrorReport::setLoggedInUser(int newLoggedInUser)
{
    loggedInUser = newLoggedInUser;
}

SubmitErrorReport::SubmitErrorReport(QWidget *parent, int userID) :
    QWidget(parent),
    ui(new Ui::SubmitErrorReport)
{
    loggedInUser = userID;
    qDebug() << "Error report page uid is " << loggedInUser;
    ui->setupUi(this);
}

SubmitErrorReport::~SubmitErrorReport()
{
    delete ui;
}

void SubmitErrorReport::on_btn_backToHome_clicked()
{
    this->close();
}

void SubmitErrorReport::on_btn_submit_clicked()
{
    HandleCSV getFilePath;
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = getFilePath.returnCSVFilePath("dbReports");

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Writing to " << QDir::currentPath();
        QFile f{filepath};
        qDebug() << "Filepath is " << filepath;
        if (!f.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            qDebug() << "Is the file open? " << f.isOpen();
            qDebug() << "File error: " << f.error();
            qDebug() << "Error string: " << f.errorString();
        }
        else
        {
            qDebug() << "date is" << ui->dateEdit->date();
            QString date = ui->dateEdit->date().toString("yyyy-MM-dd");
            qDebug() << "date is" << date;
            date.remove('-');
            int formattedDate = date.toInt();
            qDebug() << "date is" << date << ", formattedDate is" << formattedDate;
            QString escapedTitle = ui->lineEdit_title->text();
            for(int i=0; i < escapedTitle.size(); i++){
                if(escapedTitle[i] == ','){
                    escapedTitle[i] = '~';
                }
            }
            QString escapedText = ui->textEdit->toPlainText();
            for(int i=0; i < escapedText.size(); i++){
                if(escapedText[i] == ','){
                    escapedText[i] = '~';
                }
            }
            QTextStream stream(&f);
            stream << escapedTitle << "," << escapedText << "," << date << "," << loggedInUser << "," << "TRUE" << "\n";
            qDebug() << "I have theoretically streamed data.";
        }
        f.close();
    }
    QMessageBox::information(this, "Error Report Submitted", "Report Submitted. Thank you!");
    this->close();
}

