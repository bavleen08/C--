#include <iostream>
using namespace std;

int reverse(int n){
    int res =0;
    while(n > 0){
    int lastdig = n % 10;
    res = 10*res + lastdig;
    n /= 10;
    }
    return res;
}
bool ispalindrome(int num){
    int revnum = reverse(num);
    return num == revnum;
}

int main(){
    return 0;
}