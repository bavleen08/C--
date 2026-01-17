#include <bits\stdc++.h>
using namespace std;

// 1015. Smallest Integer Divisible by K  (Medium)

/*Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
Return the length of n. If there is no such n, return -1. Note: n may not fit in a 64-bit signed integer*/

int smallIntDiv(int k){
    if(k % 2 == 0 || k % 5 == 0){
        return -1;
    }
    int rem = 0;
    int length = 0;
    unordered_set<int> seen;
    while(true){
        length++;
        rem = (rem*10 +1)%k;
        if(rem == 0){
            return length;
        }
        if(seen.find(rem) != seen.end()){   // means rem is repeating
            return -1;   
        }
        seen.insert(rem);
    }
}

// Fast solution
int smallestRepunitDivByK(int k) {
    int r = 0;
    if(k%2==0 || k%5==0){
        return -1;
    }
    for(int i=0; i<=k; i++){
        r = (r*10 + 1) % k;
        if(r==0){
            return i;
        }
    }
    return -1;
}

int main(){
    cout << smallIntDiv(7);
    return 0;
}