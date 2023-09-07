#include "readelevewindow.h"
#include "ui_readelevewindow.h"
#include "readwindow.h"
#include "ui_readwindow.h"
#include "eleves.h"
#include "mainwindow.h"
#include <QSortFilterProxyModel>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include "deleteelevewindow.h"
#include "ui_deleteelevewindow.h"
#include "updateelevewindow.h"
#include "ui_updateelevewindow.h"
#include "elevemainwindow.h"

readeleveWindow::readeleveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::readeleveWindow)
{
    ui->setupUi(this);
    ELEVES e;
    QSortFilterProxyModel *tri = new QSortFilterProxyModel();
    tri->setSourceModel(e.selectELEVES());
    ui->tableView->setModel(tri);




}

readeleveWindow::~readeleveWindow()
{
    delete ui;
}

void readeleveWindow::on_pushButton_clicked()
{
    QString research = ui->lineEdit->text();
    ELEVES e;

    if(research == "")
    {
        ui->tableView->setModel(e.selectELEVES());
    }
    else
        ui->tableView->setModel(e.researcher(research));

}





void readeleveWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     eleveMainWindow *w = new eleveMainWindow;
     w->show();
     this->close();
}


void readeleveWindow::on_imprimer_clicked()
{   int row = ui->tableView->selectionModel()->currentIndex().row();
    if(row == -1)
    {
        qDebug()<<"nothing selected";
        return;
    }
      ELEVES e;


        QString ID  = ui->tableView->model()->index(row,1).data().toString();
        QString NOM = ui->tableView->model()->index(row,2).data().toString();
        QString PRENOM = ui->tableView->model()->index(row,3).data().toString();

        QString MOYENNE = ui->tableView->model()->index(row,4).data().toString();


        QString pdfDir = QDir::currentPath() + "/pdf";
        QDir().mkpath(pdfDir);
        QString filePath = pdfDir + "/"+NOM+"_"+PRENOM+".pdf";

        QPdfWriter writer(filePath);
        writer.setPageSizeMM(QSizeF(50, 50));

        QPainter painter(&writer);
        painter.scale(2, 2);

        QTextDocument doc;

       QString html =
       "<div align=right>"
          "ID: "+ID+""
          "NOM: "+NOM+"<br>"
          "PRENOM: "+PRENOM+"<br>"
          "MATIERE: "+MOYENNE+"<br>"


       "</div>";

       doc.setHtml(html);
       doc.drawContents(&painter);

       QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }

void readeleveWindow::on_pushButton_7_clicked()
{
    deleteeleveWindow *w = new deleteeleveWindow();
    w->show();
    this->close();
}

void readeleveWindow::on_pushButton_6_clicked()
{
    updateeleveWindow *w = new updateeleveWindow();
     w->show();
     this->close();
}
