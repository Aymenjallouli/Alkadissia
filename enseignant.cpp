#include "enseignant.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

ENSEIGNANT::ENSEIGNANT()
    : id(0), num_tel(0)
{
}

ENSEIGNANT::ENSEIGNANT(int id, const QString password, const QString nom, const QString prenom,
                   int num_tel, const QString matiere, const QString disponibilite,
                   const QString mail)
    : id(id), password(password), nom(nom), prenom(prenom), num_tel(num_tel),
      matiere(matiere), disponibilite(disponibilite), mail(mail)
{
}

void ENSEIGNANT::setId(int newId)
{
    id = newId;
}

void ENSEIGNANT::setPassword(const QString newPassword)
{
    password = newPassword;
}

void ENSEIGNANT::setNom(const QString newNom)
{
    nom = newNom;
}

void ENSEIGNANT::setPrenom(const QString newPrenom)
{
    prenom = newPrenom;
}

void ENSEIGNANT::setNumTel(int newNumTel)
{
    num_tel = newNumTel;
}

void ENSEIGNANT::setMatiere(const QString newMatiere)
{
    matiere = newMatiere;
}

void ENSEIGNANT::setDisponibilite(const QString newDisponibilite)
{
    disponibilite = newDisponibilite;
}

void ENSEIGNANT::setMail(const QString newMail)
{
    mail = newMail;
}

int ENSEIGNANT::getId() const
{
    return id;
}

QString ENSEIGNANT::getPassword() const
{
    return password;
}

QString ENSEIGNANT::getNom() const
{
    return nom;
}

QString ENSEIGNANT::getPrenom() const
{
    return prenom;
}

int ENSEIGNANT::getNumTel() const
{
    return num_tel;
}

QString ENSEIGNANT::getMatiere() const
{
    return matiere;
}

QString ENSEIGNANT::getDisponibilite() const
{
    return disponibilite;
}

QString ENSEIGNANT::getMail() const
{
    return mail;
}

bool ENSEIGNANT::createENSEIGNANT() {
    QSqlQuery query;
    query.prepare("INSERT INTO ENSEIGNANT (ID_ENS, MOT_DE_PASSE, NOM, PRENOM, NUM_TEL, MATIERE, DISPONIBILITÉ, MAIL) "
                  "VALUES (:id, :password, :nom, :prenom, :num_tel, :matiere, :disponibilite, :mail)");
    query.bindValue(":id", id);
    query.bindValue(":password",password);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":num_tel", num_tel);
    query.bindValue(":matiere", matiere);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":mail", mail);
    return query.exec();
}

bool ENSEIGNANT::deleteENSEIGNANT(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM ENSEIGNANT WHERE ID_ENS = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool ENSEIGNANT::updateENSEIGNANT() {
    QSqlQuery query;
    query.prepare("UPDATE ENSEIGNANT SET MOT_DE_PASSE = :password, NOM = :nom, PRENOM = :prenom, NUM_TEL = :num_tel, MATIERE = :matiere, DISPONIBILITÉ = :disponibilite, MAIL = :mail WHERE ID_ENS = :id");
    query.bindValue(":id", id);
    query.bindValue(":password",password);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":num_tel", num_tel);
    query.bindValue(":matiere", matiere);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":mail", mail);
    return query.exec();
}
bool ENSEIGNANT::Login(QString Mail,QString Password)
{
    QSqlQuery query;
       bool test=false;

           query.prepare("Select * FROM ENSEIGNANT where MAIL=:mail and MOT_DE_PASSE=:password");
            query.bindValue(":mail",Mail);
             query.bindValue(":password",Password);


             if(query.exec()&&query.next())
       {
                 test=true;

       }
       return test;
}

QSqlQueryModel* ENSEIGNANT::selectENSEIGNANT() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ENSEIGNANT");
    return model;
}


QSqlQueryModel* ENSEIGNANT::selectENSEIGNANTByID(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(QString("SELECT * FROM ENSEIGNANT WHERE ID_ENS = %1").arg(id));
    return model;
}

QSqlQueryModel* ENSEIGNANT::researcher(QString research) {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ENSEIGNANT WHERE NOM like '%"+research+"%' or PRENOM like '%"+research+"%' or MATIERE like  '%"+research+"%' or MAIL like '%"+research+"%' ");
    return model;
}

ENSEIGNANT ENSEIGNANT::retrieveENSEIGNANT(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM ENSEIGNANT WHERE ID_ENS = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.next()) {
        ENSEIGNANT ens;
        ens.setId(query.value("ID_ENS").toInt());
        ens.setPassword(query.value("MOT_DE_PASSE").toString());
        ens.setNom(query.value("NOM").toString());
        ens.setPrenom(query.value("PRENOM").toString());
        ens.setNumTel(query.value("NUM_TEL").toInt());
        ens.setMatiere(query.value("MATIERE").toString());
       ens.setDisponibilite(query.value("DISPONIBILITÉ").toString());
        ens.setMail(query.value("MAIL").toString());
        return ens;
    } else {
        // Return an empty ENSEIGNANT object if not found
        return ENSEIGNANT();
    }
}

QVector<ENSEIGNANT> ENSEIGNANT::retrieveAllENSEIGNANT() {
    QVector<ENSEIGNANT> ENSEIGNANTS;
    QSqlQuery query;
    query.prepare("SELECT * FROM ENSEIGNANT");
    query.exec();
    while (query.next()) {
        ENSEIGNANT ens;
        ens.setId(query.value("ID_ENS").toInt());
        ens.setPassword(query.value("MOT_DE_PASSE").toString());
        ens.setNom(query.value("NOM").toString());
        ens.setPrenom(query.value("PRENOM").toString());
        ens.setNumTel(query.value("NUM_TEL").toInt());
        ens.setMatiere(query.value("MATIERE").toString());
        ens.setDisponibilite(query.value("DISPONIBILITÉ").toString());
        ens.setMail(query.value("MAIL").toString());
        ENSEIGNANTS.append(ens);
        }
        return ENSEIGNANTS;
        }


int ENSEIGNANT::ENSEIGNANTDisponibiliter()
{
    QSqlQuery query;
     query.prepare("SELECT count(*) FROM ENSEIGNANT WHERE DISPONIBILITÉ = 'oui'");
     query.exec();
     query.next();

     if(query.value(0).toInt()<0)
     return 0;
     else
         return query.value(0).toInt();
}

int ENSEIGNANT::NonENSEIGNANTDisponibiliter()
{
    QSqlQuery query;
     query.prepare("SELECT count(*) FROM ENSEIGNANT WHERE DISPONIBILITÉ = 'non'");
     query.exec();
     query.next();
     if(query.value(0).toInt()<0)
     return 0;
     else
         return query.value(0).toInt();
}
