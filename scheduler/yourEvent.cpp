#include "yourEvent.h"
#include "eventsPage.h"
#include "Users.h"
#include "buttonsPage.h"
#include <QStackedWidget>
#include <QMessageBox>




yourEvent::yourEvent(Users* user, Events& event, set<Users>& users, QWidget* parent) : QWidget(parent)
{ 

    buttonsPage::remind(user);

    setWindowTitle("Event name");
    setFixedSize(900, 550);
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    row0layout = new QHBoxLayout();
    title_label = new QLabel("Welcome to your event!");
    title_label->setStyleSheet("font-weight: bold; font-size: 45px; color: #1e2835;");
    title_label->setAlignment(Qt::AlignCenter);
    row0layout->addWidget(title_label);
    row0layout->setAlignment(Qt::AlignTop);
    mainLayout->addLayout(row0layout);
    mainLayout->addStretch();



    row1layout = new QHBoxLayout();
    name_label = new QLabel("Name:");
    name_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");
    nameEdit = new QTextEdit(this);
    QString myQStringName = QString::fromStdString(event.name);
    nameEdit->setText(myQStringName);
    nameEdit->setMaximumHeight(40);
    nameEdit->setMaximumWidth(200);
    nameEdit->resize(nameEdit->sizeHint());

    place_label = new QLabel("Place:");
    place_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");
    placeEdit = new QTextEdit(this);
    QString myQStringPlace = QString::fromStdString(event.place);
    placeEdit->setText(myQStringPlace);
    placeEdit->setMaximumHeight(40);
    placeEdit->setMaximumWidth(200);
    placeEdit->resize(nameEdit->sizeHint());




    row1layout->addWidget(name_label);
    row1layout->addSpacing(10);
    row1layout->addWidget(nameEdit);
    row1layout->addSpacing(10);
    row1layout->addWidget(place_label);
    row1layout->addSpacing(10);
    row1layout->addWidget(placeEdit);
    row1layout->addSpacing(10);
    mainLayout->addLayout(row1layout);
    mainLayout->addStretch();


    //  ///////////////////////
    row2layout = new QHBoxLayout();
    startDate_label = new QLabel("Start date:");
    startDate_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");
    startDateEdit = new QTextEdit(this);

    tm start = convertTStoDate(event.start_date);
    QString QStringStartDay = QString::number(start.tm_mday);
    QString QStringStartMon = QString::number(start.tm_mon + 1);
    QString QStringStartYear = QString::number(start.tm_year + 1900);
    QString QStartDate = QStringStartDay + "/" + QStringStartMon + "/" + QStringStartYear;

    startDateEdit->setText(QStartDate);
    startDateEdit->setMaximumHeight(40);
    startDateEdit->setMaximumWidth(100);
    startDateEdit->resize(nameEdit->sizeHint());

    startTimeEdit = new QTextEdit(this);

    QString QStringStartHr = QString::number(start.tm_hour);
    QString QStringStartMin = QString::number(start.tm_min);
    QString QStartTime = QStringStartHr + ":" + QStringStartMin;
    startTimeEdit->setText(QStartTime);
    startTimeEdit->setMaximumHeight(40);
    startTimeEdit->setMaximumWidth(91);
    startTimeEdit->resize(nameEdit->sizeHint());






    /////////////////////////////////////////////////////////////////////

    endDate_label = new QLabel("End date:");
    endDate_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");

    endDateEdit = new QTextEdit(this);

    /////////////////////////////////////
    tm end = convertTStoDate(event.end_date);
    QString QStringEndDay = QString::number(end.tm_mday);
    QString QStringEndMon = QString::number(end.tm_mon + 1);
    QString QStringEndYear = QString::number(end.tm_year + 1900);
    QString QEndDate = QStringEndDay + "/" + QStringEndMon + "/" + QStringEndYear;

    endDateEdit->setText(QEndDate);
    endDateEdit->setMaximumHeight(40);
    endDateEdit->setMaximumWidth(100);
    endDateEdit->resize(nameEdit->sizeHint());


    //////////////////////////////////////////////

    endTimeEdit = new QTextEdit(this);
    QString QStringEndHr = QString::number(end.tm_hour);
    QString QStringEndMin = QString::number(end.tm_min);
    QString QEndTime = QStringEndHr + ":" + QStringEndMin;

    endTimeEdit->setText(QEndTime);
    endTimeEdit->setMaximumHeight(40);
    endTimeEdit->setMaximumWidth(81);
    endTimeEdit->resize(nameEdit->sizeHint());





    row2layout->addWidget(startDate_label);
    row2layout->addSpacing(3);
    row2layout->addWidget(startDateEdit);
    row2layout->addSpacing(10);
    row2layout->addWidget(startTimeEdit);
    row2layout->addSpacing(10);
    row2layout->addWidget(endDate_label);
    row2layout->addSpacing(3);
    row2layout->addWidget(endDateEdit);
    row2layout->addSpacing(10);
    row2layout->addWidget(endTimeEdit);
    row2layout->addSpacing(10);
    mainLayout->addLayout(row2layout);
    mainLayout->addStretch();

    /////////////////////////////////
    row3layout = new QHBoxLayout();
    reminder_label = new QLabel("reminder time:");
    reminder_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");

    remDay = new QTextEdit(this);

    QString QString_r1 = QString::number(event.remDay);

    remDay->setText(QString_r1);
    remDay->setMaximumHeight(30);
    remDay->setMaximumWidth(30);
    remDay->resize(nameEdit->sizeHint());

    day_label = new QLabel("days");
    day_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    remHr = new QTextEdit(this);
    QString QString_r2 = QString::number(event.remHr);

    remHr->setText(QString_r2);
    remHr->setMaximumHeight(30);
    remHr->setMaximumWidth(30);
    remHr->resize(nameEdit->sizeHint());

    hr_label = new QLabel("hrs");
    hr_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    remMin = new QTextEdit(this);

    QString QString_r3 = QString::number(event.remMin);

    remMin->setText(QString_r3);
    remMin->setMaximumHeight(30);
    remMin->setMaximumWidth(30);
    remMin->resize(nameEdit->sizeHint());

    min_label = new QLabel("mins");
    min_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");





    description_label = new QLabel("Description:");
    description_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");
    descriptionEdit = new QTextEdit(this);
    QString myQStringDesc = QString::fromStdString(event.description);
    descriptionEdit->setText(myQStringDesc);
    descriptionEdit->setMaximumHeight(40);
    descriptionEdit->setMaximumWidth(200);
    descriptionEdit->resize(nameEdit->sizeHint());



    row3layout->addWidget(reminder_label);
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

    row3layout->addWidget(description_label);
    row3layout->addSpacing(10);
    row3layout->addWidget(descriptionEdit);
    row3layout->addSpacing(10);
    mainLayout->addLayout(row3layout);
    mainLayout->addStretch();
    // 


    ////////////////////////
    row4layout = new QHBoxLayout();
    submit = new QPushButton("Submit");
    submit->setFixedWidth(120);
    submit->setFixedHeight(60);
    submit->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");
    cancel = new QPushButton("Cancel");
    cancel->setFixedWidth(120);
    cancel->setFixedHeight(60);
    cancel->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");
    row4layout->addWidget(submit);
    row4layout->addWidget(cancel);
    mainLayout->addLayout(row4layout);

    connect(cancel, &QPushButton::clicked, this, [this, user, &users]() {
        cancel_pressed(user, users);
        });
    connect(submit, &QPushButton::clicked, this, [this, &event, user, &users]() {
        submit_pressed(user, event, users);
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

//adjust the date extracted from input box which is a string into struct Date that cries integers
Date adjust_date(string s) {
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

    return date;
}

//adjust the time extracted from input box which is a string into struct Time that cries integers
Time  adjust_time(string s) {
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


void yourEvent::submit_pressed(Users* user, Events& event, set<Users>& users)
{
    //extracting data from input boxes
    QString name_ = nameEdit->toPlainText();
    string name = name_.toStdString();
    QString place_ = placeEdit->toPlainText();
    string place = place_.toStdString();
    QString description_ = descriptionEdit->toPlainText();
    string description = description_.toStdString();
    QString startDate_ = startDateEdit->toPlainText();
    string startDate = startDate_.toStdString();
    QString startTime_ = startTimeEdit->toPlainText();
    string startTime = startTime_.toStdString();
    QString endDate_ = endDateEdit->toPlainText();
    string endDate = endDate_.toStdString();
    QString endTime_ = endTimeEdit->toPlainText();
    string endTime = endTime_.toStdString();

    QString remDay_ = remDay->toPlainText();
    int remDays = remDay_.toInt();

    QString remHr_ = remHr->toPlainText();
    int remHours = remHr_.toInt();

    QString remMin_ = remMin->toPlainText();
    int remMinutes = remMin_.toInt();
    event.remDay = remDays;
    event.remHr = remHours;
    event.remMin = remMinutes;

    //Entering data into Date and Time structs
    Date SDate = adjust_date(startDate);
    Time STime = adjust_time(startTime);
    Date EDate = adjust_date(endDate);
    Time ETime = adjust_time(endTime);

    //Converting reminder data into time stamp
    rem = user->reminderToTimestamp(SDate.year, SDate.month, SDate.day, STime.hour, STime.minute, remMinutes, remHours, remDays);

    
    

    int start_date = user->convertDatetoTS(SDate.year, SDate.month, SDate.day, STime.hour, STime.minute);
    int end_date = user->convertDatetoTS(EDate.year, EDate.month, EDate.day, ETime.hour, ETime.minute);

    //Create new event
    Events e1(name, place, description, start_date, end_date, rem, 0);

    //remove old event from the maps
    user->reminderMp.erase(event.reminder_time);
    user->dateMp.erase(event.start_date);

    //Add new event to the map
    user->dateMp[start_date] = e1;
    user->reminderMp[rem] = e1;


    buttonsPage* e2 = new buttonsPage(user, users);
    e2->show();
    this->close();
}

///////////////////////////////////////////////////////////////


void yourEvent::cancel_pressed(Users* user, set<Users>& users)
{
    eventsPage* p3 = new eventsPage(user, users);
    this->close();
}

//Convert time stamp into a normal date
tm yourEvent::convertTStoDate(time_t timestamp) {
    // Convert the timestamp to a struct tm using gmtime
    struct tm* timeinfo = gmtime(&timestamp);

    return *timeinfo;
}
