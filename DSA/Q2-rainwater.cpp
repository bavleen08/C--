#include <iostream>
#include <climits>
using namespace std;

// FIND TOTAL WATER TRAPPED

int trapRainwater(int *height, int n){
    int leftmax[20000], rightmax[20000];
    leftmax[0] = height[0];
    rightmax[n-1] = height[n-1];

    for(int i=1; i<n; i++){
        leftmax[i] = max(leftmax[i-1], height[i-1]);
    }  
    for(int i=n-2; i>=0; i--){
        rightmax[i] = max(rightmax[i+1], height[i+1]);
    }  

    int watertrapped = 0;
    for (int i=0; i<n; i++){
        int currwater = min(leftmax[i], rightmax[i]) - height[i];
        if(currwater  > 0){
            watertrapped += currwater;
        }
    }  
    cout << "Water Trapped is:" << watertrapped << endl;   
    return watertrapped;  // TC = O(n)
}

// OPTIMISED APPROACH
int rainwater(int height[], int n){
    int lmax = height[0], rmax = height[n-1];
    int low = 1, high = n-2;
    int water = 0;
    while(low <= high)
    {
        lmax = max(lmax, height[low]);
        rmax = max(rmax, height[high]);
        if(lmax < rmax){
            water += (lmax - height[low]);
            low++;
        } else {
            water += (rmax - height[high]);
            high--;
        }
    }
    return water;
}

int main(){
    int height[7] = {4,2,0,6,3,2,5};
    int n = sizeof(height) / sizeof(int);
    trapRainwater(height, n);
    cout << "Water trapped is: " << rainwater(height,n) << endl;
    return 0;
}