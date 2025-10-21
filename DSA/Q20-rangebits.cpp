#include <iostream>
#include <vector>
using namespace std;

// Clear the range of bits from i to j
void ClearBits(int num, int i, int j){
    int a = (~0) << j+1;   // 1s before j
    int b = (1 << i) - 1;  // 1s after i
    int mask = a | b;      // Combine both
    num = num & mask;     // Clear bits in range i to j

    cout << num << endl;
}

int main(){}