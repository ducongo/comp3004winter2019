#ifndef CLIENTPROFILEDIALOG_H
#define CLIENTPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class ClientProfileDialog;
}

class ClientProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientProfileDialog(QWidget *parent = 0);
    ~ClientProfileDialog();

private:
    Ui::ClientProfileDialog *ui;
};

#endif // CLIENTPROFILEDIALOG_H
