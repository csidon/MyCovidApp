#ifndef ADMINQRREQUESTS_H
#define ADMINQRREQUESTS_H

#include "useraccount.h"
#include <QWidget>
#include <QObject>

namespace Ui {
class adminQRRequests;
}

class AdminQRRequests : public QWidget
{
    Q_OBJECT
private:
    int pageNumber = 0;
public:
    explicit AdminQRRequests(QWidget *parent = nullptr);
    ~AdminQRRequests();
    void setDisplayedUsers(int newPageNumber);

    int getPageNumber();
    void setPageNumber(int newPageNumber);
    void updatePageNumberDisplay();
    QString formatNameForDisplay(UserAccount dataSource);
signals:
    void pageTurned(int);
private slots:
    void on_btn_pageRight_clicked();

    void on_btn_pageLeft_clicked();

    void on_btn_backToAdminHome_clicked();

    void setDisplay(int topUser);

private:
    Ui::adminQRRequests *ui;
};

#endif // ADMINQRREQUESTS_H
