/********************************************************************************
** Form generated from reading UI file 'animalprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMALPROFILE_H
#define UI_ANIMALPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_animalprofile
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *animalprofile)
    {
        if (animalprofile->objectName().isEmpty())
            animalprofile->setObjectName(QStringLiteral("animalprofile"));
        animalprofile->resize(800, 600);
        centralwidget = new QWidget(animalprofile);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 200, 101, 17));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 20, 83, 25));
        animalprofile->setCentralWidget(centralwidget);
        menubar = new QMenuBar(animalprofile);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        animalprofile->setMenuBar(menubar);
        statusbar = new QStatusBar(animalprofile);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        animalprofile->setStatusBar(statusbar);

        retranslateUi(animalprofile);

        QMetaObject::connectSlotsByName(animalprofile);
    } // setupUi

    void retranslateUi(QMainWindow *animalprofile)
    {
        animalprofile->setWindowTitle(QApplication::translate("animalprofile", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("animalprofile", "Animal Profile", Q_NULLPTR));
        pushButton->setText(QApplication::translate("animalprofile", "EDIT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class animalprofile: public Ui_animalprofile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALPROFILE_H
