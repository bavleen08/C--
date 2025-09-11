#include <iostream>
using namespace std;

// WAF TO PRINT NTH FIBONACCI
void printNthFibonacci(int n){
    if (n <= 0) {
        cout << "INVALID INPUT" << endl;
    }

    int a = 0, b = 1;
    if (n==1){
        cout << a << endl;
    } 
    if (n==2) {
        cout << b << endl;
    }

    int next;
    for(int i=3; i<=n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    cout << b << endl;
}

int main(){

return 0;
}