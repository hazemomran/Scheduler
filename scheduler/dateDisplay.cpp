#include "dateDisplay.h"
#include "eventsPage.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <QTableWidget>
#include <fstream>
#include <QFile>
#include <map>
#include "Events.h"
#include "Users.h"
#include "AddEvent.h"
#include "signUp.h"
#include "yourEvent.h"
#include <iostream>
#include <QStringList>


using namespace std;



dateDisplay::dateDisplay(Users* user, set<Users>& users, QWidget* parent) : QWidget(parent) {

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    setFixedSize(900, 550);

    row1layout = new QHBoxLayout();
    title = new QLabel("Your upcoming events");
    title->setStyleSheet("font: bold 30px; color: grey;");
    title->setAlignment(Qt::AlignCenter);

    row1layout->addWidget(title);
    mainLayout->addLayout(row1layout);


    doneEvents* d = new doneEvents(user, users);
    d->done_event(user, users);
    // Create a table widget

    QTableWidget* tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(user->dts.size());
    tableWidget->setColumnCount(5);

    tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Place" << "Start Date" << "End Date" << "Reminder at");

    // Iterate over the map and insert the data into the table
    int row = 0;
    for (auto it = user->dts.begin(); it != user->dts.end(); it++) {

        tm start_date = user->convertTStoDate(it->second.start_date);
        tm end_date = user->convertTStoDate(it->second.end_date);
        tm rem_date = user->convertTStoDate(it->second.reminder_time);

        string startDate = to_string(start_date.tm_hour) + ":" + to_string(start_date.tm_min) + " " + to_string(start_date.tm_mday) + '/' +
            to_string(start_date.tm_mon + 1) + '/' + to_string(start_date.tm_year + 1900);

        string endDate = to_string(end_date.tm_hour) + ":" + to_string(end_date.tm_min) + " " + to_string(end_date.tm_mday) + '/' +
            to_string(end_date.tm_mon + 1) + '/' + to_string(end_date.tm_year + 1900);



        string remDate = to_string(rem_date.tm_hour) + ":" + to_string(rem_date.tm_min) + " " + to_string(rem_date.tm_mday) + '/' +
            to_string(rem_date.tm_mon + 1) + '/' + to_string(rem_date.tm_year + 1900);

        QTableWidgetItem* Item1 = new QTableWidgetItem(QString::fromStdString(it->second.name));
        QTableWidgetItem* Item2 = new QTableWidgetItem(QString::fromStdString(it->second.place));
        QTableWidgetItem* Item3 = new QTableWidgetItem(QString::fromStdString(startDate));
        QTableWidgetItem* Item4 = new QTableWidgetItem(QString::fromStdString(endDate));
        QTableWidgetItem* Item5 = new QTableWidgetItem(QString::fromStdString(remDate));
        // modifyEvent = new QPushButton("Modify Event");
        // deleteEvent = new QPushButton("Delete Event");
        tableWidget->setItem(row, 0, Item1);
        tableWidget->setItem(row, 1, Item2);
        tableWidget->setItem(row, 2, Item3);
        tableWidget->setItem(row, 3, Item4);
        tableWidget->setItem(row, 4, Item5);
        //  tableWidget->setCellWidget(row, 4, modifyEvent);
        //  tableWidget->setCellWidget(row, 5, deleteEvent);
         // QPushButton* modifyEvent = new QPushButton("modify");
         // QPushButton* deleteEvent = new QPushButton("delete");
          //connect(modifyEvent, &QPushButton::clicked, this, &eventsPage::onButtonClicked(it->second));
         // connect(modifyEvent, &QPushButton::clicked, this, std::bind(&dateDisplay::onButtonClicked, this, it->second, user));
         // tableWidget->setCellWidget(row, 4, modifyEvent);

         // connect(deleteEvent, &QPushButton::clicked, this, std::bind(&dateDisplay::onButton2Clicked, this, it->second, user));
         // tableWidget->setCellWidget(row, 5, deleteEvent);

        Item1->setSizeHint(QSize(190, 50));
        Item2->setSizeHint(QSize(190, 50));
        Item3->setSizeHint(QSize(190, 50));
        Item4->setSizeHint(QSize(190, 50));
        Item5->setSizeHint(QSize(190, 50));
        ++row;
    }

    // Resize the table columns to fit the content
    tableWidget->resizeColumnsToContents();

    tableWidget->resize(900, 300);

    row2layout = new QHBoxLayout();
    row2layout->addWidget(tableWidget);
    mainLayout->addLayout(row2layout);

    //addEvent = new QPushButton("Add Event");
    //addEvent->setFixedSize(150, 35);
    //doneEvent = new QPushButton("Done Event");
    //doneEvent->setFixedSize(150, 35);
    //row3layout = new QHBoxLayout();
    //row3layout->addWidget(addEvent);
    //row3layout->addWidget(doneEvent);
    ////row3layout->addStretch(1);
    //mainLayout->addLayout(row3layout);


    //row4layout = new QHBoxLayout();
    //row4layout->addWidget(doneEvent);
    ////row3layout->addStretch(1);
    //mainLayout->addLayout(row4layout);




    ////connect(addEvent, &QPushButton::clicked, this, &eventsPage::add_pressed);
    //connect(addEvent, &QPushButton::clicked, this, [this, &user]() {
    //    add_pressed(user);
    //    });

    //connect(doneEvent, &QPushButton::clicked, this, [this, &user]() {
    //    done_pressed(user);
    //    });
    row5layout = new QHBoxLayout();
    back = new QPushButton("Back");
    back->setToolTip("Click to cancel");
    back->setFixedWidth(100);
    back->setFixedHeight(40);
    back->setStyleSheet("font: bold 15px; color:black; background-color: #1e2835; color:white; border-radius:7px;");


    connect(back, &QPushButton::clicked, this, [this, &users, user]() {
        back_pressed(user, users);
        });
    addButton = new QPushButton("Add");
    addButton->setFixedWidth(100);
    addButton->setFixedHeight(40);
    addButton->setStyleSheet("font: bold 15px; color:black; background-color: #1e2835; color:white; border-radius:7px;");
    row5layout->addWidget(addButton);
    row5layout->addWidget(back);
    mainLayout->addLayout(row5layout);
    connect(addButton, &QPushButton::clicked, this, [this, &users, user]() {
        add_pressed(user, users);
        });

};

//void eventsPage::add_pressed(Users& user) {
//    AddEvent* addE = new AddEvent(user);
//    addE->show();
//    this->close();
//}
//
//void eventsPage::done_pressed(Users& user) {
//    doneEvents* done = new doneEvents(user);
//    done->show();
//    this->close();
//}

void dateDisplay::back_pressed(Users* user, set<Users>& users) {
    buttonsPage* bp = new buttonsPage(user, users);
    bp->show();

    this->close();
}

void dateDisplay::add_pressed(Users* user, set<Users>& users) {

    AddEvent* e7 = new AddEvent(user, users);
    e7->show();
    this->close();


}