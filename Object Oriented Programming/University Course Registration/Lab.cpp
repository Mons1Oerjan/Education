#include "Lab.h"

Lab::Lab(): CourseData() {
    this->setType("Lab");
}

Lab::Lab(string crn, string loc, string name, string t, string wd, string pct): CourseData() {
    this->setCrn(crn);
    this->setLocation(loc);
    this->setName(name);
    this->setType("Lab");
    this->setTime(t);
    this->setWeekdays(wd);
    this->setPercentage(pct);
}

Lab::~Lab() {}
