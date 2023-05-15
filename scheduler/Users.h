#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <queue>
#include <set>
#include "Events.h"
using namespace std;
class Users
{
public:
	string name;
	string email;
	string pass;
	map<int, Events>dts;
	map<int, Events>reminderMp;
	map<int, Events> allEvents;
	deque<Events>done;
	/*static set<Users>users;*/
	bool operator<(const Users& other) const {
		return name < other.name;
	}

	Users();
	Users(string, string, string);
	void setData(string, string, string);
	void addEvent(Events&);
	bool check(map<int, Events>, int, int);

	void add(string, string, string, int, int, int, int, int, int, int, int, int, int, int, int, int);
	int convertDatetoTS(int, int, int, int, int);//change
	int reminderToTimestamp(/*int*/  int, int, int, int, int, int, int, int);
	bool remind();
	void done_event();
	void deleteEvent(Events& event);
	//void updateEvent(string, Events);
	//void displayEvents();
	void invalid();
	tm convertTStoDate(time_t);


};