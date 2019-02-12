#include "addanimaldialog.h"
#include "ui_addanimaldialog.h"

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
