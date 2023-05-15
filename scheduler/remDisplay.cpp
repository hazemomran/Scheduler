#include "eventsPage.h"
#include "remDisplay.h"
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
#include "doneEvents.h"

using namespace std;

remDisplay::remDisplay(Users* user, set<Users>& users, QWidget* parent) : QWidget(parent) {

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    setFixedSize(900, 550);

    row1layout = new QHBoxLayout();
    title = new QLabel("Upcoming events");
    title->setStyleSheet("font: bold 30px; color: grey;");
    title->setAlignment(Qt::AlignCenter);

    row1layout->addWidget(title);
    mainLayout->addLayout(row1layout);

    doneEvents* d = new doneEvents(user, users);
    d->done_event(user, users);

    // Create a table widget
    QTableWidget* tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(user->reminderMp.size());
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Reminder at" << "Name" << "Place" << "Start Date" << "End Date");

    // Iterate over the map and insert the data into the table
    int row = 0;
    for (auto it = user->reminderMp.begin(); it != user->reminderMp.end(); it++) {
        tm start_date = user->convertTStoDate(it->second.start_date);
        tm end_date = user->convertTStoDate(it->second.end_date);
        tm rem_date = user->convertTStoDate(it->second.reminder_time);

        string startDate = to_string(start_date.tm_hour) + ":" + to_string(start_date.tm_min) + " " + to_string(start_date.tm_mday) + '/' +
            to_string(start_date.tm_mon + 1) + '/' + to_string(start_date.tm_year + 1900);

        string endDate = to_string(end_date.tm_hour) + ":" + to_string(end_date.tm_min) + " " + to_string(end_date.tm_mday) + '/' +
            to_string(end_date.tm_mon + 1) + '/' + to_string(end_date.tm_year + 1900);



        string remDate = to_string(rem_date.tm_hour) + ":" + to_string(rem_date.tm_min) + " " + to_string(rem_date.tm_mday) + '/' +
            to_string(rem_date.tm_mon + 1) + '/' + to_string(rem_date.tm_year + 1900);




        QTableWidgetItem* Item0 = new QTableWidgetItem(QString::fromStdString(remDate));
        QTableWidgetItem* Item1 = new QTableWidgetItem(QString::fromStdString(it->second.name));
        QTableWidgetItem* Item2 = new QTableWidgetItem(QString::fromStdString(it->second.place));
        QTableWidgetItem* Item3 = new QTableWidgetItem(QString::fromStdString(startDate));
        QTableWidgetItem* Item4 = new QTableWidgetItem(QString::fromStdString(endDate));
        // modifyEvent = new QPushButton("Modify Event");

        tableWidget->setItem(row, 0, Item0);
        tableWidget->setItem(row, 1, Item1);
        tableWidget->setItem(row, 2, Item2);
        tableWidget->setItem(row, 3, Item3);
        tableWidget->setItem(row, 4, Item4);
        // tableWidget->setCellWidget(row, 5, modifyEvent);

       // QPushButton* modifyEvent = new QPushButton(QString("modify").arg(2));
         //connect(modifyEvent, &QPushButton::clicked, this, &eventsPage::onButtonClicked(it->second));
       //  connect(modifyEvent, &QPushButton::clicked, this, std::bind(&remDisplay::onButtonClicked, this, it->second, user));
      //   tableWidget->setCellWidget(row, 5, modifyEvent);
        Item0->setSizeHint(QSize(190, 50));
        Item1->setSizeHint(QSize(190, 50));
        Item2->setSizeHint(QSize(190, 50));
        Item3->setSizeHint(QSize(190, 50));
        Item4->setSizeHint(QSize(190, 50));

        ++row;
    }

    // Resize the table columns to fit the content
    tableWidget->resizeColumnsToContents();

    tableWidget->resize(1200, 400);

    row2layout = new QHBoxLayout();
    row2layout->addWidget(tableWidget);
    mainLayout->addLayout(row2layout);

    row5layout = new QHBoxLayout();
    back = new QPushButton("Back");
    back->setToolTip("Click to cancel");
    back->setFixedWidth(100);
    back->setFixedHeight(40);

    back->setStyleSheet("font: bold 15px; color:black; background-color: #1e2835; color:white; border-radius:7px;");


    mainLayout->addLayout(row5layout);
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


};

//void eventsPage::add_pressed(Users& user) {
//    AddEvent* addE = new AddEvent(user);
//    addE->show();
//    this->close();
//}
//

void remDisplay::back_pressed(Users* user, set<Users>& users) {
    buttonsPage* bp = new buttonsPage(user, users);
    bp->show();

    this->close();
}
void remDisplay::add_pressed(Users* user, set<Users>& users) {

    AddEvent* e7 = new AddEvent(user, users);
    e7->show();
    this->close();


}