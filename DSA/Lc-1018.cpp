#include <bits\stdc++.h>
using namespace std;

// 1018. Binary Prefix Divisible By 5   (Easy)

vector<bool> prefixDivBy5(vector<int> nums){
    vector<bool> ans;
    int prefix = 0;
    for(int b : nums){
        prefix = ((prefix * 2) + b) % 5;  // same as prefix << 1
        ans.push_back(prefix == 0);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,0,1};
    vector<bool> res = prefixDivBy5(nums);
    cout << boolalpha;  // It is a formatting flag for cout It tells cout: “When printing booleans, print words (true/false), not 1/0.” once its enable it is on until u off it with cout << noboolalpha
    for(bool x: res){
        cout << x << " ";
    }
    return 0;
}
