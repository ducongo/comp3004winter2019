#ifndef ADDANIMALDIALOG_H
#define ADDANIMALDIALOG_H

#include <QDialog>
#include "animal.h"
#include "array.h"

namespace Ui {
class AddAnimalDialog;
}

class AddAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAnimalDialog(QWidget *parent = 0);
    ~AddAnimalDialog();
    Array<Animal>* animals;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddAnimalDialog *ui;
};

#endif // ADDANIMALDIALOG_H
