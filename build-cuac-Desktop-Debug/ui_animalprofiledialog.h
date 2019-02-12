/********************************************************************************
** Form generated from reading UI file 'animalprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMALPROFILEDIALOG_H
#define UI_ANIMALPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AnimalProfileDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *AnimalProfileDialog)
    {
        if (AnimalProfileDialog->objectName().isEmpty())
            AnimalProfileDialog->setObjectName(QStringLiteral("AnimalProfileDialog"));
        AnimalProfileDialog->resize(400, 300);
        label = new QLabel(AnimalProfileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 140, 111, 17));
        pushButton = new QPushButton(AnimalProfileDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 20, 83, 25));

        retranslateUi(AnimalProfileDialog);

        QMetaObject::connectSlotsByName(AnimalProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *AnimalProfileDialog)
    {
        AnimalProfileDialog->setWindowTitle(QApplication::translate("AnimalProfileDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AnimalProfileDialog", "Animal Profile", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AnimalProfileDialog", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AnimalProfileDialog: public Ui_AnimalProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALPROFILEDIALOG_H
