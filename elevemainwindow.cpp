#include "elevemainwindow.h"
#include "ui_elevemainwindow.h"


#include "login.h"


#include "eleves.h"
#include "createelevewindow.h"
#include "readelevewindow.h"
#include "updateelevewindow.h"
#include "deleteelevewindow.h"


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

eleveMainWindow::eleveMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eleveMainWindow)
{
    ui->setupUi(this);
}

eleveMainWindow::~eleveMainWindow()
{
    delete ui;
}

void eleveMainWindow::on_pushButton_4_clicked()
{
    createeleveWindow *w = new createeleveWindow();
    w->show();
    this->close();
}

void eleveMainWindow::on_pushButton_clicked()
{
    updateeleveWindow *w = new updateeleveWindow();
    w->show();
    this->close();
}

void eleveMainWindow::on_pushButton_2_clicked()
{
    deleteeleveWindow *w = new deleteeleveWindow();
    w->show();
    this->close();
}

void eleveMainWindow::on_pushButton_3_clicked()
{
    readeleveWindow *w = new readeleveWindow();
    w->show();
    this->close();
}

void eleveMainWindow::on_pushButton_6_clicked()
{
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}

void eleveMainWindow::on_pushButton_5_clicked()
{
    login *w = new login();
    w->show();
    this->close();
}
