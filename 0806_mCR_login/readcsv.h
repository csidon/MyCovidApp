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

//    // ################# Functions ####################
//    // Returning the database path based on shortname
//    QString returnCSVFilePath(QString dbName);

//    // Mapping database header fields to specific indexes
//    int returnHeaderIndex(QString dbName, QString headerName);

//    // Get all data in a column for a specified header for a CSV file
//    QStringList getColData(QString headerName, QString dbName);
QStringList HandleCSV::getColData(int headerIndex, QString dbName)

//    // Validates if any of the values in the column exist
//    // and returns the row index if yes
//    int rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue);

//    // Gets a specific cell's value based on header and row index
//    QString getCellValue(QString dbName, int headerIn, int rowIn);

    //--old -- do HseKeep //    QStringList getSpecificCell(std::string searchString, QString fileAddress);
    //--OLD-- int ReadCSV::searchRowValue(QStringList listToSearch, std::string searchValue)
    //--OLD -- do hseKeep // int searchRowValue(QStringList listToSearch, std::string searchValue);



};

#endif // READCSV_H
