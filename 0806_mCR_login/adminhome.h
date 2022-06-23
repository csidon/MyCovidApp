#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QWidget>
#include "adminqrrequests.h"
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

public slots:
    void openAdminQRRequestsWindow();

private slots:
    void on_btn_QRCodeRequests_clicked();

private:
    Ui::AdminHome *ui;
    AdminQRRequests *adminQRRequestsWindow;
};

#endif // ADMINHOME_H
