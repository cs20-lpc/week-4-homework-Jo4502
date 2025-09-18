// TODO:  Course class definitins go here.

#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>
using namespace std;


class Course {
private:
    string courseName;
    string location;

public:
    Course(string name = "",string loc = "");

    string getCourseName() const;
    string getLocation() const;

    void setCourseName(const string name);
    void setLocation(const string loc);

    void display() const;
};

#endif