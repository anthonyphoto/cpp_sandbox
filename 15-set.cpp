#include<iostream>
#include<set>

using namespace std;

int main(int argc, char* argv[])
{
    set<string> people;

    people.insert("Anthony");
    people.insert("Diane");

    for (set<string>::iterator it = people.begin(); it != people.end(); it++) {
        cout << *it << endl;
    }


    return 0;
}