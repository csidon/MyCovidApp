#ifndef ADMINQRREQUESTS_H
#define ADMINQRREQUESTS_H

#include <QWidget>

namespace Ui {
class adminQRRequests;
}

class adminQRRequests : public QWidget
{
    Q_OBJECT

public:
    explicit adminQRRequests(QWidget *parent = nullptr);
    ~adminQRRequests();

private:
    Ui::adminQRRequests *ui;
};

#endif // ADMINQRREQUESTS_H
