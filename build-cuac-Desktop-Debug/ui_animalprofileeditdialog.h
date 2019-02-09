/********************************************************************************
** Form generated from reading UI file 'animalprofileeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMALPROFILEEDITDIALOG_H
#define UI_ANIMALPROFILEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AnimalProfileEditDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *AnimalProfileEditDialog)
    {
        if (AnimalProfileEditDialog->objectName().isEmpty())
            AnimalProfileEditDialog->setObjectName(QStringLiteral("AnimalProfileEditDialog"));
        AnimalProfileEditDialog->resize(400, 300);
        label = new QLabel(AnimalProfileEditDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 140, 131, 17));

        retranslateUi(AnimalProfileEditDialog);

        QMetaObject::connectSlotsByName(AnimalProfileEditDialog);
    } // setupUi

    void retranslateUi(QDialog *AnimalProfileEditDialog)
    {
        AnimalProfileEditDialog->setWindowTitle(QApplication::translate("AnimalProfileEditDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AnimalProfileEditDialog", "Animal Profile Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AnimalProfileEditDialog: public Ui_AnimalProfileEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALPROFILEEDITDIALOG_H
