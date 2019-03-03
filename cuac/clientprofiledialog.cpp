#include "clientprofiledialog.h"
#include "ui_clientprofiledialog.h"
#include <string>

ClientProfileDialog::ClientProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientProfileDialog)
{
//    ui->setupUi(this);
//    ui->name->setText(ui->name->text().append(QString::fromStdString(client->getName())));
//    ui->email->setText(ui->email->text().append(QString::fromStdString(client->getEmail())));
//    ui->address->setText(ui->address->text().append(QString::fromStdString(client->getAddress())));
//    ui->age->setText(ui->age->text().append(QString::number(client->getAge())));
//    ui->gender->setText(ui->gender->text().append(QString::number(client->getGender())));
//    ui->cell_phone->setText(ui->cell_phone->text().append(QString::number(client->getCellPhone())));
//    ui->home_phone->setText(ui->home_phone->text().append(QString::number(client->getHomePhone())));
}

ClientProfileDialog::~ClientProfileDialog()
{
    delete ui;
}

void ClientProfileDialog::loadData(Client* a){


    ui->setupUi(this);
    ui->name->setText(ui->name->text().append(QString::fromStdString(client->getName())));
    ui->email->setText(ui->email->text().append(QString::fromStdString(client->getEmail())));
    ui->address->setText(ui->address->text().append(QString::fromStdString(client->getAddress())));
    ui->age->setText(ui->age->text().append(QString::number(client->getAge())));
    ui->gender->setText(ui->gender->text().append(QString::number(client->getGender())));
    ui->cell_phone->setText(ui->cell_phone->text().append(QString::number(client->getCellPhone())));
    ui->home_phone->setText(ui->home_phone->text().append(QString::number(client->getHomePhone())));
}
