#include "homeview.h"
#include "array.h"
#include "animal.h"
#include "client.h"
#include <QApplication>
#include "database.h"


int main(int argc, char *argv[])
{
    Array<Animal>* animals = new Array<Animal>();
    Array<Client>* clients = new Array<Client>();

    QApplication a(argc, argv);

    //animals->dbGet();
    Database* db123;
    HomeView w;

    w.animals = animals;
    w.clients = clients;
    w.db123 = db123;
    w.loadArrays();
    w.show();

    qDebug("LAUNCHING APPLICATION");



    //Animal *rat = new Animal("dor","dor","dor",1,3,2,"dor","dor");

    //animal.add(rat);

    return a.exec();
}
