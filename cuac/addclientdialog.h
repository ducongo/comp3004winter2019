#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>
#include "client.h"
#include "array.h"
#include "homeview.h"
#include "database.h"

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = 0);
    ~AddClientDialog();
    Control* control;


private slots:
    void on_pushButton_clicked();

    void on_specie_valueChanged(int arg1);

    void on_breed_currentIndexChanged(int index);

private:
    Ui::AddClientDialog *ui;
};

#endif // ADDCLIENTDIALOG_H
