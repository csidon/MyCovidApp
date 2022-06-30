#ifndef DISPLAYMYQRCODE_H
#define DISPLAYMYQRCODE_H

#include "useraccount.h"
#include <QWidget>
#include <QStandardPaths>

namespace Ui {
class DisplayMyQRCode;
}

class DisplayMyQRCode : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayMyQRCode(QWidget *parent = nullptr, int userID = 0);
    QString formatNameForDisplay(UserAccount dataSource);
    ~DisplayMyQRCode();

private slots:
    void on_btn_backToHome_clicked();

private:
    Ui::DisplayMyQRCode *ui;
};

#endif // DISPLAYMYQRCODE_H
