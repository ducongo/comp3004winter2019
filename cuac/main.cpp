#include "homeview.h"
#include "array.h"
#include "animal.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    Array<Animal>* animals = new Array<Animal>();

    QApplication a(argc, argv);
    HomeView w;
    w.animals = animals;
    w.show();



    //Animal *rat = new Animal("dor","dor","dor",1,3,2,"dor","dor");

    //animal.add(rat);

    return a.exec();
}
