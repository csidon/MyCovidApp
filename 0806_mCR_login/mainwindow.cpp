#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_QRrequested->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_requestQR_clicked()
{
    UserAccount loggedInUser;
    int ret = QMessageBox::warning(this,tr("Requesting QR code"),
             tr("QR codes (Vaccination certificates) can take "
                "up to 48 hours to process. \nRequest a QR code?"),
             QMessageBox::Cancel | QMessageBox::Yes);

    qDebug() << "What have you selected? "
                "(should return 16384 for yes | 4194304 for cancel ) " << ret;

    if(ret == 16384)
    {
        ui->btn_requestQR->hide();
        ui->btn_QRrequested->show();
        loggedInUser.requestQR();
        // To implement actual write-to-QRCodeRequests.csv and write to
        // userPID file

    }
}

