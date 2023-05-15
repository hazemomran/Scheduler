#pragma once
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QString>
#include "Users.h"
#include <QLabel>
#include <QWidget>

class doneEvents : public QWidget
{
public:
	doneEvents(Users*, set<Users>& users, QWidget* parent = nullptr);
	void cancel_pressed(Users*, set<Users>&);
	void done_event(Users*, set<Users>&);
	queue<Events> done2;

private:
	QVBoxLayout* mainLayout;
	QHBoxLayout* row1layout;
	QHBoxLayout* row2layout;
	QHBoxLayout* row3layout;

	QLabel* title;
	QPushButton* Back;

};