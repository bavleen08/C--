#include <iostream>
#include <algorithm>
using namespace std;

// 88. Merge Sorted Array

int main(){
    int nums1[6] = {1,2,2};
    int nums2[3] = {3,5,6};
    int m = 3;
    int n = 3;

    // Approach 1
    for(int i=0; i<n; i++){  // O(n)
        nums1[m+i] = nums2[i];
    }
    sort(nums1, nums1+(m+n)); // (m+n)log(m+n)
    for(int i=0; i<m+n; i++){
        cout << nums1[i]<<" ";
    }

    // Optimization   // O(m+n)
    int index = m+n-1;
    int i = m-1;
    int j = n-1;
    while(i >=0 && j >= 0){
        if(nums1[i] <= nums2[j]){
            nums1[index] = nums2[j];
            index--;
            j--;
        } else{
            nums1[index] = nums1[i];
            index--;
            i--;
        }
    }
    while(j>=0){
        nums1[index] = nums2[j];
        index--;
        j--;
    }
    for(int i=0; i<m+n; i++){
        cout << nums1[i]<<" ";
    }
    
    return 0;
}