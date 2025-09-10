// BITWISE OPERATORS  = & ^ | << >>
// int main() {
//     int a=6, b=10;
//     cout << (a & b) << endl; //2
//     cout << (a | b) << endl; //14
//     cout << (a ^ b) << endl; //12
//     cout << (10 << 2) << endl; //40
//     cout << (10 >> 1) << endl; //5
//     cout << (5 % 2 * 4) << endl;
//     return 0;
// }

// DATA TYPE MODIFIERS
// int main() {
//     cout << sizeof(int) << endl;
//     cout << sizeof(long int) << endl;
//     cout << sizeof(long long int) << endl;
//     cout << sizeof(short int) << endl;
//     unsigned int x = -10; // according to us it is negative num but compiler is taking it as positive number which starts from 1(which was for msb but since it is unsigned so msb does not matter)
//     cout << x << endl;
// }

// DECIMAL TO BINARY
int decToBinary(int decNum) {
    int ans = 0, power = 1;
    while(decNum > 0) {
        int rem = decNum % 2;
        decNum /= 2;
        ans += rem * power;
        power *= 10;
    }
    return ans; // binary form
}


// BINARY TO DECIMAL
int bintoDecimal(int binNum) {
    int ans = 0, power = 1;
    while(binNum > 0) {
        int rem = binNum % 10;
        binNum /= 10;
        ans += rem * power;
        power *= 2;
    }
    return ans; // decimal form
}