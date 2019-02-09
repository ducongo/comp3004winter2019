#ifndef ANIMALPROFILEEDITDIALOG_H
#define ANIMALPROFILEEDITDIALOG_H

#include <QDialog>

namespace Ui {
class AnimalProfileEditDialog;
}

class AnimalProfileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalProfileEditDialog(QWidget *parent = 0);
    ~AnimalProfileEditDialog();

private:
    Ui::AnimalProfileEditDialog *ui;
};

#endif // ANIMALPROFILEEDITDIALOG_H
