#ifndef UPDATEELEVEWINDOW_H
#define UPDATEELEVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class updateeleveWindow;
}

class updateeleveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit updateeleveWindow(QWidget *parent = nullptr);
    ~updateeleveWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::updateeleveWindow *ui;
};

#endif // UPDATEELEVEWINDOW_H
