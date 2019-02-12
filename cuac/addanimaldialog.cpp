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

    Animal *a = new Animal((ui->name->text()).toStdString(),(ui->specie->text()).toStdString(),(ui->breed->text()).toStdString(),(ui->age->text()).toInt(),(ui->weight->text()).toInt(),(ui->height->text()).toInt(),(ui->colour->text()).toStdString(),(ui->skill->text()).toStdString());
    qDebug("Before");
    Animal *ani[40];
    ani[0] = a;
    qDebug("SIZE OF ARRAY %d", animals->getSize());
    animals->add(a);
    qDebug("After");
    //animals->add(a);
    AddAnimalDialog::close();
}





