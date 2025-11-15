#include <iostream>
#include <vector>
using namespace std;

// 169. Majority Element

int majorityElement(vector<int>& nums) {
    int maj = 0, lead = 0;
    for(int i =0; i<nums.size(); i++){
        if(nums[i] == maj){
            lead++;
        }
        else if(lead > 0){
           lead--;
        }
        else{
            maj = nums[i];
            lead++;
        }
    }
    return maj;
}

int main(){
    return 0;
}