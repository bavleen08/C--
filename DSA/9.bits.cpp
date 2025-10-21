#include <iostream>
using namespace std;

// Check if Odd or Even
void OddorEven(int num){
    if(!(num & 1)){
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }
}

// Get ith bit
int getBit(int num , int i){
    // int mask = 1 << i;
    // if(!(num & mask)){
    //     return 0;
    // } else {
    //     return 1;
    // }

    int mask = num >> i;
    if(!(mask & 1)){
        return 0;
    } else {
        return 1;
    }
}

// Set ith bit
int setBit(int num , int i){
    int bitMask = 1 << i;
    return (num | bitMask);
}

// Clear ith bit
int clearBit(int num , int i){
    int bitMask = ~(1 << i);
    return (num & bitMask);
}

// Check for power of 2
bool isPowerOf2(int num){
    if(!(num & (num-1))){
        return true;
    } else {
        return false;
    }
}

// Update ith bit in a number according to the value
void updateithBit(int num, int i, int val){
    // clear ith bit
    num = num & ~(1 << i);

    // take or
    num = num | (val << i);

    cout << num;
}

// Clear last i bits
int cleariBits(int num , int i){
    return (num & (~0 << i));
}

// Count set bits
int countBits(int num){
    int count = 0;
    while(num > 0){
        int lastDig = num & 1;
        count += lastDig;
        num = num >> 1;
    }
    return count;
}

// Fast exponentiation
int fastExp(int x, int n){
    int ans = 1;
    while(n > 0){
        int lastDig = n & 1;
        if(lastDig){
            ans = ans * x;
        }
        x = x*x;
        n = n >> 1;
    }
    return ans;
}
int main(){
    cout << fastExp(3,5);
    return 0;
}