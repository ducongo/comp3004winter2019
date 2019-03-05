#include "addclientdialog.h"
#include "ui_addclientdialog.h"

AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
}

AddClientDialog::~AddClientDialog()
{
    delete ui;
}

void AddClientDialog::on_pushButton_clicked()
{
    Client* client = new Client((ui->name->text()).toStdString(), (ui->email->text()).toStdString(), (ui->address->text()).toStdString(), (ui->age->text()).toInt(), (ui->gender->text()).toInt(), (ui->cell_phone->text()).toInt(), (ui->home_phone->text()).toInt());
    clients->add(client);

    ClientData newClient;

    newClient.clientName = client->getName();
    newClient.clientEmail = client->getEmail();
    newClient.clientAddr = client->getAddress();
    newClient.species = "";
    newClient.breed = "";
    newClient.clientAttr[0] = client->getHomePhone();
    newClient.clientAttr[1] = client->getCellPhone();
    newClient.clientAttr[2] = client->getAge();
    newClient.clientAttr[3] = client->getGender();




    if (db->pushClient(newClient)) qDebug("failed to push animal to db");

    home->loadData();
    AddClientDialog::close();
}
