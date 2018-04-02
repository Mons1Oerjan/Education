#include "Tutorial.h"

Tutorial::Tutorial(): CourseData() {
    this->setType("Tut");
}

Tutorial::Tutorial(string crn, string loc, string name, string t, string wd, string pct): CourseData() {
    this->setCrn(crn);
    this->setLocation(loc);
    this->setName(name);
    this->setType("Tut");
    this->setTime(t);
    this->setWeekdays(wd);
    this->setPercentage(pct);
}

Tutorial::~Tutorial() {}
