#ifndef READELEVEWINDOW_H
#define READELEVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class readeleveWindow;
}

class readeleveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit readeleveWindow(QWidget *parent = nullptr);
    ~readeleveWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_imprimer_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::readeleveWindow *ui;
};

#endif // READELEVEWINDOW_H
