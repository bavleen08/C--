#include <bits\stdc++.h>
using namespace std;

// 3190. Find Minimum Operations to Make All Elements Divisible by Three

int minimumOperations(vector<int>& nums) {
    int diff = 0;
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        diff = 3 - nums[i];
        if(diff == 0 || diff%3 == 0){
            continue;
        }else{
            count++;
        }
    }
    return count;   
}

int minimumOperations(std::vector<int>& nums) {
    int count = 0;
    
    // Use a range-based for loop for cleaner iteration
    for (int num : nums) {
        // The simplest, most direct check for "is not a multiple of 3"
        // If the remainder when divided by 3 is not 0, it's not a multiple.
        if (num % 3 != 0) {
            count++;
        }
    }
    
    return count;
}

int main(){
    return 0;
}