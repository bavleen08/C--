#include <iostream>
using namespace std;

// // function definition
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

// sum 1ton
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

// calculate n factorial
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

// pass by value
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