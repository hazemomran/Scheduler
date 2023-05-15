#include "doneEvents.h"
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
#include <iostream>
#include <QStringList>
#include <QWidget>
#include <queue>
#include<QHeaderView>
#include<deque>
#include "buttonsPage.h"
using namespace std;



doneEvents::doneEvents(Users* user, set<Users>& users, QWidget* parent) : QWidget(parent) {

	mainLayout = new QVBoxLayout();
	setLayout(mainLayout);
	setFixedSize(900, 550);

	row1layout = new QHBoxLayout();
	title = new QLabel("Done Events");
	title->setStyleSheet("font: bold 30px; color: grey;");
	title->setAlignment(Qt::AlignCenter);

	row1layout->addWidget(title);
	mainLayout->addLayout(row1layout);
	done_event(user, users);

	
	buttonsPage::remind(user);

	if (!user->done.empty()) {

		QTableWidget* tableWidget = new QTableWidget(this);
		tableWidget->setRowCount(user->done.size());
		tableWidget->setColumnCount(5);
		tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Place" << "Start Date" << "End Date" << "Description");
		tableWidget->setColumnWidth(0, 200);
		


		int row = 0;
		for (int i = 0; i < user->done.size(); i++) {


			// Create a table widget
			tm start_date = user->convertTStoDate(user->done.front().start_date);
			tm end_date = user->convertTStoDate(user->done.front().end_date);

			string startDate = to_string(start_date.tm_hour) + ":" + to_string(start_date.tm_min) + " " + to_string(start_date.tm_mday) + '/' +
				to_string(start_date.tm_mon + 1) + '/' + to_string(start_date.tm_year + 1900);

			string endDate = to_string(end_date.tm_hour) + ":" + to_string(end_date.tm_min) + " " + to_string(end_date.tm_mday) + '/' +
				to_string(end_date.tm_mon + 1) + '/' + to_string(end_date.tm_year + 1900);



			QTableWidgetItem* Item1 = new QTableWidgetItem(QString::fromStdString(user->done.front().name));
			QTableWidgetItem* Item2 = new QTableWidgetItem(QString::fromStdString(user->done.front().place));
			QTableWidgetItem* Item3 = new QTableWidgetItem(QString::fromStdString(startDate));
			QTableWidgetItem* Item4 = new QTableWidgetItem(QString::fromStdString(endDate));
			QTableWidgetItem* Item5 = new QTableWidgetItem(QString::fromStdString(user->done.front().description));

			tableWidget->setItem(row, 0, Item1);
			tableWidget->setItem(row, 1, Item2);
			tableWidget->setItem(row, 2, Item3);
			tableWidget->setItem(row, 3, Item4);
			tableWidget->setItem(row, 4, Item5);

			Item1->setSizeHint(QSize(190, 50));
			Item2->setSizeHint(QSize(190, 50));
			Item3->setSizeHint(QSize(190, 50));
			Item4->setSizeHint(QSize(190, 50));

			++row;
			user->done.push_back(user->done.front());
			user->done.pop_front();

		}




		// Resize the table columns to fit the content
		tableWidget->resizeColumnsToContents();

		tableWidget->resize(900, 300);

		row2layout = new QHBoxLayout();
		row2layout->addWidget(tableWidget);
		mainLayout->addLayout(row2layout);
	}
	else
	{
		title->setText("NO DONE EVENTS!!");
	}

	Back = new QPushButton("Back");
	Back->setFixedWidth(100);
	Back->setFixedHeight(40);
	Back->setStyleSheet("font: bold 15px; color:black; background-color: #1e2835; color:white; border-radius:7px;");
	row3layout = new QHBoxLayout();
	row3layout->addWidget(Back);
	mainLayout->addLayout(row3layout);

	connect(Back, &QPushButton::clicked, this, [this, user, &users]() {
		cancel_pressed(user, users);
		});


};



void doneEvents::cancel_pressed(Users* user, set<Users>& users) {
	buttonsPage* addE = new buttonsPage(user, users);
	addE->show();
	this->close();
}
void doneEvents::done_event(Users* user, set<Users>& users) {

	map<int, Events>::iterator it;

	it = user->dateMp.begin();

	//Get current time as time stamp
	auto currentTime = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(currentTime);

	//Iterate throw dateMp and remove done events
	for (it = user->dateMp.begin(); it != user->dateMp.end();) {
		if (it->first <= time + 10800) {
			user->done.push_back(it->second);
			it = user->dateMp.erase(it);
		}
		else {
			++it;
		}
	}

	//Iterate throw reminderMp and remove done events
	map<int, Events> ::iterator it2;
	it2 = user->reminderMp.begin();
	for (it2 = user->reminderMp.begin(); it2 != user->reminderMp.end();) {
		if (it2->second.start_date <= time + 10800) {
			it2 = user->reminderMp.erase(it2);
			
		}
		else {
			++it2;
		}
	}

}
