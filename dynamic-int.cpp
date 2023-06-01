#include <iostream>
using namespace std;

int main() {
    int stuCnt;
    int scoreCnt;
    
    cin >> stuCnt >> scoreCnt;

    int** scores = new int*[stuCnt];

    for (int i=0; i<stuCnt; i++) {
        scores[i] = new int[scoreCnt];
    }

    for (int i=0; i<stuCnt; i++){
        cout << "student " << (i+1) << endl;
        for (int j=0; j<scoreCnt; j++) {
            int num;
            cout << "enter the subject " << j+1 << endl;
            cin >> num;
            scores[i][j] = num;
        }
    }

    for (int i=0; i<stuCnt; i++){
        cout << "student " << (i+1) << endl;
        for (int j=0; j<scoreCnt; j++) {
            cout << "enter the subject " << j+1 << ": " << scores[i][j] << endl;
        }
    }

    for (int i=0; i<scoreCnt; i++) {
        delete [] scores[i];
    }

    delete [] scores;
    

    return 0;
}