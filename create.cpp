#include "create.h"
#include <QSqlQuery>
#include <QDebug>

Create::Create(int id, QString password, QString nom, QString prenom, int num_tel, QString departement, QString disponibilite, QString mail) :
    m_id(id), m_password(password), m_nom(nom), m_prenom(prenom), m_num_tel(num_tel), m_departement(departement), m_disponibilite(disponibilite), m_mail(mail)
{
}

void Create::createEmployee() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYÉE (ID_EMPL, MOT_DE_PASSE, NOM, PRENOM, NUM_TEL, DEPARTEMENT, DISPONIBILITÉ, MAIL) "
                  "VALUES (:id, :password, :nom, :prenom, :num_tel, :departement, :disponibilite, :mail)");
    query.bindValue(":id", m_id);
    query.bindValue(":password", m_password);
    query.bindValue(":nom", m_nom);
    query.bindValue(":prenom", m_prenom);
    query.bindValue(":num_tel", m_num_tel);
    query.bindValue(":departement", m_departement);
    query.bindValue(":disponibilite", m_disponibilite);
    query.bindValue(":mail", m_mail);
    if (query.exec()) {
        qDebug() << "Employé ajouté avec succès";
    } else {
        qDebug() << "Erreur lors de l'ajout de l'employé";
    }
}
