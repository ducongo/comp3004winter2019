/********************************************************************************
** Form generated from reading UI file 'homeview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEVIEW_H
#define UI_HOMEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeView
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidgetHomeView;
    QWidget *tabanimalTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addAnimal;
    QSpacerItem *horizontalSpacer;
    QLabel *totalAnimalLabel;
    QListWidget *listWidgetAnimal;
    QLabel *label_2;
    QWidget *clientTab;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addClient;
    QSpacerItem *horizontalSpacer_2;
    QLabel *totalClientLabel;
    QListWidget *listWidgetClient;
    QWidget *acmTab;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HomeView)
    {
        if (HomeView->objectName().isEmpty())
            HomeView->setObjectName(QStringLiteral("HomeView"));
        HomeView->resize(990, 585);
        centralWidget = new QWidget(HomeView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidgetHomeView = new QTabWidget(centralWidget);
        tabWidgetHomeView->setObjectName(QStringLiteral("tabWidgetHomeView"));
        tabWidgetHomeView->setGeometry(QRect(0, 0, 991, 541));
        tabWidgetHomeView->setTabPosition(QTabWidget::West);
        tabanimalTab = new QWidget();
        tabanimalTab->setObjectName(QStringLiteral("tabanimalTab"));
        verticalLayoutWidget = new QWidget(tabanimalTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 931, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addAnimal = new QPushButton(verticalLayoutWidget);
        addAnimal->setObjectName(QStringLiteral("addAnimal"));

        horizontalLayout_3->addWidget(addAnimal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        totalAnimalLabel = new QLabel(verticalLayoutWidget);
        totalAnimalLabel->setObjectName(QStringLiteral("totalAnimalLabel"));

        horizontalLayout_3->addWidget(totalAnimalLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        listWidgetAnimal = new QListWidget(verticalLayoutWidget);
        listWidgetAnimal->setObjectName(QStringLiteral("listWidgetAnimal"));

        verticalLayout->addWidget(listWidgetAnimal);

        label_2 = new QLabel(tabanimalTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 10, 111, 17));
        tabWidgetHomeView->addTab(tabanimalTab, QString());
        clientTab = new QWidget();
        clientTab->setObjectName(QStringLiteral("clientTab"));
        label_3 = new QLabel(clientTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 0, 111, 17));
        verticalLayoutWidget_2 = new QWidget(clientTab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 20, 931, 501));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addClient = new QPushButton(verticalLayoutWidget_2);
        addClient->setObjectName(QStringLiteral("addClient"));

        horizontalLayout_4->addWidget(addClient);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        totalClientLabel = new QLabel(verticalLayoutWidget_2);
        totalClientLabel->setObjectName(QStringLiteral("totalClientLabel"));

        horizontalLayout_4->addWidget(totalClientLabel);


        verticalLayout_2->addLayout(horizontalLayout_4);

        listWidgetClient = new QListWidget(verticalLayoutWidget_2);
        listWidgetClient->setObjectName(QStringLiteral("listWidgetClient"));

        verticalLayout_2->addWidget(listWidgetClient);

        tabWidgetHomeView->addTab(clientTab, QString());
        acmTab = new QWidget();
        acmTab->setObjectName(QStringLiteral("acmTab"));
        label = new QLabel(acmTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 261, 17));
        label_4 = new QLabel(acmTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 10, 101, 17));
        label_5 = new QLabel(acmTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 80, 321, 17));
        label_6 = new QLabel(acmTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 110, 321, 17));
        pushButton = new QPushButton(acmTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 171, 25));
        tabWidgetHomeView->addTab(acmTab, QString());
        HomeView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HomeView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 990, 22));
        HomeView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HomeView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HomeView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HomeView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HomeView->setStatusBar(statusBar);

        retranslateUi(HomeView);

        tabWidgetHomeView->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(HomeView);
    } // setupUi

    void retranslateUi(QMainWindow *HomeView)
    {
        HomeView->setWindowTitle(QApplication::translate("HomeView", "HomeView", Q_NULLPTR));
        addAnimal->setText(QApplication::translate("HomeView", "ADD ANIMAL", Q_NULLPTR));
        totalAnimalLabel->setText(QApplication::translate("HomeView", "@00 animals ready for adoption", Q_NULLPTR));
        label_2->setText(QApplication::translate("HomeView", "Animal catalogue", Q_NULLPTR));
        tabWidgetHomeView->setTabText(tabWidgetHomeView->indexOf(tabanimalTab), QApplication::translate("HomeView", "Animals", Q_NULLPTR));
        label_3->setText(QApplication::translate("HomeView", "Client Catalogue", Q_NULLPTR));
        addClient->setText(QApplication::translate("HomeView", "ADD CLIENT", Q_NULLPTR));
        totalClientLabel->setText(QApplication::translate("HomeView", "@00 animals ready for adoption", Q_NULLPTR));
        tabWidgetHomeView->setTabText(tabWidgetHomeView->indexOf(clientTab), QApplication::translate("HomeView", "Clients", Q_NULLPTR));
        label->setText(QApplication::translate("HomeView", "ACM algorithm last ran on Feb1, 2019", Q_NULLPTR));
        label_4->setText(QApplication::translate("HomeView", "ACM Algorithm", Q_NULLPTR));
        label_5->setText(QApplication::translate("HomeView", "Total number of pets available for adoption: 200", Q_NULLPTR));
        label_6->setText(QApplication::translate("HomeView", "Total number of clients: 200", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HomeView", "RUN ACM ALGORITHM", Q_NULLPTR));
        tabWidgetHomeView->setTabText(tabWidgetHomeView->indexOf(acmTab), QApplication::translate("HomeView", "ACM Algorithm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomeView: public Ui_HomeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEVIEW_H
