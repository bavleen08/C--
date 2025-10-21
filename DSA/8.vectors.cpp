#include <iostream>
#include <vector>
using namespace std;

// DYNAMIC MEMORY ALLOCATION
void func(){
    int size;
    cout << " enter size: ";
    cin >> size;

    int *arr = new int[size];
    int x=1;
    for(int i=0; i<size; i++){
        arr[i] = x++;
        cout << arr[i] << " ";
    }

    delete[] arr;
}

// 2D DYNAMIC ARRAYS
// int main(){
//     int rows;
//     cout << " enter rows: ";
//     cin >> rows;
//     int cols;
//     cout << " enter cols: ";
//     cin >> cols;

//     int* *matrix = new int*[rows];

//     for(int i=0; i<rows; i++){
//         matrix[i] = new int[cols];
//     }

//     //data store
//     int x=1;
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++){
//             matrix[i][j] = x++;  // matrix[i][j] = *(*(matrix + i)+ j)
//             cout << matrix[i][j]<< " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

int main(){
    // vectors
    vector<int> vec1 = {1,2,3};
    cout << vec1.size() << endl;
    for(int i=0; i<vec1.size(); i++){
        cout << vec1[i]<< " ";
    }
    cout << endl;

    // vector in memory
    vector<int> vec = {1,2,3,4};
    cout << "size: " << vec.size()<< endl;
    cout << "capacity: " << vec.capacity()<< endl;

    vec.push_back(5);
    cout << "size: " << vec.size()<< endl;
    cout << "capacity: " << vec.capacity()<< endl;

    vec.pop_back();
    cout << "size: " << vec.size()<< endl;
    cout << "capacity: " << vec.capacity()<< endl;

    // 2D vectors
    vector<vector<int>> matrix = {{1,2,3}, {1,2}, {1}};
    cout << matrix.size()<< endl;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}