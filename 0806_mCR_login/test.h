#ifndef TEST_H
#define TEST_H
#include <QWidget>
#include <QDate>
#include <QString>
#include <QObject>


class Test
{
private:
    int testUserID;
    int testDate;
    bool testResult;
    int testRecDate;
public:
    //Getters
    int getTestUserID();
    int getTestDate();
    bool getTestResult();
    int getTestRecDate();

    //Setters
    void setTestUserID(int userID);
    void setTestDate(int date);
    void setTestResult(bool result);
    void setTestRecDate(int recDate);

    //Constructor
    Test();
//    Test(QString testDate, bool testResult, int uid, QString testRecDate);
};

#endif // TEST_H
