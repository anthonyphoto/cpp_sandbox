#include<iostream>
#include<vector>
using namespace std;

// int rsum_it(int data[], int size) {
//     if (size == 1) {
//         return data[size - 1];
//     } else {
//         return data[size - 1] + rsum_it(data, size - 1);
//     }
// }

int rsum_it(int data[], int size, int prevSum) {
    if (size == 1) {
        return prevSum + data[size - 1];
    } else {
        prevSum += data[size - 1];
        return rsum_it(data, size - 1, prevSum);
    }
}
int fact(int n, vector<int> res) {
    if (n == 1) {
        return res[res.size() - 1];
    } else {

        int acc = res.size() == 0 ? 1 : res[res.size() - 1];        
        res.push_back(n * acc);
        return fact(n - 1, res);
    }

}

int main(int argc, char* argv[])
{
    // int data[4] = {8, 6, 7, 9};
    // int size=4;
    // int sum1 = isum_it(data, size);
    // int sum2 = rsum_it(data, size, 0);
    // int sum2 = fact(5, vector<int>(0));
    int sum2 = fact(5, vector<int>(0));
    cout << sum2 << endl;

    return 0;
}