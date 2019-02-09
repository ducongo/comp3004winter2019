/********************************************************************************
** Form generated from reading UI file 'animalprofileedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMALPROFILEEDIT_H
#define UI_ANIMALPROFILEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_animalprofileedit
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *animalprofileedit)
    {
        if (animalprofileedit->objectName().isEmpty())
            animalprofileedit->setObjectName(QStringLiteral("animalprofileedit"));
        animalprofileedit->resize(800, 600);
        centralwidget = new QWidget(animalprofileedit);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 210, 201, 17));
        animalprofileedit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(animalprofileedit);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        animalprofileedit->setMenuBar(menubar);
        statusbar = new QStatusBar(animalprofileedit);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        animalprofileedit->setStatusBar(statusbar);

        retranslateUi(animalprofileedit);

        QMetaObject::connectSlotsByName(animalprofileedit);
    } // setupUi

    void retranslateUi(QMainWindow *animalprofileedit)
    {
        animalprofileedit->setWindowTitle(QApplication::translate("animalprofileedit", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("animalprofileedit", "Animal Profile Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class animalprofileedit: public Ui_animalprofileedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALPROFILEEDIT_H
