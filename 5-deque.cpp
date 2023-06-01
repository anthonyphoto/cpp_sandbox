#include<iostream>
#include<deque>

using namespace std;

int main(int argc, char* argv[])
{
    deque<int> dq;
    for (int i = 0; i < 3; i++) {
        dq.push_back(i + 50);
        dq.push_front(i);
    }
    cout << "ind 2:" << dq[5] << endl;
    dq.pop_front();


    return 0;
}