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

bool Test::getTestIsNew()
{
    return this->testIsNew;
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

void Test::setTestIsNew(bool isNew)
{
    this->testIsNew = isNew;
}

//Constructor
Test::Test()
{
    testUserID = 0;
    testDate = 0;
    testResult = false;
    testIsNew = true;
}
