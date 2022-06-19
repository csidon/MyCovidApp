#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "useraccount.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int loggedInUserID;
public:
    MainWindow(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~MainWindow();

    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);

//public slots:
    //void receiveUID(int uid);

private slots:
    void on_btn_requestQR_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
