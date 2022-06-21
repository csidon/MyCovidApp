#ifndef TEST_H
#define TEST_H
#include <QWidget>
#include <QDate>
#include <QString>


class Test
{
private:
    int testUserID;
    QString testDate;
    bool testResult;
    QString testRecDate;
public:
    //Getters
    int getTestUserID();
    QString getTestDate();
    bool getTestResult();
    QString getTestRecDate();

    //Setters
    void setTestUserID(int userID);
    void setTestDate(QString date);
    void setTestResult(bool result);
    void setTestRecDate(QString recDate);

    //Constructor
    Test();
//    Test(QString testDate, bool testResult, int uid, QString testRecDate);
};

#endif // TEST_H
