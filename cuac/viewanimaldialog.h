#ifndef VIEWANIMALDIALOG_H
#define VIEWANIMALDIALOG_H

#include <QDialog>
#include "animal.h"


namespace Ui {
class ViewAnimalDialog;
}

class ViewAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAnimalDialog(QWidget *parent = 0);
    ~ViewAnimalDialog();
    void loadData(Animal*);
    Animal* a;

private:
    Ui::ViewAnimalDialog *ui;
};

#endif // VIEWANIMALDIALOG_H
