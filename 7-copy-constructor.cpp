#include<iostream>

using namespace std;

class Student{
    public:
        //  자동으로 다음과 같은 컨스트럭터가 추가가 됨
        //  Student(const Student&);
        //  Student& operator=(const Student&);
        Student() {
            id_ = 0;
            name_ = "noName";
        };
        Student(int id, string name) {
            id_ = id;
            name_ = name;
        };
        void setName(string name) {
            name_ = name;
        };
        void printInfo(){
            cout << id_ << ":" << name_ << endl;
        }
    private:
        int id_;
        string name_;
};

int main(int argc, char* argv[])
{
    Student s1(1, "Anthony");
    Student s2(s1);     // Student(const Student &) 카피는 인풋값을 못 바꿈
    Student s3 = s1;    // Student& operator=(const Student&); 
    s1.setName("Diane");
    s1.printInfo();
    s2.printInfo();
    s3.printInfo();


    return 0;
}