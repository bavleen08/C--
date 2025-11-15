#include <iostream>
#include <vector>
using namespace std;

// 1. Printing numbers in increasing order
void print(int n){
    if(n==0){
        return;
    }
    
    print(n-1);
    cout << n << endl;
}

// 2. Sum of n natural numbers
int sum(int n){
    if(n==1){
        return 1;
    }
    return n +  sum(n-1);
}

// 3. Print nth fibonacci number
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// 4. Check if array is sorted
bool isSorted(int arr[] , int n, int i){
    if(i==(n-1)) return true;
    if(arr[i] > arr[i+1]) return false;
    return isSorted(arr, n, i+1);
}

// 5. First occurence of element
int firstOccur(vector<int> arr, int i, int target){
    if(i==arr.size()) return -1;
    if(arr[i]== target) return i;
    return firstOccur(arr, i+1, target);
}

// 6. Last occurence of element
int lastOccur(vector<int> arr, int i, int target){
    if(i==arr.size()) return -1;
    int idx = lastOccur(arr, i+1, target);
    if(idx==-1 && arr[i] == target){
        return i;
    }
    return idx;
}

// 7. Print x to the power n
// O(logn)
int pow(int x, int n){
    if(n==0){
        return 1;
    }
    return x * pow(x,n-1);
}
// O(n)
int PowerOfx(int x, int n){
    if(n==0) return 1;
    int halfPow = PowerOfx(x, n/2);
    int halfPowSq = halfPow * halfPow;
    if(n % 2 != 0) return x * halfPowSq;
    return halfPowSq;
}

int main(){
    cout << pow(2,8);
    cout << PowerOfx(2,8);
    return 0;
}