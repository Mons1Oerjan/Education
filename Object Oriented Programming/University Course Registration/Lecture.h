#ifndef LECTURE_H
#define LECTURE_H
#include "CourseData.h"

class Lecture: public CourseData {
private:

public:
    Lecture();
    Lecture(string crn, string loc, string name, string t, string wd, string pct);
    ~Lecture();
};

#endif
