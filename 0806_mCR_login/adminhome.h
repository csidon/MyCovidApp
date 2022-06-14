#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QWidget>

namespace Ui {
class AdminHome;
}

class AdminHome : public QWidget
{
    Q_OBJECT

public:
    explicit AdminHome(QWidget *parent = nullptr);
    ~AdminHome();

private:
    Ui::AdminHome *ui;
};

#endif // ADMINHOME_H
