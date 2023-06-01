// Operator Overloading
#include<iostream>

using namespace std;

class Complex {
    public:
        Complex(double r, double i) {
            real_ = r;
            ima_ = i;
        };

        Complex operator+(const Complex &c) const { // const &로 하면 사이즈를 줄임 
            cout << "Member Fn" << endl;
            return Complex(real_ + c.real_, ima_ + c.ima_);
        };

        friend Complex operator+(const int &real, const Complex &c);
        // friend Complex operator+(const Complex &a, const Complex &b);

        friend ostream& operator<<(ostream& os, const Complex& c); 

        void printInfo() {
            cout << real_ << ":" << ima_ << endl;
        };

    private:
        double real_;
        double ima_;
};

string operator+(int time, string apm) {
    return to_string(time) + apm;
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real_ << ", " << c.ima_ << endl;
    return os;
}

// Complex operator+(const Complex &a, const Complex &b) {
//     cout << "Global fn" << endl;
//     return Complex(a.real_ + b.real_, a.ima_ + b.ima_);
// }

Complex operator+(const int &real, const Complex &c) {
    Complex tmp(0,0);
    tmp.real_ = real + c.real_;
    tmp.ima_ = c.ima_;
    return tmp;
    // return Complex(real, 0) + c;
}

int main(int argc, char* argv[])
{
    int hr = 9;
    string suffix = "pm";
    // string time = to_string(hr) + suffix;
    cout << hr + suffix << endl;    // same as operator+(hr, suffix)
    cout << operator+(hr, suffix) << endl;    // same as operator+(hr, suffix)

    Complex a(1, 1);
    Complex b(2, 0);
    Complex c(3, 3);
    Complex d = a + b + c;  // same as a.operator+(b)
    d.printInfo();
    
    Complex x(1,1);
    Complex z = 5 + x;
    z.printInfo();

    cout << a;

    return 0;
}