#include <iostream>
#include <climits>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// BUBBLE SORT ALGORITHM
void bubbleSort(int *arr, int n){
    bool isSwap = false;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){ // array is already is sorted
        return;
    }
    }
    print(arr, n);
    
}

// SELECTION SORT
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr, n);
}

// INSERTION SORT
void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while (prev >=0 && arr[prev] > curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
    print(arr,n);
}

// COUNTING SORT
void countSort(int arr[], int n){
    int freq[100000] = {0}; 
    int minVal = INT_MAX; int maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        minVal = min(minVal , arr[i]);
        maxVal = max(maxVal , arr[i]);
    }

    for(int i=0; i<n; i++){  // O(n)
        freq[arr[i]]++;
    }

    for(int i=minVal, j=0; i<maxVal; i++){  // O(range)
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr, n);
}

int main(){
    int arr[5] = {3,3,4,1,2};
    bubbleSort(arr, 5);
    selectionSort(arr, 5);
    insertionSort(arr, 5);
    countSort(arr,5);
    return 0;
}