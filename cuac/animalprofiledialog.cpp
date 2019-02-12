#include "animalprofiledialog.h"
#include "ui_animalprofiledialog.h"
#include <string>

AnimalProfileDialog::AnimalProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfileDialog)
{
    qDebug("Called Function SETUPPPPPPP");

//    qDebug("NAME OF ANIMAL: %s", animal->getName());
//    ui->setupUi(this);
//    ui->name->setText(QString::fromStdString(animal->getName()));
//    ui->specie->setText(QString::fromStdString(animal->getSpecies()));
//    ui->breed->setText(QString::fromStdString(animal->getBreed()));
//    ui->age->setText(QString::fromStdString(std::to_string(animal->getAge())));
//    ui->weight->setText(QString::fromStdString(std::to_string(animal->getWeight())));
//    ui->height->setText(QString::fromStdString(std::to_string(animal->getHeight())));
//    ui->colour->setText(QString::fromStdString(animal->getColour()));
//    ui->special_skill->setText(QString::fromStdString(animal->getSkill()));
}

AnimalProfileDialog::~AnimalProfileDialog()
{
    delete ui;
}
