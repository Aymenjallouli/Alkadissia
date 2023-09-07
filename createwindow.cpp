#include "createwindow.h"
#include "ui_createwindow.h"
#include "enseignant.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "readwindow.h"

createWindow::createWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createWindow)
{
    ui->setupUi(this);
}

createWindow::~createWindow()
{
    delete ui;
}
void createWindow::on_pushButton_clicked()
{
    int id = ui->id->toPlainText().toInt();
    QString nom = ui->nom->toPlainText();
    QString prenom = ui->prenom->toPlainText();
    QString disponibilite = ui->dispo->toPlainText();
    QString mdp = ui->mdp->toPlainText();
    int numtele = ui->numtele->toPlainText().toInt();
    QString matiere = ui->matiere->toPlainText();
    QString mail = ui->mail->toPlainText();

    if(nom == "" || prenom == "" || disponibilite == "" ||mdp == "" || ui->numtele->toPlainText() == "" || ui->id->toPlainText() == "" || matiere == "" || mail == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Fields are empty"), QMessageBox::Cancel);
        return;
    }

    ENSEIGNANT e(id, mdp, nom, prenom,numtele, matiere, disponibilite,mail);

    if(e.selectENSEIGNANTByID(id)->rowCount()>0)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Id Exists"), QMessageBox::Cancel);
        return;
    }

    if (e.createENSEIGNANT()) {
        QByteArray write("1");
        readWindow *w = new readWindow;
        QMessageBox::critical(nullptr, QObject::tr("Success"),
                              QObject::tr("ENSEIGNANT ajouté avec succès"), QMessageBox::Cancel);
        w->show();

    } else {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Error while adding"), QMessageBox::Cancel);
        return;
    }

}

void createWindow::on_pushButton_2_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();

}

