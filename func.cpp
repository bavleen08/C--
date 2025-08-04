#include <iostream>
using namespace std;

// // FUNCTION DEFINITION
// void printHello(){
//     cout << "hello";
// }
// int main(){ //In C++, every program must have a main() function. It's the entry point of your program — the place where execution starts.
//     // function call / invoke
//     printHello();
// }

// int minOftwo(int a, int b) { //parameters
//     if(a<b) {
//         return a;
//     } else {
//         return b;
//     }
// }

// int main() { 
//     cout << minOftwo(3,5); //arguments
//     return 0; //return 0; tells the operating system:➤ "The program ran successfully."If something goes wrong, you might return another value (like 1, -1, etc.).
// }

// SUM 1TON
// int sumN(int n) {
//     int sum =0;
//     for(int i=1; i<=n; i++) {
//         sum += i;
//     }
//     return sum;
// }
// int main() {
//     cout << sumN(10);
// }

// CALCULATE N FACTORIAL
// int factorial(int n) {
//     int fact = 1;
//     for(int i=1; i<=n; i++) {
//         fact *= i;
//     }
//     return fact;
// }
// int main() {
//     cout << factorial(5);
// }

// PASS BY VALUE
// int sum(int a, int b) {
//     a = a+10; //15
//     b = b+10; //14
//     return a+b; //29
// }
// int main() {
//     int a = 5, b = 4;
//     cout << sum(a, b) << endl;
//     cout << a; //5
//     return 0;
// }

// CALCULATE SUM OF THE DIGITS
// int SumOfDigits(int num) {
//     int digitSum = 0;
//     while(num > 0) {
//         int lastDigit = num % 10;
//         num = num / 10;
//         digitSum += lastDigit;
//     }
//     return digitSum;
// }
// int main() {
//     cout << "Sum = " << SumOfDigits(2345);
// }

// CALCULATE nCr FOR N AND R
// int factorial(int n) {
//     int fact = 1;
//     for(int i=1; i<=n; i++) {
//         fact *= i;
//     }
//     return fact;
// }

// int nCr(int n, int r) {
//     int fact_n = factorial(n);
//     int fact_r = factorial(r);
//     int fact_nmr = factorial(n-r);

//     return fact_n / (fact_r * fact_nmr);
// }

// int main() {
//     int n = 8, r = 2;
//     cout << nCr(n,r) << endl;
// }

// WAF TO CHECK PRIME OR NOT
// bool isPrime(int n) {
//     if(n<=1) return false; // 0 and 1 are not prime numbers
//     for(int i=2; i<n; i++) { // To improve efficiency, check up to i * i <= n
//         if(n % i == 0){
//             return false; // Not prime if divisible
//         }     
//     }
//     return true; // Prime if not divisible by any i
// }    
// int main(){
//     int n = 2;
//     if (isPrime(n)) {
//         cout << "PRIME" << endl;
//     } else {
//         cout << "NOT PRIME" << endl;
//     }
// }
//Incorrect logic to check for prime:
// You're checking if (n % i != 0) and printing "PRIME" as soon as one number doesn’t divide n. That’s wrong. A number is prime only if none of the numbers from 2 to n-1 divide it.
// But your function prints "PRIME" as soon as it finds one number that doesn't divide n, which leads to incorrect results.
// Return type mismatch:
// Your function has return type int, but it doesn't return anything. You're using cout inside the function and again printing cout << primeORnot(n) in main. That leads to confusing and undefined behavior.

// ANOTHER WAY->

// void primeORnot(int n) {
//     if (n <= 1) {
//         cout << "NOT PRIME" << endl;
//         return;
//     }
//     for(int i = 2; i * i <= n; i++) {
//         if(n % i == 0) {
//             cout << "NOT PRIME" << endl;
//             return;
//         }
//     }
//     cout << "PRIME" << endl;
// }
// int main() {
//     int n = 8;
//     primeORnot(n);
//     return 0;
// }

// WAF TO PRINT ALL THE PRIME NUMBERS FROM 2 TO N
// void printPRIMESuptoN(int n) {
//     for(int i=2; i<=n; i++) {
//         if(isPrime(i)) {
//             cout << i << " ";
//         }
//     }
// }
// int main(){
//     int n = 20;
//     printPRIMESuptoN(n);
//     return 0;
// }

// WAF TO PRINT NTH FIBONACCI
// void printNthFibonacci(int n) {
//     if (n <= 0) {
//         cout << "INVALID INPUT" << endl;
//     }

//     int a = 0, b = 1;
//     if (n==1){
//         cout << a << endl;
//     } 
//     if (n==2) {
//         cout << b << endl;
//     }

//     int next;
//     for(int i=3; i<=n; i++) {
//         next = a + b;
//         a = b;
//         b = next;
//     }
//     cout << b << endl;
// }

// int main() {
//     int n = 7;
//     printNthFibonacci(n);
//     return 0;
// }

// DECIMAL TO BINARY
// int decToBinary(int decNum) {
//     int ans = 0, power = 1;
//     while(decNum > 0) {
//         int rem = decNum % 2;
//         decNum /= 2;
//         ans += rem * power;
//         power *= 10;
//     }
//     return ans; // binary form
// }
// int main() {
//     int decNum = 50;
//     cout << "Binary Number: "<< decToBinary(decNum);
//     return 0;
// }

// BINARY TO DECIMAL
// int bintoDecimal(int binNum) {
//     int ans = 0, power = 1;
//     while(binNum > 0) {
//         int rem = binNum % 10;
//         binNum /= 10;
//         ans += rem * power;
//         power *= 2;
//     }
//     return ans; // decimal form
// }
// int main() {
//     int binNum = 101;
//     cout << "Decimal Number: " << bintoDecimal(binNum);
//     return 0;
// }

// BITWISE OPERATORS  = & ^ | << >>
// int main() {
//     int a=6, b=10;
//     cout << (a & b) << endl; //2
//     cout << (a | b) << endl; //14
//     cout << (a ^ b) << endl; //12
//     cout << (10 << 2) << endl; //40
//     cout << (10 >> 1) << endl; //5
//     cout << (5 % 2 * 4) << endl;
//     return 0;
// }

// DATA TYPE MODIFIERS
int main() {
    cout << sizeof(int) << endl;
    cout << sizeof(long int) << endl;
    cout << sizeof(long long int) << endl;
    cout << sizeof(short int) << endl;
    unsigned int x = -10; // according to us it is negative num but compiler is taking it as positive number which starts from 1(which was for msb but since it is unsigned so msb does not matter)
    cout << x << endl;
}