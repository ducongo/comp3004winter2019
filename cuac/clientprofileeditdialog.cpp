#include "clientprofileeditdialog.h"
#include "ui_clientprofileeditdialog.h"

ClientProfileEditDialog::ClientProfileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientProfileEditDialog)
{
    ui->setupUi(this);
}

ClientProfileEditDialog::~ClientProfileEditDialog()
{
    delete ui;
}
