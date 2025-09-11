#include <iostream>
#include <climits>
using namespace std;

// // SMALLEST AND LARGEST IN ARRAY
// int main(){
//     int nums[] = {5, 6, 1, 5};
//     int size = 4;
//     int smallest = INT_MAX;
//     int idx = -1;
//     for(int i=0; i<size; i++){
//         smallest = min(nums[i], smallest);
//     }
//     cout << "smallest:" << smallest;
//     return 0;
// }

// ARRAY PASSED BY REFERENCE
void func(int arr[]){
    arr[0] = 2000;
}
//both functions are same
void func2(int *ptr){
    ptr[0] = 2000;
}

// ARRAY PASSED AS POINTERS
int printArr(int nums[], int n){ // pointer to the array
    //int n = sizeof(nums); // 8 = size of int pointer
    //int n = sizeof(nums) / sizeof(int); //8/4 = 2// nums is a pointer and this will give size of pointer not array so we have to pass size
    for(int i=0; i<n; i++){
        cout << nums[i] <<" ";
    }
    cout << endl;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    // cout << arr << endl; // expectation: this will give the whole array, reality: array is converted to a pointer which is pointing at the 0th index of array and giving its address.
    // cout << *arr << endl; // printed 1 coz we defrence the pointer.
    // cout << *(arr+1) << endl; // arr[1]
    // cout << *(arr+2) << endl;    // arr[2]
    // cout << arr + 1 << endl; // +1 does not mean that address value is jumping by 1, its actually jumping by block of integer like 0,4,8...
    // cout << arr + 2 << endl;
    //func2(arr); // passing array name is eq. to passing the pointer
    //cout << arr[0] << endl; 

    int n = sizeof(arr) / sizeof(int); // 5
    cout << sizeof(arr) << endl; // 20

    printArr(arr, n);

}