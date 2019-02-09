/********************************************************************************
** Form generated from reading UI file 'clientprofileeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPROFILEEDITDIALOG_H
#define UI_CLIENTPROFILEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ClientProfileEditDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *ClientProfileEditDialog)
    {
        if (ClientProfileEditDialog->objectName().isEmpty())
            ClientProfileEditDialog->setObjectName(QStringLiteral("ClientProfileEditDialog"));
        ClientProfileEditDialog->resize(400, 300);
        label = new QLabel(ClientProfileEditDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 140, 131, 17));

        retranslateUi(ClientProfileEditDialog);

        QMetaObject::connectSlotsByName(ClientProfileEditDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientProfileEditDialog)
    {
        ClientProfileEditDialog->setWindowTitle(QApplication::translate("ClientProfileEditDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ClientProfileEditDialog", "Client Profile Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientProfileEditDialog: public Ui_ClientProfileEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPROFILEEDITDIALOG_H
