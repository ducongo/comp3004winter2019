#ifndef ARRAY_H
#define ARRAY_H
#include "database.h"
#include "animal.h"
//using namespace std;

#define MAX_SIZE  200

template <class T>
class Array
{
  public:
    Array();
    //~Array();

    void add(T*);
    int getSize();
    T* get(int);
    void dbGet();

  private:
    int    size;
    T* data[MAX_SIZE];
    Database db;
};

template <class T>
Array<T>::Array(){

  size = 0;
  qDebug("ARRAY CONSTRUCTOR CALLED");
  db.initTables();
  AnimalData animal1;
  AnimalData animal2;
  AnimalData animal3;
  AnimalData animal4;
  AnimalData animal5;
  AnimalData animal6;
  animal1.animalName = "Victor";
  animal1.typeOfAnimal = "dog";
  animal1.breed = "Doberman";
  animal1.colour = "brown";
  animal1.animalAttr[0] = 0;
  animal1.animalAttr[1] = 9;
  animal1.animalAttr[2] = 100;
  animal1.animalAttr[3] = 36;

  animal2.animalName = "Kyle";
  animal2.typeOfAnimal = "cat";
  animal2.breed = "Ragdoll";
  animal2.colour = "gray";
  animal2.animalAttr[0] = 0;
  animal2.animalAttr[1] = 6;
  animal2.animalAttr[2] = 10;
  animal2.animalAttr[3] = 13;

  animal3.animalName = "Parfait";
  animal3.typeOfAnimal = "dog";
  animal3.breed = "GermanShepherd";
  animal3.colour = "blue";
  animal3.animalAttr[0] = 0;
  animal3.animalAttr[1] = 7;
  animal3.animalAttr[2] = 90;
  animal3.animalAttr[3] = 40;

  animal4.animalName = "John";
  animal4.typeOfAnimal = "dog";
  animal4.breed = "Persian";
  animal4.colour = "pink";
  animal4.animalAttr[0] = 1;
  animal4.animalAttr[1] = 2;
  animal4.animalAttr[2] = 6;
  animal4.animalAttr[3] = 12;

  animal5.animalName = "Bingo";
  animal5.typeOfAnimal = "Bear";
  animal5.breed = "Polar";
  animal5.colour = "Black";
  animal5.animalAttr[0] = 1;
  animal5.animalAttr[1] = 3;
  animal5.animalAttr[2] = 400;
  animal5.animalAttr[3] = 50;

  animal6.animalName = "Rogue";
  animal6.typeOfAnimal = "Bird";
  animal6.breed = "Parrot";
  animal6.colour = "All";
  animal6.animalAttr[0] = 1;
  animal6.animalAttr[1] = 4;
  animal6.animalAttr[2] = 3;
  animal6.animalAttr[3] = 7;

  if (db.pushAnimal(animal1)){
      qDebug("Failed to push animal 1 to DB");
  }
  if (db.pushAnimal(animal2)){
        qDebug("Failed to push animal 2 to DB");
  }
  if (db.pushAnimal(animal3)){
      qDebug("Failed to push animal 3 to DB");
  }
  if (db.pushAnimal(animal4)){
      qDebug("Failed to push animal 4 to DB");
  }
  if (db.pushAnimal(animal5)){
      qDebug("Failed to push animal 5 to DB");
  }
  if (db.pushAnimal(animal6)){
      qDebug("Failed to push animal 6 to DB");
  }
}

//template <class T>
//Array<T>::~Array(){}

template <class T>
void Array<T>::add(T* i){
    AnimalData animal;
    animal.animalName = i->getName();
    animal.typeOfAnimal = i->getSpecies();
    animal.breed = i->getBreed();
    animal.animalAttr[0] = 1;
    animal.animalAttr[1] = i->getAge();
    animal.animalAttr[2] = i->getWeight();
    animal.animalAttr[3] = i->getHeight();
     if (db.pushAnimal(animal))
            qDebug("failed to push animal to db");
  data[size] = i;


  size++;

}

template <class T>
int Array<T>::getSize(){
  return size;
}

template <class T>
T* Array<T>::get(int i){
  return data[i];
}

template <class T>
void Array<T>::dbGet(){
    qDebug("*********************PULLING DATA**************");

    db.initTables();
    AnimalData** test = db.pullAnimals();
    int x = 0;
    while(test[x] != NULL){

        Animal *a = new Animal(test[x]->animalName,test[x]->typeOfAnimal, test[x]->breed, test[x]->animalAttr[1],test[x]->animalAttr[2],test[x]->animalAttr[3], test[x]->colour, std::to_string(test[x]->animalAttr[0]));
        add(a);
        qDebug("Yooo %s", QString::fromStdString(test[x]->animalName));

        x++;
    }

}

#endif













