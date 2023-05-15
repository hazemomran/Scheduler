#pragma once
#ifndef SIGNIN_H
#define SIGNIN_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <set>
#include "Users.h"
class signIn : public QWidget
{
public:
    signIn(set<Users>&, QWidget* parent = nullptr);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* titlelayout;
    QHBoxLayout* row1layout;
    QHBoxLayout* row2layout;
    QHBoxLayout* row3layout;
    QHBoxLayout* rowChecklayout;

    QLabel* username_label;
    QLabel* password_label;
    QLabel* title;

    QLineEdit* username_box;
    QLineEdit* password_box;

    QPushButton* login;
    QPushButton* cancel;

    QCheckBox* showPass;

    void login_pressed(set<Users>&);
    void cancel_pressed(set<Users>&);
};

#endif