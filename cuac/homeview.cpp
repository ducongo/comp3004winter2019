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
        profile.loadData(animals->get(item->listWidget()->currentRow()));
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
        profile.loadData(clients->get(item->listWidget()->currentRow()));
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
        d.animals = animals;
        d.home = this;
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
        d.clients = clients;
        d.home = this;
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

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(animals->get(i)->getName() + "\n " + animals->get(i)->getBreed()));

        ui->listWidgetAnimal->addItem(item);

     }

    int iNum2 = ui->listWidgetClient->count();
    for (int z = 0; z < iNum2; z++){
        delete (ui->listWidgetClient->takeItem(0));
    }

    for (int i = 0; i < clients->getSize(); i++){

        QString path = ":/img/images/client.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(clients->get(i)->getName()));

        ui->listWidgetClient->addItem(item);

     }

    ui->total->setText((QString::fromStdString(std::to_string(animals->getSize()))) + " animal(s) ready for adoption");
}

void HomeView::loadArrays(){
    db123->initTables();
    db123->initValues();

    AnimalData** aLists = db123->pullAnimals();
    ClientData** cLists = db123->pullClients();


    int x = 0;
    while(aLists[x] != NULL){

        Animal *a = new Animal(aLists[x]->animalName,
                               aLists[x]->typeOfAnimal,
                               aLists[x]->breed,
                               aLists[x]->animalAttr[1],
                               aLists[x]->animalAttr[2],
                               aLists[x]->animalAttr[3],
                               aLists[x]->colour,
                               /*aLists[x]->specialSkill*/ 0,
                               aLists[x]->animalAttr[4],
                               aLists[x]->animalAttr[6],
                               aLists[x]->animalAttr[9],
                               aLists[x]->animalAttr[10],
                               aLists[x]->animalAttr[11],
                               aLists[x]->animalAttr[18],
                               aLists[x]->animalAttr[12],
                               aLists[x]->animalAttr[8],
                               aLists[x]->animalAttr[14],
                               aLists[x]->animalAttr[15],
                               aLists[x]->animalAttr[16],
                               aLists[x]->animalAttr[17],
                               aLists[x]->animalAttr[19],
                               aLists[x]->animalAttr[5],
                               aLists[x]->animalAttr[7]);
        animals->add(a);


        x++;
    }



    x = 0;
    while(cLists[x] != NULL){

        Client *c = new Client(cLists[x]->clientName, cLists[x]->clientEmail,
                              cLists[x]->clientAddr, cLists[x]->clientAttr[2],
                              cLists[x]->clientAttr[3], cLists[x]->clientAttr[1],
                              cLists[x]->clientAttr[0]);

        clients->add(c);
        x++;
    }

    loadData();

}
