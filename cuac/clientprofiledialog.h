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
    Client* client;
    void loadData(Client*);

private:
    Ui::ClientProfileDialog *ui;
};

#endif // CLIENTPROFILEDIALOG_H
