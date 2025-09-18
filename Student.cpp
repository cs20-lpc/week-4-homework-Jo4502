// TODO:  Student class methods implementation here.

#include "Student.hpp"

Student::Student(int id, string name, float gpa)
    : id(id), name(name), gpa(gpa), head(nullptr) {
}

Student::~Student() {
    while (head) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Student::addCourse(const Course& course) {
    CourseNode* newNode = new CourseNode(course);
    if (!head) head = newNode;
    else {
        CourseNode* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

void Student::display() const {
    cout << id << " " << name << " " << gpa;
    if (!head) {
        cout << " None" << endl;
    }
    else {
        cout << "\nCourses:\n";
        CourseNode* curr = head;
        while (curr) {
            curr->data.display();
            curr = curr->next;
        }
    }
}