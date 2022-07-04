#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QLayout>

// This is a custom widget created to emulate
// QListWidget, but with the ability to add multiple QLabels
// With different styling results
// Used in conjunction with ToolItem and CustomListWidget
// Refer to documentation on layout priorities
class CustomListWidget : public QListWidget
{
public:
    // Constructor
    CustomListWidget(QListWidget *parent = nullptr);

    // Getters & Setters
    int getPage();
    void setPage(int page);
    int getTotalPages();
    void setTotalPages(int pages);

    // Functions
    void addLabelItem(QLabel *uppLeft, QLabel *uppRight, QLabel *botLeft, QLabel *botRight);
    void addProfileItem(QLabel *title, QLabel *data);
    void addArrows(int printingPage, int totalPages);
    void addPageNumDisplay(int page, int totalPages);

    QPushButton *backArrow;
    QPushButton *nextArrow;

private:
    int currentPage;
    int totalPages;
    QVBoxLayout *layout;
    QLabel *dispPageNum;




};

#endif // CUSTOMLISTWIDGET_H
