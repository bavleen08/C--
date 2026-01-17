#include <bits\stdc++.h>
using namespace std;

void findOccurences(int arr[], int key, int i, int n){
    if(i==n){
        return;
    }
    if(arr[i] == key){
        cout<< i<< " ";
    }
    findOccurences(arr, key, i+1, n);
}

int main(){
    return 0;
}