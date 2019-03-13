#ifndef CONTROL_H
#define CONTROL_H

#include <string>

#include "animal.h"
#include "client.h"
#include "array.h"
#include "database.h"
#include "homeview.h"


using namespace std;

class Control
{
  public:
    Control();

    void addAnimal(Animal*);
    void addClient(Client*);

    void updateAnimal(Animal*);
    void upDateClient(Client*);

    Animal* getAnimal();
    Client* getClient();
    HomeView* getHomeView();

    void populateAnimalArray();
    void populateClientArray();

    int getAnimalArraySize();
    int getAnimalClientSize();

    void setHomeView();







  private:
    Array<Animal>* animals;
    Array<Client>* clients;
    Database* db;
    HomeView *home;


};

  #endif
