#include <bits\stdc++.h>
using namespace std;

// Merge Sort Algorithm --> TC = O(nlogn)   SC = O(n)

// CONQUER
void merge(int arr[], int si, int ei, int mid){
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while(i <= mid && j <= ei){   // we exit the loop when one iterator goes out of array
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
     
    // to print rest of the values of other part ,,,,, only one of the loop will run
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }

    // vector temp --> org arr
    for(int idx=si, x=0; idx<=ei; idx++){  // loop on org array
        arr[idx] = temp[x++];
    }
}

// DIVIDE
void mergeSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int mid = si + ((ei - si)/2); // same as (si+ei)/2
    mergeSort(arr, si, mid);     // left part, assuming that they will give us sorted list
    mergeSort(arr, mid+1, ei);   // right part
    merge(arr, si, ei, mid);
}

// void printArr(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }



// Quick Sort Algorithm --> TC = O(nlogn), worst= n*n   SC = O(1)
int partitionFunc(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];
    for(int j = si; j<ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}
void quickSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int pivotIdx = partitionFunc(arr, si, ei);
    quickSort(arr, si, pivotIdx-1);
    quickSort(arr, pivotIdx+1, ei);
}

void printArr(char arr[][10], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Search in Rotated Search --> modified binary search  O(logn)
int search(int arr[], int si, int ei, int tar){
    if(si > ei){   // si >= ei is wrong if there left only one val and tar is also that value then ans will come -1
        return -1;
    }
    int mid = si + (ei-si)/2;
    if(arr[mid] == tar){
        return mid;
    }

    // L1
    if(arr[si] <= arr[mid]){
        if(arr[si] <= tar && tar < arr[mid]){
            return search(arr, si, mid-1, tar);  // left half
        }
        else{                             
            return search(arr, mid+1, ei, tar);  // right half
        }
    } // only one of the calls will run not all the 4
    // L2
    else{
        if(arr[mid] < tar && tar <= arr[ei]){
            return search(arr, mid+1, ei, tar);  // right half
        }
        else{                             
            return search(arr, si, mid-1, tar);  // left half
        }
    }
}

// merge sort array of strings 
void mergeFunc(char arr[][10], int st, int end, int mid){
    vector<string> temp;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(strcmp(arr[i], arr[j]) < 0){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= end){
        temp.push_back(arr[j++]);
    }

    // vector temp --> org arr
    for(int idx=st, x=0; idx<=end; idx++){  // loop on org array
        strcpy(arr[idx], temp[x++].c_str());
    }
}
void ms(char arr[][10], int st, int end){
    if(st >= end){
        return;
    }
    int mid = st+ (end-st)/2;
    ms(arr, st, mid);
    ms(arr, mid+1, end);
    mergeFunc(arr, st, end, mid); 
}
int main(){
    // int arr[6] = {6,7,8,3,4,5};
    // int n = 6;

    // mergeSort(arr, 0, n-1);
    // printArr(arr, n);
    // quickSort(arr, 0, n-1);
    char arr[5][10] = {"sam", "joe", "doe"};
    int n = 3;
    ms(arr, 0, n-1);
    printArr(arr, n);
    //cout << search(arr, 0, n-1, 3);
    return 0;
}