#include <iostream>
using namespace std;

int main(){
    int matrix[4][3]; // can also initialize
    int n =4, m=3;
    for(int i=0; i<n; i++){ // rows
        for(int j=0; j<m; j++){ // columns
            cin >> matrix[i][j];
        }
    }
    for(int i=0; i<n; i++){ // rows
        for(int j=0; j<m; j++){ // columns
            cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}