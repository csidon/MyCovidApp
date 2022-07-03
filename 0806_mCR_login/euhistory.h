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

    void printPageIntro();
    void collectAllTestInfo();
    void collectAllVaxInfo();
    void printEUHistory(int page);
    void printEUprofile();

    void clearPage();
//                        int numRows,int totalPages, int movingToPage,
//                          int currentPage, int vaxRows);
//                          allTestDateValues,allTestResultValues,
//                          vaxRows, allVaxDates, allVaxManufs);
public slots:
    void goToNextPage();
    void goToPrevPage();

private slots:
    void on_btn_backToAdminHome_clicked();

private:
    int userID;
    QString testDate;
    int numRows = 0;            // These pages/rows all refer to the Test pages
    int totalPages = 0;         // since they are the only ones that have
    int movingToPage = 0;       // a list that will keep growing
    int currentPage = 0;
    int vaxRows = 0;
    QLabel *pageHeader;      // These labels are constant
    QLabel *dispUserName;    // So pointers are initialised right at the top
    QLabel *dispNHI;
    ExpandingToolBox *profileToolBox;
    ExpandingToolBox *toolBox;
    CustomListWidget *c19VaxHistory;
    CustomListWidget *c19TestList;
    QVBoxLayout *overallWrapper;
    QVBoxLayout *pageIntro;
    QVBoxLayout *userProfile;
    QVBoxLayout *overarchingLayout;


    // Labels/vars used for displaying test results
    // ReportType and TestType are hardcoded to Self-reported and RAT
    // for this version
    // New objs have to be created for each label (They are temporary objects)
    QLabel *testTypeUL;
    QLabel *dateLabelUR;
    QLabel *reportTypeBL;
    QLabel *testResultBR;

    //--------------------------------------------
    //Creating QStringLists to store each row of test/vaxdata
    //(we only really care about test dates and test results)

    // THESE ARE NOT POINTERS!
    //--- Test Data ---
    QStringList allTestDateValues = {};
    QStringList allTestResultValues = {};
    //---Vax Data ---
    QStringList allVaxDates = {};
    QStringList allVaxManufs = {};
    //--------------------------------------------

    Ui::EUHistory *ui;
};

#endif // EUHISTORY_H
