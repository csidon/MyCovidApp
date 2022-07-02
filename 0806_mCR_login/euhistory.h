#ifndef EUHISTORY_H
#define EUHISTORY_H

#include <QWidget>

#include <QListWidget>
#include <QDateTime>
#include <QCommonStyle>
#include <QFrame>
#include <QToolBox>
#include <QPushButton>
#include <QListWidgetItem>
#include <QVector>

#include "useraccount.h"
#include "handlecsv.h"
#include "useraccount.h"
#include "toolitem.h"
#include "expandingtoolbox.h"
#include "customlistwidget.h"

namespace Ui {
class EUHistory;
}

class EUHistory : public QWidget
{
    Q_OBJECT

public:
    explicit EUHistory(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~EUHistory();
    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);
    QString getTestDate();
    void setTestDate(QString tDate);
//    CustomListWidget printTestSummary(int pageNum, std::vector<QString>, std::vector<QString>);

    int getCurrentPage() const;
    void setCurrentPage(int newCurrentPage);

    int getTotalPages() const;
    void setTotalPages(int newTotalPages);

    int getMovingToPage() const;
    void setMovingToPage(int newMovingToPage);

    int getNumRows() const;
    void setNumRows(int newNumRows);

    void printHistoryPage();

    void clearPage();
//                        int numRows,int totalPages, int movingToPage,
//                          int currentPage, int vaxRows);
//                          allTestDateValues,allTestResultValues,
//                          vaxRows, allVaxDates, allVaxManufs);
public slots:
    void goToNextPage();

private slots:
    void on_btn_backToAdminHome_clicked();

private:
    int userID;
    QString testDate;
    int numRows;            // These pages/rows all refer to the Test pages
    int totalPages;         // since they are the only ones that have
    int movingToPage;       // a list that will keep growing
    int currentPage;
    int vaxRows = 0;
    QLabel *pageHeader;
    QLabel *dispUserName;
    QLabel *dispNHI;
    ExpandingToolBox *toolBox;
    CustomListWidget *c19VaxHistory;
    CustomListWidget *c19TestList;
    QVector<CustomListWidget> *allTestLabelValues;
    QVBoxLayout *overarchingLayout;
    QVBoxLayout *overallWrapper;

    // Labels/vars used for displaying test results
    // ReportType and TestType are hardcoded to Self-reported and RAT
    // for this version

    QLabel *testTypeUL;
    QLabel *dateLabelUR;
    QLabel *reportTypeBL;
    QLabel *testResultBR;

    //Creating a vector to store each row of data -- **Can use a QStringList
    //(we only really care about test dates and test results)
    QVector<QString> allTestDateValues;     // **Create getters/setters!
    QVector<QString> allTestResultValues;

    QStringList allVaxDates;
    QStringList allVaxManufs;
public:
    Ui::EUHistory *ui;
};

#endif // EUHISTORY_H
