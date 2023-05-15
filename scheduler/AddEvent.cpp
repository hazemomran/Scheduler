#include "AddEvent.h"
#include <iostream>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QLineEdit>  
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QTextEdit>
#include "eventsPage.h"
#include "signUp.h"
#include "buttonsPage.h"

AddEvent::AddEvent(Users* user, set<Users>& users, QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Add Event!");
    setFixedSize(900, 550);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);


    titlelayout = new QHBoxLayout();
    title = new QLabel("Add your upcoming event!");
    title->setStyleSheet("font: bold 45px; color: #1e2835;");
    title->setAlignment(Qt::AlignCenter);

    titlelayout->addWidget(title);
    titlelayout->setAlignment(Qt::AlignTop);



    mainLayout->addLayout(titlelayout);
    mainLayout->addStretch();

    row1layout = new QHBoxLayout();
    name_label = new QLabel("Event name: ");
    name_label->setStyleSheet("font: bold 25px; color: #1e2835;");
    name_box = new QLineEdit();
    name_box->setFixedWidth(200);
    name_box->setFixedHeight(40);

    place = new QLabel("Location: ");
    place->setStyleSheet("font: bold 25px; color: #1e2835;");
    place_box = new QLineEdit();
    place_box->setFixedWidth(200);
    place_box->setFixedHeight(40);

    row1layout->addWidget(name_label);
    row1layout->addSpacing(10);
    row1layout->addWidget(name_box);
    row1layout->addSpacing(10);
    row1layout->addWidget(place);
    row1layout->addSpacing(10);
    row1layout->addWidget(place_box);
    row1layout->addSpacing(10);

    mainLayout->addLayout(row1layout);
    mainLayout->addStretch();


    row2layout = new QHBoxLayout();
    start_date = new QLabel("Start Date: ");
    start_date->setStyleSheet("font: bold 25px; color: #1e2835;");
    start_box = new QTextEdit(this);
    start_box->setFixedWidth(100);
    start_box->setFixedHeight(40);
    start_box->setPlaceholderText("day/month/year");
    startTimeEdit = new QTextEdit(this);
    endTimeEdit = new QTextEdit(this);
    startTimeEdit->setPlaceholderText("hr:min");
    startTimeEdit->setMaximumHeight(40);
    startTimeEdit->setMaximumWidth(91);
    startTimeEdit->resize(startTimeEdit->sizeHint());


    endTimeEdit->setPlaceholderText("hr:min");
    endTimeEdit->setMaximumHeight(40);
    endTimeEdit->setMaximumWidth(91);
    endTimeEdit->resize(startTimeEdit->sizeHint());


    end_date = new QLabel("End Date: ");
    end_date->setStyleSheet("font: bold 25px; color: #1e2835;");
    end_box = new QTextEdit(this);
    end_box->setFixedWidth(100);
    end_box->setFixedHeight(40);
    end_box->setPlaceholderText("day/month/year");

    row2layout->addWidget(start_date);
    row2layout->addSpacing(10);
    row2layout->addWidget(start_box);
    row2layout->addSpacing(10);
    row2layout->addWidget(startTimeEdit);
    row2layout->addSpacing(10);
    row2layout->addWidget(end_date);
    row2layout->addSpacing(10);
    row2layout->addWidget(end_box);
    row2layout->addSpacing(10);
    row2layout->addWidget(endTimeEdit);
    row2layout->addSpacing(10);

    mainLayout->addLayout(row2layout);
    mainLayout->addStretch();


    row3layout = new QHBoxLayout();
    remindertime = new QLabel("reminder time:");
    remindertime->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");

    remDay = new QTextEdit(this);



    remDay->setText(" ");
    remDay->setMaximumHeight(30);
    remDay->setMaximumWidth(30);

    day_label = new QLabel("days");
    day_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    remHr = new QTextEdit(this);


    remHr->setText(" ");
    remHr->setMaximumHeight(30);
    remHr->setMaximumWidth(30);


    hr_label = new QLabel("hrs");
    hr_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    remMin = new QTextEdit(this);


    remMin->setText(" ");
    remMin->setMaximumHeight(30);
    remMin->setMaximumWidth(30);


    min_label = new QLabel("mins");
    min_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    description = new QLabel("Description: ");
    description->setStyleSheet("font: bold 25px; color: #1e2835;");
    desc_box = new QLineEdit();
    desc_box->setFixedWidth(200);
    desc_box->setFixedHeight(40);

    row3layout->addWidget(remindertime);
    row3layout->addSpacing(10);
    row3layout->addWidget(remDay);
    row3layout->addSpacing(6);
    row3layout->addWidget(day_label);
    row3layout->addSpacing(6);
    row3layout->addWidget(remHr);
    row3layout->addSpacing(6);
    row3layout->addWidget(hr_label);
    row3layout->addSpacing(6);
    row3layout->addWidget(remMin);
    row3layout->addSpacing(6);
    row3layout->addWidget(min_label);
    row3layout->addSpacing(10);
    row3layout->addWidget(description);
    row3layout->addSpacing(10);
    row3layout->addWidget(desc_box);
    row3layout->addSpacing(10);

    mainLayout->addLayout(row3layout);
    mainLayout->addStretch();

    row4layout = new QHBoxLayout();

    add = new QPushButton("Add");
    add->setFixedWidth(100);
    add->setFixedHeight(60);
    add->setStyleSheet("font: bold 27px; color:black; background-color: #1e2835; color:white; border-radius:15px;");

    cancel = new QPushButton("Cancel");
    cancel->setFixedWidth(100);
    cancel->setFixedHeight(60);
    cancel->setStyleSheet("font: bold 27px; color:black; background-color: #1e2835; color:white; border-radius:15px;");

    row4layout->addWidget(add);
    row4layout->addSpacing(2);
    row4layout->addWidget(cancel);
    row4layout->setSpacing(10);


    mainLayout->addLayout(row4layout);
    mainLayout->addStretch();
    connect(add, &QPushButton::clicked, this, [this, user, &users]() {
        add_pressed(user, users);
        });
    
    connect(cancel, &QPushButton::clicked, this, [this, user, &users]() {
        cancel_pressed(user, users);
        });
}

struct Date {
    int day;
    int month;
    int year;
};

struct Time {
    int hour;
    int minute;
};


Date adjust_date1(string s) {
    int pos = s.find('/');
    Date date;
    bool valid = true;
    // Check if "/" is found
    if (pos != string::npos) {

        // s = "23/45/67" 
        // first_num_str = "23"
        string first_num_str = s.substr(0, pos);

        // Check if all characters are digits
        for (char c : first_num_str) {
            if (!isdigit(c)) {
                //QMessageBox::information(this, "Selected Item", "You selected: " + selectedItem);
                break;
            }
        }

        // s = "23/45/67" 
        // second_part = "45/67"
        string second_part = s.substr(pos + 1);
        pos = second_part.find('/');

        if (pos != string::npos) {

            // s = "23/45/67" 
            // second_num_str = "45"
            // third_num_str = "67"
            string second_num_str = second_part.substr(0, pos);
            string third_num_str = second_part.substr(pos + 1);

            // checking ranges
            if (stoi(first_num_str) < 32 && stoi(second_num_str) < 13 && stoi(third_num_str) < 2100 && stoi(third_num_str) > 1900) {

                // Check if all characters are digits
                for (char c : first_num_str) {
                    if (!isdigit(c)) {
                        valid = false;
                        break;
                    }
                }
                // Check if all characters are digits
                for (char c : second_num_str) {
                    if (!isdigit(c)) {
                        valid = false;
                        break;
                    }
                }
                // Check if all characters are digits
                for (char c : third_num_str) {
                    if (!isdigit(c)) {
                        valid = false;
                        break;
                    }
                }

                date.day = stoi(first_num_str);
                date.month = stoi(second_num_str);
                date.year = stoi(third_num_str);
                if (valid) return date;
            }
        }
    }
}

Time  adjust_time1(string s) {
    Time result = { 0, 0 };
    int pos = s.find(':');
    bool valid = true;
    if (pos != std::string::npos) {
        std::string first_num_str = s.substr(0, pos);
        std::string second_num_str = s.substr(pos + 1);

        // Check if all characters are digits

        for (char c : first_num_str) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
        for (char c : second_num_str) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid && stoi(first_num_str) < 25 && stoi(second_num_str) < 60) {
            result.hour = stoi(first_num_str);
            result.minute = stoi(second_num_str);
            return result;
        }
    }
}





//
void AddEvent::add_pressed(Users* user, set<Users>& users) {

    //extracting data from input boxes
    QString name_ = name_box->text();
    string name = name_.toStdString();
    QString place_ = place_box->text();
    string place = place_.toStdString();
    QString description_ = desc_box->text();
    string description = description_.toStdString();
    QString startDate_ = start_box->toPlainText();
    string startDate = startDate_.toStdString();
    QString startTime_ = startTimeEdit->toPlainText();
    string startTime = startTime_.toStdString();
    QString endDate_ = end_box->toPlainText();
    string endDate = endDate_.toStdString();
    QString endTime_ = endTimeEdit->toPlainText();
    string endTime = endTime_.toStdString();
    QString remDay_ = remDay->toPlainText();
    int remDays = remDay_.toInt();

    QString remHr_ = remHr->toPlainText();
    int remHours = remHr_.toInt();

    QString remMin_ = remMin->toPlainText();
    int remMinutes = remMin_.toInt();

    //Entering data into Date and Time structs
    Date SDate = adjust_date1(startDate);
    Time STime = adjust_time1(startTime);
    Date EDate = adjust_date1(endDate);
    Time ETime = adjust_time1(endTime);

    //Converting reminder data into time stamp
    rem = user->reminderToTimestamp(SDate.year, SDate.month, SDate.day, STime.hour, STime.minute, remMinutes, remHours, remDays);

    

    int start_date = user->convertDatetoTS(SDate.year, SDate.month, SDate.day, STime.hour, STime.minute);
    int end_date = user->convertDatetoTS(EDate.year, EDate.month, EDate.day, ETime.hour, ETime.minute);

    //Add new event
    user->add(name, place, description, SDate.year, SDate.month, SDate.day, STime.hour, STime.minute, remMinutes, remHours, remDays, EDate.year, EDate.month, EDate.day, ETime.hour, ETime.minute);


    buttonsPage* e1 = new buttonsPage(user, users);
    e1->show();
    this->close();

}

void AddEvent::cancel_pressed(Users* user, set<Users>& users)
{
    buttonsPage* ep = new buttonsPage(user, users);
    ep->show();
    this->close();
}