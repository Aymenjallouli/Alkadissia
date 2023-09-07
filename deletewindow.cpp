#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "enseignant.h"
#include <QMessageBox>
#include "readwindow.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"

deleteWindow::deleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteWindow)
{
    ui->setupUi(this);
}

deleteWindow::~deleteWindow()
{
    delete ui;
}

void deleteWindow::on_pushButton_clicked()
{
    int id = ui->textEdit->toPlainText().toInt();

    if(ui->textEdit->toPlainText() == "")
      {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Fields are empty"), QMessageBox::Cancel);
    }

    ENSEIGNANT e;

    if(e.selectENSEIGNANTByID(id)->rowCount()<=0)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Id doesnt Exists"), QMessageBox::Cancel);
        return;
    }
    if (e.deleteENSEIGNANT(id)) {


        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("DELETED"), QMessageBox::Cancel);
        return;
    }
}

void deleteWindow::on_pushButton_2_clicked()
{

    this->close();
    readWindow *w = new readWindow;
    w->show();
}
