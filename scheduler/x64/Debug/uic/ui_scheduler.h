/********************************************************************************
** Form generated from reading UI file 'scheduler.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULER_H
#define UI_SCHEDULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_schedulerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *schedulerClass)
    {
        if (schedulerClass->objectName().isEmpty())
            schedulerClass->setObjectName("schedulerClass");
        schedulerClass->resize(600, 400);
        menuBar = new QMenuBar(schedulerClass);
        menuBar->setObjectName("menuBar");
        schedulerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(schedulerClass);
        mainToolBar->setObjectName("mainToolBar");
        schedulerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(schedulerClass);
        centralWidget->setObjectName("centralWidget");
        schedulerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(schedulerClass);
        statusBar->setObjectName("statusBar");
        schedulerClass->setStatusBar(statusBar);

        retranslateUi(schedulerClass);

        QMetaObject::connectSlotsByName(schedulerClass);
    } // setupUi

    void retranslateUi(QMainWindow *schedulerClass)
    {
        schedulerClass->setWindowTitle(QCoreApplication::translate("schedulerClass", "scheduler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class schedulerClass: public Ui_schedulerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULER_H
