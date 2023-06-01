#include<iostream>

using namespace std;

class Dog {
    public:
        string name;
        int age;
        Dog() {
            name = "noName";
            age = 0;
        }
};

int main(int argc, char* argv[])
{   
    Dog d1;
    d1.name = "Ddol";
    d1.age = 5;

    Dog d2;
    d2 = d1;
    d2.name = "Coco";

    cout << d1.name << " " << d1.age << endl;
    cout << d2.name << " " << d2.age << endl;




    return 0;
}