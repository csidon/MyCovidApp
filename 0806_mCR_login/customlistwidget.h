#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>


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
    void addArrows();
    void addPageNumDisplay(int page, int totalPages);

private:
    int currentPage;
    int totalPages;
    QVBoxLayout *layout;
    QPushButton *backArrow;
    QPushButton *nextArrow;
    QLabel *dispPageNum;
private slots:
    void nextPage();
    void backPage();
//    void on_nextArrow_clicked();

};

#endif // CUSTOMLISTWIDGET_H
