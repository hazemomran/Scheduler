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
	remDisplay(Users*, set<Users>&, QWidget* parent = nullptr);



private:
	QVBoxLayout* mainLayout;
	QHBoxLayout* row1layout;
	QHBoxLayout* row2layout;
	QHBoxLayout* row3layout;
	QHBoxLayout* row4layout;
	QHBoxLayout* row5layout;
	QLabel* title;

	QPushButton* modifyEvent;
	QPushButton* back;
	void back_pressed(Users*, set<Users>&);
	QPushButton* addButton;

	void add_pressed(Users*, set<Users>&);

};
