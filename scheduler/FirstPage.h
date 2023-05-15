#pragma once
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
#include "Users.h"

#pragma once
//#ifndef SIGNUP_H
//#define SIGNUP_H
class FirstPage : public QWidget
{
public:
    FirstPage(set<Users>&, QWidget* parent = nullptr);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* row1layout;
    QHBoxLayout* row2layout;

    QLabel* title;

    QPushButton* login_button;
    QPushButton* signup_button;
    void login_pressed(set<Users>&);
    void signUp_pressed(set<Users>&);

};
//#endif // WINDOW_H