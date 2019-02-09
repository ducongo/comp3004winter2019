/********************************************************************************
** Form generated from reading UI file 'clientprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPROFILE_H
#define UI_CLIENTPROFILE_H

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

class Ui_clientprofile
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientprofile)
    {
        if (clientprofile->objectName().isEmpty())
            clientprofile->setObjectName(QStringLiteral("clientprofile"));
        clientprofile->resize(800, 600);
        centralwidget = new QWidget(clientprofile);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 230, 161, 17));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 20, 83, 25));
        clientprofile->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientprofile);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        clientprofile->setMenuBar(menubar);
        statusbar = new QStatusBar(clientprofile);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        clientprofile->setStatusBar(statusbar);

        retranslateUi(clientprofile);

        QMetaObject::connectSlotsByName(clientprofile);
    } // setupUi

    void retranslateUi(QMainWindow *clientprofile)
    {
        clientprofile->setWindowTitle(QApplication::translate("clientprofile", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("clientprofile", "Client Progile", Q_NULLPTR));
        pushButton->setText(QApplication::translate("clientprofile", "EDIT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clientprofile: public Ui_clientprofile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPROFILE_H
