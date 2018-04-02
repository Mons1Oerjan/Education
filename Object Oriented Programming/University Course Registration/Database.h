#ifndef DATABASE_H
#define DATABASE_H

#include "Course.h"
#include <vector>

class Database {
    private:
        vector<Course*> courses;
        vector<string> registered_courses;
        int num_registered_courses;
        void seed();
    public:
        Database();
        ~Database();
        vector<Course*> findAll();
        Course* findById(string id);
        bool containsCourse(string id);
        Course* findByCrn(string crn);
        vector<Course*> findByName(string name);
        vector<Course*> findByType(string type);
        vector<Course*> findByLocation(string loc);
        vector<Course*> findByTime(string t);
        vector<Course*> findByWeekdays(string wd);
        vector<Course*> findByPercentage(string pct);
        void registerCourse(string crn);
        void dropCourse(string crn);
        vector<string> getRegisteredCourses();
        int getNumRegisteredCourses();
};

#endif
