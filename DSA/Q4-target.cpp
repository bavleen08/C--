#include <iostream>
using namespace std;

// FIND THE TARGET AND PRINT ITS INDEX

// APPROACH 1= linear search

// APPROACH 2= binary search
int findTarget(int *nums, int n, int tar){
    int st = 0; int end = n-1;
    while(st <= end){
        int mid = (st+end)/2;

        if(nums[mid] == tar){
            return mid;
        }

        if(nums[st] <= nums[mid]){
            if(nums[st] <= tar && tar < nums[mid]){
                end = mid -1;
            } else{
                st = mid +1;
            }
        } else {
            if(nums[mid] <= tar && tar < nums[end]){
                st = mid +1;
            } else{
                end = mid -1;
            }
        }
    }
    return -1;       // TC= O(logn)
}
int main(){
    int nums[5] = {7,8,9,5,6};
    int n = sizeof(nums) / sizeof(int);
    cout << findTarget(nums, n, 6);

}
