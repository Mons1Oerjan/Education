#include "Thesis.h"

Thesis::Thesis(): CourseData() {
    this->setType("Ths");
}

Thesis::Thesis(string crn, string loc, string name, string t, string wd, string pct): CourseData() {
    this->setCrn(crn);
    this->setLocation(loc);
    this->setName(name);
    this->setType("Ths");
    this->setTime(t);
    this->setWeekdays(wd);
    this->setPercentage(pct);
}

Thesis::~Thesis() {}
