#include <iostream>
#include <algorithm> // for sort
#include <vector>
using namespace std;

// FINDING DUPLICATES IN THE ARRAY

// USING RAW ARRAYS
bool containDuplicate1(int *nums1, int n){
    sort(nums1, nums1+n);
    for(int i=0; i<n; i++){
        if(nums1[i] == nums1[i-1]){
            return true;
        }
    }
    return false;
}

// USING VECTORS
bool containDuplicate2(vector<int>& nums2){
    sort(nums2.begin(), nums2.end());
    for(int i=0; i<nums2.size(); i++){
        if(nums2[i] == nums2[i-1]){
            return true;
        }
    }
    return false;
}

int main(){
    int nums1[5] = {1,2,5,1,3};
    int n = sizeof(nums1) / sizeof(int);
    cout << containDuplicate1(nums1, n) << endl;

    vector<int> nums2 = {1,2,9,4,3};
    cout << containDuplicate2(nums2) << endl;
    return 0;
}


