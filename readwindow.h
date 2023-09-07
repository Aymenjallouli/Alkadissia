#ifndef READWINDOW_H
#define READWINDOW_H

#include <QMainWindow>

namespace Ui {
class readWindow;
}

class readWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit readWindow(QWidget *parent = nullptr);
    ~readWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::readWindow *ui;
};

#endif // READWINDOW_H
