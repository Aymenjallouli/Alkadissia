#ifndef CREATE_H
#define CREATE_H




#include <QString>

class Create {
public:
    Create(int id, QString password, QString nom, QString prenom, int num_tel, QString departement, QString disponibilite, QString mail);
    void createEmployee();

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

#endif // CREATE_H

