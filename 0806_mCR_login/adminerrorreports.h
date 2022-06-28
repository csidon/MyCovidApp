#ifndef ADMINERRORREPORTS_H
#define ADMINERRORREPORTS_H

#include "useraccount.h"
#include <QWidget>
#include <QLabel>

namespace Ui {
class AdminErrorReports;
}

class AdminErrorReports : public QWidget
{
    Q_OBJECT
private:
    QLabel* reportLabels[6];
    QLabel* nameLabels[6];
    QLabel* newLabels[6];
    QLabel* dateLabels[6];
    int pageNumber = 0, noOfPages = 0;

public:
    explicit AdminErrorReports(QWidget *parent = nullptr);
    ~AdminErrorReports();
    //Getters and Setters
    int getNoOfPages();
    void setNoOfPages(int newNoOfPages);
    int getPageNumber();
    void setPageNumber(int newPageNumber);

    void setDisplayedReports();
    void updatePageNumberDisplay();
    void viewButtonClicked(int button);
    QString formatNameForDisplay(UserAccount user);

private slots:
    void on_btn_backToAdminHome_clicked();

    void on_btn_pageLeft_clicked();

    void on_btn_pageRight_clicked();

    void on_btn_view_1_clicked();

    void on_btn_view_2_clicked();

    void on_btn_view_3_clicked();

    void on_btn_view_4_clicked();

    void on_btn_view_5_clicked();

    void on_btn_view_6_clicked();

private:
    Ui::AdminErrorReports *ui;
};

#endif // ADMINERRORREPORTS_H
