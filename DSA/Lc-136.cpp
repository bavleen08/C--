#include <iostream>
#include <vector>
using namespace std;

// 136. Single Number

int findSingle(vector<int> nums, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= nums[i];
    }
    return ans;
}