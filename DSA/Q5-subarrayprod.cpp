#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// FINDING MAXIMUM PRODUCT OF SUBARAYS

// APPROACH 1        TC= O(n*n)
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

// APPROACH 2  KADANE ALOGRITHM     TC= O(n)
int maxProduct(int arr[], int n){
    int maxi = arr[0];
    int mini = arr[0];
    int ans = maxi;
    for(int i=1; i<n; i++){
        if(arr[i] < 0){
            swap(mini, maxi);
        }
        maxi = max(arr[i], maxi*arr[i]);
        mini = min(arr[i], mini*arr[i]);
        ans = max(ans, maxi);
    }
    return ans;
}

int main(){
    int arr[] = {3, -2, -1, 5, 9};
    int n = sizeof(arr) / sizeof(int);
    maxSubarrayprod(arr, n);
}