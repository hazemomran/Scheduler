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
	map<int, Events>dateMp;
	map<int, Events>reminderMp;
	map<int, Events> allEvents;
	deque<Events>done;
	bool operator<(const Users& other) const {
		return name < other.name;
	}

	Users();
	Users(string, string, string);
	void setData(string, string, string);
	void addEvent(Events&);
	bool check(map<int, Events>, int, int);

	void add(string, string, string, int, int, int, int, int, int, int, int, int, int, int, int, int);
	int convertDatetoTS(int, int, int, int, int);
	int reminderToTimestamp(int, int, int, int, int, int, int, int);
	void done_event();
	void deleteEvent(Events& event);
	tm convertTStoDate(time_t);


};