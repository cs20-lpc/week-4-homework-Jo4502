#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

struct Node {                     //Create a Node structure to represent each student  
    Student student;
    Node* next;
    Node(Student s) : student(s), next(nullptr) {}
};

int main()
{
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.

    Node* head = nullptr; // start of the linked list
    int choice;

    do {
        // Menu
        cout << "\n1. Insert \n";
        cout << "2. Delete \n";
        cout << "3. Search \n";
        cout << "4. Display All \n";
        cout << "5. Count \n";
        cout << "6. Add a Course\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // --- INSERT STUDENT ---
            int id;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter GPA: ";
            cin >> gpa;

            Node* newNode = new Node(Student(id, name, gpa));

            if (!head) {
                // If list is empty, new node becomes the head
                head = newNode;
            }
            else {
                // Otherwise go to the last node and link new node
                Node* current = head;
                while (current->next) current = current->next;
                current->next = newNode;
            }
            cout << "Student added.\n";
        }
        else if (choice == 2) {
            // --- DELETE STUDENT ---
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            Node* current = head;
            Node* previous = nullptr;
            bool found = false;

            while (current) {
                if (current->student.getId() == id) {
                    if (previous) previous->next = current->next;
                    else head = current->next;
                    delete current;
                    found = true;
                    cout << "Deleted student with ID " << id << endl;
                    break;
                }
                previous = current;
                current = current->next;
            }
            if (!found) cout << "Student not found.\n";
        }
        else if (choice == 3) {
            // --- SEARCH STUDENT ---
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Node* current = head;
            bool found = false;

            while (current) {
                if (current->student.getId() == id) {
                    current->student.display();
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (!found) cout << "Student not found.\n";
        }
        else if (choice == 4) {
            // --- DISPLAY ALL STUDENTS ---
            if (!head) {
                cout << "No students in the list.\n";
            }
            else {
                Node* current = head;
                while (current) {
                    current->student.display();
                    current = current->next;
                }
            }
        }
        else if (choice == 5) {
            // --- COUNT STUDENTS ---
            int count = 0;
            Node* current = head;
            while (current) {
                count++;
                current = current->next;
            }
            cout << "Total students: " << count << endl;
        }
        else if (choice == 6) {
            // --- ADD A COURSE ---
            int id;
            cout << "Enter ID: ";
            cin >> id;

            Node* current = head;
            bool found = false;

            while (current) {
                if (current->student.getId() == id) {
                    cin.ignore();
                    string cname, loc;
                    cout << "Enter Course Name: ";
                    getline(cin, cname);
                    cout << "Enter Location: ";
                    getline(cin, loc);

                    current->student.addCourse(Course(cname, loc));
                    cout << "Course added.\n";
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (!found) cout << "Student not found.\n";
        }

    } while (choice != 7);

    // --- CLEAN UP MEMORY ---
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << "Exiting program...\n";


    //Node* head = nullptr;
    //int choice;

    //do {
    //    cout << "\n1. Insert Student\n2. Delete Student\n3. Search Student\n";
    //    cout << "4. Display All\n5. Count Students\n6. Add a course\n7. Exit\n";
    //    cout << "Enter choice: ";
    //    cin >> choice;

    //    if (choice == 1) { // Insert
    //        int id; string name; float gpa;
    //        cout << "Enter ID: "; cin >> id;
    //        cout << "Enter Name: "; cin >> name;
    //        cout << "Enter GPA: "; cin >> gpa;
    //        Node* newNode = new Node(Student(id, name, gpa));

    //        if (!head) head = newNode;
    //        else {
    //            Node* curr = head;
    //            while (curr->next) curr = curr->next;
    //            curr->next = newNode;
    //        }
    //    }
    //    else if (choice == 2) { // Delete
    //        int id; cout << "Enter ID to delete: "; cin >> id;
    //        Node* curr = head;
    //        Node* prev = nullptr;
    //        bool found = false;
    //        while (curr) {
    //            if (curr->data.getId() == id) {
    //                if (prev) prev->next = curr->next;
    //                else head = curr->next;
    //                delete curr;
    //                found = true;
    //                cout << "Deleted student with ID " << id << endl;
    //                break;
    //            }
    //            prev = curr;
    //            curr = curr->next;
    //        }
    //        if (!found) cout << "Student not found\n";
    //    }
    //    else if (choice == 3) { // Search
    //        int id; cout << "Enter ID to search: "; cin >> id;
    //        Node* curr = head;
    //        bool found = false;
    //        while (curr) {
    //            if (curr->data.getId() == id) {
    //                curr->data.display();
    //                found = true;
    //                break;
    //            }
    //            curr = curr->next;
    //        }
    //        if (!found) cout << "Student not found\n";
    //    }
    //    else if (choice == 4) { // Display all
    //        Node* curr = head;
    //        while (curr) {
    //            curr->data.display();
    //            curr = curr->next;
    //        }
    //    }
    //    else if (choice == 5) { // Count
    //        int count = 0;
    //        Node* curr = head;
    //        while (curr) {
    //            count++;
    //            curr = curr->next;
    //        }
    //        cout << "Total students: " << count << endl;
    //    }
    //    else if (choice == 6) { // Add course
    //        int id; cout << "Enter ID: "; cin >> id;
    //        Node* curr = head;
    //        bool found = false;
    //        while (curr) {
    //            if (curr->data.getId() == id) {
    //                cin.ignore();
    //                string cname, loc;
    //                cout << "Enter Course Name: "; getline(cin, cname);
    //                cout << "Enter location: "; getline(cin, loc);
    //                curr->data.addCourse(Course(cname, loc));
    //                found = true;
    //                break;
    //            }
    //            curr = curr->next;
    //        }
    //        if (!found) cout << "Student not found\n";
    //    }
    //} while (choice != 7);

    //// Cleanup memory
    //while (head) {
    //    Node* temp = head;
    //    head = head->next;
    //    delete temp;
    //}
    return 0;



}
