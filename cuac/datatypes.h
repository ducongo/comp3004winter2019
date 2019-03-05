#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>

using namespace std;

struct StaffData {
    int staffId;
    string staffName;
};

struct AnimalData {
    string animalName;
    string typeOfAnimal;
    string breed;
    string colour;
    string specialSkill;
    int animalAttr [21];
};

struct ClientData {
    string clientName;
    string clientEmail;
    string clientAddr;
    string species;
    string breed;
    int clientAttr [11];
};

#endif // DATATYPES_H
