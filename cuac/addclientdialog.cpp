#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include "client.h"

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
    control->addClient(client);

    control->getHomeView()->loadData();
    AddClientDialog::close();
}
