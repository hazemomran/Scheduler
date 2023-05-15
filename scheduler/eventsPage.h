#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QString>
#include "Users.h"
#include "doneEvents.h"


class eventsPage : public QWidget
{
public:
	eventsPage(Users*, set<Users>&, QWidget* parent = nullptr);
	void onButtonClicked(Events&, Users*, set<Users>&);
	void onButton2Clicked(Events&, Users*, set<Users>&);

private:
	QVBoxLayout* mainLayout;
	QHBoxLayout* row1layout;
	QHBoxLayout* row2layout;
	QHBoxLayout* row3layout;
	QHBoxLayout* row4layout;

	QLabel* title;
	QPushButton* modifyEvent;
	QPushButton* deleteEvent;
	QHBoxLayout* row5layout;
	QPushButton* back;
	void back_pressed(Users*, set<Users>&);

};