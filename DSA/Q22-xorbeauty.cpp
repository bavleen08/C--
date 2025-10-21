#include <iostream>
#include <vector>
using namespace std;

// Find XOR Beauty
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