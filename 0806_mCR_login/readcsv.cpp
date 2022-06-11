#include "readcsv.h"
#include <QMessageBox>
#include <QMap>
#include <QStringList>

ReadCSV::ReadCSV()
{

}


QStringList ReadCSV::getSpecificCell(std::string searchHeaderValue)
{
    QStringList data;

    QFile file(":/database/dummyPID.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File did not open";
        return data;
    }

    // Read the header line and get the value of each cell
    int headerIndex = 0;
    QString headers = file.readLine().trimmed();
    QStringList headerRowValues = headers.split(',');

    // Compare that cell value to the searchHeader term
    // to grab the column index that we are retrieving
    for(int i = 0; i < headerRowValues.length(); i++)
    {
        if(headerRowValues[i] == QString::fromStdString(searchHeaderValue))
        {
            headerIndex = i;
            break;
        }
    }

    // Retrieve all of the row values for that column index

    while(!file.atEnd())
    {
        // Read the line and store it
        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');
        data << rowValues[headerIndex];
    }
    return data;
}

int ReadCSV::searchRowValue(QStringList listToSearch, std::string searchValue)
{
    for(int i = 0; i < listToSearch.length(); i++)
    {
        if(listToSearch[i] == QString::fromStdString(searchValue))
        {
            return i;
        }
    }
    return -1;
}

