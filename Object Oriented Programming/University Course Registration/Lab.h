#ifndef LAB_H
#define LAB_H
#include "CourseData.h"

class Lab: public CourseData {
private:

public:
    Lab();
    Lab(string crn, string loc, string name, string t, string wd, string pct);
    ~Lab();
};

#endif
