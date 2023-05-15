#include "scheduler.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <set>
#include "signIn.h"
#include "eventsPage.h"
#include "AddEvent.h"
#include "signUp.h"
#include "FirstPage.h"
#include "yourEvent.h"
#include "buttonsPage.h"
#include"doneEvents.h"
#include<vector>
#include <cstdlib>
#include<fstream>
#include <map>
#include <queue>
#include <set>
#include<QFile>
#include<QTextStream>
#include "Events.h"
#include <QCoreApplication>
vector<Users> obj;
void fromFiles() {
    ifstream file;
    file.open("Users.txt", ios::in); //read
    if (file.is_open()) {
        string line;
        while (line != "end")
        {
            file >> line;
            if (line == "Name:") {
                Users NewUser;
                file >> NewUser.name;
                obj.push_back(NewUser);
            }
            else if (line == "Email:") {
                file >> obj[obj.size() - 1].email;
            }
            else if (line == "Password:") {
                file >> obj[obj.size() - 1].pass;
            }
            else if (line == "Key:") {
                int key;
                file >> key;
                string plc, nm, desc;
                int start, end, reminder;
                bool st;
                file >> plc >> start >> end >> reminder >> st >> nm >> desc;
                obj[obj.size() - 1].dts[key] = Events(nm, plc, desc, start, end, reminder, st);
                obj[obj.size() - 1].reminderMp[reminder] = Events(nm, plc, desc, start, end, reminder, st);
                cout << obj[obj.size() - 1].name;
            }
        }
    }
    file.close();
    ofstream ofs("Users.txt", ofstream::trunc); //erase all
    ofs.close();

    // storing all events
    /*for (int i = 0; i < obj.size(); i++) {
        obj[i].allEvents.insert(obj[i].dts.begin(), obj[i].dts.end());
        obj[i].allEvents.insert(obj[i].done.front(), obj[i].done.back());*/
        // iterate through the temporary queue
        /*while (!tempQueue.empty()) {
            Events value = tempQueue.front();
            obj[i].allEvents[value.start_date] = value;
            tempQueue.pop_back();
        }*/
        /*  for (int j = 0; j < obj[i].done.size(); j++) {

              obj[i].done.push_front(obj[i].done.front());
              obj[i].done.pop_back();

          }*/
          //}

}
//////////////////////////////////////////////////////////////////////////
void toFiles(vector<Users>& objj) {
    ofstream file2;
    file2.open("Users.txt", ios::app);
    if (file2.is_open()) {
        for (int i = 0; i < objj.size(); i++)
        {
            file2 << "Name: " << objj[i].name << "\n" << "Email: " << objj[i].email << "\n" << "Password: " << objj[i].pass << "\n";
            map<int, Events>::iterator it;
            for (it = objj[i].dts.begin(); it != objj[i].dts.end(); it++)
            {
                file2 << "Key: " << it->first << " " << it->second.place << " " << it->second.start_date << " " << it->second.end_date << " " << it->second.reminder_time << " " << it->second.status << " " << it->second.name << " " << it->second.description << "\n";
            }
            for (int j = 0; j < objj[i].done.size(); j++)
            {
                Events w = objj[i].done.front();
                objj[i].done.push_back(objj[i].done.front());
                objj[i].done.pop_front();
                file2 << "Key: " << w.start_date << " " << w.place << " " << w.start_date << " " << w.end_date << " " << w.reminder_time << " " << w.status << " " << w.name << " " << w.description << "\n";
            }
        }
        file2 << "end";
    }
    file2.close();
}









int main(int argc, char* argv[])
{
    fromFiles();
    set<Users> users(obj.begin(), obj.end());
    QApplication a(argc, argv);



    FirstPage first(users);
    first.show();
    int x;


    Users u("janjon", "janjon@gmail.com", "1234");
    users.insert(u);
    x = a.exec();
    vector<Users>v(users.begin(), users.end());

    toFiles(v);
    return x;
}
