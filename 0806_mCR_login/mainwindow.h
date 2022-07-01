#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "displaymyqrcode.h"
#include "submiterrorreport.h"
#include "useraccount.h"
#include <QMessageBox>
#include "covidtestforms.h"
#include "euhistory.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int loggedInUserID;
    CovidTestForms *covidTestWindow;
    EUHistory *euHistoryWindow;
    DisplayMyQRCode *displayQRWindow;
    Ui::MainWindow *ui;
    SubmitErrorReport submitErrorReport;
public:
    MainWindow(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~MainWindow();

    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);

public slots:
    void openCovidTestWindow();
    void openEUHistoryWindow();

private slots:
    void on_btn_requestQR_clicked();
    void on_btn_reportRat_clicked();



    void on_btn_vaxHistory_clicked();
    void on_btn_displayQR_clicked();
    void on_btn_accountDetails_clicked();
};
#endif // MAINWINDOW_H
