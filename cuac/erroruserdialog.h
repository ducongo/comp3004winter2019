#ifndef ERRORUSERDIALOG_H
#define ERRORUSERDIALOG_H

#include <QDialog>

namespace Ui {
class ErrorUserDialog;
}

class ErrorUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorUserDialog(QWidget *parent = 0);
    ~ErrorUserDialog();

private:
    Ui::ErrorUserDialog *ui;
};

#endif // ERRORUSERDIALOG_H
