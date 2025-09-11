#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

// WAF TO REVERSE INT
int reverseInteger(int num) {
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num; // makes it positive
    }
    
    //Convert to string
    string str = to_string(num);

    //reverse the string
    reverse(str.begin(), str.end());

    //back to int
    int reversedNum = stoi(str);

    if (isNegative) {
        reversedNum = -reversedNum;
    }
    return reversedNum;
}

int main(){
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
return 0;
}
