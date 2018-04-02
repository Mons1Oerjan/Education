#include "Lecture.h"

Lecture::Lecture(): CourseData() {
    this->setType("Lec");
}

Lecture::Lecture(string crn, string loc, string name, string t, string wd, string pct): CourseData() {
    this->setCrn(crn);
    this->setLocation(loc);
    this->setName(name);
    this->setType("Lec");
    this->setTime(t);
    this->setWeekdays(wd);
    this->setPercentage(pct);
}

Lecture::~Lecture() {}
