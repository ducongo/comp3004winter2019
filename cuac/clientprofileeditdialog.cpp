#include "clientprofileeditdialog.h"
#include "ui_clientprofileeditdialog.h"

ClientProfileEditDialog::ClientProfileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientProfileEditDialog)
{


}

ClientProfileEditDialog::~ClientProfileEditDialog()
{
    delete ui;
}

void ClientProfileEditDialog::on_specie_valueChanged(int arg1)
{
    ui->breed->clear();
    if (arg1 == 1){
        ui->breed->addItem("Black Labrador");
        ui->breed->addItem("German Shepherd");
        ui->breed->addItem("Corgi");
        ui->breed->addItem("Shiba Inu");
        ui->breed->addItem("Bulldog");
    }else if (arg1 == 2){
        ui->breed->addItem("Calico");
        ui->breed->addItem("Lion");
        ui->breed->addItem("Tiger");
        ui->breed->addItem("Leopard");
        ui->breed->addItem("Panther");
    }else if (arg1 == 3){
        ui->breed->addItem("Parrot");
        ui->breed->addItem("Flamingo");
        ui->breed->addItem("Eagle");
        ui->breed->addItem("Vulture");
        ui->breed->addItem("Raven");
    }else if (arg1 == 4){
        ui->breed->addItem("Grizzly");
        ui->breed->addItem("Polar");
        ui->breed->addItem("Black");
        ui->breed->addItem("Black");
        ui->breed->addItem("Koala");
    }else if (arg1 == 5){
        ui->breed->addItem("Goldish");
        ui->breed->addItem("Carp");
        ui->breed->addItem("Koi");
        ui->breed->addItem("Dwarf Lanternshark");
        ui->breed->addItem("Sea horse");
    }
}

void ClientProfileEditDialog::loadData(Client* c){
    client = c;

    ui->setupUi(this);
    ui->name->setText(QString::fromStdString(client->getName()));
    ui->email->setText(QString::fromStdString(client->getEmail()));
    ui->address->setText(QString::fromStdString(client->getAddress()));
    ui->age->setValue(client->getAge());
    ui->gender->setValue(client->getGender());
    ui->cell_phone->setText(QString::number(client->getCellPhone()));
    ui->home_phone->setText(QString::number(client->getHomePhone()));
    /*
    ui->economic_background->setValue(client->getEconomicBackground());
    ui->activity_level->setValue(client->getActivityLevel());
    ui->experience_with_animal->setValue(client->getExperienceWithAnimals());
    ui->level_of_patience->setValue(client->getLevelOfPatience());
    ui->house_size->setValue(client->getHouseSize());
    ui->available_time->setValue(client->getAvailableTime());
    ui->strength->setValue(client->getStrength());
    ui->specie->setValue(client->getAnimal());
    //ui->breed->setValue(client->);
    ui->special_skill->setValue(client->getSpecialRequriements());

    if (client->getAnimal() == 1){
        ui->breed->addItem("Black Labrador");
        ui->breed->addItem("German Shepherd");
        ui->breed->addItem("Corgi");
        ui->breed->addItem("Shiba Inu");
        ui->breed->addItem("Bulldog");
    }else if (client->getAnimal() == 2){
        ui->breed->addItem("Calico");
        ui->breed->addItem("Lion");
        ui->breed->addItem("Tiger");
        ui->breed->addItem("Leopard");
        ui->breed->addItem("Panther");
    }else if (client->getAnimal() == 3){
        ui->breed->addItem("Parrot");
        ui->breed->addItem("Flamingo");
        ui->breed->addItem("Eagle");
        ui->breed->addItem("Vulture");
        ui->breed->addItem("Raven");
    }else if (client->getAnimal() == 4){
        ui->breed->addItem("Grizzly");
        ui->breed->addItem("Polar");
        ui->breed->addItem("Black");
        ui->breed->addItem("Black");
        ui->breed->addItem("Koala");
    }else if (client->getAnimal() == 5){
        ui->breed->addItem("Goldish");
        ui->breed->addItem("Carp");
        ui->breed->addItem("Koi");
        ui->breed->addItem("Dwarf Lanternshark");
        ui->breed->addItem("Sea horse");
    }

    ui->breed->setCurrentIndex(client->getBreed());
    */
}

void ClientProfileEditDialog::on_pushButton_clicked()
{
    client->setName((ui->name->text()).toStdString());
    client->setEmail((ui->email->text()).toStdString());
    client->setAddress((ui->address->text()).toStdString());

    client->setCellPhone((ui->cell_phone->text()).toInt());
    client->setHomePhone((ui->home_phone->text()).toInt());
    /*
    client->setAnimal((ui->specie->text()).toInt());
    client->setBreed((ui->breed->currentIndex()) + 1);
    client->setSpecial_requriements((ui->special_skill->text()).toInt());

    client->setAge((ui->age->text()).toInt());
    client->setGender((ui->gender->text()).toInt());
    client->setEconomic_background((ui->economic_background->text()).toInt());
    client->setActivity_level((ui->activity_level->text()).toInt());
    client->setExperience_with_animals((ui->experience_with_animal->text()).toInt());
    client->setLevel_of_patience((ui->level_of_patience->text()).toInt());
    client->setHouse_size((ui->house_size->text()).toInt());
    client->setAvailable_time((ui->available_time->text()).toInt());
    client->setStrength((ui->strength->text()).toInt());
    */

    ClientProfileEditDialog::close();
}


