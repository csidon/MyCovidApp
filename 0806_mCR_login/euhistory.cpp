#include "euhistory.h"
#include "ui_euhistory.h"
#include <QFrame>
#include <QToolBox>
#include <QPushButton>
#include "mainwindow.h"
#include "useraccount.h"
#include "handlecsv.h"

EUHistory::EUHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::EUHistory)
{
    ui->setupUi(this);
    setLoggedInUserID(loggedInUserID);



//    QToolBox *toolbox = new QToolBox();
//    toolbox->setGeometry(0,0,2000,900);
//    QFrame *frm = new QFrame;
//    QLabel *lbl = new QLabel("Hello World",frm);
//    toolbox->addItem(lbl, "COVID-19");
//    toolbox->addItem(lbl, "Rapid Antigen Test");
//    toolbox->addItem(frm, "Self-reported");

//    QToolBox *newToolBox = new QToolBox(ui->frame_test);
//    newToolBox->setGeometry(0,0,2000,900);
//    QFrame *frm1 = new QFrame;
////    QLabel *lbl1 = new QLabel("Hello World",frm1);
//    newToolBox->addItem(frm1 ,"COVID-19");
//    newToolBox->addItem(frm1 ,"Rapid Antigen Test");
//    newToolBox->addItem(frm1 ,"Self-Reported");



//    QVBoxLayout *layout = new QVBoxLayout(this);

//    // For each test in user's file, create an entry
//    for (int i = 0; i < 4; i++)
//    {
//        QPushButton * newButton = new QPushButton( this );
//        newButton ->setText( "Ok" );
//        layout->addWidget( newButton );
//    }
//    setLayout(layout);


//        QLabel *lbl_type = new QLabel(this);
//        lbl_type->setText("Testing");

//    QWidget *window = new QWidget;
//    window->setWindowTitle("QToolBox Example");

    //----------------------------------------------
    // List to show if user clicks on Test History
    //-----
    // Open UserTests folder and search for a CSV file with their UID
    HandleCSV checkCSV;

    qDebug() << "Opening UserTests folder and looking for UID >>> " << getLoggedInUserID();
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = "database/UserTests/" + QString::number(getLoggedInUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Searching for " << getLoggedInUserID() << ".csv" << "...";
        QFile searchFile{filepath};
        if (searchFile.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            // File found. Now extract data for display
        }
        else
        {
            // Check if file can't be found, or file has difficulty opening
            qDebug() << "What's the QFile error? " << searchFile.errorString();
            if (searchFile.errorString() == "No such file or directory")
            {
                QListWidget *userTestList = new QListWidget;
                userTestList->addItem("You have no recorded COVID-19 tests");
            }
        }
    }



    QListWidget *list = new QListWidget;

//    list->addItem("One");
//    list->addItem("Two");
//    list->addItem("Three");
    for(int i = 0; i < 5; i++)
    {
        list->addItem("testText");

    }



    ExpandingToolBox *toolBox = new ExpandingToolBox;

//    toolBox->addItem(new ToolItem("Title 1\nSubTitles", new QLabel("Some text here\nDoes this work?")));
//    toolBox->addItem(new ToolItem("Title 2", list));
//    toolBox->addItem(new ToolItem("Fancy Title", new QLabel("Lorem Ipsum..")));
    toolBox->addItem(new ToolItem(new QLabel("Fancy Title"), list));
    toolBox->addItem(new ToolItem(new QLabel("Fancy Title"), new QLabel("Lorem Ipsum..")));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(toolBox);

    setLayout(layout);





}

EUHistory::~EUHistory()
{
    delete ui;
}

int EUHistory::getLoggedInUserID()
{
    return userID;
}

void EUHistory::setLoggedInUserID(int newLoggedInUserID)
{
    this->userID = newLoggedInUserID;
}


