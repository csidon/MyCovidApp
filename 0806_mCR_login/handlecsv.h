#ifndef HANDLECSV_H
#define HANDLECSV_H

#include <QStringList>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QMap>

#include <QDebug>
#include "useraccount.h"


class HandleCSV
{
public:
    HandleCSV();

    // ################# Functions ####################
    // Returning the database path based on shortname
    QString returnCSVFilePath(QString dbName);

    // Mapping database header fields to specific indexes
    int returnHeaderIndex(QString dbName, QString headerName);

    // Get all data in a column for a specified header for a CSV file
    QStringList getColData(QString headerName, QString dbName);

    // Validates if any of the values in the column exist
    // and returns the row index if yes
    int rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue);

    // Gets a specific cell's value based on header and row index
    QString getCellValue(QString dbName, int headerIn, int rowIn);

};

#endif // HANDLECSV_H