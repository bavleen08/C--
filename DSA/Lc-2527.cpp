#include <iostream>
#include <vector>
using namespace std;

// 2527. Find Xor-Beauty of Array

int xorBeauty(vector<int> nums, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ans = ans ^ ((nums[i] | nums[j]) & nums[k]);
            }
        }
    }
    return ans; 
}

int main(){
    vector<int> nums = {1,4};
    cout << xorBeauty(nums, 2);
    return 0;
}

