#include <bits\stdc++.h>
#define ll long long
using namespace std;

//1262. Greatest Sum Divisible by Three  (Medium)

int maxSumDivThree(vector<int>& nums){
    int sum = 0;
    vector<int> r1, r2;
    for(int i: nums){
        sum += i;
        if(i % 3 == 1) r1.push_back(i);
        else if(i % 3 == 2) r2.push_back(i);
    }

    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());

    int rem = sum % 3;
    if(rem == 0) return sum;

    ll best = 0;
    if(rem == 1){
        if(!r1.empty()){
            best = max(best, (ll)sum - r1[0]);
        }
        if(r2.size() >= 2){
            best = max(best, (ll)sum - r2[0] - r2[1]);
        }
    }

    if(rem == 2){
        if(!r2.empty()){
            best = max(best, (ll)sum - r2[0]);
        }
        if(r1.size() >= 2){
            best = max(best, (ll)sum - r1[0] - r1[1]);
        }
    }
    return best;
}

int main(){
    return 0;
}
