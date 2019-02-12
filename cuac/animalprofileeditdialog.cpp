#include "animalprofileeditdialog.h"
#include "ui_animalprofileeditdialog.h"

AnimalProfileEditDialog::AnimalProfileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfileEditDialog)
{
    ui->setupUi(this);
}

AnimalProfileEditDialog::~AnimalProfileEditDialog()
{
    delete ui;
}
