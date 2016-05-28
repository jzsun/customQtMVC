#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

static bool conncection(const QString& name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
 //   db.setHostName("localhost");
    db.setDatabaseName(name);
//    db.setUserName("sun");
//    db.setPassword("123456");
    if (!db.open()) {
        return false;
    }
    return true;
}
#endif // CONNECTION_H
