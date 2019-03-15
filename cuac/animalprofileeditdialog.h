#ifndef ANIMALPROFILEEDITDIALOG_H
#define ANIMALPROFILEEDITDIALOG_H

#include <QDialog>
#include "animal.h"

namespace Ui {
class AnimalProfileEditDialog;
}

class AnimalProfileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalProfileEditDialog(QWidget *parent = 0);
    ~AnimalProfileEditDialog();
    void on_pushButton_clicked();
    Animal* animal;
    void loadData(Animal*);

private:
    Ui::AnimalProfileEditDialog *ui;
};

#endif // ANIMALPROFILEEDITDIALOG_H
