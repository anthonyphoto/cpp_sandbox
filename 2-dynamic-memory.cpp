#include <iostream>
using namespace std;

int** captureInput(int stuCnt, int testCnt){

    int** scores = new int*[stuCnt];
    for (int i = 0; i < stuCnt; i++) {
        scores[i] = new int[testCnt];
        for (int j = 0; j < testCnt; j++) {
            int tmp;
            cout << "Student #" << i << " Test Score #" << j << endl;
            cin >> tmp;
            scores[i][j] = tmp;
        }
    }
    return scores;
}

int main() {
    int num1 = 1;
    int num1a = 1;
    int* num2 = new int;
    int* num2a = new int;
    *num2 = 1;

    cout << &num1 << endl;
    cout << &num1a << endl;
    cout << num2 << endl;
    cout << num2a << endl;

    delete num2;
    delete num2a;

    cout << "---------------------------------" << endl;

    // m*n array

    int stuCnt;
    int testCnt;
    cout << "number of students" << endl;
    cin >> stuCnt;
    cout << "number of tests" << endl;
    cin >> testCnt;

    // int** scores = new int*[stuCnt];

    int** scores = captureInput(stuCnt, testCnt);

    // for (int i = 0; i < stuCnt; i++) {
    //     scores[i] = new int[testCnt];
    //     for (int j = 0; j < testCnt; j++) {
    //         int tmp;
    //         cout << "Student #" << i << " Test Score #" << j << endl;
    //         cin >> tmp;
    //         scores[i][j] = tmp;
    //     }
    // }


    for (int i = 0; i < stuCnt; i++) {
        for (int j = 0; j < testCnt; j++) {
            cout << scores[i][j] << &scores[i][j]<< " ";
        }
        cout << endl;
    }

    for (int i = 0; i < stuCnt; i++) {
        delete [] scores[i];
    }
    delete [] scores;

    return 0;
}