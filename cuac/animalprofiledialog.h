#ifndef ANIMALPROFILEDIALOG_H
#define ANIMALPROFILEDIALOG_H

#include <QDialog>
#include "animal.h"
namespace Ui {
class AnimalProfileDialog;
}

class AnimalProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalProfileDialog(QWidget *parent = 0);
    ~AnimalProfileDialog();


private:
    Ui::AnimalProfileDialog *ui;
};

#endif // ANIMALPROFILEDIALOG_H
