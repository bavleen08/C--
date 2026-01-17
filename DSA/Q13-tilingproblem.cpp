#include <bits/stdc++.h>
using namespace std;

// Count total ways to tile a floor(2xn) with tiles(2x1) (GOOGLE)  (AMAZON)

int tileWays(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return tileWays(n-1) + tileWays(n-2);
}

int main(){
    cout << tileWays(5);
    return 0;
}