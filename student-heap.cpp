#include <iostream>

using namespace std;

class Student {
    public:
        Student();
        Student(int id, string name);
        void setId(int id);
        void getInfo();

    private:
        int id_;
        string name_;
        int score_[4];


};

Student::Student() {
    id_ = -1;
    name_ = "_";
    for (int i; i < 4; i++){
        score_[i] = -1;
    }
}
Student::Student(int id, string name) {
    id_ = id;
    name_ = name;
}
void Student::getInfo() {
    cout << "ID: " << id_ << " Name: " << name_ << endl;
}
void Student::setId(int id) {
    id_ = id;
}


int main() {

    int stuCnt, testCnt;
    cout << "Enter the number of students: " << endl;
    cin >> stuCnt;
    cout << "Enter the number of tests: " << endl;
    cin >> testCnt;

    // Student* s1 = new Student(888, "Anthony Kim");

    Student* students = new Student[stuCnt];

    for (int i=0; i < stuCnt; i++) {
        students[i] = Student(i, "testName");
    }
    // students[1] = *s1;

    for (int i=0; i < stuCnt; i++) {
        students[i].getInfo();
    }

    delete [] students;

    return 0;
}