#include<iostream>
#include<map>

using namespace std;

struct Student {
    string id;
    string name;
    int age;
};

int main(int argc, char* argv[])
{
    map<string, Student> sMap;
    Student s1 = { "okim", "Anthony Kim", 41};
    Student s2 = { "dkim", "Diane Kim", 21};
    Student s3 = { "ddol", "Ddolbok Bong", 6};

    // insert 방법 1
    sMap[s1.id] = s1;   // O(log n)

    // insert 방법 2 오브젝트는 벨류가 카피
    sMap.insert(pair<string, Student>(s2.id, s2));
    // insert 방법 3
    sMap.insert(make_pair(s3.id, s3));

    s1.age = 51;    // Map에 있는 데이터는 안 변함

    // cout << "size" << sMap.size() << endl;
    // cout << "size" << sMap.at("okim").age << endl;


    // sMap.erase("dkim"); // 지워줌
    sMap.erase("dkim"); // 지워줌

    // cout << next(sMap.begin(),2)->first << endl;
    cout << sMap["dkim"].age << endl;
    cout << sMap[s1.id].age << endl;    // 찾는 속도는 O(log n) 자바스크립트랑 다르네.. JS는 hash table lookup 방식
    cout << sMap["ddol"].name << endl;
    cout << sMap.find("ddol")->second.name << endl;

    cout << "-----------iteration" << endl;

    for (map<string, Student>::iterator it = sMap.begin(); it != sMap.end(); it++) {
        cout << it->first << it->second.age << endl;
    }


    return 0;
}