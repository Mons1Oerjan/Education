#include "Course.h"

/* Constructors */
Course::Course(string id) {
    this->id = id;
    this->wkt = NULL;
    this->ths = NULL;
}

Course::Course(string id, vector<Lecture*> lecs) {
    this->id = id;
    this->lectures = lecs;
    this->wkt = NULL;
    this->ths = NULL;
}

Course::Course(string id, vector<Lecture*> lecs, vector<Lab*> labs) {
    this->id = id;
    this->lectures = lecs;
    this->labs = labs;
    this->wkt = NULL;
    this->ths = NULL;
}

Course::Course(string id, vector<Lecture*> lecs, vector<Lab*> labs, vector<Tutorial*> tuts) {
    this->id = id;
    this->lectures = lecs;
    this->labs = labs;
    this->tutorials = tuts;
    this->wkt = NULL;
    this->ths = NULL;
}

Course::Course(string id, WorkTerm *wkt) {
    this->id = id;
    this->wkt = wkt;
    this->ths = NULL;
}

Course::Course(string id, Thesis *ths) {
    this->id = id;
    this->ths = ths;
    this->wkt = NULL;
}

/* Destructor */
Course::~Course() {
    this->lectures.clear();
    this->labs.clear();
    this->tutorials.clear();
    delete this->wkt;
    delete this->ths;
    this->wkt = NULL;
    this->ths = NULL;
}

/* Getters */

string Course::getId() {
    return this->id;
}

vector<Lecture*> Course::getLectures() {
    return this->lectures;
}

vector<Lab*> Course::getLabs() {
    return this->labs;
}

vector<Tutorial*> Course::getTutorials() {
    return this->tutorials;
}

WorkTerm* Course::getWorkTerm() {
    return this->wkt;
}

Thesis* Course::getThesis() {
    return this->ths;
}

/* Setters */
void Course::setId(string id) {
    this->id = id;
}

void Course::setLectures(vector<Lecture*> lecs) {
    this->lectures = lecs;
}

void Course::setLab(vector<Lab*> labs) {
    this->labs = labs;
}

void Course::setTutorial(vector<Tutorial*> tuts) {
    this->tutorials = tuts;
}

void Course::setWorkTerm(WorkTerm *wkt) {
    this->wkt = wkt;
}

void Course::setThesis(Thesis *ths) {
    this->ths = ths;
}

/* Adders */
void Course::addLecture(Lecture* lec) {
    this->lectures.push_back(lec);
}

void Course::addLab(Lab* lab) {
    this->labs.push_back(lab);
}

void Course::addTutorial(Tutorial* tut) {
    this->tutorials.push_back(tut);
}

void Course::print() {
    cout << this->getId() << endl;
    for (vector<Lecture*>::iterator l = this->lectures.begin(); l != this->lectures.end(); ++l) {
        (*l)->print();
    }
    for (vector<Lab*>::iterator l = this->labs.begin(); l != this->labs.end(); ++l) {
        (*l)->print();
    }
    for (vector<Tutorial*>::iterator l = this->tutorials.begin(); l != this->tutorials.end(); ++l) {
        (*l)->print();
    }
    if (this->wkt) {
        this->wkt->print();
    }
    if (this->ths) {
        this->ths->print();
    }

    cout << endl;
}
