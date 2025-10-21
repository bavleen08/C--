#include <iostream>
using namespace std;

int findError(int nums[], int n){
    int track = 1;
    int ans[5];
    for(int i=0; i<n; i++){
        if(nums[i] == track){
            track++;
        } else{
            cout << nums[i] << "," << track;
            break;
        }
    }

}

int main(){
    int nums[] = {1,2,3,2,5};
}