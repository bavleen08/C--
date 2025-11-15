#include <iostream>
#include <vector>
using namespace std;

// 303. Range Sum Query - Immutable

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){
            prefix.push_back(nums[i] + prefix[i-1]);
        }
        
    }
    
    int sum = 0;
    int sumRange(int left, int right) {
        if(left > 0){
            sum = prefix[right] - prefix[left-1];
        }
        else{
            sum = prefix[right];
        }
        return sum;
    }
};