#include "readcsv.h"
#include "qdebug.h"
#include <QMessageBox>
#include <QMap>
#include <QStringList>

ReadCSV::ReadCSV()
{

}

//-----------------------------------------------------------
// Returning the database path based on shortname
QString ReadCSV::returnCSVFilePath(QString dbName)
{
    QString filePath;
    if (dbName == "dbPID")
    {
        filePath = ":/database/dummyPID.csv";
    }
    else if (dbName == "dbTest")
    {
        filePath = ":/database/MasterTests.csv";
    }
    else if (dbName == "dbDose")
    {
        filePath = ":/database/MasterDoses.csv";
    }
    // ** Add any other database/path here
    return filePath;
}

//-----------------------------------------------------------
// Mapping database header fields to specific indexes
int ReadCSV::returnHeaderIndex(QString dbName, QString headerName)
{
    int headerIndex = -1;

    QString filePath = returnCSVFilePath(dbName);

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       // qDebug() << "File did not open";
        return headerIndex;
    }

    // Read the header line and get the value of each cell
    QString headers = file.readLine().trimmed();
    QStringList headerRowValues = headers.split(',');

    // Compare that cell value to the colHeader search value
    // and grab the column index that we are retrieving
    for(int i = 0; i < headerRowValues.length(); i++)
    {
        if(headerRowValues[i] == colHeader)
        {
            headerIndex = i;
            break;
        }
    }
    return headerIndex;
}

//-----------------------------------------------------------
// Get all data in a column for a specified header for a CSV file
QStringList ReadCSV::getColData(int headerIndex, QString dbName)
{
    QStringList data;
    QString filePath = returnCSVFilePath(dbName);

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       // qDebug() << "File did not open";
        return data;
    }

    // Retrieve all of the values in that headerIndex's column
    while(!file.atEnd())
    {
        // Read the line and store it
        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');
        data << rowValues[headerIndex];
    }
    file.close();
    return data;    // Returns all the data in that column as a QStringList
}

//-----------------------------------------------------------
// Validates if any of the values in the column exist
// and returns the row index if yes
int ReadCSV::rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue)
{
    for(int i = 0; i < colData.length(); i++)
    {
        if(colData[i] == searchValue)
        {
            return ++i; // Return rowIndex where search value (i.e. username) was found
        }
    }
    return -1;      // If not found return -1
}


//-------------------------------------------------------------
// Gets a specific cell's value based on header and row index
QString ReadCSV::getCellValue(QString dbName, int headerIn, int rowIn)
{
    QString cellValue;
    QString filePath = returnCSVFilePath(dbName);

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       // qDebug() << "File did not open";
        return cellValue;
    }

    // Retrieve all of the values in that headerIndex's column
    while(!file.atEnd())
    {
        // Skip the number of rows that are inapplicable
        int rowNum = 0;
        do
        {
            file.readLine().trimmed;
            rowNum++;
        } while(rowNum < rowIn);

        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');
        cellValue = rowValues[headerIn];
    }
    file.close();
    return cellValue;
}
