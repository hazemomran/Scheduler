#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>
#include "Users.h"

//#include "yourEvent.cpp"
class AddEvent : public QWidget
{
public:
    AddEvent(Users*, set<Users>&, QWidget* parent = nullptr);

    int rem = -1;

private:
    QLabel* min_label;
    QLabel* hr_label;
    QLabel* day_label;
    QVBoxLayout* mainLayout;
    QHBoxLayout* titlelayout;
    QHBoxLayout* row1layout;
    QHBoxLayout* row2layout;
    QHBoxLayout* row3layout;
    QHBoxLayout* row4layout;

    QTextEdit* remMin;
    QTextEdit* remHr;
    QTextEdit* remDay;
    QTextEdit* startTimeEdit;
    QTextEdit* endTimeEdit;

    QLabel* title;
    QLabel* name_label;
    QLabel* place;
    QLabel* start_date;
    QLabel* end_date;
    QLabel* remindertime;
    QLabel* description;

    QLineEdit* name_box;
    QLineEdit* place_box;
    QTextEdit* start_box;
    QTextEdit* end_box;
    QLineEdit* reminder_box;
    QLineEdit* desc_box;

    QPushButton* add;
    QPushButton* cancel;

    void cancel_pressed(Users*, set<Users>&);
    //int convertDateToint(string);
    void add_pressed(Users*, set<Users>&);
    int convertDateToint(string);


};
