#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#include "attribute.h"

using namespace std;

class Animal
{
  public:
    Animal(string, string, string, int, int, int, string, string/*,int[]*/, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    ~Animal();

    string getName();
    string getSpecies();
    string getBreed();

    int getAge();
    int getWeight();
    int getHeight();
    int getEnergy_level();
    int getKid_friendly();
    int getLevel_of_dependency();
    int getProne_to_disease();
    int getLiving_space();
    int getFeeding_cost();
    int getClimate();
    int getLevel_of_care();
    int getNeatness();
    int getCurrent_health_condition();
    int getIntelligence_level();
    int getDifficulty_to_train();
    int getNoise_level();
    int getTemperament();
    int getBad_habits();

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
    int energy_level;
    int kid_friendly;
    int level_of_dependency;
    int prone_to_disease;
    int living_space;
    int feeding_cost;
    int climate;
    int level_of_care;
    int neatness;
    int current_health_condition;
    int intelligence_level;
    int difficulty_to_train;
    int noise_level;
    int temperament;
    int bad_habits;

    string colour;
    string specialSkill;

    void initalizeAttibutes(int[]);

};

  #endif
