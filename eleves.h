#ifndef ELEVES_H
#define ELEVES_H

#include <QString>
#include <QVector>
#include <QSqlQueryModel>

class ELEVES
{
public:
    ELEVES();
    ELEVES(int id, const QString nom, const QString prenom ,int moyenne);

    void setId(int newId);

    void setNom(const QString newNom);
    void setPrenom(const QString newPrenom);

    void setMoyenne(int newMoyenne);


    int getId() const;

    QString getNom() const;
    QString getPrenom() const;

    int getMoyenne() const;
    bool createELEVES();
    bool deleteELEVES(int id);
    bool updateELEVES();

    static ELEVES retrieveELEVES(int id);
    static QVector<ELEVES> retrieveAllELEVES();

        QSqlQueryModel* selectELEVES();
        QSqlQueryModel* selectELEVESByID(int id);
         QSqlQueryModel* researcher(QString research);

       private:
    int id;

    QString nom;
    QString prenom;
    int moyenne;

};



#endif // ELEVES_H
