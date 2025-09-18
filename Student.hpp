// TO DO:  Student class definition  here.

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"
using namespace std;

class Student {
private:
    struct CourseNode {
        Course data;
        CourseNode* next;
        CourseNode(const Course& c) : data(c), next(nullptr) {}
    };

    int id;
    string name;
    float gpa;
    CourseNode* head; 

public:
    Student(int id = 0, string name = "", float gpa = 0.0f);
    ~Student();

    int getId() const { 
        return id;
    }
    string getName() const { 
        return name; 
    }
    float getGpa() const {
        return gpa;
    }

    void setId(int newId) { 
        id = newId;
    }
    void setName(string newName) { 
        name = newName; 
    }
    void setGpa(float newGpa) {
        gpa = newGpa; 
    }

    void addCourse(const Course& course);
    void display() const;
};

#endif