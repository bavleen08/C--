#include <iostream>
using namespace std;

// SPIRAL MATRIX

void spiralMatrix(int mat[][3], int n, int m){
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;
    while(srow <= erow && scol <= ecol){
    // top
    for(int i=srow; i<=ecol; i++){
        cout << mat[srow][i] << " ";
    }

    // right
    for(int i=srow+1; i<=erow; i++){
        cout << mat[i][ecol] << " ";
    }

    // bottom
    for(int i=ecol-1; i>=scol; i--){
        cout << mat[erow][i] << " ";
        if(srow == erow){ // middle
            break;
        }
    }

    // left
    for(int i=erow-1; i>=srow+1; i--){
        cout << mat[i][scol] << " ";
        if(srow == erow){ // middle
            break;
        }
    }
    srow ++; scol++;
    erow--; ecol--;
    }
    cout << endl;
}
int main(){
    int mat[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9},};
    spiralMatrix(mat, 3,3);
    return 0;
}