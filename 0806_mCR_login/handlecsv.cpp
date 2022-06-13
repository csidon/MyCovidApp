#include "handlecsv.h"
#include "useraccount.h"

HandleCSV::HandleCSV()
{

}

//-----------------------------------------------------------
// Returning the database path based on shortname
QString HandleCSV::returnCSVFilePath(QString dbName)
{
    QString filePath;
    filePath.resize(30);
    if (dbName == "dbPID")
    {
        filePath = "/database/dummyPID.csv";
//        qDebug() << "You have found dbPID with filepath " << filePath;
    }
    else if (dbName == "dbTest")
    {
        filePath = "/database/MasterTests.csv";
    }
//    else if (dbName == "dbDose")
    else
    {
        filePath = "/database/MasterDoses.csv";
    }
    // ** Add any other database/path here
    return ":" + filePath;
}

//-----------------------------------------------------------
// Mapping database header fields to specific indexes
int HandleCSV::returnHeaderIndex(QString dbName, QString headerName)
{
    int headerIndex = -1;

    QString filePath = returnCSVFilePath(dbName);
    qDebug() << "File path is " <<  filePath;

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File did not open";
        return headerIndex;
    }

    // Read the header line and get the value of each cell
    QString headers = file.readLine().trimmed();
    QStringList headerRowValues = headers.split(',');

    // Compare that cell value to the colHeader search value
    // and grab the column index that we are retrieving
    for(int i = 0; i < headerRowValues.length(); i++)
    {
        qDebug() << "Comparing colHeaders...";
        if(headerRowValues[i] == headerName)
        {
            headerIndex = i;
            break;
        }
    }
    return headerIndex;
}

//-----------------------------------------------------------
// Get all data in a column for a specified header for a CSV file
QStringList HandleCSV::getColData(QString headerName, QString dbName)
{
    QStringList data;
    QString filePath = returnCSVFilePath(dbName);

    int headerIndex = returnHeaderIndex(dbName,headerName);

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
int HandleCSV::rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue)
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
QString HandleCSV::getCellValue(QString dbName, int headerIn, int rowIn)
{
    QString cellValue;
    QString filePath = returnCSVFilePath(dbName);
    qDebug() << "Filepath for getCellVal = "<< filePath;

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File did not open";
        return cellValue;
    }

    // Retrieve all of the values in that headerIndex's column
    while(!file.atEnd())
    {

        // Skip the number of rows that are inapplicable
        int rowNum = 0;
        do
        {
            file.readLine();
            rowNum++;
        } while(rowNum < rowIn);

        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');
        cellValue = rowValues[headerIn];
//        qDebug() << "You made it here!";
        file.close();
        return cellValue;
    }

    return cellValue;

}

void HandleCSV::writeToPIDCSV(UserAccount userConstructor)
{
    // Storing in userPID db
    QString filePath = returnCSVFilePath("dbPID");
    qDebug() << "File path is " <<  filePath;

    // Mapping info in userConstructor to cells
    QString email, pass, fn, ln, pn, nhi, qrAdd;
    int uid, ph, vaxstat,qrstat;
    uid = userConstructor.getUserIDNumber();
    email = userConstructor.getUserEmail();
    pass = userConstructor.getUserPassword();
    fn = userConstructor.getUserFirstName();
    ln = userConstructor.getUserLastName();
    pn = userConstructor.getUserPreferredName();
    nhi = userConstructor.getUserNHINumber();
    qrAdd = userConstructor.getUserQRCodeAddress();
    ph = userConstructor.getUserPhoneNumber();
    vaxstat = userConstructor.getUserVaccinationStatus();
    qrstat = userConstructor.getUserQRStatus();

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        qDebug() << "File did not open";
    }
    // Streaming info back into db
    QTextStream stream(&file);
    stream << uid << "," << email << "," << pass << "," << fn << ","
           << ln << "," << pn << "," << nhi << "," << ph << ","
           << vaxstat << "," << qrstat << "," << qrAdd;

    file.close();
}
