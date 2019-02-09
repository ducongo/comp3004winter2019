#include "clientprofiledialog.h"
#include "ui_clientprofiledialog.h"

ClientProfileDialog::ClientProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientProfileDialog)
{
    ui->setupUi(this);
}

ClientProfileDialog::~ClientProfileDialog()
{
    delete ui;
}
