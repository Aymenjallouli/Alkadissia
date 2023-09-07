#ifndef ELEVEMAINWINDOW_H
#define ELEVEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class eleveMainWindow;
}

class eleveMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit eleveMainWindow(QWidget *parent = nullptr);
    ~eleveMainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::eleveMainWindow *ui;
};

#endif // ELEVEMAINWINDOW_H
