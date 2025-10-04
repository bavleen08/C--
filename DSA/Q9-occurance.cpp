#include <iostream>
using namespace std;

// Print the number of all 7’s that are in the 2d array.

int occurs(int arr[][3], int n, int m, int key){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == key){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int arr[2][3] = {{4,7,7},
                     {8,8,7}};
    cout << occurs(arr,2,3,7);
}