
#include "delete.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void Delete::deleteEmployee(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYÉE WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'employé :" << query.lastError().text();
        throw std::runtime_error(query.lastError().text().toStdString());
    }
}
