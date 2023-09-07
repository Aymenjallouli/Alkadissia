#include "updatewindow.h"
#include "ui_updatewindow.h"
#include "readwindow.h"
#include <QMessageBox>
#include "enseignant.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"
updatewindow::updatewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updatewindow)
{
    ui->setupUi(this);
}

updatewindow::~updatewindow()
{
    delete ui;
}

void updatewindow::on_pushButton_2_clicked()
{
    readWindow *w = new readWindow;
    w->show();
    this->close();
}

void updatewindow::on_pushButton_clicked()
{
    int id = ui->id->toPlainText().toInt();
    QString nom = ui->nom->toPlainText();
    QString prenom = ui->prenom->toPlainText();
    QString dispo = ui->dispo->toPlainText();
    QString mdp = ui->mdp->toPlainText();
    int numtele = ui->numtele->toPlainText().toInt();
    QString matiere = ui->matiere->toPlainText();
    QString mail = ui->mail->toPlainText();

    if(nom == "" || prenom == "" || dispo == "" || mdp == "" || ui->numtele->toPlainText() == "" || ui->id->toPlainText() == "" || matiere == "" || mail == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Fields are empty"), QMessageBox::Cancel);
        return;
    }

   ENSEIGNANT e(id, mdp, nom, prenom,numtele, matiere, dispo,mail);

    if(e.selectENSEIGNANTByID(id)->rowCount()<=0)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Id doesnt Exists"), QMessageBox::Cancel);
        return;
    }
    if (e.updateENSEIGNANT()) {

        readWindow *w = new readWindow;
        QMessageBox::critical(nullptr, QObject::tr("Success"),
                              QObject::tr("Enseignant modifier avec succès"), QMessageBox::Cancel);
        w->show();
        this->close();
        return;
    } else {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Error while upadting"), QMessageBox::Cancel);
        return;
    }

}
