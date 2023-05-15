#pragma once
#ifndef YOUREVENT_H
#define YOUREVENT_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QTextEdit>
#include<QComboBox>
#include "Events.h"
#include "Users.h"
#include"buttonsPage.h"
class yourEvent : public QWidget
{
public:
    yourEvent(Users* user, Events&, set<Users>&, QWidget* parent = nullptr);
    int rem = -1;
    int start_min;
    int start_hour;
    int start_day;
    int start_month;
    int start_year;

    int end_min;
    int end_hour;
    int end_day;
    int end_month;
    int end_year;

private:
    QTextEdit* nameEdit;
    QTextEdit* placeEdit;
    QTextEdit* startDateEdit;
    QTextEdit* startTimeEdit;
    QTextEdit* endDateEdit;
    QTextEdit* endTimeEdit;
    QTextEdit* remMin;
    QTextEdit* remHr;
    QTextEdit* remDay;
    QTextEdit* descriptionEdit;


    QVBoxLayout* mainLayout;
    QHBoxLayout* row1layout;
    QHBoxLayout* row2layout;
    QHBoxLayout* row3layout;
    QHBoxLayout* row0layout;
    QHBoxLayout* row4layout;


    QLabel* title_label;
    QLabel* name_label;
    QLabel* place_label;
    QLabel* startDate_label;
    QLabel* endDate_label;
    QLabel* reminder_label;
    QLabel* min_label;
    QLabel* hr_label;
    QLabel* day_label;
    QLabel* description_label;
    QLabel* empty_label;

    QPushButton* cancel;
    QPushButton* submit;

    QComboBox* reminderEdit;




    void submit_pressed(Users*, Events&, set<Users>&);
    void cancel_pressed(Users*, set<Users>&);
    void stioToint(int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
    tm convertTStoDate(time_t);
    

};

#endif