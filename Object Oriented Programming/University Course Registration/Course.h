#ifndef COURSE_H
#define COURSE_H
#include "Lecture.h"
#include "Lab.h"
#include "Tutorial.h"
#include "WorkTerm.h"
#include "Thesis.h"
#include <iostream>
#include <vector>
using namespace std;

class Course {
    private:
        string id;
        vector<Lecture*> lectures;
        vector<Lab*> labs;
        vector<Tutorial*> tutorials;
        WorkTerm *wkt;
        Thesis *ths;
    public:
        Course(string id);
        Course(string id, vector<Lecture*> lecs);
        Course(string id, vector<Lecture*> lecs, vector<Lab*> labs);
        Course(string id, vector<Lecture*> lecs, vector<Lab*> labs, vector<Tutorial*> tuts);
        Course(string id, WorkTerm *wkt);
        Course(string id, Thesis *ths);
        ~Course();
        string getId();
        vector<Lecture*> getLectures();
        vector<Lab*> getLabs();
        vector<Tutorial*> getTutorials();
        WorkTerm* getWorkTerm();
        Thesis* getThesis();
        void setId(string id);
        void setLectures(vector<Lecture*> lectures);
        void setLab(vector<Lab*> labs);
        void setTutorial(vector<Tutorial*> tutorials);
        void setWorkTerm(WorkTerm *wkt);
        void setThesis(Thesis *ths);
        void addLecture(Lecture* lec);
        void addLab(Lab* lab);
        void addTutorial(Tutorial* tut);
        void print();
};

#endif
