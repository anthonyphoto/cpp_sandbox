#include<iostream>
#include<vector>

using namespace std;


int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}
int sumT(int n, int sum = 0) {
    if (n == 0) {
        return sum;
    } else {
        sum += n;

        return sumT(n - 1, sum);
    }
}

int sumArr(const int a[], int len) {
    // cout << "--" << a << endl;
    if (len == 1) {
        return a[0];
    } else {
        return a[len - 1] + sumArr(a, len - 1);
    }

}

int sumArrT(const int a[], int len, int sum = 0) {
    if (len == 0) {
        return sum;
    } else {
        sum += a[len - 1];
        return sumArrT(a, len - 1, sum);
    }
}

int sumVec(vector<int>& v) {
    // cout << "--" << &v << endl;
    if (v.size() == 1) {
        return v[0];
    } else {
        int last = v[v.size()  - 1];
        v.pop_back();
        return last + sumVec(v);
    }
}

int sumVecT(vector<int>& v, int sum = 0) {
    if (v.size() == 0) {
        return sum;
    } else {
        int last = v[v.size() - 1];
        v.pop_back();
        sum += last;
        return sumVecT(v, sum);
    }
}


int main(int argc, char* argv[])
{
    cout << sum(10) << endl;
    cout << sumT(10) << endl;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << sumArr(arr, 10) << endl;
    cout << sumArrT(arr, 10) << endl;

    vector<int> v(arr, arr + 10);
    vector<int> v2 = v;
    cout << sumVec(v) << endl;
    cout << "vector: " << sumVecT(v2) << endl;

    return 0;
}