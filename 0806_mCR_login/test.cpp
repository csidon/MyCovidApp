#include "test.h"


//Getters
int Test::getTestUserID()
{
    return this->testUserID;
}

int Test::getTestDate()
{
    return this->testDate;
}

bool Test::getTestResult()
{
    return this->testResult;
}

int Test::getTestRecDate()
{
    return this->testRecDate;
}

//Setters
void Test::setTestUserID(int userID)
{
    this->testUserID = userID;
}

void Test::setTestDate(int date)
{
    this->testDate = date;
}

void Test::setTestResult(bool result)
{
    this->testResult = result;
}

void Test::setTestRecDate(int thisDate)
{
    this->testRecDate = thisDate;
}

//Constructor
Test::Test()
{
    testUserID = 0;
    testDate = 0;
    testResult = false;
    testRecDate = 0;
}

