#include <iomanip>
#include <sstream>
using namespace std;

#include "animal.h"

Animal::Animal(string Name,string Species,string Breed,int Age,int Weight,int Height,string Colour,string Skill/*,int at[17]*/)
{
  name = Name;
  species = Species;
  breed = Breed;
  age = Age;
  weight = Weight;
  height = Height;
  colour = Colour;
  specialSkill = Skill;

  //initalizeAttibutes(at);
}

Animal::~Animal()
{

}

string Animal::getName(){return name;}
string Animal::getSpecies(){return species;}
string Animal::getBreed(){return breed;}

int Animal::getAge(){return age;}
int Animal::getWeight(){return weight;}
int Animal::getHeight(){return height;}

void Animal::setAge(int a){age = a;}
void Animal::setWeight(int w){weight = w;}
void Animal::setHeight(int h){height = h;}

string Animal::getColour(){return colour;}
string Animal::getSkill(){return specialSkill;}

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
