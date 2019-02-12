/********************************************************************************
** Form generated from reading UI file 'clientprofileedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPROFILEEDIT_H
#define UI_CLIENTPROFILEEDIT_H

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

class Ui_clientprofileedit
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientprofileedit)
    {
        if (clientprofileedit->objectName().isEmpty())
            clientprofileedit->setObjectName(QStringLiteral("clientprofileedit"));
        clientprofileedit->resize(800, 600);
        centralwidget = new QWidget(clientprofileedit);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 220, 64, 17));
        clientprofileedit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientprofileedit);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        clientprofileedit->setMenuBar(menubar);
        statusbar = new QStatusBar(clientprofileedit);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        clientprofileedit->setStatusBar(statusbar);

        retranslateUi(clientprofileedit);

        QMetaObject::connectSlotsByName(clientprofileedit);
    } // setupUi

    void retranslateUi(QMainWindow *clientprofileedit)
    {
        clientprofileedit->setWindowTitle(QApplication::translate("clientprofileedit", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("clientprofileedit", "Client profile edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clientprofileedit: public Ui_clientprofileedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPROFILEEDIT_H
