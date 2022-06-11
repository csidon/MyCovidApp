#include "errorreport.h"

std::string ErrorReport::getTitle()
{
    return title;
}

std::string ErrorReport::getText()
{
    return text;
}

int ErrorReport::getDate()
{
    return date;
}

int ErrorReport::getSender()
{
    return sender;
}

bool ErrorReport::getIsNew()
{
    return isNew;
}

void ErrorReport::setTitle(std::string &newTitle)
{
    title = newTitle;
}

void ErrorReport::setText(std::string &newText)
{
    text = newText;
}

void ErrorReport::setDate(int newDate)
{
    date = newDate;
}

void ErrorReport::setSender(int newSender)
{
    sender = newSender;
}

void ErrorReport::setIsNew(bool newIsNew)
{
    isNew = newIsNew;
}

ErrorReport::ErrorReport()
{
    title = "";
    text = "";
    date = 0;
    sender = 0;
    isNew = true;
}
