#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int key){
    int st = 0, end = n-1;
    while(st <= end){
        int mid = (st + end) / 2;
        if(arr[mid] == key){ // key found
            return mid;
        } else if(arr[mid] < key){ // 2nd half
            st = mid +1;
        } else { // 1st half
            end = mid-1;
        }
    }
    return -1;
}
int main (){
    int arr[] = {2,4,6,8,10,12,14};
    int n = sizeof(arr) / sizeof(int);

    cout << binarySearch(arr, n, 12);

    return 0;
}
