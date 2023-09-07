#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H

#include <QMainWindow>

namespace Ui {
class updatewindow;
}

class updatewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit updatewindow(QWidget *parent = nullptr);
    ~updatewindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::updatewindow *ui;
};

#endif // UPDATEWINDOW_H
