#include <iostream>
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
    // for(i=2; i*i<=n; i++){ //i<=n-1
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

// 1. pattern printing
// int n = 6;
// for(int i=1 ; i<=n; i++) {
//     for(int j=1 ; j<=n; j++){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 2. printing character
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

// 3. printing continuous
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

// 4. printing continuous abc
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

// 5. priting triangle pattern
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++){
//         cout << '*';
//     }
//     cout << endl;
// }
// return 0;

// 6. priting triangle pattern with numbers
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++){
//         cout << (i+1);
//     }
//     cout << endl;
// }
// return 0;

// 7. priting triangle pattern with characters repetitive
// int n = 4;
// for(int i=0; i<n; i++) {
//     char ch = 'A'+ i;
//     for(int j=0; j<i+1; j++){
//         cout << ch << " ";
        
//     }
//     cout << endl;
// }
// return 0;

// 8. priting triangle pattern with numbers 1,12,123...
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=1; j<=i+1; j++){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 9. printing reverse triangle
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j= i+1; j>0; j--) {
//         cout << j << " ";
//     }
//     cout << endl;
// }

// 10. floyds triangle with numbers
// int n = 4;
// int num = 1;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++) {
//         cout << num << " ";
//         num++;    
//     }
//     cout << endl;
// }

// 11. floyds triangle with characters
// int n = 4;
// char ch = 'A';
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++) {
//         cout << ch << " ";
//         ch++;    
//     }
//     cout << endl;
// }

// 12. reverse triangle with characters
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

// 13. inverted triangle with numbers
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

// 14. inverted triangle with characters
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

// 15. pyramid pattern
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
}


