#include <iostream>
using namespace std;

// Write a program to Find Transpose of a Matrix

void transpose(int mat[][3], int n, int m){
    int transposedmat[m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transposedmat[j][i]= mat[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout  << transposedmat[i][j] << " ";
        }
        cout << endl;
    } 
}
int main(){
    int mat[2][3] = {{1,2,3},
                     {4,5,6}};
    transpose(mat,2,3);
    return 0;
}