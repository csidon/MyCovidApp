#include "adminqrrequests.h"

#include "ui_adminqrrequests.h"



//Getters
int AdminQRRequests::getPageNumber()
{
    return pageNumber;
}

int AdminQRRequests::getNoOfPages()
{
    return noOfPages;
}

//Setters
void AdminQRRequests::setPageNumber(int newPageNumber)
{
    pageNumber = newPageNumber;
}

void AdminQRRequests::setNoOfPages(int newNoOfPages)
{
    noOfPages = newNoOfPages;
}

void AdminQRRequests::assignmentButtonClicked(int button)
{
    //Calculate user's index in an array read from the file
    int userIndex = ((getPageNumber()-1)*6)+button;
    //read from files
    HandleCSV readUsers;
    QStringList allRequestingUsers = readUsers.getColData("userIDNumber", "dbQRRequests");
    UserAccount assignedUser = readUsers.getUserAccount(allRequestingUsers.at(userIndex).toInt());
    //User finds image
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select QR Code"), "./database/UnassignedQRCodes", tr("Image Files (*.png)"));
    if(QString::compare(fileName, QString()) !=0){
        QImage image;
        bool valid = image.load(fileName);
        if(valid){
            //Save image in new location with new name
            image.save("./database/AssignedQRCodes/" + QString::number(assignedUser.getUserIDNumber()) + ".png", nullptr, -1);
            //Set user's information
            assignedUser.setUserQRCodeAddress("./database/AssignedQRCodes/" + QString::number(assignedUser.getUserIDNumber()) + ".png");
            assignedUser.setUserQRStatus(2);
            readUsers.updatePID(assignedUser);
            //Page display
            allRequestingUsers.remove(userIndex);
            readUsers.removeQRRequest(allRequestingUsers);
            if(button == 1 && allRequestingUsers.size() < userIndex){
                setPageNumber(getPageNumber()-1);
            }
            updatePageNumberDisplay();
            setDisplayedUsers(getPageNumber());
            //Delete original image from unassigned folder
            QFile deletee = fileName;
            deletee.remove();
        }
    }
}


//This function makes the page number display correct based on pageNumber() and noOfPages
void AdminQRRequests::updatePageNumberDisplay()
{
    HandleCSV countQRRequests;
    QStringList QRRequests = countQRRequests.getColData("userIDNumber", "dbQRRequests");
    QRRequests.takeFirst();//drops the header

    qDebug() << "QRRequests.size at updatePagenum " << QRRequests.size();

    if(QRRequests.size() == 0)
    {
        this->close();
    }
    //How many pages do we need?
    setNoOfPages(QRRequests.size()/6);
    if(QRRequests.size()%6!=0){
        setNoOfPages(getNoOfPages()+1);
    }
    //Send to label
    ui->lbl_currentPage->setText(QString::number(getPageNumber())+" of " + QString::number(getNoOfPages()));
    if(getPageNumber() == getNoOfPages()){
        ui->btn_pageRight->setEnabled(false);
    }
}

QString AdminQRRequests::formatNameForDisplay(UserAccount dataSource)
{
    //Format name
    QString toPrint = "";// Should stay blank if no name found
    if(dataSource.getUserFirstName() != ""){//Checks if name is blank
        toPrint = dataSource.getUserFirstName() + " " + dataSource.getUserLastName();//spaces names
       if(dataSource.getUserFirstName() != dataSource.getUserPreferredName()){//Adds preferred name in brackets if different from first name
           toPrint = toPrint + " (" + dataSource.getUserPreferredName() + ")";
       }
    }
    return toPrint;
}



AdminQRRequests::AdminQRRequests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminQRRequests)
{
    ui->setupUi(this);
    ui->btn_pageLeft->setEnabled(false);//start on page one; there's no page zero, so left button would go nowhere
    //populating this array allows looping through the labels
    nameLabels[0] = ui->lbl_name_1;
    nameLabels[1] = ui->lbl_name_2;
    nameLabels[2] = ui->lbl_name_3;
    nameLabels[3] = ui->lbl_name_4;
    nameLabels[4] = ui->lbl_name_5;
    nameLabels[5] = ui->lbl_name_6;
    setPageNumber(1);//start on page one
    updatePageNumberDisplay();
    if(getNoOfPages() < 2){//this variable is set as part of the previous function. If there isn't a page two, the code doesn't need the right button
        ui->btn_pageRight->setEnabled(false);
    }
    setDisplayedUsers(getPageNumber());
}

AdminQRRequests::~AdminQRRequests()
{
    delete ui;
}

void AdminQRRequests::setDisplayedUsers(int currentPage)
{
    //calculate first user to display's index in the list read form the file
    int printUser = ((currentPage - 1) * 6) + 1;
    HandleCSV readQRRequests;//Access reading functions
    QStringList requestingUsers = readQRRequests.getColData("userIDNumber", "dbQRRequests");
    int i=0;
    UserAccount dataSource;
    QString toPrint = "";
    while(printUser < requestingUsers.size() && i < 6){//display user names
       dataSource = readQRRequests.getUserAccount(requestingUsers.at(printUser++).toInt());
       toPrint = formatNameForDisplay(dataSource);
       //elide long name
       QFontMetrics metricsName(nameLabels[i]->font());
       QString elidedName = metricsName.elidedText(toPrint, Qt::ElideRight, nameLabels[i]->width());
       nameLabels[i]->setText(elidedName);
       i++;
    }
    toPrint = "";
    while(printUser >= requestingUsers.size() && i < 6){//blank out the spaces after the last user
       nameLabels[i]->setText(toPrint);
       i++;
    }
}


void AdminQRRequests::on_btn_pageRight_clicked()
{
    //increase page number and display more users
    setPageNumber(getPageNumber()+1);
    this->updatePageNumberDisplay();
    this->setDisplayedUsers(getPageNumber());
    //set buttons
    ui->btn_pageLeft->setEnabled(true);
    if(this->getPageNumber() >= getNoOfPages()){
        ui->btn_pageRight->setEnabled(false);
    }
}


void AdminQRRequests::on_btn_pageLeft_clicked()
{
    //decrease page number and display previous users
    setPageNumber(getPageNumber()-1);
    this->updatePageNumberDisplay();
    this->setDisplayedUsers(getPageNumber());
    //set buttons
    ui->btn_pageRight->setEnabled(true);
    if(this->getPageNumber() == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
}


void AdminQRRequests::on_btn_backToAdminHome_clicked()
{
    this->close();
}


void AdminQRRequests::on_btn_assign_1_clicked()
{
    assignmentButtonClicked(1);
}


void AdminQRRequests::on_btn_assign_2_clicked()
{
    assignmentButtonClicked(2);
}


void AdminQRRequests::on_btn_assign_3_clicked()
{
    assignmentButtonClicked(3);
}


void AdminQRRequests::on_btn_assign_4_clicked()
{
    assignmentButtonClicked(4);
}


void AdminQRRequests::on_btn_assign_5_clicked()
{
    assignmentButtonClicked(5);
}


void AdminQRRequests::on_btn_assign_6_clicked()
{
    assignmentButtonClicked(6);
}

