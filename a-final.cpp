#include<iostream>

using namespace std;
class J1 {
    public:
        virtual void f1() {
            cout << "J 1" << endl;
        }
        void f2() {
            cout << "J 2" << endl;
        }
        virtual void f3(){
            cout << "J 3" << endl;
        }
};

class K1: public J1 {
    public:
        virtual void f1(){
            cout << "K 1" << endl;
        }
        virtual void f2(){
            cout << "K 2" << endl;
        }
};

class M1: public J1 {
    public:
        void f2(){
            J1::f2();
            cout << "M 2" << endl;
        }
        virtual void f4(){
            M1::f2();
            cout << "M 4" << endl;
        }
};

class P1: public M1 {
    public:
        void f1(){
            cout << "P 1" << endl;
        }
        virtual void f2(){
            cout << "P 2" << endl;
            P1::f4();
        }
};

int main(int argc, char* argv[])
{
    J1* var1 = new K1;
    var1->f1(); // K 1 
    var1->f2(); // J 2

    J1* var2 = new M1;
    // var2->f4(); // Compile Error
    
    M1* var3 = new P1;
    var3->f1(); // P 1
    var3->f2(); // J 2 // M 2
    var3->f3(); // J 3
    



    return 0;
}