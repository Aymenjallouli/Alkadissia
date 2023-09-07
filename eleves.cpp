#include "eleves.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

ELEVES::ELEVES()
    : id(0)
{
}

ELEVES::ELEVES(int id,  const QString nom, const QString prenom, int moyenne)
    : id(id),  nom(nom), prenom(prenom),
      moyenne(moyenne)
{
}

void ELEVES::setId(int newId)
{
    id = newId;
}



void ELEVES::setNom(const QString newNom)
{
    nom = newNom;
}

void ELEVES::setPrenom(const QString newPrenom)
{
    prenom = newPrenom;
}


void ELEVES::setMoyenne(int newmoyenne)
{
    moyenne = newmoyenne;
}



int ELEVES::getId() const
{
    return id;
}


QString ELEVES::getNom() const
{
    return nom;
}

QString ELEVES::getPrenom() const
{
    return prenom;
}



int ELEVES::getMoyenne() const
{
    return moyenne;
}




bool ELEVES::createELEVES() {
    QSqlQuery query;
    query.prepare("INSERT INTO ELEVES (ID,  NOM, PRENOM, moyenne) "
                  "VALUES (:id,  :nom, :prenom, :moyenne)");
    query.bindValue(":id", id);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    query.bindValue(":moyenne", moyenne);


    return query.exec();
}

bool ELEVES::deleteELEVES(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM ELEVES WHERE ID = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool ELEVES::updateELEVES() {
    QSqlQuery query;
    query.prepare("UPDATE ELEVES SET  NOM = :nom, PRENOM = :prenom,  moyenne = :moyenne WHERE ID = :id");
    query.bindValue(":id", id);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    query.bindValue(":moyenne", moyenne);


    return query.exec();
}


QSqlQueryModel* ELEVES::selectELEVES() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ELEVES");
    return model;
}


QSqlQueryModel* ELEVES::selectELEVESByID(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(QString("SELECT * FROM ELEVES WHERE ID = %1").arg(id));
    return model;
}

QSqlQueryModel* ELEVES::researcher(QString research) {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ELEVES WHERE NOM like '%"+research+"%' or PRENOM like '%"+research+"%' or moyenne like  '%"+research+"%' or id like '%"+research+"%' ");
    return model;
}

ELEVES ELEVES::retrieveELEVES(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM ELEVES WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.next()) {
        ELEVES e;
        e.setId(query.value("ID").toInt());

        e.setNom(query.value("NOM").toString());
        e.setPrenom(query.value("PRENOM").toString());
        e.setMoyenne(query.value("moyenne").toInt());


        return e;
    } else {
        // Return an empty ELEVES object if not found
        return ELEVES();
    }
}

QVector<ELEVES> ELEVES::retrieveAllELEVES() {
    QVector<ELEVES> ELEVESS;
    QSqlQuery query;
    query.prepare("SELECT * FROM ELEVES");
    query.exec();
    while (query.next()) {
        ELEVES e;
        e.setId(query.value("ID").toInt());

        e.setNom(query.value("NOM").toString());
        e.setPrenom(query.value("PRENOM").toString());
         e.setMoyenne(query.value("moyenne").toInt());

        ELEVESS.append(e);
        }
        return ELEVESS;
        }



