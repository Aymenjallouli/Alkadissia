QSqlQuery query;
query.prepare("INSERT INTO personnes (id, nom, prenom, mail, telephone, departement, mot_de_passe) "
              "VALUES (:id, :nom, :prenom, :mail, :telephone, :departement, :mot_de_passe)");
query.bindValue(":id", 1);
query.bindValue(":nom", "Doe");
query.bindValue(":prenom", "John");
query.bindValue(":mail", "johndoe@example.com");
query.bindValue(":telephone", "555-1234");
query.bindValue(":departement", "RH");
query.bindValue(":mot_de_passe", "secret");
query.exec();
