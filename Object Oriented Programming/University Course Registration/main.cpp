#include "Database.h"
#include "Course.h"
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    Database *db = new Database();
    vector<Course*> courseList = db->findAll();
    bool runProgram = true;

    cout << "Welcome to the Course Registration System." << endl;

    while (runProgram) {
        string input;
        cout << "Your commands are:" << endl;
        cout << "\t- all: Display all courses in the database" << endl;
        cout << "\t- show: Display a single course given its course ID, e.g. CSCI 1100" << endl;
        cout << "\t- filter: filter by specific course info, e.g. CRN, name, time, weekday, or location" << endl;
        cout << "\t- register: register for a course" << endl;
        cout << "\t- show_registered: display the CRNs you have currently registered for" << endl;
        cout << "\t- drop: Drop a course by CRN number" << endl;
        cout << "\t- exit: exit the program" << endl;
        cout << "Please enter your command:" << endl;
        cin >> input;

        if (input == "all") {
            // display all courses in the database:
            for (vector<Course*>::iterator c = courseList.begin(); c != courseList.end(); ++c) {
                (*c)->print();
                cout << endl;
            }
        }
        else if (input == "show") {
            // display a single course by the course ID (e.g. CSCI 1100)
            string courseId = "CSCI ";
            int courseNumber;
            cout << "Please enter the course ID (e.g. CSCI 1100): " << endl;
            cout << courseId;
            cin >> courseNumber;
            courseId += to_string(courseNumber);

            if (db->containsCourse(courseId)) {
                // this course exists in the database. display the course:
                Course* c_id = db->findById(courseId);
                c_id->print();
            } else {
                cout << "We couldn't find this course in the database. Please try again." <<endl;
            }
        }
        else if (input == "filter") {
            string filterGroup;
            cout << "Select which group to filter by. Your options are:" << endl;
            cout << "\t- CRN" << endl;
            cout << "\t- Name" << endl;
            cout << "\t- Type" << endl;
            cout << "\t- Location" << endl;
            cout << "\t- Time" << endl;
            cout << "\t- Weekdays" << endl;
            cout << "\t- Percentage" << endl;
            cout << "Enter filter group: ";
            cin >> filterGroup;

            if (filterGroup == "CRN" || filterGroup == "crn" || filterGroup == "Crn") {
                int crn_num;
                cout << "Enter CRN number (e.g. 14727): ";
                cin >> crn_num;
                string crn = to_string(crn_num);

                Course* c_crn = db->findByCrn(crn);
                if (c_crn) {
                    // we now have the course. Find the item with the CRN:
                    bool found = false;
                    while (!found) {
                        // search in lectures:
                        vector<Lecture*> lecs = c_crn->getLectures();
                        for (vector<Lecture*>::iterator l = lecs.begin(); l != lecs.end(); ++l) {
                            if ((*l)->getCrn() == crn) {
                                found = true;
                                (*l)->print();
                                break;
                            }
                        }
                        // search in labs:
                        vector<Lab*> labs = c_crn->getLabs();
                        for (vector<Lab*>::iterator l = labs.begin(); l != labs.end(); ++l) {
                            if ((*l)->getCrn() == crn) {
                                found = true;
                                (*l)->print();
                                break;
                            }
                        }
                        // search in tutorials:
                        vector<Tutorial*> tuts = c_crn->getTutorials();
                        for (vector<Tutorial*>::iterator l = tuts.begin(); l != tuts.end(); ++l) {
                            if ((*l)->getCrn() == crn) {
                                found = true;
                                (*l)->print();
                                break;
                            }
                        }
                        // search in workterm:
                        if (c_crn->getWorkTerm()) {
                            if (c_crn->getWorkTerm()->getCrn() == crn) {
                                found = true;
                                c_crn->getWorkTerm()->print();
                                break;
                            }
                        }
                        // search in thesis:
                        if (c_crn->getThesis()) {
                            if (c_crn->getThesis()->getCrn() == crn) {
                                found = true;
                                c_crn->getThesis()->print();
                                break;
                            }
                        }
                    }
                }
            }
            else if (filterGroup == "Name" || filterGroup == "name") {
                string course_name;
                cout << "Enter course name (e.g. Social Computing): ";
                cin >> course_name;
                vector<Course*> courses_name = db->findByName(course_name);

                for (vector<Course*>::iterator c = courses_name.begin(); c != courses_name.end(); ++c) {
                    (*c)->print();
                }
            }
            else if (filterGroup == "Type" || filterGroup == "type") {
                string courseType;
                cout << "Enter course type (e.g. Lec, Lab, Tut, WkT, Ths): ";
                cin >> courseType;
                vector<Course*> courses_type = db->findByType(courseType);

                if (courseType == "Lec") {
                    // print all lectures in courses_type:
                    for (vector<Course*>::iterator c = courses_type.begin(); c != courses_type.end(); ++c) {
                        vector<Lecture*> lecs = (*c)->getLectures();
                        for (vector<Lecture*>::iterator l = lecs.begin(); l != lecs.end(); ++l) {
                            (*l)->print();
                        }
                    }
                }
                else if (courseType == "Lab") {
                    // print all labs in courses_type:
                    for (vector<Course*>::iterator c = courses_type.begin(); c != courses_type.end(); ++c) {
                        vector<Lab*> labs = (*c)->getLabs();
                        for (vector<Lab*>::iterator l = labs.begin(); l != labs.end(); ++l) {
                            (*l)->print();
                        }
                    }
                }
                else if (courseType == "Tut") {
                    // print all tutorials in courses_type:
                    for (vector<Course*>::iterator c = courses_type.begin(); c != courses_type.end(); ++c) {
                        vector<Tutorial*> tuts = (*c)->getTutorials();
                        for (vector<Tutorial*>::iterator l = tuts.begin(); l != tuts.end(); ++l) {
                            (*l)->print();
                        }
                    }
                }
                else if (courseType == "WkT") {
                    // print all workterms in courses_type:
                    for (vector<Course*>::iterator c = courses_type.begin(); c != courses_type.end(); ++c) {
                        (*c)->getWorkTerm()->print();
                    }
                }
                else if (courseType == "Ths") {
                    // print all thesises in courses_type:
                    for (vector<Course*>::iterator c = courses_type.begin(); c != courses_type.end(); ++c) {
                        (*c)->getThesis()->print();
                    }
                }
            }
            else if (filterGroup == "Location"  || filterGroup == "location") {
                string location;
                cout << "Enter course location (e.g. SIR JAMES DUNN): ";
                cin >> location;
                vector<Course*> courses_loc = db->findByLocation(location);

                for (vector<Course*>::iterator c = courses_loc.begin(); c != courses_loc.end(); ++c) {
                    // print lectures with inputted location:
                    vector<Lecture*> lecs = (*c)->getLectures();
                    for (vector<Lecture*>::iterator l = lecs.begin(); l != lecs.end(); ++l) {
                        if ((*l)->getLocation().find(location) != string::npos) {
                            (*l)->print();
                        }
                    }
                    // print labs with inputted location:
                    vector<Lab*> labs = (*c)->getLabs();
                    for (vector<Lab*>::iterator l = labs.begin(); l != labs.end(); ++l) {
                        if ((*l)->getLocation().find(location) != string::npos) {
                            (*l)->print();
                        }
                    }
                    // print tutorials with inputted location:
                    vector<Tutorial*> tuts = (*c)->getTutorials();
                    for (vector<Tutorial*>::iterator l = tuts.begin(); l != tuts.end(); ++l) {
                        if ((*l)->getLocation().find(location) != string::npos) {
                            (*l)->print();
                        }
                    }
                    // print workterm with inputted location:
                    if ((*c)->getWorkTerm()) {
                        if ((*c)->getWorkTerm()->getLocation().find(location) != string::npos) {
                            (*c)->getWorkTerm()->print();
                        }
                    }
                    // print thesis with inputted location:
                    if ((*c)->getThesis()) {
                        if ((*c)->getThesis()->getLocation().find(location) != string::npos) {
                            (*c)->getThesis()->print();
                        }
                    }
                }
            }
            else if (filterGroup == "Time"  || filterGroup == "time") {
                int start;
                int end;
                cout << "Enter start time (e.g. 1335): ";
                cin >> start;
                cout << "Enter end time (e.g. 1425): ";
                cin >> end;
                string startEndTime = to_string(start) + "-" + to_string(end);
                vector<Course*> courses_time = db->findByTime(startEndTime);

                for (vector<Course*>::iterator c = courses_time.begin(); c != courses_time.end(); ++c) {
                    // print lectures with time = t:
                    vector<Lecture*> lecs = (*c)->getLectures();
                    for (vector<Lecture*>::iterator lec = lecs.begin(); lec != lecs.end(); ++lec) {
                        if ((*lec)->getTime() == startEndTime) {
                            (*lec)->print();
                        }
                    }
                    // print labs with time = t:
                    vector<Lab*> labs = (*c)->getLabs();
                    for (vector<Lab*>::iterator lab = labs.begin(); lab != labs.end(); ++lab) {
                        if ((*lab)->getTime() == startEndTime) {
                            (*lab)->print();
                        }
                    }
                    // print tutorials with time = t:
                    vector<Tutorial*> tuts = (*c)->getTutorials();
                    for (vector<Tutorial*>::iterator tut = tuts.begin(); tut != tuts.end(); ++tut) {
                        if ((*tut)->getTime() == startEndTime) {
                            (*tut)->print();
                        }
                    }
                    // print the workterm if time = t:
                    if ((*c)->getWorkTerm()) {
                        if ((*c)->getWorkTerm()->getTime() == startEndTime) {
                            (*c)->getWorkTerm()->print();
                        }
                    }
                    // print the thesis if time = t:
                    if ((*c)->getThesis()) {
                        if ((*c)->getThesis()->getTime() == startEndTime) {
                            (*c)->getThesis()->print();
                        }
                    }
                }
            }
            else if (filterGroup == "Weekdays"  || filterGroup == "weekdays") {
                string weekdays;
                cout << "Enter weekdays (e.g. MTWF, T, R, MW): ";
                cin >> weekdays;
                vector<Course*> courses_wd = db->findByWeekdays(weekdays);

                for (vector<Course*>::iterator c = courses_wd.begin(); c != courses_wd.end(); ++c) {
                    // print lectures with inputted weekdays:
                    vector<Lecture*> lecs = (*c)->getLectures();
                    for (vector<Lecture*>::iterator l = lecs.begin(); l != lecs.end(); ++l) {
                        if ((*l)->getWeekdays() == weekdays) {
                            (*l)->print();
                        }
                    }
                    // print labs with inputted weekdays:
                    vector<Lab*> labs = (*c)->getLabs();
                    for (vector<Lab*>::iterator l = labs.begin(); l != labs.end(); ++l) {
                        if ((*l)->getWeekdays() == weekdays) {
                            (*l)->print();
                        }
                    }
                    // print tutorials with inputted weekdays:
                    vector<Tutorial*> tuts = (*c)->getTutorials();
                    for (vector<Tutorial*>::iterator l = tuts.begin(); l != tuts.end(); ++l) {
                        if ((*l)->getWeekdays() == weekdays) {
                            (*l)->print();
                        }
                    }
                    // print the workterm with inputted weekdays:
                    if ((*c)->getWorkTerm()) {
                        if ((*c)->getWorkTerm()->getWeekdays() == weekdays) {
                            (*c)->getWorkTerm()->print();
                        }
                    }
                    // print the thesis with inputted weekdays:
                    if ((*c)->getThesis()) {
                        if ((*c)->getThesis()->getWeekdays() == weekdays) {
                            (*c)->getThesis()->print();
                        }
                    }
                }
            }
            else if (filterGroup == "Percentage"  || filterGroup == "percentage") {
                string pct;
                cout << "Enter percentage (e.g. FULL, 98.8, WLIST): ";
                cin >> pct;
                vector<Course*> courses_pct = db->findByPercentage(pct);

                for (vector<Course*>::iterator c = courses_pct.begin(); c != courses_pct.end(); ++c) {
                    // print lectures with inputted percentage:
                    vector<Lecture*> lecs = (*c)->getLectures();
                    for (vector<Lecture*>::iterator l = lecs.begin(); l != lecs.end(); ++l) {
                        if ((*l)->getPercentage() == pct) {
                            (*l)->print();
                        }
                    }
                    // print labs with inputted percentage:
                    vector<Lab*> labs = (*c)->getLabs();
                    for (vector<Lab*>::iterator l = labs.begin(); l != labs.end(); ++l) {
                        if ((*l)->getPercentage() == pct) {
                            (*l)->print();
                        }
                    }
                    // print tutorials with inputted percentage:
                    vector<Tutorial*> tuts = (*c)->getTutorials();
                    for (vector<Tutorial*>::iterator l = tuts.begin(); l != tuts.end(); ++l) {
                        if ((*l)->getPercentage() == pct) {
                            (*l)->print();
                        }
                    }
                    // print the workterm with inputted percentage:
                    if ((*c)->getWorkTerm()) {
                        if ((*c)->getWorkTerm()->getPercentage() == pct) {
                            (*c)->getWorkTerm()->print();
                        }
                    }
                    // print the thesis with inputted percentage:
                    if ((*c)->getThesis()) {
                        if ((*c)->getThesis()->getPercentage() == pct) {
                            (*c)->getThesis()->print();
                        }
                    }
                }
            }
            else {
                cout << "Cannot filter by " << filterGroup << ". Please try again." << endl;
            }
        }
        else if (input == "Register" || input == "register") {
            int crn_register;
            cout << "Please enter the CRN: ";
            cin >> crn_register;
            string crn_register_str = to_string(crn_register);
            db->registerCourse(crn_register_str);
        }
        else if (input == "show_registered" || input == "Show_Registered") {
            vector<string> registeredCourses = db->getRegisteredCourses();
            cout << "You have registered in the following CRNs:" << endl;
            for (vector<string>::iterator i = registeredCourses.begin(); i != registeredCourses.end(); ++i) {
                cout << "\t- " << (*i) << endl;
            }
        }
        else if (input == "Drop" || input == "drop") {
            int crn_drop;
            cout << "Please enter the CRN to drop: ";
            cin >> crn_drop;
            string crn_drop_str = to_string(crn_drop);
            db->dropCourse(crn_drop_str);
        }
        else if (input == "exit" || input == "Exit") {
            runProgram = false;
        } else {
            cout << "Command not found. Please try again." << endl;
        }
    }

    cout << "Terminating..." << endl;
    delete db;
    courseList.clear();
    return 0;
}
