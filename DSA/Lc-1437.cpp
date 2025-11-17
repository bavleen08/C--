#include <iostream>
#include <vector>
using namespace std;

// 1437. Check If All 1's Are at Least Length K Places Away

/* Tracks zeros between 1s directly.
Works like: “Count zeros until I hit the next 1.” */

bool isKplaces(vector<int> nums, int k){
    int count = k;     // // start with >= k so first 1 is never invalid For the first 1 in the array, we don't want to wrongly return false.
    for(int i=0; i<nums.size(); i++){
        if(!nums[i]){
            count++;
        }
        else{
            if(count < k){
                return false;    // violation: distance too small
            }
            count = 0;
        }
    }
    return true;
}

/* Tracks previous index of 1 and calculates spacing using math:
“Distance = current index − last index − 1.” */
// (Recommended)

bool checkPlace(vector<int> nums, int k){
    int last = -1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]){
            if(last != -1 && i-last-1 < k){    /* When we see a 1 at index i, and previous 1 at index last: We want to count how many zeros lie BETWEEN two 1s. */
                return false;
            }
            last = i;
        }
    }
    return true;
}

int main(){
    vector<int> nums = {1,0,1,0,0,1};
    //cout << isKplaces(nums, 2);
    cout << checkPlace(nums, 1);
    return 0;
}


// My mistakes
/*    Your logic returns TRUE when it finds one good pair
When you execute return true;, the function immediately ends. So count = 0; is dead code (never runs).
Your code checks:
Is there any 1 that appears after at least k zeros?
If yes → return true
Otherwise → return false
Every pair of 1’s must be at least k places apart.
If even ONE pair violates the distance → return false.
But your code returns TRUE if it finds even one valid pair.
But the problem requires FALSE when one bad pair is found. Your logic is flipped.
Before first 1, there are no zeros, so count = 0, which would incorrectly trigger violation.
So starting with count = k means the first 1 is always accepted   */