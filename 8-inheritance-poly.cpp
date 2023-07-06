#include<iostream>
#include<vector>

using namespace std;

class Animal {
    public:
        Animal(string name_, int legCount_=0) {
            name = name_;
            legCount = legCount_;
        }
        void setName(string name_) {
            name = name_;
        }
        virtual void printInfo() {  // virtual - dynamic binding
            cout << name << " " << legCount << endl;
        }

    protected:
        string name;
        int legCount;
};

class Dog: public Animal {
    public: 
        Dog(string name_, string breed_): Animal(name_, 4), breed() {
            breed = breed_;
        }
        void setBreed(string breed_){
            breed = breed_;
        }
        void printInfo() {
            cout << name << " " << legCount << " " << breed << endl;
        }
    private:
        string breed;

};

int main(int argc, char* argv[])
{
    vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    vector<int> v2;
    v2 = v1;
    v2[0] = 100;
    cout << "v1:" << v1[0] << v1.size() << endl;
    cout << "v2:" << v2[0] << v2.size() << endl;


    Dog d1("Coco", "Poodle");
    d1.setName("KOKO");
    d1.printInfo();

    Dog* d2 = &d1;
    d2->setBreed("Yorkie");
    d2->printInfo();

    Animal a1("Remi");
    a1.printInfo(); // Dog::printInfo 실행함

    Animal* a2 = &d1;

    a2->setName("Grom");
    // a2->setBreed("Beagle");  // 에러남
    a2->printInfo();

    cout << "SIZE: " << sizeof(Animal) << " " << sizeof(Dog) << endl;
    cout << "SIZE: " << sizeof(d1) << " " << sizeof(*d2) << " " << sizeof(a1) << endl;


    return 0;
}