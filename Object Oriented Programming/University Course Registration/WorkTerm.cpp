#include "WorkTerm.h"

WorkTerm::WorkTerm(): CourseData() {
    this->setType("WkT");
}

WorkTerm::WorkTerm(string crn, string loc, string name, string t, string wd, string pct): CourseData() {
    this->setCrn(crn);
    this->setLocation(loc);
    this->setName(name);
    this->setType("WkT");
    this->setTime(t);
    this->setWeekdays(wd);
    this->setPercentage(pct);
}

WorkTerm::~WorkTerm() {}
