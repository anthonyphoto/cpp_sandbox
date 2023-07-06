#include<iostream>
#include<set>

using namespace std;

int main(int argc, char* argv[])
{
    std::set<int> s1;   // 1,  3,5
    std::set<int> s2;   //   2,3,5,6
    s1.insert(1);
    s1.insert(3);
    s1.insert(5);
    s2.insert(2);
    s2.insert(3);
    s2.insert(5);
    s2.insert(6);

    set<int> s_union;
    set<int> s_int;
    set<int> s_diff;

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s_union, s_union.begin()));    // 1,2,3,4,5,6
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s_int, s_int.begin())); // 3,5
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s_diff, s_diff.begin())); // 1


    for (set<int>::iterator it = s_union.begin(); it != s_union.end(); it++) {
        cout << *it << ",";
    }
    cout << endl;

    for (set<int>::iterator it = s_int.begin(); it != s_int.end(); it++) {
        cout << *it << ",";
    }
    cout << endl;

    for (set<int>::iterator it = s_diff.begin(); it != s_diff.end(); it++) {
        cout << *it << ",";
    }
    cout << endl;

    return 0;
}