#ifndef CLIENTPROFILEEDITDIALOG_H
#define CLIENTPROFILEEDITDIALOG_H

#include <QDialog>

namespace Ui {
class ClientProfileEditDialog;
}

class ClientProfileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientProfileEditDialog(QWidget *parent = 0);
    ~ClientProfileEditDialog();

private:
    Ui::ClientProfileEditDialog *ui;
};

#endif // CLIENTPROFILEEDITDIALOG_H
