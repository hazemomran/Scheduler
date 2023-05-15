#include "buttonsPage.h"
#include "doneEvents.h"
#include "eventsPage.h"
#include "remDisplay.h"
#include "Users.h"
#include "dateDisplay.h"
#include "signIn.h"
#include <QStackedWidget>
#include "AddEvent.h"
#include <thread>
buttonsPage::buttonsPage(Users* user, set<Users>& users, QWidget* parent) : QWidget(parent)
{

    doneEvents* done = new doneEvents(user, users);
    done->done_event(user, users);

    setWindowTitle("buttons page");
    setFixedSize(900, 550);
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    
    row0layout = new QHBoxLayout();
    title_label = new QLabel("        Options");
    title_label->setStyleSheet("font-weight: bold; font-size: 55px; color: #1e2835;");
    title_label->setFont(QFont("Georgia", 55));
    title_label->setAlignment(Qt::AlignCenter);
    // title_label->setMargin(50);
    row0layout->addWidget(title_label);
    QSpacerItem* horizontalSpacer;
    horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum);
    row0layout->addItem(horizontalSpacer);

    logOutButton = new QPushButton("Log out");
    logOutButton->setFixedWidth(100);
    logOutButton->setFixedHeight(40);
    logOutButton->setStyleSheet("font: bold 15px; color:black; background-color: #1e2835; color:white; border-radius:7px;");
    connect(logOutButton, &QPushButton::clicked, this, [this, &users]() {
        logout_pressed(users);
        });






    row0layout->addWidget(logOutButton);

    row0layout->setAlignment(Qt::AlignTop);


    mainLayout->addLayout(row0layout);
    mainLayout->addStretch(2);
    ///////////////////////////////////////////////////////

    row1layout = new QHBoxLayout();
    addButton = new QPushButton("Add event");
    addButton->setFixedWidth(165);
    addButton->setFixedHeight(75);
    addButton->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");
    deleteButton = new QPushButton("Update/delete");
    deleteButton->setFixedWidth(175);
    deleteButton->setFixedHeight(75);
    deleteButton->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");
    DoneButton = new QPushButton("Done events");
    DoneButton->setFixedWidth(165);
    DoneButton->setFixedHeight(75);
    DoneButton->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");

    row1layout->addWidget(addButton);
    row1layout->addWidget(deleteButton);
    row1layout->addWidget(DoneButton);
    mainLayout->addLayout(row1layout);
    mainLayout->addStretch(2);
    /////////////////////////////////////////////////////////////////////////////////////////////
    row3layout = new QHBoxLayout();
    display_label = new QLabel("Display events:");
    display_label->setStyleSheet("font-weight: bold; font-size: 30px; color: #1e2835;");
    display_label->setFont(QFont("Georgia", 30));
    display_label->setAlignment(Qt::AlignCenter);
    row3layout->addWidget(display_label);
    mainLayout->addLayout(row3layout);
    mainLayout->addStretch(1);








    ///////////////    //////////////////////////////////////////////////////////////
    row2layout = new QHBoxLayout();
    DisplayByDate = new QPushButton("by date");
    DisplayByDate->setFixedWidth(165);
    DisplayByDate->setFixedHeight(75);
    DisplayByDate->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");
    ///////////////////////////////////////////////////////////////////   

    

    connect(DisplayByDate, &QPushButton::clicked, this, [this, user, &users]() {
        DisplayByDate_pressed(user, users);
        });







    DisplayByRem = new QPushButton("by reminder");
    DisplayByRem->setFixedWidth(165);
    DisplayByRem->setFixedHeight(75);
    DisplayByRem->setStyleSheet("font: bold 25px; color:black; background-color: #1e2835; color:white; border-radius:15px;");
    connect(DisplayByRem, &QPushButton::clicked, this, [this, user, &users]() {
        DisplayByRem_pressed(user, users);
        });
    row2layout->addWidget(DisplayByDate);
    row2layout->addWidget(DisplayByRem);

    mainLayout->addLayout(row2layout);
    mainLayout->addStretch(2);
    /////////////////////////////////////////////////////

    connect(DoneButton, &QPushButton::clicked, this, [this, user, &users]() {
        donePressed(user, users);
        });
    connect(deleteButton, &QPushButton::clicked, this, [this, user, &users]() {
        deleteButton_pressed(user, users);
        });
    connect(addButton, &QPushButton::clicked, this, [this, user, &users]() {
        addButton_pressed(user, users);
        });

   
    remind(user);

}

void buttonsPage::DisplayByDate_pressed(Users* user, set<Users>& users) {

    dateDisplay* ep = new dateDisplay(user, users);
    ep->show();
    this->close();
}
void buttonsPage::DisplayByRem_pressed(Users* user, set<Users>& users) {

    remDisplay* ep = new remDisplay(user, users);
    ep->show();
    this->close();
}

void  buttonsPage::logout_pressed(set<Users>& users) {
    signIn* s5 = new signIn(users);
    s5->show();
    this->close();
}
void  buttonsPage::donePressed(Users* user, set<Users>& users) {

    doneEvents* d2 = new doneEvents(user, users);
    d2->show();
    this->close();
}
void buttonsPage::deleteButton_pressed(Users* user, set<Users>& users) {

    eventsPage* e5 = new eventsPage(user, users);
    e5->show();
    this->close();


}
void buttonsPage::addButton_pressed(Users* user, set<Users>& users) {

    AddEvent* e7 = new AddEvent(user, users);
    e7->show();
    this->close();


}

//Remind the user if there any event is about to start.
void buttonsPage::remind(Users* user) {
    // Get the current system time
    auto currentTime = std::chrono::system_clock::now();

    // Convert the current time to a time_t object
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);


    if (!user->dateMp.empty())
    {
        //Check if the current time passed reminder time
        if (user->dateMp.begin()->second.reminder_time <= time + 10800 && !user->dateMp.begin()->second.status) {
            user->dateMp.begin()->second.status = true;
            QMessageBox::information(nullptr, "Reminder", QString::fromStdString(user->dateMp.begin()->second.name) + " about to start!");
        }
    }


}