/********************************************************************************
** Form generated from reading UI file 'clientprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPROFILEDIALOG_H
#define UI_CLIENTPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClientProfileDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *ClientProfileDialog)
    {
        if (ClientProfileDialog->objectName().isEmpty())
            ClientProfileDialog->setObjectName(QStringLiteral("ClientProfileDialog"));
        ClientProfileDialog->resize(400, 300);
        pushButton = new QPushButton(ClientProfileDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 10, 83, 25));
        label = new QLabel(ClientProfileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 140, 101, 17));

        retranslateUi(ClientProfileDialog);

        QMetaObject::connectSlotsByName(ClientProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientProfileDialog)
    {
        ClientProfileDialog->setWindowTitle(QApplication::translate("ClientProfileDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ClientProfileDialog", "Edit", Q_NULLPTR));
        label->setText(QApplication::translate("ClientProfileDialog", "Client Profile", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientProfileDialog: public Ui_ClientProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPROFILEDIALOG_H
