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


class dateDisplay : public QWidget
{
public:
	dateDisplay(Users*, set<Users>&, QWidget* parent = nullptr);


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
	QPushButton* addButton;
	void back_pressed(Users*, set<Users>&);
	void add_pressed(Users*, set<Users>&);

};
