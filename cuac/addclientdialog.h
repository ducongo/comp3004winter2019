#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>
#include "client.h"
#include "array.h"
#include "homeview.h"

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = 0);
    ~AddClientDialog();
    Array<Client>* clients;
    HomeView *home;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddClientDialog *ui;
};

#endif // ADDCLIENTDIALOG_H
