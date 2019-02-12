#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <datatypes.h>

class Database
{
    public:
        Database();
        int initTables();
        int pushAnimal(AnimalData);
        void pushClient();
        void pushStaff();
        AnimalData** pullAnimals();
        void pullClients();
        void pullStaffs();
    private:
        QSqlDatabase db;

};

#endif // DATABASE_H
