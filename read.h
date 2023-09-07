#ifndef READ_H
#define READ_H


#include <QSqlQueryModel>

class Read {
public:
    static QSqlQueryModel* selectEmployees();
};

#endif // READ_H
