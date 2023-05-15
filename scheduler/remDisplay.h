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


class remDisplay : public QWidget
{
public:
	//eventsPage();
	remDisplay(Users*, set<Users>&, QWidget* parent = nullptr);
	/*void add_pressed(Users&);
	void done_pressed(Users&);*/


private:
	QVBoxLayout* mainLayout;
	QHBoxLayout* row1layout;
	QHBoxLayout* row2layout;
	QHBoxLayout* row3layout;
	QHBoxLayout* row4layout;
	QHBoxLayout* row5layout;
	QLabel* title;


	/*QPushButton* addEvent;
	QPushButton* doneEvent;*/
	QPushButton* modifyEvent;
	QPushButton* back;
	void back_pressed(Users*, set<Users>&);
	QPushButton* addButton;

	void add_pressed(Users*, set<Users>&);

};
