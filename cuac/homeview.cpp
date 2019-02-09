#include "homeview.h"
#include "ui_homeview.h"
#include "animalprofiledialog.h"
#include "clientprofiledialog.h"


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


    for (int i = 0; i < 200; i++){

        QString path = "/home/student/Documents/src/pet.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString("FirstName " + QString::number(i) + "\n Dog"));

        ui->listWidgetAnimal->addItem(item);

     }

    for (int i = 0; i < 20; i++){

        QString path = "/home/student/Documents/src/client.png";

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
}

void HomeView::on_addClient_clicked()
{
    qDebug("Adding animal");
}
