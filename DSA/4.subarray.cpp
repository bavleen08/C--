#include <iostream>
#include <climits>
using namespace std;

// PRINTING SUBARRAYS
void printSubarrays(int *arr, int n){
    for(int start = 0; start <n; start ++){
        for(int end=start; end<n; end++){
            //cout << "(" << start << "," <<end << ")  ";
            for(int i=start; i<=end; i++){
                cout << arr[i];
            }
            cout << ", ";
        }
        cout<<endl;
    }
}

// BRUTE FORCE
void maxSubarraySum1(int *arr, int n){
    int max_Sum = INT_MIN;
    for(int start = 0; start <n; start ++){
        for(int end=start; end<n; end++){
            int currsum = 0;
            for(int i=start; i<=end; i++){
                currsum += arr[i];
            }
            cout << currsum <<", ";
            max_Sum = max(max_Sum , currsum);
        }
        cout<<endl;
    }
    cout << "Maximum sum is: "<< max_Sum;
}

// OPTIMIZATION
void maxSubarraySum2(int *arr, int n){
    int max_Sum = INT_MIN;
    for(int start = 0; start <n; start ++){
        int currsum = 0;
        for(int end=start; end<n; end++){
            currsum += arr[end];
            cout << currsum <<", ";
            max_Sum = max(max_Sum , currsum);
        }
        cout<<endl;
    }
    cout << "Maximum sum is: "<< max_Sum;
}

// KADANE'S ALGORITHM
void maxSubarraySum3(int *arr, int n){
    int max_Sum = INT_MIN;
    int currsum = 0;
    for(int start = 0; start <n; start ++){
        currsum += arr[start];
        max_Sum = max(max_Sum , currsum);
        if (currsum < 0){
            currsum = 0;
        }
    }
    cout << "Maximum sum is: "<< max_Sum;
}

int main(){
    int arr[] = {2,-3, 6,-5, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    //printSubarrays(arr , n);
    maxSubarraySum3(arr, n);
    return 0;
}