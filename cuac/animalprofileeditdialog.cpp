#include "animalprofileeditdialog.h"
#include "ui_animalprofileeditdialog.h"

AnimalProfileEditDialog::AnimalProfileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfileEditDialog)
{
    ui->setupUi(this);
//    ui->name->setText(ui->name->text().append(QString::fromStdString(animal->getName())));
//    ui->specie->setText(ui->specie->text().append(QString::fromStdString(animal->getSpecies())));
//    ui->breed->setText(ui->breed->text().append(QString::fromStdString(animal->getBreed())));
//    ui->colour->setText(ui->colour->text().append(QString::fromStdString(animal->getColour())));
//    ui->special_skill->setText(ui->special_skill->text().append(QString::number(animal->getSkill())));
//    ui->age->setText(ui->age->text().append(QString::number(animal->getAge())));
//    ui->weight->setText(ui->weight->text().append(QString::number(animal->getWeight())));
//    ui->height->setText(ui->height->text().append(QString::number(animal->getHeight())));
//    ui->energy_level->setText(ui->energy_level->text().append(QString::number(animal->getEnergy_level())));
//    ui->temperament->setText(ui->temperament->text().append(QString::number(animal->getTemperament())));
//    ui->kid_friendly->setText(ui->kid_friendly->text().append(QString::number(animal->getKid_friendly())));
//    ui->level_of_dependency->setText(ui->level_of_dependency->text().append(QString::number(animal->getLevel_of_dependency())));
//    ui->prone_to_disease->setText(ui->prone_to_disease->text().append(QString::number(animal->getProne_to_disease())));
//    ui->living_space_needed->setText(ui->living_space_needed->text().append(QString::number(animal->getLiving_space())));
//    ui->feeding_cost->setText(ui->feeding_cost->text().append(QString::number(animal->getFeeding_cost())));
//    ui->bad_habits->setText(ui->bad_habits->text().append(QString::number(animal->getBad_habits())));
//    ui->climate->setText(ui->climate->text().append(QString::number(animal->getClimate())));
//    ui->level_of_care_needed->setText(ui->level_of_care_needed->text().append(QString::number(animal->getLevel_of_care())));
//    ui->neatness->setText(ui->neatness->text().append(QString::number(animal->getNeatness())));
//    ui->current_health_condition->setText(ui->current_health_condition->text().append(QString::number(animal->getCurrent_health_condition())));
//    ui->intelligence_level->setText(ui->intelligence_level->text().append(QString::number(animal->getIntelligence_level())));
//    ui->difficulty_to_train->setText(ui->difficulty_to_train->text().append(QString::number(animal->getDifficulty_to_train())));
//    ui->noise_level->setText(ui->noise_level->text().append(QString::number(animal->getNoise_level())));





}

AnimalProfileEditDialog::~AnimalProfileEditDialog()
{
    delete ui;
}

void AnimalProfileEditDialog:: loadData(Animal* a){
    animal = a;

    ui->name->setText(ui->name->text().append(QString::fromStdString(animal->getName())));
    ui->specie->setText(ui->specie->text().append(QString::fromStdString(animal->getSpecies())));
    ui->breed->setText(ui->breed->text().append(QString::fromStdString(animal->getBreed())));
    ui->colour->setText(ui->colour->text().append(QString::fromStdString(animal->getColour())));

    ui->special_skill->setValue(animal->getSkill());
    ui->age->setValue(animal->getAge());
    ui->weight->setValue(animal->getWeight());
    ui->height->setValue(animal->getHeight());
    ui->energy_level->setValue(animal->getEnergy_level());
    ui->temperament->setValue(animal->getTemperament());
    ui->kid_friendly->setValue(animal->getKid_friendly());
    ui->level_of_dependency->setValue(animal->getLevel_of_dependency());
    ui->prone_to_disease->setValue(animal->getProne_to_disease());
    ui->living_space_required->setValue(animal->getLiving_space());
    ui->feeding_cost->setValue(animal->getFeeding_cost());
    ui->bad_habits->setValue(animal->getBad_habits());
    ui->climate->setValue(animal->getClimate());
    ui->level_of_care->setValue(animal->getLevel_of_care());
    ui->neatness->setValue(animal->getNeatness());
    ui->current_health_condition->setValue(animal->getCurrent_health_condition());
    ui->intelligence_level->setValue(animal->getIntelligence_level());
    ui->difficulty_to_train->setValue(animal->getDifficulty_to_train());
    ui->noise_level->setValue(animal->getNoise_level());
}

void AnimalProfileEditDialog::on_pushButton_clicked()
{
    AnimalProfileEditDialog::close();
}
