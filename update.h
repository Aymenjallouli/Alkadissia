#ifndef UPDATE_H
#define UPDATE_H


#include <QString>

class Update {
public:
    Update(int id, QString password, QString nom, QString prenom, int num_tel, QString departement, QString disponibilite, QString mail);
    void updateEmployee();

private:
    int m_id;
    QString m_password;
    QString m_nom;
    QString m_prenom;
    int m_num_tel;
    QString m_departement;
    QString m_disponibilite;
    QString m_mail;
};

#endif // UPDATE_H
