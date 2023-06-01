#include<iostream>

using namespace std;

class Student {
    private:
        int id;
        double gpa;
    public:
        Student(int i, double g) {
            id = i;
            gpa = g;
        }
        operator bool(); // 리턴값 bool
        operator int(); // 리턴값 int
        int operator!() {
            return id + 1;
        };
        
};

Student::operator bool() {
    return gpa >= 2.0;
}

Student::operator int() {
    return id;
}

int main(int argc, char* argv[])
{
    Student s1(200, 3.8);
    cout << (s1 ? ">=2.0" : "<2.0") << endl;
    bool res = s1;  // 1 = true
    int id = s1;    // 200
    cout << id << ":" << res << endl;
    int tmpNum = !s1;
    cout << !s1 << endl;

    return 0;
}