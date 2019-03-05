#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "homeview.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    HomeView* home;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_staff_clicked();

    void on_client_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
