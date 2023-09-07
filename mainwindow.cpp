#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createwindow.h"
#include "readwindow.h"
#include "updatewindow.h"
#include "deletewindow.h"
#include "login.h"
#include "enseignant.h"
#include"createelevewindow.h"
#include "eleves.h"
#include "ui_createwindow.h"
#include "createwindow.cpp"
#include "elevemainwindow.h"
#include "ui_elevemainwindow.h"

#include "mainwindow.h"
#include "connection.h"


#include <QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QString>
#include <QImage>
#include <QPixmap>

#include <regex>
#include <QSqlQuery>
#include <QTextDocument>
#include <QList>
#include <QtPrintSupport/QPrintDialog>
#include <QtCharts/QChartView>
#include <QDebug>

#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_4_clicked()//create
{
    createWindow *w = new createWindow();
    w->show();
    this->close();
}
void MainWindow::on_pushButton_clicked()//update
{
    updatewindow *w = new updatewindow();
    w->show();
    this->close();
}
void MainWindow::on_pushButton_2_clicked()//delete
{
    deleteWindow *w = new deleteWindow();
    w->show();
    this->close();
}
void MainWindow::on_pushButton_3_clicked()//read
{
    readWindow *w = new readWindow();
    w->show();
    this->close();
}

void MainWindow::on_pushButton_5_clicked()//login
{

    login *w = new login();
    w->show();
    this->close();
}


void MainWindow::on_pushButton_6_clicked()
{
    eleveMainWindow *w = new eleveMainWindow();
    w->show();
    this->close();

}
