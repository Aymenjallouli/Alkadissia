#include "deleteelevewindow.h"
#include "ui_deleteelevewindow.h"
#include "eleves.h"
#include <QMessageBox>
#include "readelevewindow.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"

#include"elevemainwindow.h"

deleteeleveWindow::deleteeleveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteeleveWindow)
{
    ui->setupUi(this);
}

deleteeleveWindow::~deleteeleveWindow()
{
    delete ui;
}

void deleteeleveWindow::on_pushButton_clicked()
{
    int id = ui->textEdit->toPlainText().toInt();

    if(ui->textEdit->toPlainText() == "")
      {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Fields are empty"), QMessageBox::Cancel);
    }

    ELEVES e;

    if(e.selectELEVESByID(id)->rowCount()<=0)
    {

        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Id doesnt Exists"), QMessageBox::Cancel);
        return;
    }
    if (e.deleteELEVES(id)) {


        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("DELETED SUCCEFULLY"), QMessageBox::Cancel);
        return;
    }
}



void deleteeleveWindow::on_pushButton_2_clicked()
{
    eleveMainWindow *w = new eleveMainWindow;
    w->show();
    this->close();
}
