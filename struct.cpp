#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Dog {
    Dog(string b, string n, int a) {
        breed = b;
        name = n;
        age = a;

    };
    void bark();
    string breed;
    string name;
    int age;
};

// Dog::Dog(string b, string n, int a) {
//     breed = b;
//     name = n;
//     age = a;
// }

void Dog::bark(){
    cout << name << " is barking " << endl;
}

int main() {
    Dog coco("poodle", "Coco", 3);
    // coco.age = 3;
    cout << coco.name << endl;
    cout << coco.breed << endl;
    cout << coco.age << endl;
    // coco.bark();
    
    double a = 1;
    // double b = 0.3 * 3 + 0.1;
    double b = (double)1/3 + (double)2/3;
    double c = 4.5;
    // bool eq = abs(a - b) < 0.00000001;
    bool eq = (a == b);
    
    cout << (eq ? "EQUAL" : "NOTEQUAL") << endl;
    cout << setprecision(20);
    cout << a << endl;
    cout << b << endl;





    return 0;
}