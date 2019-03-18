#ifndef CLIENTPROFILEEDITDIALOG_H
#define CLIENTPROFILEEDITDIALOG_H

#include <QDialog>
#include "client.h"
#include "control.h"


namespace Ui {
class ClientProfileEditDialog;
}

class ClientProfileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientProfileEditDialog(QWidget *parent = 0);
    ~ClientProfileEditDialog();
    Control* control;
    Client* client;
    void loadData(Client*);


private slots:
    void on_specie_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::ClientProfileEditDialog *ui;
};

#endif // CLIENTPROFILEEDITDIALOG_H
