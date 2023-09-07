#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QMainWindow>

namespace Ui {
class createWindow;
}

class createWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit createWindow(QWidget *parent = nullptr);
    ~createWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_id_copyAvailable(bool b);

private:
    Ui::createWindow *ui;

};

#endif // CREATEWINDOW_H
