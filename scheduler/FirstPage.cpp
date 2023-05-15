#include "FirstPage.h"
#include "signIn.h"
#include "signUp.h"
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
#include <QStackedWidget>
#include <QStyle>


FirstPage::FirstPage(set<Users>& users, QWidget* parent) : QWidget(parent)
{

    setWindowTitle("Welcome!");
    setFixedSize(900, 550);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    row1layout = new QHBoxLayout();
    title = new QLabel("Welcome to your Events Scheduler!");
    title->setStyleSheet("font: bold 45px; color: #1e2835;");
    title->setAlignment(Qt::AlignHCenter);

    row1layout->addWidget(title);
    row1layout->setAlignment(Qt::AlignCenter);



    mainLayout->addLayout(row1layout);

   
    row2layout = new QHBoxLayout();

    login_button = new QPushButton("LOGIN");
    login_button->setFixedWidth(170);
    login_button->setFixedHeight(110);
    login_button->setStyleSheet("font: bold 27px; color:black; background-color: white; color:1e2835; border-radius:15px; border:#1e2835");


    signup_button = new QPushButton("SIGNUP");
    signup_button->setFixedWidth(170);
    signup_button->setFixedHeight(110);
    signup_button->setStyleSheet("font: bold 27px; color:black; background-color: #1e2835; color:white; border-radius:15px;");

    row2layout->setSpacing(70);

    row2layout->addWidget(login_button);
    row2layout->addWidget(signup_button);

    row2layout->setAlignment(Qt::AlignCenter);
    mainLayout->addLayout(row2layout);


    connect(login_button, &QPushButton::clicked, this, [this, &users]() {
        login_pressed(users);
        });

    connect(signup_button, &QPushButton::clicked, this, [this, &users]() {
        signUp_pressed(users);
        });



};

void FirstPage::login_pressed(set<Users>& users) {

    signIn* log_in = new signIn(users);
    log_in->show();
    this->close();
}

void FirstPage::signUp_pressed(set<Users>& users) {
    signUp* sign_up = new signUp(users);
    sign_up->show();
    this->close();
}