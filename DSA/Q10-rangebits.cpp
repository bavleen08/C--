#include <iostream>
using namespace std;

// Clear the range of bits from i to j

// Approach 1
void ClearBits(int num, int i, int j){
    int a = (~0) << j+1;   // 1s before j
    int b = (1 << i) - 1;  // 1s after i
    int mask = a | b;      // Combine both
    num = num & mask;     // Clear bits in range i to j

    cout << num << endl;
}

// Approach 2
int clearRangeOfBits(int num, int i){
    int bitMask = ~(1 << i);
    return (num & bitMask);
}
int rangeOfBits(int num, int i, int j){
    for(int p=i; p<=j; p++){
        num = clearRangeOfBits(num, i);
        return num;
    }
}

int main(){
    return 0;
}