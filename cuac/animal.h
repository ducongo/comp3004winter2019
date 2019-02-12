#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#include "attribute.h"

using namespace std;

class Animal
{
  public:
    Animal(string,string,string,int,int,int,string,string/*,int[]*/);
    ~Animal();

    string getName();
    string getSpecies();
    string getBreed();

    int getAge();
    int getWeight();
    int getHeight();

    void setAge(int);
    void setWeight(int);
    void setHeight(int);

    string getColour();
    string getSkill();

    Attribute* att[17];

  private:

    string name;
    string species;
    string breed;

    int age;
    int weight;
    int height;

    string colour;
    string specialSkill;

    void initalizeAttibutes(int[]);

};

  #endif
