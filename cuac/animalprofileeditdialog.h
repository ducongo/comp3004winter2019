#ifndef ANIMALPROFILEEDITDIALOG_H
#define ANIMALPROFILEEDITDIALOG_H

#include <QDialog>
#include "animal.h"
#include "control.h"

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
    Control* control;
    void loadData(Animal*);

private slots:
    void on_update_clicked();

private:
    Ui::AnimalProfileEditDialog *ui;
};

#endif // ANIMALPROFILEEDITDIALOG_H
