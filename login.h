#ifndef LOGIN_H
#define LOGIN_H

#include "enseignant.h"
#include <QMainWindow>


// Forward declaration of Employee class
class Employee;

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pb_login_clicked();
    void on_pb_clear_clicked();
    void checkSerial();
private:
    Ui::login *ui;
    ENSEIGNANT* ens; // Pointeur vers la classe Employee pour gérer les informations des employés

};

#endif // LOGIN_H
