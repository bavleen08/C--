#include <iostream>
#include <vector>
#include <unordered_map>
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

int mE(vector<int>& nums){
    int candidate = 0;
    int count = 0;
    for(int num : nums){
        if(count == 0){
            candidate = num;
            count++;
        }
        else if(num == candidate) count ++;
        else count--;
    }
    return candidate;
}

void majEl(vector<int> &nums){
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++){
        if(m.count(nums[i])){
            m[nums[i]]++;
        } else{
            m[nums[i]] = 1;
        }
    }
    for(pair<int, int> vec: m){
        if(vec.second > nums.size()/3){
            cout << vec.first << " ";
        }
    }
}

int main(){
    vector<int> nums = {3,3,2,2,2,2,2};
    majEl(nums);
    return 0;
}

// BRUTE FORCE

// for(int i =0; i<n; i++){
//     maj = nums[i];
//     for(int j=0; j<n; j++){
//         if(nums[j] == maj){
//             count ++;
//         }
//     }
//     if(count > n/2){
//         return maj;
//     }else{
//         count = 0;
//     }
// }