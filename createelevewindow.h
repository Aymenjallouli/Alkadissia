#ifndef CREATEELEVEWINDOW_H
#define CREATEELEVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class createeleveWindow;
}

class createeleveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit createeleveWindow(QWidget *parent = nullptr);
    ~createeleveWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::createeleveWindow *ui;
};

#endif // CREATEELEVEWINDOW_H
