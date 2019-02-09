#include "animalprofiledialog.h"
#include "ui_animalprofiledialog.h"

AnimalProfileDialog::AnimalProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfileDialog)
{
    ui->setupUi(this);
}

AnimalProfileDialog::~AnimalProfileDialog()
{
    delete ui;
}
