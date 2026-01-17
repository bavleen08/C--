#include <bits\stdc++.h>
using namespace std;

// APPROACH 1
// O(N log N) using sorting and linear scan  ,  SC = O(1)
int findFinalValue(vector<int>& nums, int original) {
    sort(nums.begin(), nums.end());
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == original){
            original *= 2;
        }
    }
    return original;
}

// APPROACH 2
// O(N) using Hash table -> better  ,  SC = O(N)
int findval(vector<int>& nums, int original){
    unordered_set<int> numSet(nums.begin(), nums.end());
    while(numSet.count(original)){   // it jumps directly to that memory location
        original *= 2;
    }
    return original;
}
// The unordered_set is implemented using a Hash Table. It uses a hashing function to calculate the exact memory location (bucket) where a number should be stored.

int main(){
    return 0;
}