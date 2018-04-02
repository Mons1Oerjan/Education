#ifndef TUTORIAL_H
#define TUTORIAL_H
#include "CourseData.h"

class Tutorial: public CourseData {
private:

public:
    Tutorial();
    Tutorial(string crn, string loc, string name, string t, string wd, string pct);
    ~Tutorial();
};

#endif
