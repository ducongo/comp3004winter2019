#ifndef CLIENTPROFILEDIALOG_H
#define CLIENTPROFILEDIALOG_H

#include <QDialog>
#include "client.h"

namespace Ui {
class ClientProfileDialog;
}

class ClientProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientProfileDialog(QWidget *parent = 0);
    ~ClientProfileDialog();
    Client* c;
    void loadData(Client*);
    void resetLabels();

private slots:
    void on_update_button_clicked();

private:
    Ui::ClientProfileDialog *ui;
};

#endif // CLIENTPROFILEDIALOG_H
