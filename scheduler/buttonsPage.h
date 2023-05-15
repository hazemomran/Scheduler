#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include "Users.h"
#include "FirstPage.h"
#include "remDisplay.h"
class buttonsPage : public QWidget
{

public:
    buttonsPage(Users* user, set<Users>& users, QWidget* parent = nullptr);
    //bool check_signup(set<Users>&, string name, string password);

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* row0layout;
    QHBoxLayout* row1layout;
    QHBoxLayout* row2layout;
    QHBoxLayout* row3layout;

    QLabel* title_label;
    QLabel* display_label;



    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* DoneButton;
    QPushButton* DisplayByDate;
    QPushButton* DisplayByRem;
    QPushButton* logOutButton;

    void addButton_pressed(Users*, set<Users>&);
    void deleteButton_pressed(Users*, set<Users>&);
    // void DoneButton_pressed();
    void DisplayByDate_pressed(Users*, set<Users>&);
    void DisplayByRem_pressed(Users*, set<Users>&);
    void logout_pressed(set<Users>&);
    // void done_event(Users& user);
    void donePressed(Users*, set<Users>&);
    //void DisplayByRem_pressed();
   // void logOut_pressed();*/
    void remind(Users*);

};