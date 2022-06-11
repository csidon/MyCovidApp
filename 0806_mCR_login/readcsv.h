#ifndef READCSV_H
#define READCSV_H
#include "useraccount.h"
#include <QStringList>
#include <QFile>
#include <QString>


class ReadCSV
{
public:


    ReadCSV();
    QStringList getSpecificCell(std::string searchString, QString fileAddress);
    int searchRowValue(QStringList listToSearch, std::string searchValue);


};

#endif // READCSV_H
