#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "login.h"
#include "connection.h"
#include "enseignant.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   // Connexion à la base de données
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setHostName("localhost");
   db.setDatabaseName("mybase");
   db.setUserName("aymen");
   db.setPassword("boog0914k");
   if (!db.open()) {
       QMessageBox::critical(nullptr, QObject::tr("Impossible de se connecter à la base de données"),
           db.lastError().text(), QMessageBox::Cancel);
       return -1;
   }

   login w;
   w.show();


   return a.exec();
}
