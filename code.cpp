#include <iostream> // we can give space here before < bcoz c++ compiler genereally ignore all the whitespaces, tabs
#include <iomanip>
#include <cmath>
using namespace std;

int main() {  // main function
    // cout << "hello world"<<endl <<"hi there"; // std::cout << "hello"
    
 // data types
    // int age = 25;
    // char grade = 'A';
    // float PI = 3.14f;
    // double price = 23.4;
    // bool isSafe = true; // true-> 1 false-> 0

 // type casting
    // char grades = 'b'; // 98
    // int value = grades; // implicit
    
    // double prices = 45.6; // even if it wouldne 45.9, the int value will still be 45
    // int newPrice = (int)prices; // explicit

// input
    // int age;
    // cout << "Enter your age: ";
    // cin >> age;

// operators
    // int a = 12, b = 5;

    // cout << a/double(b);

// loops
    // int count = 1;

    // while (count <= 5) {
    //     cout << count << " ";
    //     count++;
    // }
    // return 0;  
    
// if prime or not
    // int n;
    // cout << "enter n: ";
    // cin >> n;
    // int i;
    // for(i=2; i*i<=n; i++){ //i<=n-1 //O(underroot n approach) another way  2to n-1
    //     if(n%i==0){
    //         cout << "It is non prime";
    //         //break;
    //     } else{
    //         cout << "It is prime";
    //         //break;
    //     }
    // }

// sum of 1 to n which are divisible by 3
    // int n = 10;
    // int sum = 0;
    // int i;
    // for(i=1; i<=n; ++i){
    //     if(i%3==0){
    //         sum += i;
    //     }       
    // }
 // cout << sum; 
 // return 0;

// print factorial of n
// int n =3;
// int fact = 1;
// for(int i =1; i<=n; i++){
//     fact *= i;
// }
// cout << fact;

// 1. PATTERN PRINTING
// int n = 6;
// for(int i=1 ; i<=n; i++) {
//     for(int j=1 ; j<=n; j++){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 2. PRINTING CHARACTERS
// int n = 6;
// for(int i=0 ; i<n; i++) {
//     char ch = 'A';
//     for(int j=0 ; j<n; j++){
//         cout << ch;
//         ch = ch + 1;
//     }
//     cout << endl;
// }
// return 0;

// 3. PRINTING CONTINUOUS
// int n = 4;
// int num = 1;
// for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//         cout << num << " ";
//         num++;
//     }
//     cout << endl;
// }
// cout << "after pattern:"<< num;
// return 0;

// 4. PRINTING CONTINUOUS ABC
// int n = 3;
// char ch = 'A';
// for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//         cout << ch << " ";
//         ch = ch + 1;
//     }
//     cout << endl;
// }
// cout << "after pattern:"<< ch;
// return 0;

// 5. PRINTING TRIANGLE PATTERN 
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++){
//         cout << '*';
//     }
//     cout << endl;
// }
// return 0;

// 6. PRINTING TRIANGLE PATTERN WITH NUMBERS
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++){
//         cout << (i+1);
//     }
//     cout << endl;
// }
// return 0;

// 7. PRINTING TRIANGLE PATTERN WITH CHARACTERS REPITITIVE
// int n = 4;
// for(int i=0; i<n; i++) {
//     char ch = 'A'+ i;
//     for(int j=0; j<i+1; j++){
//         cout << ch << " ";
        
//     }
//     cout << endl;
// }
// return 0;

// 8. PRINTING TRIANGLE PATTERN WITH NUMBERS 1,12,123...
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=1; j<=i+1; j++){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 9. PRINTING REVERSE TRIANGLE
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j= i+1; j>0; j--) {
//         cout << j << " ";
//     }
//     cout << endl;
// }

// 10.  FLOYDS TRIANGLE WITH NUMBERS
// int n = 4;
// int num = 1;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++) {
//         cout << num << " ";
//         num++;    
//     }
//     cout << endl;
// }

// 11. FLOYDS TRIANGLE WITH CHARACTERS
// int n = 4;
// char ch = 'A';
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++) {
//         cout << ch << " ";
//         ch++;    
//     }
//     cout << endl;
// }

// 12. REVERSE TRIANGLE WITH NUMBERS
// int n = 4;
// char ch ='a';
// for(int i=0; i<n; i++) {
//     char temp = ch;
//     for(int j= i+1; j>0; j--) {
//         cout << temp-- << " ";
//         //cout << temp;

//     }
//     ch++;
//     cout << endl;
// }

// 13. INVERTED TRIANGLE WITH NUMBERS
// int n = 4;
// for(int i=0; i<n; i++) {
//     //spaces
//     for(int j=0; j<i; j++) {
//         cout << " ";
//     }
//     //nums
//     for(int j=0; j<n-i; j++) {
//         cout << (i+1);
//     }
//     cout << endl;
// }

// 14. INVERTED TRIANGLE WITH CHARACTERS
// int n = 5;
// char ch = 'A';
// for(int i=0; i<n; i++) {
//     //spaces
//     for(int j=0; j<i; j++) {
//         cout << " ";
//     }
//     //nums
//     for(int j=0; j<n-i; j++) {
//         cout << ch;
//         ch++; //<-- HERE: increases in every loop (so every character changes)  
//     }
//     ch++; //<-- HERE: increases once per row (so whole row has same character)
//     cout << endl;
// }

// 15. PYRAMID PATTERN
// int n = 4;
// for(int i=0; i<n; i++) {
//     //spaces: n-i-1
//     for(int j=0; j<n-i-1; j++){
//         cout << " ";
//     }
//     //nums1: 1 to i+1
//     for(int j=1; j<=i+1; j++){
//         cout << j;
//     }
//     //nums2
//     for(int j=i; j>=1; j--){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 16.HOLLOW DIAMOND PATTERN
// int n = 4;

//top part
// for(int i=0; i<n; i++){
//     // leading spaces
//     for(int j=0; j<(n-i-1); j++){ //my mistake- i wrote j<=(n-i-1) which affect the position of middle star
//         cout << " ";
//     }
//     cout << "*"; // first star //my mistake- i wrote this inside the inner loop which printed stars inside the spaces

//     if(i!=0){
//     //internal spaces
//     for(int j=0; j<(2*i-1); j++){
//         cout << " ";
        
//     }
//     cout << "*"; // second star

//     }
//     cout << endl;   
// }
// //bottom part
// for(int i=0; i<n-1; i++){ // 0 to n-2

//     //leading spaces
//     for(int j=0; j<i+1; j++){
//         cout << " ";
//     }
//     cout << '*';

//     //internal spaces
//     if(i!=n-2){ //my mistake- i wrote n-1 Ab i goes from 0 to n-2. So i != n-1 is always true in this loop. Even at the last iteration i = n-2, it's still i != n-1.
//         for(int j=0; j<(2*(n-i)-5); j++){
//             cout << " ";
//         }
//         cout << '*';
//     }
//     cout << endl;
// }
// return 0;

// 17. BUTTERFLY PATTERN
// int n = 6;

// //top part
// for(int i=0; i<n; i++){

//     // left triangle
//     for(int j=0; j<i+1; j++){
//         cout << '*';
//     }

//     // internal spaces
//     for(int j=0; j<2*(n-i)-2; j++){ //my mistake- i used 2*3-i which is not related to n so we need to related formula with n otherwise when n will n chnage this wont work. This is hardcoded for n = 4 using the number 3. That works only when n = 4, because 2 * (3 - i) gives internal spaces from 4 to 0, matching the required spacing for n=4. But this will break if n is changed, and is not scalable.
//         cout << " ";
//     }

//     // right triangle
//     for(int j=0; j<i+1; j++){
//         cout << "*";
//     }
//     cout << endl;    
// }

// //bottom part
// for(int i=0; i<n; i++){

//     // left inverted triangle
//     for(int j=0; j<n-i; j++){ // if j is initiated with 1 then only we will write j<=n-i
//         cout << "*";
//     }

//     // internal spaces
//     for(int j=0; j<2*i; j++){
//         cout << " ";
//     }
    
//     // right inverted triangle
//     for(int j=0; j<n-i; j++){
//         cout << "*";
//     }
//     cout << endl;   
// }
// return 0;

// float PI = 3.14159265359;
// double PI2 = 3.14159265359;
// cout << setprecision(12) <<"PI = " << PI <<endl; 
// cout << setprecision(12) << "PI2 = " << PI2;

// float penCost,pencilCost,eraserCost;
// cin>>penCost;
// cin>>pencilCost;
// cin>>eraserCost;
// float totCost=penCost+pencilCost+eraserCost;
// cout<<"total="<<totCost<<endl;
// cout<<"totalwithGST="<<(totCost+(0.18*totCost))<<endl;

//approach 1
// int n = 15;
// for(int i=1; i<=n; i++){
//         if(i%3 == 0 && i%5 == 0){
//         cout << "FIZZ BUZZ"<< endl;
//     }
//     else if(i%3 == 0){
//         cout << "FIZZ"<<endl;
//     }
//     else if(i%5 == 0){
//         cout << "BUZZ"<< endl;
//     }
//     else{
//         cout << i << endl;
//     }
// }

// approach 2
// int counter3 = 0, counter5 = 0;
// for (int i = 1; i <= n; i++ ){
//     counter3++ ; counter5++ ;
//     if (counter3 == 3 && counter5 == 5){
//         cout << "FizzBuzz"<< endl;
//         counter3 = 0; counter5 = 0;
//     }
//     else if (counter3 == 3){
//         cout << "Fizz"<<  endl;
//         counter3 = 0;
//     }
//     else if (counter5 == 5){
//         cout << "Buzz"<< endl;
//         counter5 = 0;
//     }
//     else{
//         cout << i << endl;
//     }
// }

// income tax calculator
// int income;
// float tax;
// cout << "Enter income(in lakhs): ";
// cin >> income;
// if(income < 5){
//     tax = 0;
// } else if(income < 10){
//     tax = 0.2 * income;
// } else{
//     tax = 0.3 * income;
// }
// cout << "Tax = "<< tax<<"%"<< "or" << tax * 100000 << endl;

//  switch statement
// int day = 6;
// switch(day){
//     case 1 : cout << "Monday"<<endl;
//              break;
//     case 2 : cout << "Tuesday"<<endl;
//              break;
//     case 3 : cout << "Wednesday"<<endl;
//              break;
//     case 4 : cout << "Thursday"<<endl;
//              break;
//     case 5 : cout << "Friday"<<endl;
//              break;
//     case 6 : cout << "Saturday"<<endl;
//              break;
//     case 7 : cout << "Sunday"<<endl;
//              break;
//     default : cout << "Invalid Day"<< endl;
// }

// calculator using switch
// int a, b;
// char op;

// cout << "Enter a: ";
// cin >> a;
// cout << "Enter b: ";
// cin >> b;
// cout << "Enter an operator(+,-,*,/): ";
// cin >> op;

// switch (op){
// case '+': cout << "Addition is = "<< a+b << endl;
//           break;
// case '-': cout << "Subtraction is = "<< a-b << endl;
//           break;
// case '*': cout << "Multiplication is = "<< a*b << endl;
//           break;
// case '/': cout << "Division is = "<< a/b << endl;
//           break;
// default : cout << "Invalid Operator" <<endl;
//           //no need for break keyword because eventually nothing is gonna print after this
// }

// leap year or not
// int year;
// cin >> year;
// if (year % 400 == 0) {
//     cout << "It is a LEAP year.";
// } else if (year % 100 == 0) {
//     cout << "It is not a leap year.";
// } else if (year % 4 == 0) {
//     cout << "It is a LEAP year.";
// } else {
//     cout << "It is NOT a leap year.";
//} //leap year ki defination ye hai ki  year 4 se divisible hona chahiye lekin agar vo century year hai (yani 100 se divisible hai) to use 400 se bhi divisible hona padega nhi to vo leap year nhi hoga for ex 1900 ye 4 se divisible hai to ye leap year hona chahiye but vo 100 se divisible hai but 400 se nhi isliye 1900 leap year nhi hai

// ARMSTRONG NUMBER
// int n, armstrongNum;
// cin >> n;
// int num = n; // creating a copy
// int dig1 = num % 10;
// num /= 10;
// int dig2 = num % 10;
// num /= 10;
// int dig3 = num;

// armstrongNum = (dig1*dig1*dig1) + (dig2*dig2*dig2) + (dig3*dig3*dig3);
// if (armstrongNum == n) {
//     cout << "This is an armstrong number.";
// } else {
//     cout << "This is not an armstrong number.";
// }

// SUM OF DIGITS
// int num = 10829;
// int lastDigit;
// int sumOFdigits = 0;
// while(num > 0) {
//     lastDigit = num % 10;
//     num /= 10;
//     sumOFdigits += lastDigit;
// }
// cout << sumOFdigits;

// SUM OF ODD DIGITS
// int num = 10829;
// int lastDigit;
// int sumOFdigits = 0;
// while(num > 0) {
//     lastDigit = num % 10;
//     num /= 10;
//     if (lastDigit % 2 != 0) { //odd
//         sumOFdigits += lastDigit;
//     } else {
//         continue;
//     }
// }
// cout << sumOFdigits;

// REVERSE NUMBER
// int num = 10829;
// int lastDigit;
// int sumOFdigits = 0;
// while(num > 0) {
//     lastDigit = num % 10;
//     cout << lastDigit;
//     num /= 10;
// }

// REVERSE NUMBER WITHOUT CALLING EACH DIGIT
// int num = 12345;
// int lastDigit;
// int power = 0;
// while(num > 0) {
//     lastDigit = num % 10;
//     power = (power * 10) + lastDigit;
//     num /= 10;
// }
// cout << power;

// BREAK & CONTINUE
// int n;
// do {
//     cout << "enter number:";
//     cin >> n;
//     if(n % 10 == 0){
//         //break;
//         continue;
//     }
//     cout << "your entered "<< n<< endl;
// } while(true); // infinite loop

//  PRIME OR NOT
// int n;
// cin >> n;
// bool isPrime = true;
// for(int i = 2; i <= sqrt(n); i++){
//     if(n % i == 0){
//         isPrime = false;
//         break;
//     } 
// }
// if (isPrime){
//     cout << "PRIME";
// } else {
//     cout << "NOT PRIME";
// }

// FACTORIAL
// int n;
// int factorialOfn = 1;
// cin >> n;
// for(int i=1; i<=n; i++){ 
//     factorialOfn *= i;
// }
// cout << "Factorial is "<< factorialOfn;
return 0;
}