#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include <QString>
#include <QVector>
#include <QSqlQueryModel>

class ENSEIGNANT
{
public:
    ENSEIGNANT();
    ENSEIGNANT(int id, const QString password, const QString nom, const QString prenom,
             int num_tel, const QString matiere, const QString disponibilite,
             const QString mail);

    void setId(int newId);
    void setPassword(const QString newPassword);
    void setNom(const QString newNom);
    void setPrenom(const QString newPrenom);
    void setNumTel(int newNumTel);
    void setMatiere(const QString newMatiere);
    void setDisponibilite(const QString newDisponibilite);
    void setMail(const QString newMail);

    int getId() const;
    QString getPassword() const;
    QString getNom() const;
    QString getPrenom() const;
    int getNumTel() const;
    QString getMatiere() const;
    QString getDisponibilite() const;
    QString getMail() const;

    bool createENSEIGNANT();
    bool deleteENSEIGNANT(int id);
    bool updateENSEIGNANT();
    bool Login(QString Mail,QString Password);
    static ENSEIGNANT retrieveENSEIGNANT(int id);
    static QVector<ENSEIGNANT> retrieveAllENSEIGNANT();

        QSqlQueryModel* selectENSEIGNANT();
        QSqlQueryModel* selectENSEIGNANTByID(int id);

        QSqlQueryModel* researcher(QString research);
        int ENSEIGNANTDisponibiliter();
        int NonENSEIGNANTDisponibiliter();

private:
    int id;
    QString password;
    QString nom;
    QString prenom;
    int num_tel;
    QString matiere;
    QString disponibilite;
    QString mail;
};

#endif // ENSEIGNANT_H
