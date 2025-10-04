#include <iostream>
using namespace std;

// matrix pointer in functions
void func1(int mat[][3], int n , int m){
    cout << "0th row ptr " << mat << endl;
    cout << "1st row ptr " << mat+1 << endl;
    cout << "2nd row ptr " << mat+2 << endl;

    cout << "0th row value " << *mat << endl;
    cout << "1st row value " << *(mat+1) << endl;
    cout << "2nd row value " << *(mat+2) << endl;

    cout << *(*(mat+1)+1);
    cout << mat[1][1];

}
void func2(int (*mat)[4], int n, int m){
    // same as func1
}

int main(){
    // int matrix[4][3]; // can also initialize
    // int n =4, m=3;
    // for(int i=0; i<n; i++){ // rows
    //     for(int j=0; j<m; j++){ // columns
    //         cin >> matrix[i][j];
    //     }
    // }
    // for(int i=0; i<n; i++){ // rows
    //     for(int j=0; j<m; j++){ // columns
    //         cout << matrix[i][j]<< " ";
    //     }
    //     cout << endl;
    // }

    // matrix pointers
    int mat[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};
    cout << mat << " = " << &mat[0][0]<< endl;
    cout << mat + 1 << " != " << &mat[0][1]<< endl;
    cout << mat + 1 << " = " << &mat[1][0]<< endl;

    func1(mat,3,3);
    return 0; 
}