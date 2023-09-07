#include "updateelevewindow.h"
#include "ui_updateelevewindow.h"
#include "readelevewindow.h"
#include <QMessageBox>
#include "eleves.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"
#include"elevemainwindow.h"

updateeleveWindow::updateeleveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateeleveWindow)
{
    ui->setupUi(this);
}

updateeleveWindow::~updateeleveWindow()
{
    delete ui;
}

void updateeleveWindow::on_pushButton_clicked()
{
    int id = ui->id->toPlainText().toInt();
    QString nom = ui->nom->toPlainText();
    QString prenom = ui->prenom->toPlainText();
   int moyenne = ui->moyenne->toPlainText().toInt();


    if(nom == "" || prenom == ""|| ui->id->toPlainText() == "" || ui->moyenne->toPlainText() == "" )
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Fields are empty"), QMessageBox::Cancel);
        return;
    }

   ELEVES e(id, nom, prenom, moyenne);

    if(e.selectELEVESByID(id)->rowCount()<=0)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Id doesnt Exists"), QMessageBox::Cancel);
        return;
    }
    if (e.updateELEVES()) {

        readeleveWindow *w = new readeleveWindow;
        QMessageBox::critical(nullptr, QObject::tr("Success"),
                              QObject::tr("Eleve modifier avec succès"), QMessageBox::Cancel);
        w->show();
        this->close();
        return;
    } else {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Error while upadting"), QMessageBox::Cancel);
        return;
    }
}

void updateeleveWindow::on_pushButton_2_clicked()
{
    eleveMainWindow *w = new eleveMainWindow;
    w->show();
    this->close();
}
