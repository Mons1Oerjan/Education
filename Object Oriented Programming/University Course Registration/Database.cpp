#include "Database.h"
#include "Lecture.h"
#include "Lab.h"
#include "Tutorial.h"
#include "WorkTerm.h"
#include "Thesis.h"
#include "json.hpp"
#include <iostream>
#include <fstream>

#define MAX_REGISTERED_COURSES 5
#define NUM_COURSES_THESIS 4

using namespace std;
using json = nlohmann::json;

/*
 * Constructor that initializes the database and seeds data
 */
Database::Database() {
    this->num_registered_courses = 0;
    Database::seed();
}

/*
 * Destructor
 */
Database::~Database() {

}

/*
 * Retrieve all courses in the database
 */
vector<Course*> Database::findAll() {
    return this->courses;
}

/*
 * Find a course in the database with the given ID
 */
Course* Database::findById(string id) {
    for (vector<Course*>::iterator it = this->courses.begin(); it != this->courses.end(); ++it) {
        if ((*it)->getId() == id) {
            return (*it);
        }
    }

    cout << "Course with ID " << id << " not found." << endl;
    return nullptr;
}

/*
 * Check if the database contains the course with the given ID
 */
bool Database::containsCourse(string id) {
    for (vector<Course*>::iterator it = this->courses.begin(); it != this->courses.end(); ++it) {
        if ((*it)->getId() == id) {
            return true;
        }
    }

    return false;
}

/*
 * Find a single course by the unique CRN number
 */
Course* Database::findByCrn(string crn) {
    // iterate over each course:
    for (vector<Course*>::iterator c = this->courses.begin(); c != this->courses.end(); ++c) {
        // search for the CRN in each lecture:
        vector<Lecture*> lecs = (*c)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            if ((*lec)->getCrn() == crn) {
                return (*c);
            }
        }

        // search for the CRN in each lab:
        vector<Lab*> labs = (*c)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            if ((*lab)->getCrn() == crn) {
                return (*c);
            }
        }

        // search for the CRN in each tutorial:
        vector<Tutorial*> tuts = (*c)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            if ((*tut)->getCrn() == crn) {
                return (*c);
            }
        }

        // search for the CRN in the workterm:
        if ((*c)->getWorkTerm()) {
            if ((*c)->getWorkTerm()->getCrn() == crn) {
                return (*c);
            }
        }

        // search for the CRN in the thesis:
        if ((*c)->getThesis()) {
            if ((*c)->getThesis()->getCrn() == crn) {
                return (*c);
            }
        }
    }

    cout << "Course with CRN " << crn << " not found." << endl;
    return nullptr;
}

vector<Course*> Database::findByName(string name) {
    vector<Course*> coursesWithName;

    // iterate over each course:
    for (vector<Course*>::iterator c = this->courses.begin(); c != this->courses.end(); ++c) {
        // search for the name in each lecture:
        vector<Lecture*> lecs = (*c)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            size_t found = (*lec)->getName().find(name);
            if (found != string::npos) {
                coursesWithName.push_back((*c));
            }
        }

        // search for the name in each lab:
        vector<Lab*> labs = (*c)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            size_t found = (*lab)->getName().find(name);
            if (found != string::npos) {
                coursesWithName.push_back((*c));
            }
        }

        // search for the name in each tutorial:
        vector<Tutorial*> tuts = (*c)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            size_t found = (*tut)->getName().find(name);
            if (found != string::npos) {
                coursesWithName.push_back((*c));
            }
        }

        // search for the name in the workterm:
        if ((*c)->getWorkTerm()) {
            size_t found = (*c)->getWorkTerm()->getName().find(name);
            if (found != string::npos) {
                coursesWithName.push_back((*c));
            }
        }

        // search for the name in the thesis:
        if ((*c)->getThesis()) {
            size_t found = (*c)->getThesis()->getName().find(name);
            if (found != string::npos) {
                coursesWithName.push_back((*c));
            }
        }
    }

    return coursesWithName;
}

vector<Course*> Database::findByType(string type) {
    vector<Course*> coursesWithType;

    // iterate over each course:
    for (vector<Course*>::iterator c = this->courses.begin(); c != this->courses.end(); ++c) {
        // search for the type in each lecture:
        vector<Lecture*> lecs = (*c)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            size_t found = (*lec)->getType().find(type);
            if (found != string::npos) {
                coursesWithType.push_back((*c));
            }
        }

        // search for the type in each lab:
        vector<Lab*> labs = (*c)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            size_t found = (*lab)->getType().find(type);
            if (found != string::npos) {
                coursesWithType.push_back((*c));
            }
        }

        // search for the type in each tutorial:
        vector<Tutorial*> tuts = (*c)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            size_t found = (*tut)->getType().find(type);
            if (found != string::npos) {
                coursesWithType.push_back((*c));
            }
        }

        // search for the type in the workterm:
        if ((*c)->getWorkTerm()) {
            size_t found = (*c)->getWorkTerm()->getType().find(type);
            if (found != string::npos) {
                coursesWithType.push_back((*c));
            }
        }

        // search for the type in the thesis:
        if ((*c)->getThesis()) {
            size_t found = (*c)->getThesis()->getType().find(type);
            if (found != string::npos) {
                coursesWithType.push_back((*c));
            }
        }
    }

    return coursesWithType;
}

vector<Course*> Database::findByLocation(string loc) {
    vector<Course*> coursesWithLocation;

    // iterate over each course:
    for (vector<Course*>::iterator c = this->courses.begin(); c != this->courses.end(); ++c) {
        // search for the location in each lecture:
        vector<Lecture*> lecs = (*c)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            size_t found = (*lec)->getLocation().find(loc);
            if (found != string::npos) {
                coursesWithLocation.push_back((*c));
            }
        }

        // search for the location in each lab:
        vector<Lab*> labs = (*c)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            size_t found = (*lab)->getLocation().find(loc);
            if (found != string::npos) {
                coursesWithLocation.push_back((*c));
            }
        }

        // search for the location in each tutorial:
        vector<Tutorial*> tuts = (*c)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            size_t found = (*tut)->getLocation().find(loc);
            if (found != string::npos) {
                coursesWithLocation.push_back((*c));
            }
        }

        // search for the location in the workterm:
        if ((*c)->getWorkTerm()) {
            size_t found = (*c)->getWorkTerm()->getLocation().find(loc);
            if (found != string::npos) {
                coursesWithLocation.push_back((*c));
            }
        }

        // search for the location in the thesis:
        if ((*c)->getThesis()) {
            size_t found = (*c)->getThesis()->getLocation().find(loc);
            if (found != string::npos) {
                coursesWithLocation.push_back((*c));
            }
        }
    }

    return coursesWithLocation;
}

vector<Course*> Database::findByTime(string t) {
    vector<Course*> coursesWithTime;

    // iterate over each course:
    for (vector<Course*>::iterator course = this->courses.begin(); course != this->courses.end(); ++course) {
        // search for the time in each lecture:
        vector<Lecture*> lecs = (*course)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            if ((*lec)->getTime() == t) {
                coursesWithTime.push_back((*course));
            }
        }

        // search for the time in each lab:
        vector<Lab*> labs = (*course)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            if ((*lab)->getTime() == t) {
                coursesWithTime.push_back((*course));
            }
        }

        // search for the time in each tutorial:
        vector<Tutorial*> tuts = (*course)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            if ((*tut)->getTime() == t) {
                coursesWithTime.push_back((*course));
            }
        }

        // search for the time in the workterm:
        if ((*course)->getWorkTerm()) {
            if ((*course)->getWorkTerm()->getTime() == t) {
                coursesWithTime.push_back((*course));
            }
        }

        // search for the time in the thesis:
        if ((*course)->getThesis()) {
            if ((*course)->getThesis()->getTime() == t) {
                coursesWithTime.push_back((*course));
            }
        }
    }

    return coursesWithTime;
}

vector<Course*> Database::findByWeekdays(string wd) {
    vector<Course*> coursesWithWeekdays;

    // iterate over each course:
    for (vector<Course*>::iterator c = this->courses.begin(); c != this->courses.end(); ++c) {
        // search for the weekdays in each lecture:
        vector<Lecture*> lecs = (*c)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            size_t found = (*lec)->getWeekdays().find(wd);
            if (found != string::npos) {
                coursesWithWeekdays.push_back((*c));
            }
        }

        // search for the weekdays in each lab:
        vector<Lab*> labs = (*c)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            size_t found = (*lab)->getWeekdays().find(wd);
            if (found != string::npos) {
                coursesWithWeekdays.push_back((*c));
            }
        }

        // search for the weekdays in each tutorial:
        vector<Tutorial*> tuts = (*c)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            size_t found = (*tut)->getWeekdays().find(wd);
            if (found != string::npos) {
                coursesWithWeekdays.push_back((*c));
            }
        }

        // search for the weekdays in the workterm:
        if ((*c)->getWorkTerm()) {
            size_t found = (*c)->getWorkTerm()->getWeekdays().find(wd);
            if (found != string::npos) {
                coursesWithWeekdays.push_back((*c));
            }
        }

        // search for the weekdays in the thesis:
        if ((*c)->getThesis()) {
            size_t found = (*c)->getThesis()->getWeekdays().find(wd);
            if (found != string::npos) {
                coursesWithWeekdays.push_back((*c));
            }
        }
    }

    return coursesWithWeekdays;
}

vector<Course*> Database::findByPercentage(string pct) {
    vector<Course*> coursesWithPercentage;

    // iterate over each course:
    for (vector<Course*>::iterator c = this->courses.begin(); c != this->courses.end(); ++c) {
        // search for the pct in each lecture:
        vector<Lecture*> lecs = (*c)->getLectures();
        for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
            size_t found = (*lec)->getPercentage().find(pct);
            if (found != string::npos) {
                coursesWithPercentage.push_back((*c));
            }
        }

        // search for the pct in each lab:
        vector<Lab*> labs = (*c)->getLabs();
        for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
            size_t found = (*lab)->getPercentage().find(pct);
            if (found != string::npos) {
                coursesWithPercentage.push_back((*c));
            }
        }

        // search for the pct in each tutorial:
        vector<Tutorial*> tuts = (*c)->getTutorials();
        for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
            size_t found = (*tut)->getPercentage().find(pct);
            if (found != string::npos) {
                coursesWithPercentage.push_back((*c));
            }
        }

        // search for the pct in the workterm:
        if ((*c)->getWorkTerm()) {
            size_t found = (*c)->getWorkTerm()->getPercentage().find(pct);
            if (found != string::npos) {
                coursesWithPercentage.push_back((*c));
            }
        }

        // search for the pct in the thesis:
        if ((*c)->getThesis()) {
            size_t found = (*c)->getThesis()->getPercentage().find(pct);
            if (found != string::npos) {
                coursesWithPercentage.push_back((*c));
            }
        }
    }

    return coursesWithPercentage;
}

/*
 * Register for a course
 */
void Database::registerCourse(string crn) {
    vector<string> reg_courses = Database::getRegisteredCourses();

    // check if the course registration limit has been reached:
    if (this->num_registered_courses >= MAX_REGISTERED_COURSES) {
        cout << "Warning: You can't register for more courses." << endl;
        return;
    }


    for (vector<string>::iterator i = reg_courses.begin(); i != reg_courses.end(); ++i) {
        Course* c = Database::findByCrn((*i));

        // check if already registered for a workterm:
        if (c->getWorkTerm()) {
            cout << "Warning: You are registered for a workterm." << endl;
            return;
        }

        // check if course is already registered:
        if ((*i) == crn) {
            cout << "Warning: You are already registered for this course." << endl;
            return;
        }
    }

    // get the course with the inputted CRN number:
    Course* c = Database::findByCrn(crn);

    if (!c) {
        cout << "Warning: The inputted CRN does not exist in the database." << endl;
        return;
    }

    if (c->getThesis()) {
        // the course is a thesis
        if (reg_courses.size() != NUM_COURSES_THESIS) {
            cout << "Warning: You must be registered in " << NUM_COURSES_THESIS << " courses before registering for a Thesis." << endl;
            return;
        }

        // register:
        this->registered_courses.push_back(crn);
        this->num_registered_courses += 1;
    }
    else if (c->getWorkTerm()) {
        // the course is a workterm
        if (reg_courses.size() > 0) {
            cout << "Warning: You must be registered in 0 courses before registering for a WorkTerm." << endl;
            return;
        }

        // register:
        this->registered_courses.push_back(crn);
        this->num_registered_courses += 1;
    }
    else {
        // the course is either a lec, lab, or tut:
        vector<Lecture*> lectures = c->getLectures();
        vector<Lab*> labs = c->getLabs();
        vector<Tutorial*> tutorials = c->getTutorials();

        for (vector<Lecture*>::iterator i = lectures.begin(); i != lectures.end(); ++i) {
            if ((*i)->getCrn() == crn) {
                // the course is a lecture. Check if this lec has a lab and tut:
                if (labs.size() > 0) {
                    // this course has associated labs
                    string lab_crn;
                    cout << "Register for one of the following labs:" << endl;

                    for (vector<Lab*>::iterator j = labs.begin(); j != labs.end(); ++j) {
                        (*j)->print();
                    }

                    cout << "Enter lab CRN: " << endl;
                    cin >> lab_crn;

                    // validate input:
                    bool should_add = false;
                    for (vector<Lab*>::iterator j = labs.begin(); j != labs.end(); ++j) {
                        if ((*j)->getCrn() == lab_crn) {
                            should_add = true;
                            break;
                        }
                    }

                    // add lab only if it exists and has a relationship with the selected lecture:
                    if (should_add) {
                        this->registered_courses.push_back(lab_crn);
                    } else {
                        cout << "Warning: Couldn't find inputted CRN amongst the associated labs." << endl;
                        return;
                    }
                }
                if (tutorials.size() > 0) {
                    // this course has associated tutorials
                    string tut_crn;
                    cout << "Register for one of the following tutorials:" << endl;
                    for (vector<Tutorial*>::iterator j = tutorials.begin(); j != tutorials.end(); ++j) {
                        (*j)->print();
                    }
                    cout << "Enter tutorial CRN: " << endl;
                    cin >> tut_crn;

                    // validate input:
                    bool should_add = false;
                    for (vector<Tutorial*>::iterator j = tutorials.begin(); j != tutorials.end(); ++j) {
                        if ((*j)->getCrn() == tut_crn) {
                            should_add = true;
                            break;
                        }
                    }

                    // add lab only if it exists and has a relationship with the selected lecture:
                    if (should_add) {
                        this->registered_courses.push_back(tut_crn);
                    } else {
                        cout << "Warning: Couldn't find inputted CRN amongst the associated tutorials." << endl;
                        return;
                    }
                }
                this->registered_courses.push_back(crn);
                this->num_registered_courses += 1;
            }
        }

        for (vector<Lab*>::iterator i = labs.begin(); i != labs.end(); ++i) {
            if ((*i)->getCrn() == crn) {
                // the course is a lab. automatically add the corresponding lecture (if only one lecture):
                if (lectures.size() == 1) {
                    cout << "Automatically adding the lecture with CRN " << (*lectures.begin())->getCrn() << endl;
                    this->registered_courses.push_back((*lectures.begin())->getCrn());
                }
                else {
                    // more than 1 lecture. Ask the user to input the lecture CRN:
                    string lec_crn;
                    cout << "This lab has multiple lectures. Please select one of these lectures:" << endl;
                    for (vector<Lecture*>::iterator j = lectures.begin(); j != lectures.end(); ++j) {
                        (*j)->print();
                    }
                    cout << "Enter lecture CRN: ";
                    cin >> lec_crn;
                    this->registered_courses.push_back(lec_crn);
                }
                this->registered_courses.push_back(crn);
                this->num_registered_courses += 1;
            }
        }

        for (vector<Tutorial*>::iterator i = tutorials.begin(); i != tutorials.end(); ++i) {
            if ((*i)->getCrn() == crn) {
                // the course is a tutorial
                if (lectures.size() == 1) {
                    // automatically add the lecture if there's only one lecture
                    cout << "Automatically adding the lecture with CRN " << (*lectures.begin())->getCrn() << endl;
                    this->registered_courses.push_back((*lectures.begin())->getCrn());
                }
                else {
                    // more than 1 lecture. Ask the user to input the lecture CRN:
                    string lec_crn;
                    cout << "This tutorial has multiple lectures. Please select one of these lectures:" << endl;
                    for (vector<Lecture*>::iterator j = lectures.begin(); j != lectures.end(); ++j) {
                        (*j)->print();
                    }
                    cout << "Enter lecture CRN: ";
                    cin >> lec_crn;
                    this->registered_courses.push_back(lec_crn);
                }
                if (labs.size() == 1) {
                    // automatically add the lab if there's only one lab
                    cout << "Automatically adding the lab with CRN " << (*labs.begin())->getCrn() << endl;
                    this->registered_courses.push_back((*labs.begin())->getCrn());
                }
                else {
                    // more than 1 lab. Ask the user to input the lab CRN:
                    string lab_crn;
                    cout << "This tutorial has multiple labs. Please select one of these labs:" << endl;
                    for (vector<Lab*>::iterator j = labs.begin(); j != labs.end(); ++j) {
                        (*j)->print();
                    }
                    cout << "Enter lab CRN: ";
                    cin >> lab_crn;
                    this->registered_courses.push_back(lab_crn);
                }
                this->registered_courses.push_back(crn);
                this->num_registered_courses += 1;
            }
        }
    }
}

/*
 * Drop the selected course
 */
void Database::dropCourse(string crn) {
    // get the course with the inputted CRN number:
    Course* c = Database::findByCrn(crn);
    vector<string> reg_courses = this->registered_courses;
    bool isRegistered = false;
    int index = 0;

    // check if the course exists in the database:
    if (!c) {
        cout << "Warning: Tried to drop a course that does not exist." << endl;
        return;
    }

    // check if the course is a registered course:
    for (vector<string>::iterator i = reg_courses.begin(); i != reg_courses.end(); ++i) {
        if ((*i) == crn) {
            isRegistered = true;
            break;
        }
        index++;
    }

    if (!isRegistered) {
        cout << "Warning: Tried to drop a course that the user is not registered in." << endl;
        return;
    }

    // drop the course:
    this->registered_courses.erase(this->registered_courses.begin()+index);
    this->num_registered_courses -= 1;
    cout << "Successfully dropped CRN " << crn << endl;
}

/*
 * get all courses the user has registered for
 */
vector<string> Database::getRegisteredCourses() {
    return this->registered_courses;
}

/*
 * get the number of courses that the user has registered for
 */
int Database::getNumRegisteredCourses() {
    return this->num_registered_courses;
}

/*
 * Database seed script that runs on DB initialization.
 * Fetches data from courses.json and stores it in the DB.
 */
void Database::seed() {
    ifstream jsonFile;
    string line = "";
    string combine = "";
    jsonFile.open("courses.json");

    if (jsonFile.is_open()) {
        while (getline(jsonFile, line)) {
            combine += line;
        }
    }

    json jsonContent = json::parse(combine);
    combine = "";
    line = "";
    jsonFile.close();

    // store JSON in a vector of courses:
    for (json::iterator it = jsonContent.begin(); it != jsonContent.end(); ++it) {
        json j = *it;
        string courseName = j["name"];
        string courseId = courseName.substr(0, 9); // e.g. CSCI 1100
        bool courseExists = Database::containsCourse(courseId);

        if (courseExists) {
            // Course already exists in the database. Append to the existing course:
            Course* currentCourse = Database::findById(courseId);

            if (j["type"] == "Lec") {
                Lecture *lec = new Lecture(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                currentCourse->addLecture(lec);
            }
            else if (j["type"] == "Lab") {
                Lab *lab = new Lab(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                currentCourse->addLab(lab);
            }
            else if (j["type"] == "Tut") {
                Tutorial *tut = new Tutorial(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                currentCourse->addTutorial(tut);
            }
            else if (j["type"] == "WkT") {
                WorkTerm *wkt = new WorkTerm(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                currentCourse->setWorkTerm(wkt);
            }
            else if (j["type"] == "Ths") {
                Thesis *ths = new Thesis(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                currentCourse->setThesis(ths);
            }
        } else {
            // Course does not exist in the database. Create a new course:
            Course* c = new Course(courseId);
            if (j["type"] == "Lec") {
                Lecture *lec = new Lecture(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                c->addLecture(lec);
            }
            else if (j["type"] == "Lab") {
                Lab *lab = new Lab(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                c->addLab(lab);
            }
            else if (j["type"] == "Tut") {
                Tutorial *tut = new Tutorial(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                c->addTutorial(tut);
            }
            else if (j["type"] == "WkT") {
                WorkTerm *wkt = new WorkTerm(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                c->setWorkTerm(wkt);
            }
            else if (j["type"] == "Ths") {
                Thesis *ths = new Thesis(j["crn"], j["location"], j["name"], j["time"], j["weekdays"], j["percent"]);
                c->setThesis(ths);
            }

            this->courses.push_back(c);
        }
    }
}
