#include "submiterrorreport.h"
#include "handlecsv.h"
#include "qdir.h"
#include "ui_submiterrorreport.h"

//Getter
int SubmitErrorReport::getLoggedInUser()
{
    return loggedInUser;
}

//Setter
void SubmitErrorReport::setLoggedInUser(int newLoggedInUser)
{
    loggedInUser = newLoggedInUser;
}

SubmitErrorReport::SubmitErrorReport(QWidget *parent, int userID) :
    QWidget(parent),
    ui(new Ui::SubmitErrorReport)
{
    loggedInUser = userID;
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
    //Append report details to csv
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
            //format date
            QString date = ui->dateEdit->date().toString("yyyy-MM-dd");
            date.remove('-');
            //substitute commas and line breaks with rarely used characters ` and ~ to presever them through csv storage
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
                if(escapedText[i] == '\n'){
                    escapedText[i] = '`';
                }
            }
            qDebug() << "escapedText = " << escapedText;
            //output to file
            QTextStream stream(&f);
            stream << escapedTitle << "," << escapedText << "," << date << "," << loggedInUser << "," << "TRUE" << "\n";
            qDebug() << "I have theoretically streamed data.";
        }
        f.close();
    }
    QMessageBox::information(this, "Error Report Submitted", "Report Submitted. Thank you!");
    this->close();
}

