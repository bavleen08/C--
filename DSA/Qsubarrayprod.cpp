#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// FINDING MAXIMUM PRODUCT OF SUBARAYS

// void maxSubarrayprod(int *arr, int n){
//     int maxprod = 0;
//     for(int start = 0; start <n; start ++){
//         int prod = 1;
//         for (int end= start; end < n; end++){
//             prod *= arr[end];
//             cout << prod << " ";
//             maxprod = max(maxprod, prod);
//             cout << ",";
//         }
//         cout << endl;     
//     }
//     cout << " max product: " << maxprod << endl;
// }
// int main(){
//     int arr[3] = {-2, 0,1};
//     int n = sizeof(arr) / sizeof(int);
//     maxSubarrayprod(arr, n);
// }

void maxSubarrayprod(int *arr, int n){
    int maxprod = arr[0];  // start with first element
    for(int start = 0; start < n; start++){
        int prod = 1;
        for (int end = start; end < n; end++){
            prod *= arr[end];
            cout << prod << " ";  // print current product
            maxprod = max(maxprod, prod);
            cout << ",";
        }
        cout << endl;
    }
    cout << "Max product: " << maxprod << endl;
}

int main(){
    int arr[] = {3, -2, -1, 5, 9};
    int n = sizeof(arr) / sizeof(int);
    maxSubarrayprod(arr, n);
}

// intmaxProduct(vector<int>&nums){
//     intmaxTillNow=nums[0];
//     intminTillNow=nums[0];
//     intans=maxTillNow;
//     for(inti=1;i<nums.size();i++){
//         intcurr=nums[i];
//         inttempMaxTillNow=max(curr,max(maxTillNow*curr,minTillNow*curr));
//         minTillNow=min(curr,min(maxTillNow*curr,minTillNow*curr));
//         maxTillNow=tempMaxTillNow;ans=max(maxTillNow,ans);
//     }
//     return ans;
// }