#ifndef DELETEELEVEWINDOW_H
#define DELETEELEVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class deleteeleveWindow;
}

class deleteeleveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteeleveWindow(QWidget *parent = nullptr);
    ~deleteeleveWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::deleteeleveWindow *ui;
};

#endif // DELETEELEVEWINDOW_H
