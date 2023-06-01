#include<iostream>
#include<sstream>

using namespace std;

int main(int argc, char* argv[])
{
    stringstream ss;
    
    // ss << "2.0 35 a";
    // ss << 123;
    // ss << " ";
    // ss << "Hello";
    // ss << " ";
    // ss << "World";
    // ss << "Anthony";
    ss.str("123 Hello WorldAnthony");

    int n;
    ss >> n;
    cout << "n:" << typeid(n).name() << endl;

    // double x; int y; char z;
    string str;
    ss >> str;
    cout << str << endl;

    cout << sizeof(ss) << endl;
    cout << ss.str() << endl;
    ss >> str;
    cout << "-------" << endl;
    cout << str << endl;
    cout << ss.str() << endl;
    ss.clear();
    // ss.str("")


    return 0;
}