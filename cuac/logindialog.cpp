#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{

}

void LoginDialog::on_pushButton_2_clicked()
{

}

void LoginDialog::on_staff_clicked()
{
    home->is_staff_member = 1;
    LoginDialog::close();
}

void LoginDialog::on_client_clicked()
{
    home->is_staff_member = 2;
    LoginDialog::close();
}
