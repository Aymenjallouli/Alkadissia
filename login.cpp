

#include "login.h"
#include "ui_login.h"
#include <QTimer>
#include "mainwindow.h"
#include "createwindow.h"
#include "enseignant.h"



login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}



void login::on_pb_login_clicked()
{

    QString Mail = ui->le_login->toPlainText();
    QString Password = ui->le_password->toPlainText();
    bool test = ens->Login(Mail,Password);
    if (test)
    {
        MainWindow *w = new MainWindow();
        w->show();
        this->close();



    }
    else
    {
        ui->le_status->setText("Nom d'utilisateur ou mot de passe incorrect");
    }
}

void login::on_pb_clear_clicked()
{
    ui->le_password->setText("");
    ui->le_login->setText("");
}
