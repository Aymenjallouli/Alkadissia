#include "read.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


QSqlQueryModel* Read::selectEmployees() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYÉE");
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de la récupération des employés :" << model->lastError().text();
    }
    return model;
}
