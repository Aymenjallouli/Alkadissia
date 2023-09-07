#include "readwindow.h"
#include "ui_readwindow.h"
#include "enseignant.h"
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
#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "updatewindow.h"
#include "ui_updatewindow.h"
readWindow::readWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::readWindow)
{
    ui->setupUi(this);
    ENSEIGNANT e;
    QSortFilterProxyModel *tri = new QSortFilterProxyModel();
    tri->setSourceModel(e.selectENSEIGNANT());
    ui->tableView->setModel(tri);

    QStringList categories;
    categories << "Disponible" << "Pas disponible";
    QtCharts::QBarSet *set = new QtCharts::QBarSet("Numbre");
    *set <<e.ENSEIGNANTDisponibiliter()<<e.NonENSEIGNANTDisponibiliter();

    QtCharts::QBarSeries *series = new QtCharts::QBarSeries(this);
    series->append(set);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Disponibiliter");
    chart->createDefaultAxes();

    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
   axis->append(categories);
   chart->setAxisX(axis, series);

   QtCharts::QChartView * m_chartView = new QtCharts::QChartView(chart, this);
   QVBoxLayout *layout = new QVBoxLayout(this);
   layout->addWidget(m_chartView);

   qDeleteAll(ui->widget->children());
   ui->widget->setLayout(layout);
}

readWindow::~readWindow()
{
    delete ui;
}

void readWindow::on_pushButton_2_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
}

void readWindow::on_pushButton_clicked()
{
    QString research = ui->lineEdit->text();
    ENSEIGNANT e;

    if(research == "")
    {
        ui->tableView->setModel(e.selectENSEIGNANT());
    }
    else
        ui->tableView->setModel(e.researcher(research));

}


void readWindow::on_pushButton_3_clicked()
{
    int row = ui->tableView->selectionModel()->currentIndex().row();
    if(row == -1)
    {
        qDebug()<<"nothing selected";
        return;
    }
      ENSEIGNANT e;


        QString ID_ENS  = ui->tableView->model()->index(row,1).data().toString();
        QString NOM = ui->tableView->model()->index(row,2).data().toString();
        QString PRENOM = ui->tableView->model()->index(row,3).data().toString();
        QString NUM_TEL = ui->tableView->model()->index(row,4).data().toString();
        QString MATIERE = ui->tableView->model()->index(row,5).data().toString();
        QString DISPONIBILITE = ui->tableView->model()->index(row,6).data().toString();
        QString MAIL = ui->tableView->model()->index(row,7).data().toString();

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
          "ID_ENS: "+ID_ENS+""
          "NOM: "+NOM+"<br>"
          "PRENOM: "+PRENOM+"<br>"
          "MATIERE: "+MATIERE+"<br>"
          "DISPONIBILITE: "+DISPONIBILITE+"<br>"
          "MAIL: "+MAIL+"<br>"
          "NUM_TEL: "+NUM_TEL+"<br>"

       "</div>";

       doc.setHtml(html);
       doc.drawContents(&painter);

       QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }

void readWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void readWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void readWindow::on_pushButton_7_clicked()
{

    deleteWindow *w = new deleteWindow();
    w->show();
    this->close();
}

void readWindow::on_pushButton_6_clicked()
{

   updatewindow *w = new updatewindow();
    w->show();
    this->close();

}
