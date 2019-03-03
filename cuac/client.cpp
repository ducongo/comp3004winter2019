#include <iomanip>
#include <sstream>
using namespace std;

#include "client.h"

Client::Client(string Name, string Email, string Address, int Age, int Gender, int Cell_phone, int Home_phone)
{
    name = Name;
    email = Email;
    address = Address;
    age = Age;
    gender = Gender;
    cellPhone = Cell_phone;
    homePhone = Home_phone;

  //initalizeAttibutes(at);
}

Client::~Client()
{

}

string Client::getName(){return name;}
string Client::getEmail(){return email;}
string Client::getAddress(){return address;}

int Client::getCellPhone(){return cellPhone;}
int Client::getHomePhone(){return homePhone;}

int Client::getAnimal();
int Client::getBreed();
int Client::getSpecialRequriements();

int Client::getAge(){return age;}
int Client::getGender(){return gender;}
int Client::getEconomicBackground();
int Client::getActivityLevel();
int Client::getExperienceWithAnimals();
int Client::getLevelOfPatience();
int Client::getHouseSize();
int Client::getAvailableTime();
int Client::getStrength();

void Client::setName();
void Client::setEmail();
void Client::setAddress();

void Client::setCellPhone();
void Client::setHomePhone();

void Client::setAnimal();
void Client::setBreed();
void Client::setSpecialRequriements();

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

void Animal::initalizeAttibutes(int at[]){

  /*att[0] = new Attibute("Energy Level",at[0],0,"(1-Enegitic,2-Typical,3-Slugish)");
  att[1] = new Attibute("Temperament",at[1],0,"(1-Agressive,2-Typical,3-Calm)");
  att[2] = new Attibute("Kid Friendly",at[2],0,"(1-Slugish,2-Typical,3-Enegitic)");
  att[3] = new Attibute("Bad Habits",at[3],0,"(1-Alot,2-Typical,3-little to none)");
  att[4] = new Attibute("Previous Level of Care",at[4],0,"(1-Pampered,2-Typical,3-Maltreated)");
  att[5] = new Attibute("Level of Dependency",at[5],0,"(1-Dependent,2-Typical,3-Independent)");
  att[6] = new Attibute("Prone to Disease",at[6],0,"(1-Very Prone,2-Typical,3-Not very Prone)");
  att[7] = new Attibute("Living Space Needed",at[7],0,"(1-Large,2-Typical,3-Small)");
  att[8] = new Attibute("Climate Sensitivity",at[8],0,"(1-Sensitive,2-Typical,3-Tolerant)");
  att[9] = new Attibute("Level of Care Needed",at[9],0,"(1-Round the clock,2-Typical,3-Minimal)");
  att[10] = new Attibute("Neatness",at[10],0,"(1-Filthy,2-Typical,3-Sanitary)");
  att[11] = new Attibute("Medical History",at[11],0,"(1-Cronic ilnesses,2-Typical,3-Mostly Healthy)");
  att[12] = new Attibute("Current Health Condition",at[12],0,"(1-ill,2-falling ill,3-healthy)");
  att[13] = new Attibute("Intelligence level",at[13],0,"(1-Idiotic,2-Typical,3-Inteligent)");
  att[14] = new Attibute("Difficulty to train",at[14],0,"(1-Hard,2-Typical,3-Easy)");
  att[15] = new Attibute("Feeding Cost",at[15],0,"(1-$$$,2-$$,3-$)");
  att[16] = new Attibute("Noise Level",at[16],0,"(1-Loud,2-Typical,3-Quiet)");*/

}
