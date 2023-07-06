#include<iostream>
#include<vector>

using namespace std;



void heapify(vector<int>& v, int size, int ind) {
    int leftInd = ind * 2 + 1;
    int rightInd = ind * 2 + 2;

    int lowestInd = ind;

    if (leftInd < size && v[leftInd] < v[lowestInd]) lowestInd = leftInd;
    if (rightInd < size && v[rightInd] < v[lowestInd]) lowestInd = rightInd;

    if (lowestInd != ind) {
        swap(v[ind], v[lowestInd]);
        heapify(v, size, lowestInd);
    }
}


void make_heap(vector<int>& v) {
    // starting 2i + 1 = size - 1부터 i = size/2 - 1
    for (int i = (v.size() / 2 - 1); i >= 0; i--) {
        heapify(v, v.size(), i);

    }
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;

    // heapsort after heap conversion
    for (int i = v.size() - 1; i > 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;

}

/* 
 *          28
 *        /    \
 *      35      14
 *     /  \     / \
 *    25  10   18  7
 *   /
 *  19
 *  
 */


int main(int argc, char* argv[])
{
    int arr[] = {28, 35, 14, 25, 10, 18, 7, 19};
    vector<int> v(arr, &arr[8]);    
    // parent: (i+1)/2 - 1
    // children: 2i + 1, 2i + 2

    make_heap(v);

    cout << endl;

    return 0;
}