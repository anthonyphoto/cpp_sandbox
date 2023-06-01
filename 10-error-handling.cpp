#include<iostream>
#include<stdexcept>

using namespace std;

int divide(int m, int n) {
    if (n == 0) {
        throw range_error("divide by 0!");
    }
    return m/n;
}

int main(int argc, char* argv[])
{
    try {
        cout << divide(4,0) << endl;
    } catch(range_error e) {
        cout << e.what() << endl;
    }




    return 0;
}