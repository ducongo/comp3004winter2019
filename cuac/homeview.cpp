#include "homeview.h"
#include "ui_homeview.h"
#include "animalprofiledialog.h"
#include "clientprofiledialog.h"
#include "addanimaldialog.h"


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


    for (int i = 0; i < animals->getSize(); i++){

        QString path = ":/img/images/pet.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(animals->get(i)->getName() + "\n " + animals->get(i)->getBreed()));

        ui->listWidgetAnimal->addItem(item);

     }

    for (int i = 0; i < 20; i++){

        QString path = ":/img/images/client.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString("FirstName " + QString::number(i) + "\nLastname"));

        ui->listWidgetClient->addItem(item);

     }
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
    qDebug("Animal Selected at index: %d", item->listWidget()->currentRow());
    AnimalProfileDialog aprofile;
    aprofile.setModal(true);
    aprofile.exec();
}

void HomeView::on_listWidgetClient_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug("Client Selected at index: %d", item->listWidget()->currentRow());
    ClientProfileDialog cprofile;
    cprofile.setModal(true);
    cprofile.exec();


}

void HomeView::on_addAnimal_clicked()
{
    qDebug("Adding animal");
    AddAnimalDialog d;
    d.animals = animals;
    d.setModal(true);
    d.exec();
}

void HomeView::on_addClient_clicked()
{
    qDebug("Adding animal");
}

void HomeView::on_pushButton_clicked()
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
}
