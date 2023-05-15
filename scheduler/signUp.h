#pragma once
#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include "Users.h"
#include "FirstPage.h"

class signUp : public QWidget
{

public:
    signUp(set<Users>&, QWidget* parent = nullptr);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* row1layout;
    QHBoxLayout* row2layout;
    QHBoxLayout* row3layout;
    QHBoxLayout* row4layout;
    QHBoxLayout* row5layout;
    QHBoxLayout* rowChecklayout;
    QHBoxLayout* titlelayout;

    QLabel* username_label;
    QLabel* password_label;
    QLabel* confirm_label;
    QLabel* email_label;
    QLabel* title;
    QLabel* extra_label;
    QLabel* extra_label1;
    QLabel* extra_label2;
    QLabel* extra_label3;
    QLabel* extra_label4;

    QLineEdit* username_box;
    QLineEdit* password_box;
    QLineEdit* email_box;
    QLineEdit* confirm_box;

    QPushButton* back;
    QPushButton* sign;

    QCheckBox* showPass;



    void sign_pressed(set<Users>&);
    void back_pressed(set<Users>&);
    bool validate_signup(const set<Users>&, const string&, const string&, const string&, const string&);


};
#endif