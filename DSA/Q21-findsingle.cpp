#include <iostream>
#include <vector>
using namespace std;

// Find the element which is not repeating
int findSingle(vector<int> nums, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= nums[i];
    }
    return ans;
}