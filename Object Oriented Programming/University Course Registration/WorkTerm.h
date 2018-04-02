#ifndef WORKTERM_H
#define WORKTERM_H
#include "CourseData.h"

class WorkTerm: public CourseData {
private:

public:
    WorkTerm();
    WorkTerm(string crn, string loc, string name, string t, string wd, string pct);
    ~WorkTerm();
};

#endif
