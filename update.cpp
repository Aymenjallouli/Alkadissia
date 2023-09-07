#include "update.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Update::Update(int id, QString password, QString nom, QString prenom, int num_tel, QString departement, QString disponibilite, QString mail) :
    m_id(id), m_password(password), m_nom(nom), m_prenom(prenom), m_num_tel(num_tel), m_departement(departement), m_disponibilite(disponibilite), m_mail(mail)
{}

void Update::updateEmployee() {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYÉE SET PASSWORD = :password, NOM = :nom, PRENOM = :prenom, NUM_TEL = :num_tel, DEPARTEMENT = :departement, DISPONIBILITÉ = :disponibilite, MAIL = :mail WHERE ID = :id");
    query.bindValue(":id", m_id);
    query.bindValue(":password", m_password);
    query.bindValue(":nom", m_nom);
    query.bindValue(":prenom", m_prenom);
    query.bindValue(":num_tel", m_num_tel);
    query.bindValue(":departement", m_departement);
    query.bindValue(":disponibilite", m_disponibilite);
    query.bindValue(":mail", m_mail);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour de l'employé :" << query.lastError().text();
        throw query.lastError().text();
    }
}
