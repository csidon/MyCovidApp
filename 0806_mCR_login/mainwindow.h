#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    Ui::MainWindow *ui;
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
};
#endif // MAINWINDOW_H
