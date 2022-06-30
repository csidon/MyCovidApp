#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>


class CustomListWidget : public QListWidget
{
public:
    // Constructor
    CustomListWidget(QListWidget *parent = nullptr);
    void addLabelItem(QLabel *uppLeft, QLabel *uppRight, QLabel *botLeft, QLabel *botRight);
private:
    QVBoxLayout *layout;

};

#endif // CUSTOMLISTWIDGET_H
