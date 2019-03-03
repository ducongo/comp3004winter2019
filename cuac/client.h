#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "attribute.h"

using namespace std;

class Client
{
  public:
    Client(string, string, string, int,int, int,int);
    ~Client();

    string getName();
    string getEmail();
    string getAddress();

    int getCellPhone();
    int getHomePhone();

    int getAnimal();
    int getBreed();
    int getSpecialRequriements();

    int getAge();
    int getGender();
    int getEconomicBackground();
    int getActivityLevel();
    int getExperienceWithAnimals();
    int getLevelOfPatience();
    int getHouseSize();
    int getAvailableTime();
    int getStrength();

    void setName();
    void setEmail();
    void setAddress();

    void setCellPhone();
    void setHomePhone();

    void setAnimal();
    void setBreed();
    void setSpecialRequriements();

    void setAge();
    void setGender();
    void setEconomicBackground();
    void setActivityLevel();
    void setExperienceWithAnimals();
    void setLevelOfPatience();
    void setHouseSize();
    void setAvailableTime();
    void setStrength();

    Attribute* att[17];

  private:

    string name;
    string email;
    string address;

    int cellPhone;
    int homePhone;

    int animal;
    int breed;
    int specialRequriements;

    int age;
    int gender;
    int economicBackground;
    int activityLevel;
    int experienceWithAnimals;
    int levelOfPatience;
    int houseSize;
    int availableTime;
    int strength;

    void initalizeAttibutes(int[]);

};

  #endif

