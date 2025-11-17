#include <iostream>
#include <vector>
using namespace std;

// 2022. Convert 1D array into  2D array

void rotate(int org[], int m, int n, int size){   // vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    int arr[100][100]; // fixed size to avoid VLA issue  // vector<vector<int>> mat(m, vector<int>(n));
    if(size != m*n){
        cout << "[]"<< endl;
        return;
    }
    int row = 0, col = 0;
    for(int i=0; i < size; i++){
        arr[row][col] = org[i];
        col++;
        if(col==n){
            row++;
            col = 0;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n));
        if(original.size() != m*n){
            return{};
        }
        int row = 0, col=0;
        for(int i=0; i<original.size(); i++){
            mat[row][col] = original[i];
            col++;
            if(col == n){
                row++;
                col = 0;
            }
        }
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                cout << mat[i][j] << endl;
            }
        }
        return mat;
    }

int main(){
    int org[4] = {1,2,3,4};
    rotate(org,2,2,4);
    return 0;
}