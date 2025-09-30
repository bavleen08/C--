#include <iostream>
#include <algorithm> // for sort
#include <vector>
#include <set>
using namespace std;

// FINDING DUPLICATES IN THE ARRAY

// APPROACH 1
bool duplicate(int nums1[], int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<n+1; j++){
            if(nums1[i] == nums1[j]){
                return true;
            }
        }
    }
    return false;   // TC= O(n*n)
}

// APPROACH 2- USING RAW ARRAYS
bool containDuplicate1(int *nums1, int n){
    sort(nums1, nums1+n); // TC= nlogn
    for(int i=0; i<n; i++){  // TC= O(n)
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
    return false;          // overall TC= O(nlogn)
}   

// APPROACH 3- USING HASHMAPS
bool duplicate2(int nums1[], int n){
    set<int>s;
    for(int i=0; i<n; i++){  // TC= O(n)
        if(s.find(nums1[i]) == s.end()){
            s.insert(nums1[i]);
        } else{
            return true;
        }
    }
    return false;          // TC= O(n) SC= O(n)
}

int main(){
    int nums1[5] = {1,2,5,1,3};
    int n = sizeof(nums1) / sizeof(int);
    cout << containDuplicate1(nums1, n) << endl;

    vector<int> nums2 = {1,2,9,4,3};
    cout << containDuplicate2(nums2) << endl;
    cout << duplicate(nums1, n) << endl;
    cout << duplicate2(nums1, n) << endl;
    return 0;
}