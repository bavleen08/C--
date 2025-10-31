#include <iostream>
#include <vector>
using namespace std;

// 167. Two Sum II - Input Array Is Sorted

// Approach 1 = pointer approach     O(n)
vector<int> pairSum(vector<int> arr, int target){
    int st = arr[0];
    int end = arr.size()-1;
    vector<int> ans;

    while(st < end){
        int currSum = arr[st] + arr[end];
        if(target == currSum){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        } else if(target < currSum){
            end--;
        } else if(target > currSum){
            st++;
        }
    }
    return ans;
}

// Approach 2 = brute froce(not recommended)    O(n*n)
int sumOfpairs(vector<int> arr, int target){
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            int ans = arr[i] + arr[j];
            if(ans == target){
                cout << i << "," << j;
            } else{
                ans = 0;
            }
        }
    }
}
int main(){
    vector<int> arr = {2,5,3,6};
    int target = 9;
    // vector<int> ans = pairSum(arr,target);
    // cout << ans[0] << "," << ans[1];
    sumOfpairs(arr, target);
    return 0;
}