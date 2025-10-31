#include <iostream>
#include <vector>
using namespace std;

// 645. Set Mismatch
vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n+1, 0);
    int duplicate = -1, missing = -1;
    for(int i=0; i<n; i++){
        freq[nums[i]]++;
    }
    for(int i = 1; i<=n; i++){
        if(freq[i] == 2){
            duplicate = i;
        } else if(freq[i] == 0){
            missing = i;
        }
    }
    return {duplicate, missing};
}

int main(){
    vector<int> nums = {1,2,2,4};
    // vector<int> ans = findErrorNums(nums);
    // cout << ans[0] <<','<< ans[1];
    vector<pair<int>> res = findErrorNums(nums);
    cout << res;
}