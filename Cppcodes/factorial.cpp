#include <iostream>
using namespace std;

// FACTORIAL
int main(){
int n;
int factorialOfn = 1;
cin >> n;
for(int i=1; i<=n; i++){ 
    factorialOfn *= i;
}
cout << "Factorial is "<< factorialOfn;
}