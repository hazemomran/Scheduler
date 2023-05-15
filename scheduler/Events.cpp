#include "Events.h"
Events Events::updateEvent(string& name, string place, string description, int start_date, int end_date, int reminder_time, Events& event) {
    this->name = name;

    this->place = place;
    this->description = description;
    this->start_date = start_date;
    this->end_date = end_date;
    this->reminder_time = reminder_time;

    return event;
}
