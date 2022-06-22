#include "test.h"


//Getters
int Test::getTestUserID()
{
    return this->testUserID;
}

QString Test::getTestDate()
{
    return this->testDate;
}

bool Test::getTestResult()
{
    return this->testResult;
}

QString Test::getTestRecDate()
{
    return this->testRecDate;
}

//Setters
void Test::setTestUserID(int userID)
{
    this->testUserID = userID;
}

void Test::setTestDate(QString date)
{
    this->testDate = date;
}

void Test::setTestResult(bool result)
{
    this->testResult = result;
}

void Test::setTestRecDate(QString thisDate)
{
    this->testRecDate = thisDate;
}

//Constructor
Test::Test()
{
    testUserID = 0;
    testDate = "";
    testResult = false;
    testRecDate = "";
}

//Test::Test(QString testDate = "", bool testResult = false,
//           int uid = 0, QString testRecDate = "")
//{
//    this->testUserID = uid;
//    this->testDate = testDate;
//    this->testResult = testResult;
//    this->testRecDate = testRecDate;
//}
