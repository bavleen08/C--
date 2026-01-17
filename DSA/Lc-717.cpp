#include <bits/stdc++.h>
using namespace std;

// 717. 1-bit character and 2-bit characters (Easy)

bool findBitChar(vector<int> bits){
    int n = bits.size();
    int i = 0;
    while(i < (n-1)){
        if(bits[i] == 1){
            i +=2;
        }
        else{
            i +=1;
        }
    }
    return (i == n-1);
}

// using recursion
bool findBitChar2(vector<int> bits, int i){
    int n = bits.size();
    if(i = n-1){
        return bits[i] == 0;
    }
    if(i >= n){
        return false;
    }
    if(bits[i] == 1){
        return findBitChar2(bits, i+2);
    } else{
        return findBitChar2(bits, i+1);
    }
}
int main(){
    vector<int> bits = {0,1,0,0,0};
    cout << findBitChar(bits);
    findBitChar2(bits, 0);
    return 0;
}