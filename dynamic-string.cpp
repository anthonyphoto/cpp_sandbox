#include <iostream>
using namespace std;

char* createDeepCopy(char txt[]) {
    char* newMem = new char[strlen(txt)+1];
    strcpy(newMem, txt);
    return newMem;
}

int main() {
    int num = 0;
    cin >> num;
    
    char** names = new char*[num];

    char tmp[40];

    for (int i=0; i<num; i++){
        cin >> tmp;
        names[i] = createDeepCopy(tmp);
        // names[i] = new char[strlen(tmp)+1];
        // strcpy(names[i], tmp);
    }

    for (int i=0; i<num; i++){
        cout << names[i] << endl;
    }

    for (int i=0; i<num; i++){
        delete [] names[i];
    }

    delete [] names;
    return 0;
}