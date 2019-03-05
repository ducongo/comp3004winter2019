#include "addanimaldialog.h"
#include "ui_addanimaldialog.h"
#include "animal.h"
#include <exception>

AddAnimalDialog::AddAnimalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAnimalDialog)
{
    ui->setupUi(this);
}

AddAnimalDialog::~AddAnimalDialog()
{
    delete ui;
}

void AddAnimalDialog::on_pushButton_clicked()
{
    //(string Name,string Species,string Breed,int Age,int Weight,int Height,string Colour,string Skill,
                   /*
                   int Energy_level,1
                   int Kid_friendly,
                   int Level_of_dependency,
                   int Prone_to_disease,
                   int Living_space,
                   int Feeding_cost,
                   int Climate,
                   int Level_of_care,
                   int Neatness,
                   int Current_health_condition,
                   int Intelligence_level,
                   int Difficulty_to_train,
                   int Noise_level) */
    Animal *a = new Animal((ui->name->text()).toStdString()
                           , (ui->specie->text()).toStdString()
                           , (ui->breed->text()).toStdString()
                           , (ui->age->text()).toInt()
                           , (ui->weight->text()).toInt()
                           , (ui->height->text()).toInt()
                           , (ui->colour->text()).toStdString()
                           , (ui->special_skill->text()).toInt()
                           , (ui->energy_level->text()).toInt()
                           , (ui->kid_friendly->text()).toInt()
                           , (ui->level_of_dependency->text()).toInt()
                           , (ui->prone_to_disease->text()).toInt()
                           , (ui->living_space_required->text()).toInt()
                           , (ui->feeding_cost->text()).toInt()
                           , (ui->climate->text()).toInt()
                           , (ui->level_of_care->text()).toInt()
                           , (ui->neatness->text()).toInt()
                           , (ui->current_health_condition->text()).toInt()
                           , (ui->intelligence_level->text()).toInt()
                           , (ui->difficulty_to_train->text()).toInt()
                           , (ui->noise_level->text()).toInt()
                           , (ui->temperament->text()).toInt()
                           , (ui->bad_habits->text()).toInt());
    qDebug("Before");
    Animal *ani[40];
    ani[0] = a;
    qDebug("SIZE OF ARRAY %d", animals->getSize());
    animals->add(a);
    qDebug("After");

    AnimalData newAnimal;
    newAnimal.animalName = a->getName();
    newAnimal.typeOfAnimal = a->getSpecies();
    newAnimal.breed = a->getBreed();
    newAnimal.animalAttr[0] = 0;
    newAnimal.animalAttr[1] = a->getAge();
    newAnimal.animalAttr[2] = a->getWeight();
    newAnimal.animalAttr[3] = a->getHeight();
    newAnimal.animalAttr[4] = a->getEnergy_level();
    newAnimal.animalAttr[5] = a->getTemperament();
    newAnimal.animalAttr[6] = a->getKid_friendly();
    newAnimal.animalAttr[7] = a->getBad_habits();
    newAnimal.animalAttr[8] = a->getLevel_of_care();
    newAnimal.animalAttr[9] = a->getLevel_of_dependency();
    newAnimal.animalAttr[10] = a->getProne_to_disease();
    newAnimal.animalAttr[11] = a->getLiving_space();
    newAnimal.animalAttr[12] = a->getClimate();
    newAnimal.animalAttr[14] = a->getNeatness();
    newAnimal.animalAttr[15] = a->getCurrent_health_condition();
    newAnimal.animalAttr[16] = a->getIntelligence_level();
    newAnimal.animalAttr[17] = a->getDifficulty_to_train();
    newAnimal.animalAttr[18] = a->getFeeding_cost();
    newAnimal.animalAttr[19] = a->getNoise_level();

    if (db->pushAnimal(newAnimal)) qDebug("failed to push animal to db");

    //animals->add(a);
    home->loadData();
    AddAnimalDialog::close();
}





