#include "createelevewindow.h"
#include "ui_createelevewindow.h"
#include "eleves.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "readelevewindow.h"
#include "elevemainwindow.h"

createeleveWindow::createeleveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createeleveWindow)
{
    ui->setupUi(this);
}

createeleveWindow::~createeleveWindow()
{
    delete ui;
}

void createeleveWindow::on_pushButton_clicked()
{
    int id = ui->id->toPlainText().toInt();
    QString nom = ui->nom->toPlainText();
    QString prenom = ui->prenom->toPlainText();


    int moyenne = ui->moyenne->toPlainText().toInt();


    if(nom == "" || prenom == "" || ui->id->toPlainText() == "" || ui->moyenne->toPlainText() == "" )
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Fields are empty"), QMessageBox::Cancel);
        return;
}

ELEVES e(id, nom, prenom,moyenne);

if(e.selectELEVESByID(id)->rowCount()>0)
{

    QMessageBox::critical(nullptr, QObject::tr("Error"),
                          QObject::tr("Id Exists"), QMessageBox::Cancel);
    return;
}

if (e.createELEVES()) {
    QByteArray write("1");
    readeleveWindow *w = new readeleveWindow;
    QMessageBox::critical(nullptr, QObject::tr("Success"),
                          QObject::tr("ELEVES ajouté avec succès"), QMessageBox::Cancel);
    w->show();

} else {

    QMessageBox::critical(nullptr, QObject::tr("Error"),
                          QObject::tr("Error while adding"), QMessageBox::Cancel);
    return;
}

}
void createeleveWindow::on_pushButton_2_clicked()
{
    eleveMainWindow *w = new eleveMainWindow;
    w->show();
    this->close();
}
