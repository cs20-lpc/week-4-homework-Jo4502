// TODO:  Course class methods implementation here.

#include "Course.hpp"

Course::Course(string name, string loc)
    : courseName(name), location(loc) {
}

string Course::getCourseName() const { 
    return courseName; 
}

string Course::getLocation() const { 
    return location; 
}

void Course::setCourseName(string name) { 
    courseName = name; 
}

void Course::setLocation(string loc) { 
    location = loc; 
}

void Course::display() const {
    cout << courseName << " " << location << endl;
}