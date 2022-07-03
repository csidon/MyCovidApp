#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QWidget>
#include "adminerrorreports.h"
#include "adminqrrequests.h"
#include "adminsearchusers.h"
#include "handlecsv.h"

namespace Ui {
class AdminHome;
}

class AdminHome : public QWidget
{
    Q_OBJECT
public:
    explicit AdminHome(QWidget *parent = nullptr);
    ~AdminHome();

private slots:
    void on_btn_QRCodeRequests_clicked();

    void on_btn_issuesReported_clicked();

    void on_btn_searchAndManageUsers_clicked();

private:
    Ui::AdminHome *ui;
    AdminErrorReports adminErrorReports;
    AdminQRRequests adminQRRequestsWindow;
    AdminSearchUsers adminSearchUsers;
};

#endif // ADMINHOME_H
