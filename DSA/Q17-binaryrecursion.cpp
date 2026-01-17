#include <bits\stdc++.h>
using namespace std;

// Write a recursive function to perform Binary Search.
// TC = O(logn)    SC = O(logn)
int findKey(vector<int> arr, int key, int si, int ei){
    if(si > ei){
        return -1;
    }
    int mid = si + ((ei - si)/2);

    if(arr[mid] == key){
        return mid;
    }
    else if(key > arr[mid]){
        return findKey(arr, key, mid+1, ei);  // my mistake= i didnot returned it
    }
    else{
        return findKey(arr, key, si, mid-1);
    }
}
// The function sometimes works because of undefined behavior, but logically it is incorrect since recursive calls do not return their values.
// calling the function and return a function are not the same
    

int main(){
    int arr[5] = {1,2,2,4,2};
}