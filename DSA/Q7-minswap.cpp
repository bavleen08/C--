#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// FIND MINIMUM SWAPS TO SORT THE ARRAYS

int minSwaps(vector<int>& arr){
    int n = arr.size();

    vector<pair<int,int>>v;
    for(int i=0; i<n; i++){
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end());     

    int i=0;
    int count = 0;
    while(i<n)                    // O(nlogn) + O(n) = O(nlogn)
    {
        while (i != v[i].second)
        {
            swap(v[i], v[v[i].second]);
            count++;
        }
        i++;  
    }
    return count;
}
int main(){
    vector<int> arr = {2,3,6,1};
    cout << minSwaps(arr);
}