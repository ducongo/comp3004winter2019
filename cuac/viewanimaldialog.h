#ifndef VIEWANIMALDIALOG_H
#define VIEWANIMALDIALOG_H

#include <QDialog>
#include "animal.h"
#include "control.h"


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
    void resetLabels();
    Animal* a;
    Control* control;

private slots:
    void on_update_button_clicked();

private:
    Ui::ViewAnimalDialog *ui;
};

#endif // VIEWANIMALDIALOG_H
