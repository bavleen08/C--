#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

// // FUNCTION DEFINITION
void printHello(){
    cout << "hello";
}
int main(){ //In C++, every program must have a main() function. It's the entry point of your program — the place where execution starts.
    // function call / invoke
    printHello();
}

int minOftwo(int a, int b) { //parameters
    if(a<b) {
        return a;
    } else {
        return b;
    }
}

//return 0; tells the operating system:➤ "The program ran successfully."If something goes wrong, you might return another value (like 1, -1, etc.).

// SUM 1 TO N
int sumN(int n) {
    int sum =0;
    for(int i=1; i<=n; i++) {
        sum += i;
    }
    return sum;
}


// CALCULATE N FACTORIAL
int factorial(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}


// PASS BY VALUE
int sum(int a, int b) {
    a = a+10; //15
    b = b+10; //14
    return a+b; //29
}
int main() {
    int a = 5, b = 4;
    cout << sum(a, b) << endl;
    cout << a; //5
    return 0;
}

// CALCULATE SUM OF THE DIGITS
int SumOfDigits(int num) {
    int digitSum = 0;
    while(num > 0) {
        int lastDigit = num % 10;
        num = num / 10;
        digitSum += lastDigit;
    }
    return digitSum;
}

// CALCULATE nCr FOR N AND R
int factorial(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}
int nCr(int n, int r) {
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_nmr = factorial(n-r);

    return fact_n / (fact_r * fact_nmr);
}

// WAF TO CHECK PRIME OR NOT
bool isPrime(int n) {
    if(n<=1) return false; // 0 and 1 are not prime numbers
    for(int i=2; i<n; i++) { // To improve efficiency, check up to i * i <= n
        if(n % i == 0){
            return false; // Not prime if divisible
        }     
    }
    return true; // Prime if not divisible by any i
}    
//Incorrect logic to check for prime:
// You're checking if (n % i != 0) and printing "PRIME" as soon as one number doesn’t divide n. That’s wrong. A number is prime only if none of the numbers from 2 to n-1 divide it.
// But your function prints "PRIME" as soon as it finds one number that doesn't divide n, which leads to incorrect results.
// Return type mismatch:
// Your function has return type int, but it doesn't return anything. You're using cout inside the function and again printing cout << primeORnot(n) in main. That leads to confusing and undefined behavior.
// ANOTHER WAY->
void primeORnot(int n) {
    if (n <= 1) {
        cout << "NOT PRIME" << endl;
        return;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            cout << "NOT PRIME" << endl;
            return;
        }
    }
    cout << "PRIME" << endl;
}

// WAF TO PRINT ALL THE PRIME NUMBERS FROM 2 TO N
void printPRIMESuptoN(int n) {
    for(int i=2; i<=n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
}


// H.W Que 1- FIND IF NUMBER IS POWER OF 2
// with loops
#include <cmath>
bool powerOf2(int n) {
    int num = 1;
    while(num < n) {
        if(n == pow(2, num)){ // my mistake- i used 2**num, is not the way to write "2 raised to the power num". The ** operator is not defined for exponentiation like in Python.Use pow() from <cmath> (returns a double)
            return true;
        }
        num++;
    }

// without loops- using bitwise op
    while(num < n){
        if(n == (1 << num)){
            return true;
        }
        num++;
    }
    //num++; // my mistake- This is outside the loop, so num never changes, the num++ is placed after the while loop, which means it's never incremented, causing an infinite loop if n != pow(2, 1).
    return false;
}


int largest(int a, int b, int c){
    return max(a, max(b,c));
}

char next(char ch){
    return ch + 1;
}
