#include<iostream>

using namespace std;

class DList {
    public:
        DList(int l) {
            dynamicList = new int[l];
            len = l;
        };

        DList(const DList &dl) {
            dynamicList = new int[dl.len];
            len = dl.len;
            for (int i = 0; i < len; i++) {
                dynamicList[i] = dl.dynamicList[i];
            }    
        }
        DList& operator=(const DList &dl) {
            if (this == &dl) return *this;
            if (dynamicList) delete [] dynamicList;

            len = dl.len;
            dynamicList = new int(len);
            for (int i = 0; i < len; i++) {
                dynamicList[i] = dl.dynamicList[i];
            }
            return *this;
        }

        // ~DList() {
        //     delete [] dynamicList;
        // }

        void setNum(int ind, int val) {
            dynamicList[ind] = val;
        }

        void printDList() {
            cout << dynamicList << ":";
            for (int i = 0; i < len; i++) {
                cout << dynamicList[i] << ",";
            }
            cout << endl;
        }

    private:
        int* dynamicList;
        int len;
};

class List {
    public:
        List(int* arr, string n) {
            for (int i = 0; i < 5; i++) {
                localList[i] = arr[i];
            }
            name_ = n;
        };

        void printInfo() {
            cout << localList << ":";
            for (int i = 0; i < 5; i++) {
                cout << localList[i] << ",";
            }
            cout << name_ << endl;
        };

    private:
        string name_;
        int localList[5];
};

int main(int argc, char* argv[])
{
    int arr[] = { 1, 2, 3, 4, 5};
    List l1(arr, "Anthony List");
    List l2(l1);    // deep copy
    List l3 = l1;   // deep copy

    l1.printInfo();
    l2.printInfo();
    l3.printInfo();

    DList d1(5);
    d1.setNum(0, 1);
    d1.setNum(4, 9);
    DList d2(d1);   // Shallow Copy
    DList d3 = d2;
    DList d4(5);
    cout << "d4" << &d4 << endl;
    d4 = d1;    // Operator 
    cout << "d4" << &d4 << endl;
    d1.printDList();
    d2.printDList();
    d3.printDList();
    d4.printDList();







    return 0;
}