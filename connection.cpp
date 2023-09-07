#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("mybase");
db.setUserName("aymen");//inserer nom de l'utilisateur
db.setPassword("boog0914k");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
