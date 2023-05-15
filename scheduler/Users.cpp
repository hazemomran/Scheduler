#include "Users.h"
#include <QMessageBox>


Users::Users(string name, string email, string password) {
	this->name = name;
	this->email = email;
	this->pass = password;
}

Users::Users() {

}

void Users::setData(string name, string email, string password) {
	this->name = name;
	this->email = email;
	this->pass = password;
};


void Users::addEvent(Events& event) {
	bool ch = check(dts, event.start_date, event.end_date);

	if (ch) {
		dts[event.start_date] = event;
		reminderMp[event.reminder_time] = event;
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("Event Invalid");
		msgBox.setInformativeText("This event has a conflict with another event!");
		msgBox.resize(100, 50);
		msgBox.exec();
	}
}

// 1-2 2-4 4-6 7-9  6-8

bool Users::check(map<int, Events>mp, int start_date, int end_date) {

	map<int, Events>::iterator it;
	if (mp.empty()) {
		return true;
	}
	for (it = mp.begin(); it != mp.end(); it++) {

		if (it->first > start_date) {

			it--;
			if (it->second.end_date > start_date) {
				return false;
			}
			else if (it->second.end_date <= start_date && (it++)->first >= end_date) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (it->second.end_date == start_date) {
			return false;
		}
	}

	it = mp.end();
	if ((--it)->second.end_date > start_date) {
		return false;
	}
	else {
		return true;
	}
}

int Users::convertDatetoTS(int year, int month, int day, int hour, int minute) //change
{
	// Create a std::tm object with the specific date and time
	tm timeInfo = { 0 };
	timeInfo.tm_year = year - 1900;  // Years since 1900
	timeInfo.tm_mon = month - 1;    // Months since January
	timeInfo.tm_mday = day;         // Day of the month
	timeInfo.tm_hour = hour+2;        // Hour (0-23)
	timeInfo.tm_min = minute;

	// Convert the std::tm object to a std::chrono::time_point object
	chrono::system_clock::time_point timeStamp = chrono::system_clock::from_time_t(std::mktime(&timeInfo));

	// Convert the time_point object to a timestamp
	time_t date = chrono::system_clock::to_time_t(timeStamp);
	// Print the timestamp
	cout << "date: " << date << endl;

	return date;


}

int Users::reminderToTimestamp(/*int start_date,*/ int start_year, int start_month, int start_day, int start_hour, int start_minute, int start_reminder_mins, int start_reminder_hours, int start_reminder_day)
{
	tm reminder = { 0 };
	reminder.tm_year = start_year - 1900;
	reminder.tm_mon = start_month - 1;
	reminder.tm_mday = start_day - start_reminder_day;
	reminder.tm_hour = (start_hour - start_reminder_hours) + 2;
	reminder.tm_min = start_minute - start_reminder_mins;

	chrono::system_clock::time_point timeStamp = chrono::system_clock::from_time_t(std::mktime(&reminder));

	// Convert the time_point object to a timestamp
	time_t remindStamp = chrono::system_clock::to_time_t(timeStamp);

	return remindStamp;


}

void Users::add(string name, string place, string description, int start_year, int start_month, int start_day, int start_hour, int start_minute, int start_reminder_mins, int start_reminder_hours, int start_reminder_day, int end_year, int end_month, int end_day, int end_hour, int end_minute) {


	int startDate = convertDatetoTS(start_year, start_month, start_day, start_hour, start_minute);
	int endDate = convertDatetoTS(end_year, end_month, end_day, end_hour, end_minute);
	int remineder = reminderToTimestamp(/*startDate,*/ start_year, start_month, start_day, start_hour, start_minute, start_reminder_mins, start_reminder_hours, start_reminder_day); //error

	Events event(name, place, description, startDate, endDate, remineder, 0);
	event.remDay = start_reminder_day;
	event.remHr = start_reminder_hours;
	event.remMin = start_reminder_mins;
	addEvent(event);

}

bool Users::remind() {
	// Get the current system time
	auto currentTime = std::chrono::system_clock::now();

	// Convert the current time to a time_t object
	std::time_t time = std::chrono::system_clock::to_time_t(currentTime);

	if (dts.begin()->first <= time) {
		return true;
	}
	return false;
}

//void Users::done_event() {
//
//	map<int, Events>::iterator it;
//	it = dts.begin();
//
//	auto currentTime = std::chrono::system_clock::now();
//	std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
//
//
//	if (it->first <= time) {
//		done.push_back(it->second);
//		dts.erase(dts.find(it->first));
//		reminderMp.erase(reminderMp.find(it->second.reminder_time));
//		//cout << "first event doneeee!!!!";
//	}
//
//}

//delete event
void Users::deleteEvent(Events& event) {
	dts.erase(event.start_date);
	reminderMp.erase(event.reminder_time);

}

//update event
//void Users::updateEvent(string eventName, Events event) {
//
//	map<string, Events> ::iterator it;
//	it = nameMap.find(eventName);
//	if (it == nameMap.end()) {
//		invalid();
//	}
//	else {
//		//GUIIIIIIIIIIIIIIIIII
//	}
//
//}

////display event
//void Users::displayEvents() {
//	map<int, Events> ::iterator it;
//	//display when gui is finished
//	for (it = dts.begin(); it != dts.end(); it++) {
//		cout << it->second.name << it->second.place << it->second.reminder_time << it->second.status << it->second.start_date; //and each attribute
//	}
//}
////invalid message 
void Users::invalid() {
	cout << "invalid!!!!!!"; // gui
}

tm Users::convertTStoDate(time_t timestamp) {
	// Convert the timestamp to a struct tm using gmtime
	struct tm* timeinfo = gmtime(&timestamp);

	return *timeinfo;
}