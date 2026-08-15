#include <iostream>
using namespace std;

// SEARCH IN SORTED MATRIX

// approach 1 - BRUTE FORCE   O(n*m)
void sortedMat1(int mat[][4], int n, int m, int key){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == key){
                cout << i << "," << j << endl;   
                return; // stop after finding
            }  
        }
    } 
    cout << "Not found" << endl;     
}

// approach 2 - BINARY SEARCH  O(n*logm)
void sortedMat2(int mat[][4], int n, int m, int key){
    for(int i=0; i<n; i++){ //go row by row , for column- i<m
        int start = 0, end = m-1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(mat[i][mid] == key){
                cout << i << "," << mid<< endl;
                return;
            }
            if(key < mat[i][mid]){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
    }
    cout << "-1";
}

// approach 3 - STAIRCASE SEARCH  O(n+m)
bool sortedMat3(int mat[][4], int n, int m, int key){
    int i = 0, j=m-1;
    while(i<n && j>=0){
        if(mat[i][j] == key){
            cout << i << "," << j << endl;
            return true;
        }
        if(mat[i][j] > key){
            // move left
            j--;
        }
        if(mat[i][j] < key){
            // move down
            i++;
        }
    }
    cout << "key not found";
    return false;
}
int main(){
    int mat[4][4] = {{10,20,30,40},
                     {15,25,35,45},
                     {27,29,37,48},
                     {32,33,39,50}};
    //sortedMat1(mat,4,4,33);
    //sortedMat2(mat,4,4,33);
    sortedMat3(mat,4,4,50);
    return 0;
}

//search in sorted matrix when last element of one row is always smaller than the first element of next row

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();

//         int st = 0;
//         int end = rows*cols-1;

//         while(st <= end){
//             int mid = st + (end-st)/2;

//             int row = mid / cols;
//             int col = mid % cols;
//             if(matrix[row][col] == target) return true;

//             else if(matrix[row][col] < target){
//                 st = mid+1;
//             }
            
//             else{
//                 end = mid-1;  
//             }
//         }
//         return false;
//     }
// };