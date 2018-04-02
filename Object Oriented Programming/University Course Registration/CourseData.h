#ifndef COURSEDATA_H
#define COURSEDATA_H
#include <iostream>
using namespace std;

class CourseData {
    private:
        string crn;
        string location;
        string type;
        string name;
        string weekdays;
        string time;
        string percentage;
    public:
        CourseData();
        CourseData(string crn, string loc, string type, string name, string time, string weekdays, string percentage);
        ~CourseData();
        string getCrn();
        string getLocation();
        string getType();
        string getName();
        string getWeekdays();
        string getTime();
        string getPercentage();
        void setCrn(string crn);
        void setLocation(string loc);
        void setType(string type);
        void setName(string name);
        void setWeekdays(string weekdays);
        void setTime(string time);
        void setPercentage(string percentage);
        void print();
};

#endif
