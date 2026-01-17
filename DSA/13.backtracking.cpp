#include <bits\stdc++.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void changeArr(int arr[], int n, int i){
    if(i == n){
        printArr(arr, n);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;  // backtrack
}

// Print Subsets

void printSubset(string str, string subset){
    if(str.size() == 0){
        cout << subset << "\n";
        return;
    }
    char ch = str[0];
    printSubset(str.substr(1,str.size()-1), subset+ch); // yes choice
    printSubset(str.substr(1,str.size()-1), subset);  // no choice

}

// Find Permutations

void printPerm(string str, string ans){
    int n = str.size();
    if(n == 0){
        cout << ans << "\n";
        return;
    }
    for(int i = 0; i<n; i++){
        char ch = str[i];
        string nextStr = str.substr(0,i) + str.substr(i+1, n-i-1); // deleting ith char
        printPerm(nextStr, ans + ch);
    }
}

// N Queens
void printBoard(vector<vector<char>> board){
    int n = board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    
    //horizontal
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    //vertical
    for(int j=0; j<row; j++){
        if(board[j][col] == 'Q'){
            return false;
        }
    }

    //diagonal left
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //diagonal right
    for(int i=row,j=col; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void nQueens(vector<vector<char>> board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return;
    }
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            nQueens(board, row+1);
            board[row][j] = '.';
        }
    }
}

// GRID WAYS
int gridWays(int r, int c, int n, int m){
    if(r==n-1 && c==m-1){
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    return gridWays(r+1,c,n,m) + gridWays(r,c+1,n,m);
}

// SODUKU SOLVER
bool isSafe(int soduku[9][9], int row, int col, int digit){
    //vertical
    for(int i=0; i<=8; i++){
        if(soduku[i][col] == digit){
            return false;
        }
    }

    //horizontal
    for(int j=0; j<=8; j++){
        if(soduku[row][j] == digit){
            return false;
        }
    }

    //3x3 grid
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i=startRow; i<=startRow+2; i++){
        for(int j=startCol; j<=startCol+2; j++){
            if(soduku[i][j] == digit){
                return false;
            }
        }
    }
    return true;
}

void printSoduku(int soduku[][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << soduku[i][j] << " ";
        }
        cout << endl;
    }
}

bool sodukuSolver(int soduku[9][9], int row, int col){
    if(row==9){
        printSoduku(soduku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(col==8){
        nextRow = row+1;
        nextCol = 0;
    }

    if(soduku[row][col] != 0){
        return (soduku, nextRow, nextCol);
    }

    for(int digit=1; digit<=9; digit++){
        if(isSafe(soduku,row,col,digit)){
            soduku[row][col] = digit;
            if(sodukuSolver(soduku, nextRow,nextCol)){
                return true;
            }
            soduku[row][col] = 0;
        }
    }
    return false;
}
int main(){
    
    // vector<vector<char>> board;
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     vector<char> newRow;
    //     for(int j=0; j<n; j++){
    //         newRow.push_back('.');
    //     }
    //     board.push_back(newRow);
    // }
    // nQueens(board, 0);
    // cout << gridWays(0,0,3,3);
    int soduku[9][9] = {{0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},
                        {0,0,3,0,0,4,1,9,0},
                        {1,8,5,0,6,0,0,2,0},
                        {0,0,0,0,2,0,0,6,0},
                        {9,6,0,4,0,5,3,0,0},
                        {0,3,0,0,7,2,0,0,4},
                        {0,4,9,0,3,0,0,5,7},
                        {8,2,7,0,0,9,0,1,3}};
    sodukuSolver(soduku,0,0);
    return 0;
}
