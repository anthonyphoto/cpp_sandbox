#include <iostream>
#include "split-sum.h"
using namespace std;

bool done = false;

int main() {
    int array[3] = {1,2,3};
    int val = sum(array, 3);
    cout << val << endl;
    return 0;
}

