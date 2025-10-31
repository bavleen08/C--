#include <iostream>
#include <vector>
using namespace std;
// 287. Find the Duplicate Number

    int findDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int num : nums){
        if(seen.count(num)){
            return num;
        }else{
            seen.insert(num);
        }
    } 
    return -1;
}