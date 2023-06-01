#include <iostream>
#include "student.h"

using namespace std;

Student::Student() {
    name_ = "";
    id_ = 0;
    gpa_ = 0.0;
}

Student::Student(string name, int id, double gpa) {
    name_ = name;
    id_ = id;
    gpa_ = gpa;
}

void Student::printInfo() {
    cout << "Name: " << name_ << endl;
    cout << "Id: " << id_ << endl;
    cout << "GPA: " << gpa_ << endl;
}

double Student::getGpa() const {
    return gpa_;
}

int Student::getId() const {
    return id_;
}