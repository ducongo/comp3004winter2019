#include "viewanimaldialog.h"
#include "ui_viewanimaldialog.h"
#include "animal.h"
#include "animalprofileeditdialog.h"

ViewAnimalDialog::ViewAnimalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAnimalDialog)
{
    ui->setupUi(this);
    ui->image->setStyleSheet("background-image: url(:/img/images/pet.png)");
}

ViewAnimalDialog::~ViewAnimalDialog()
{
    delete ui;
}

void ViewAnimalDialog::loadData(Animal* animal){

    a = animal;
    resetLabels();
    ui->name->setText(ui->name->text().append(QString::fromStdString(animal->getName())));
    ui->specie->setText(ui->specie->text().append(QString::fromStdString(animal->getSpecies())));
    ui->breed->setText(ui->breed->text().append(QString::fromStdString(animal->getBreed())));
    ui->colour->setText(ui->colour->text().append(QString::fromStdString(animal->getColour())));
    ui->special_skill->setText(ui->special_skill->text().append(QString::number(animal->getSkill())));
    ui->age->setText(ui->age->text().append(QString::number(animal->getAge())));
    ui->weight->setText(ui->weight->text().append(QString::number(animal->getWeight())));
    ui->height->setText(ui->height->text().append(QString::number(animal->getHeight())));
    ui->energy_level->setText(ui->energy_level->text().append(QString::number(animal->getEnergy_level())));
    ui->temperament->setText(ui->temperament->text().append(QString::number(animal->getTemperament())));
    ui->kid_friendly->setText(ui->kid_friendly->text().append(QString::number(animal->getKid_friendly())));
    ui->level_of_dependency->setText(ui->level_of_dependency->text().append(QString::number(animal->getLevel_of_dependency())));
    ui->prone_to_disease->setText(ui->prone_to_disease->text().append(QString::number(animal->getProne_to_disease())));
    ui->living_space_needed->setText(ui->living_space_needed->text().append(QString::number(animal->getLiving_space())));
    ui->feeding_cost->setText(ui->feeding_cost->text().append(QString::number(animal->getFeeding_cost())));
    ui->bad_habits->setText(ui->bad_habits->text().append(QString::number(animal->getBad_habits())));
    ui->climate->setText(ui->climate->text().append(QString::number(animal->getClimate())));
    ui->level_of_care_needed->setText(ui->level_of_care_needed->text().append(QString::number(animal->getLevel_of_care())));
    ui->neatness->setText(ui->neatness->text().append(QString::number(animal->getNeatness())));
    ui->current_health_condition->setText(ui->current_health_condition->text().append(QString::number(animal->getCurrent_health_condition())));
    ui->intelligence_level->setText(ui->intelligence_level->text().append(QString::number(animal->getIntelligence_level())));
    ui->difficulty_to_train->setText(ui->difficulty_to_train->text().append(QString::number(animal->getDifficulty_to_train())));
    ui->noise_level->setText(ui->noise_level->text().append(QString::number(animal->getNoise_level())));
}

void ViewAnimalDialog::resetLabels(){
    ui->name->setText("Name: ");
    ui->specie->setText("Specie: ");
    ui->breed->setText("Breed: ");
    ui->colour->setText("Colour: ");
    ui->special_skill->setText("Special skill: ");
    ui->age->setText("Age: ");
    ui->weight->setText("Weight: ");
    ui->height->setText("Height: ");
    ui->energy_level->setText("Energy Level: ");
    ui->temperament->setText("Temperament: ");
    ui->kid_friendly->setText("Kid Friendly: ");
    ui->level_of_dependency->setText("Level of Dependency: ");
    ui->prone_to_disease->setText("Prone to Disease: ");
    ui->living_space_needed->setText("");
    ui->feeding_cost->setText("Feeding Cost: ");
    ui->bad_habits->setText("Bad Habits: ");
    ui->climate->setText("Climate: ");
    ui->level_of_care_needed->setText("Level of Care Needed: ");
    ui->neatness->setText("Neatness: ");
    ui->current_health_condition->setText("Current Health Condition: ");
    ui->intelligence_level->setText("Intellihence Level: ");
    ui->difficulty_to_train->setText("Difficulty to Train");
    ui->noise_level->setText("Noise Level");
}

void ViewAnimalDialog::on_update_button_clicked()
{
    AnimalProfileEditDialog d;
    d.animal = a;
    d.loadData(a);
    d.setModal(true);
    d.exec();
    qDebug("WE RETURNING TO THE CALLING DIALOG");

    resetLabels();
    loadData(a);

}
