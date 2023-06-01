#include <iostream>
using namespace std;


int main() {
    int arr1[3] = {1, 2, 3};
    int arr2[3];
    // arr2 = arr1;    // 어떻게 풀까?
    for (int i=0; i<3; i++) arr2[i] = arr1[i];

    int arr[3] = {1,2,3};
    cout << arr << endl;
    cout << &arr << endl;



    char strArr[40];    // size없으면 에러남
    char* strPtr;
    int num;

    // variable    addr        value                    size
    // strArr      A00         Array of characters      40
    // strPtr      B00         pointer(e.g., A00)       8
    // num         C00         number (4byte)           4

    // variable은 주소를 가지고 있고 이름을 대면 주소에 있는 값을 리턴함
    // domain naver처럼 모든 변수는 address하고 동일함

    // 모든 변수는 pass할때 value로 넘어감.. 단 array만 예외

    strPtr = strArr; // 에러가 날까? 반대면 에러남s
    // strArr = strPtr; // 에러남

    cout << strPtr << endl;

    // strArr 에 Diane을 할당함
    // strArr = "Diane";   //안됨
    strcpy(strArr, "Diane"); // 이렇게 안하려면 declare할떄 정의하면 됨

    strcpy(strPtr, "Test"); // 1. strArr이 덮어씌워짐 2. line 23을 지우면 에러남 

    cout << strArr << endl;

    // -----------------------------------------------
    // ARRAY OF CSTRING은 2D Arr

    char names1[3][10] = {"Anthony", "Kim", "Diane"};   // 차이를 알아야함
    char* names2[3] = {(char *)"Anthony", (char *)"Kim", (char *)"Diane"};  // 워닝 안나게 할려면 앞에 (char *)

    cout << sizeof(names1) << endl;
    cout << sizeof(names2) << endl;

    char* names3[3];
    // names3[0]에 Ddolbok을 넣어봄
    char tmp[10];
    strcpy(tmp, "Ddolbok"); // char tmp[10] = "Ddolbok" 하고 같음
    names3[0] = tmp;

    // char* names1Ptr = names1[0]; // array 갯수와 동일함 
    char** names2Ptr = names2; // array 갯수와 동일함 


    // strcpy(names3[0], "Diane");

    cout << names3[0] << endl;




    return 0;
}