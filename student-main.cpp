#include <iostream>
#include "student.h"

using namespace std;

Student* createStudent(){
    Student* tmp = new Student("Placeholder", 1, 2.5);
    return tmp;
}

Student createStudent2(){
    Student tmp("Name2", 5, 3.4);
    return tmp;
}

int main() {
    Student s1("Anthony", 775, 3.8);
    int num = 1;
    string str = "ANTHONY";
    Student* s2 = createStudent();
    Student s3 = createStudent2();
    s3.printInfo();

    int* num2 = new int;
    *num2 = 3;

    cout << &s1 << ", " << typeid(s1).name() << endl;
    cout << &num << ", " << sizeof(num) << endl;
    cout << str << ", " << sizeof(str) << endl;
    cout << s2 << ", " << sizeof(s2) << endl;
    cout << num2 << ", " << sizeof(num2) << endl;
    cout << "---------" << endl;


    s1.printInfo();
    s2->printInfo();
    cout << s2->getGpa() << s2->getId() << endl;

    delete s2;
    return 0;
}