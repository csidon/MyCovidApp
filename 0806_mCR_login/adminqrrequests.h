#ifndef ADMINQRREQUESTS_H
#define ADMINQRREQUESTS_H

#include "useraccount.h"
#include <QWidget>
#include <QObject>
#include <QFileDialog>
#include <QStandardPaths>

namespace Ui {
class adminQRRequests;
}

class AdminQRRequests : public QWidget
{
    Q_OBJECT
private:
    QLabel* nameLabels[6];
    int pageNumber = 0, noOfPages = 0;
public:
    explicit AdminQRRequests(QWidget *parent = nullptr);
    ~AdminQRRequests();
    void setDisplayedUsers(int newPageNumber);

    int getPageNumber();
    void setPageNumber(int newPageNumber);
    void updatePageNumberDisplay();
    QString formatNameForDisplay(UserAccount dataSource);

    int getNoOfPages();
    void setNoOfPages(int newNoOfPages);

    void assignmentButtonClicked(int button);

private slots:
    void on_btn_pageRight_clicked();

    void on_btn_pageLeft_clicked();

    void on_btn_backToAdminHome_clicked();

    void on_btn_assign_1_clicked();

    void on_btn_assign_2_clicked();

    void on_btn_assign_3_clicked();

    void on_btn_assign_4_clicked();

    void on_btn_assign_5_clicked();

    void on_btn_assign_6_clicked();

private:
    Ui::adminQRRequests *ui;
};

#endif // ADMINQRREQUESTS_H
