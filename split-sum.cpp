// #include <iostream>
// using namespace std;
extern bool done;
int sum(int a[], int n) {
    int sum = 0;
    for (int i=0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}