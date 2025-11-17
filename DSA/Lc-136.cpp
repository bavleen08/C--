#include <iostream>
#include <vector>
using namespace std;

// 136. Single Number

int findSingle(vector<int> nums){
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans ^= nums[i];
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,1,3,3,2};
    cout << findSingle(nums);
    return 0;
}