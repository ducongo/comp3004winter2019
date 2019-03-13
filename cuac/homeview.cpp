#include "homeview.h"
#include "ui_homeview.h"
#include "animalprofiledialog.h"
#include "clientprofiledialog.h"
#include "addanimaldialog.h"
#include "addclientdialog.h"
#include "viewanimaldialog.h"
#include "logindialog.h"
#include "erroruserdialog.h"


HomeView::HomeView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeView)
{
    ui->setupUi(this);
    ui->listWidgetAnimal->setViewMode(QListWidget::IconMode);
    ui->listWidgetAnimal->setIconSize(QSize(128, 128));
    ui->listWidgetAnimal->setResizeMode(QListWidget::Adjust);

    ui->listWidgetClient->setViewMode(QListWidget::IconMode);
    ui->listWidgetClient->setIconSize(QSize(128, 128));
    ui->listWidgetClient->setResizeMode(QListWidget::Adjust);

    LoginDialog loginDialog;
    loginDialog.home = this;
    loginDialog.setModal(true);
    loginDialog.exec();

}

HomeView::~HomeView()
{
    delete ui;
}

void HomeView::on_runACMButton_clicked()
{
    qDebug("Running ACM Algorithm");
}

void HomeView::on_listWidgetAnimal_itemDoubleClicked(QListWidgetItem *item)
{
    if (is_staff_member != 0){
        qDebug("Animal Selected at index: %d", item->listWidget()->currentRow());
        ViewAnimalDialog profile;
        profile.setModal(true);
        profile.loadData(control->getAnimal(item->listWidget()->currentRow()));
        //profile.loadData(animals->get(item->listWidget()->currentRow()));
        //aprofile.animal = animals->get(item->listWidget()->currentRow());
        profile.exec();
    }else{
        LoginDialog loginDialog;
        loginDialog.home = this;
        loginDialog.setModal(true);
        loginDialog.exec();
    }

}

void HomeView::on_listWidgetClient_itemDoubleClicked(QListWidgetItem *item)
{
    if (is_staff_member != 0){
        qDebug("Animal Selected at index: %d", item->listWidget()->currentRow());
        ClientProfileDialog profile;
        profile.setModal(true);
        profile.loadData(control->getAnimal(item->listWidget()->currentRow()));
        //aprofile.animal = animals->get(item->listWidget()->currentRow());
        profile.exec();
    }else{
        LoginDialog loginDialog;
        loginDialog.home = this;
        loginDialog.setModal(true);
        loginDialog.exec();
    }

}

void HomeView::on_addAnimal_clicked()
{
    if ((is_staff_member == 1) && (is_staff_member != 0)){
        qDebug("Adding animal");
        AddAnimalDialog d;
        d.control = control;
        d.setModal(true);
        d.exec();
    }else if ((is_staff_member == 2) && (is_staff_member != 0)){
        ErrorUserDialog e;
        e.setModal(true);
        e.exec();
    }else{
        LoginDialog loginDialog;
        loginDialog.home = this;
        loginDialog.setModal(true);
        loginDialog.exec();
    }

}

void HomeView::on_addClient_clicked()
{
    if ((is_staff_member == 1) && (is_staff_member != 0)){
        qDebug("Adding client");
        qDebug("Adding animal");
        AddClientDialog d;
        d.control = control;
        d.setModal(true);
        d.exec();
    }else if ((is_staff_member == 2) && (is_staff_member != 0)){
        ErrorUserDialog e;
        e.setModal(true);
        e.exec();
    }else{

        LoginDialog loginDialog;
        loginDialog.home = this;
        loginDialog.setModal(true);
        loginDialog.exec();
    }

}

void HomeView::on_pushButton_clicked()
{

    LoginDialog loginDialog;
    loginDialog.home = this;
    loginDialog.setModal(true);
    loginDialog.exec();
}

void HomeView::loadData()
{

    int iNum = ui->listWidgetAnimal->count();
    for (int j = 0; j < iNum; j++){
        delete (ui->listWidgetAnimal->takeItem(0));
    }

    for (int i = 0; i < animals->getSize(); i++){

        QString path = ":/img/images/pet.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(control->getAnimal(i)->getName() + "\n " + control->getAnimal(i)->getBreed()));

        ui->listWidgetAnimal->addItem(item);

     }

    int iNum2 = ui->listWidgetClient->count();
    for (int z = 0; z < iNum2; z++){
        delete (ui->listWidgetClient->takeItem(0));
    }

    for (int i = 0; i < clients->getSize(); i++){

        QString path = ":/img/images/client.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(control->Client(i)->getName()));

        ui->listWidgetClient->addItem(item);

     }

    ui->total->setText((QString::fromStdString(std::to_string(control->getAnimalArraySize()))) + " animal(s) ready for adoption");
}

void HomeView::loadArrays(){

    control->populateAnimalArray();
    control->populateClientArray();

    loadData();

}
