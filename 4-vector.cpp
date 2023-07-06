#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> v) {
    for (size_t i = 0; i < v.size(); i++) {  // size_t는 size()의 리턴타입 = unsigned int
        cout << v[i] << ",";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{   
    vector<int> vtest;
    for (size_t i = 0; i < 10; i++) {
        vtest.push_back(i * 2);
    }

    for (size_t i = 0; i < 10; i++) {
        cout << vtest.at(i) << endl;
    }
    
    for (vector<int>::iterator it = vtest.begin(); it != vtest.end(); it++) {
        cout << *it << endl;
    }


    return 0;


    vector<int> v(5); // 처음에 사이즈 선언하거나 resize하면 size와 capacity가 같이 세팅.. 자동으로 증가되면 capacity만 증가됨


    v[0] = 1;
    v[1] = 2;
    for (size_t i = 0; i < 1; i++) {
        v.push_back(i);
    }
    printVector(v);

    cout << v.front() << " " << v.back() << endl;  // v[0]과 v[4]가 나옴

    // v.push_back(5); 
    cout << v.size() << endl; // 6
    cout << v.capacity() << endl; // 10 항상 두배 증가
    v.push_back(6); 
    v.resize(100);
    cout << v.size() << endl;  // 100
    cout << v.capacity() << endl; // 100
    v.push_back(100); //사이즈 101 캐파 200 
    printVector(v);

    v.clear(); // 전부 지움
    v.resize(5);
    for (size_t i = 0; i < v.size(); i++) {
        v[i] = i;
    }
    cout << v.size() << endl;  // 5
    cout << v.capacity() << endl; // 200 한번 올린건 안 내려감

    v.insert(v.begin() + 1, 9); // 두번째 index에 추가됨 
    v.erase(v.begin() + 1); // 두번째 index가 삭제됨 

    v.pop_back();   // 뒤에꺼 지움 = v.erase(v.end()-1) 
    // v.pop_front();

    printVector(v);

    vector<int> v2(5);
    v2 = v; // deep copy
    printVector(v2);

    return 0;
}