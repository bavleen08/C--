#include <iostream>
#include <climits>
using namespace std;

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
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    //printSubarrays(arr , n);
    maxSubarraySum1(arr, n);

}