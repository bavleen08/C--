#include <iostream> // we can give space here before < bcoz c++ compiler genereally ignore all the whitespaces, tabs
#include <iomanip>
#include <cmath>
using namespace std;

int main() {  // main function
    // cout << "hello world"<<endl <<"hi there"; // std::cout << "hello"
    
 // DATA TYPES
    // int age = 25;
    // char grade = 'A';
    // float PI = 3.14f;
    // double price = 23.4;
    // bool isSafe = true; // true-> 1 false-> 0

 // TYPE CASTING
    // char grades = 'b'; // 98
    // int value = grades; // implicit
    
    // double prices = 45.6; // even if it wouldne 45.9, the int value will still be 45
    // int newPrice = (int)prices; // explicit

// INPUT
    // int age;
    // cout << "Enter your age: ";
    // cin >> age;

// OPERATORS
    // int a = 12, b = 5;

    // cout << a/double(b);

// LOOPS
    // int count = 1;

    // while (count <= 5) {
    //     cout << count << " ";
    //     count++;
    // }
    // return 0;  

//  SWITCH STATEMENT
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

// CALCULATOR USING SWITCH
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

// PRECISION (include iomanip)
// float PI = 3.14159265359;
// double PI2 = 3.14159265359;
// cout << setprecision(12) <<"PI = " << PI <<endl; 
// cout << setprecision(12) << "PI2 = " << PI2;

// SUM OF 1 TO N WHICH ARE DIVISIBLE BY 3
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

// FIZZ BUZZ
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

// INCOME TAX CALCULATOR
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


// LEAP YEAR OR NOT
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

return 0;
}