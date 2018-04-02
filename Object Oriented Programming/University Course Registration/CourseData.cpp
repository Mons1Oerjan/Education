#include "CourseData.h"

/* Constructors */
CourseData::CourseData() {}

CourseData::CourseData(string crn, string loc, string type, string name, string time, string weekdays, string percentage) {
    this->crn = crn;
    this->location = loc;
    this->type = type;
    this->name = name;
    this->time = time;
    this->weekdays = weekdays;
    this->percentage = percentage;
}

/* Destructor */
CourseData::~CourseData() {}

/* Getters */
string CourseData::getCrn() {
    return this->crn;
}

string CourseData::getLocation() {
    return this->location;
}

string CourseData::getName() {
    return this->name;
}

string CourseData::getTime() {
    return this->time;
}

string CourseData::getType() {
    return this->type;
}

string CourseData::getPercentage() {
    return this->percentage;
}

string CourseData::getWeekdays() {
    return this->weekdays;
}

/* Setters */
void CourseData::setCrn(string crn) {
    this->crn = crn;
}

void CourseData::setLocation(string loc) {
    this->location = loc;
}

void CourseData::setName(string name) {
    this->name = name;
}

void CourseData::setTime(string time) {
    this->time = time;
}

void CourseData::setType(string type) {
    this->type = type;
}

void CourseData::setPercentage(string percentage) {
    this->percentage = percentage;
}

void CourseData::setWeekdays(string weekdays) {
    this->weekdays = weekdays;
}

void CourseData::print() {
    cout << this->name << endl;
    cout << "Type:        " << this->type << endl;
    cout << "Location:    " << this->location << endl;
    cout << "Time:        " << this->time << endl;
    cout << "Weekdays:    " << this->weekdays << endl;
    cout << "Percentage:  " << this->percentage << endl;
    cout << "CRN:         " << this->crn << endl;
}
