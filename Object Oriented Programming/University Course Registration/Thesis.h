#ifndef THESIS_H
#define THESIS_H
#include "CourseData.h"

class Thesis: public CourseData {
private:

public:
    Thesis();
    Thesis(string crn, string loc, string name, string t, string wd, string pct);
    ~Thesis();
};

#endif
