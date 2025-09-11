#include <iostream>
using namespace std;

// int main(){
//     int a=5;
//     int *ptr = &a; // stores address of a
//     cout << ptr << endl; // gives the address

// // DEFERENCE OPERATOR 
//     cout << *ptr << endl; // gives value of a
//     *ptr = 10;
//     cout << a << endl;

//     int *ptr1 = NULL; // null pointer, equivalent to write as *ptr = 0
//     cout << ptr1 << endl; // 0x0

// // REFERENCE VARIABLE
//     int num = 200;
//     int &val = num;
//     cout << val << endl;
//     val = 10;
//     cout << num << endl;
//     return 0;
// }

// PASS BY VALUE
// void changeA(int param){
//     param = 50;
//     cout << param << endl;
// }
// int main(){
//     int a = 5;
//     changeA(a);
//     cout << a << endl;
//     return 0;
// }

// PASS BY REFERENCE USING POINTERS
void changeA(int *ptr){
    *ptr = 50;
    cout << *ptr << endl;
}

// PASS BY REFERENCE USING REFERENCE VARIABLES
void changeA(int &a){
    a = 50;
    cout << a << endl;
}
int main(){
    int a = 5;
    //changeA(&a);
    changeA(a);
    cout << a << endl;
    return 0;
}