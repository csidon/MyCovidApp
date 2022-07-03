#ifndef TESTHISTORY_H
#define TESTHISTORY_H

#include "qlabel.h"
#include <QWidget>

namespace Ui {
class TestHistory;
}

class TestHistory : public QWidget
{
    Q_OBJECT
private:
    QLabel* results[6];
    QLabel* dates[6];
    int loggedInUser;
    int noOfPages;
    int currentPage;
public:
    explicit TestHistory(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~TestHistory();

    int getLoggedInUser();
    void setLoggedInUser(int newLoggedInUser);

    void setDisplayedTests();
    void setPageNumbersDisplay();

    int getNoOfPages();
    void setNoOfPages(int newNoOfPages);

    int getCurrentPage();
    void setCurrentPage(int newCurrentPage);

private slots:
    void on_btn_pageLeft_clicked();

    void on_btn_pageRight_clicked();


    void on_btn_backToChoose_clicked();

private:
    Ui::TestHistory *ui;
};

#endif // TESTHISTORY_H
