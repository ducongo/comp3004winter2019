#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include "client.h"

AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    ui->breed->addItem("Black Labrador");
    ui->breed->addItem("German Shepherd");
    ui->breed->addItem("Corgi");
    ui->breed->addItem("Shiba Inu");
    ui->breed->addItem("Bulldog");
}

AddClientDialog::~AddClientDialog()
{
    delete ui;

}

void AddClientDialog::on_pushButton_clicked()
{

    Client* client = new Client((ui->name->text()).toStdString(), (ui->email->text()).toStdString(), (ui->address->text()).toStdString(), (ui->age->text()).toInt(), (ui->gender->text()).toInt(), (ui->cell_phone->text()).toInt(), (ui->home_phone->text()).toInt()
                                ,(ui->economic_background->text()).toInt()
                                ,(ui->activity_level->text()).toInt()
                                ,(ui->experience_with_animal->text()).toInt()
                                ,(ui->level_of_patience->text()).toInt()
                                ,(ui->house_size->text()).toInt()
                                ,(ui->available_time->text()).toInt()
                                ,(ui->strength->text()).toInt()
                                ,(ui->specie->text()).toInt()
                                ,(ui->breed->currentIndex()) + 1
                                ,(ui->special_skill->text()).toInt()
                                ,control->getClientArraySize() + 1);
    control->addClient(client);

    control->getHomeView()->loadData();
    AddClientDialog::close();
}

void AddClientDialog::on_specie_valueChanged(int arg1)
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

void AddClientDialog::on_breed_currentIndexChanged(int index)
{
    //qDebug("INDEXXXXXXX: %d", (ui->breed->currentIndex()));
}
