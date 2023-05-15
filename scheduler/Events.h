#pragma once
#include <string>
#include <chrono>
using namespace std;
class Events
{
public:
	string name;
	string place;
	string description;
	int start_date;
	int end_date;
	int reminder_time;
	int remDay = 0;
	int remHr = 0;
	int remMin = 0;
	int index = 0;
	//tm tmp_time;
	bool status;

public:
	Events() {
		place = "";
		start_date = 0;
		end_date = 0;
		reminder_time = 0;
		name = "";
	}

	Events(string name, string place, string description, int start_date, int end_date, int reminder_time, bool status) {
		this->name = name;
		this->place = place;
		this->description = description;
		this->start_date = start_date;
		this->end_date = end_date;
		this->reminder_time = reminder_time;
		this->status = status;

	}
	Events updateEvent(string& name, string place, string description, int start_date, int end_date, int reminder_time, Events& event);
};