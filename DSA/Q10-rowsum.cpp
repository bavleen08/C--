#include <iostream>
using namespace std;

// Print out the sum of the numbers in the second row of the “nums” array

int rowSum(int nums[][3], int n, int m){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[1][i];
    }
    return sum;
}
int main(){
    int nums[3][3] = {{1,4,9},
                      {11,4,4},
                      {2,2,3}};
    cout << rowSum(nums,3,3); 
}