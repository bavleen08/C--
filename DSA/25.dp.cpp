#include <bits\stdc++.h>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int n, int w){
    if(n==0 || w== 0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        int ans1 = knapsackRec(val, wt, n-1, w-itemWt) + itemVal;
        int ans2 = knapsackRec(val, wt, n-1, w);
        return max(ans1, ans2);
    }
    else {
        return knapsackRec(val, wt, n-1, w);
    }
}

int knapsackMem(vector<int> val, vector<int> wt, int n, int w, vector<vector<int>> &dp){
    if(n==0 || w== 0){
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        int ans1 = knapsackMem(val, wt, n-1, w-itemWt, dp) + itemVal;
        int ans2 = knapsackMem(val, wt, n-1, w, dp);
        dp[n][w] =  max(ans1, ans2);
    }
    else {
        dp[n][w] = knapsackMem(val, wt, n-1, w, dp);
    }
    return dp[n][w];
}

int knapsackTab(vector<int> val, vector<int> wt, int n, int w, vector<vector<int>> &dp){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if(itemWt <= j){
                dp[i][j] = max(itemVal+ dp[i-1][j-itemWt], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}


bool targetSum(vector<int> nums, int target){
    vector<vector<int>>dp(nums.size()+1, vector<int>(target+1, 0));
    for(int i=1; i<=nums.size(); i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[nums.size()][target] == target;
}

// HOUSE ROBBER
int helper(int n, vector<int> &nums, vector<int> &res){
        if(n <= 0) return 0;
        if(res[n-1] != -1) return res[n-1];
        int ans1 = nums[n-1] + helper(n-2, nums, res);
        int ans2 = helper(n-1, nums, res);
        res[n-1] = max(ans1, ans2);
        return res[n-1];
}
int rob(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        return helper(nums.size(), nums, res);
}

int lcsRec(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    if(n == 0 || m == 0) return 0;
    if(str1[n-1] == str2[m-1]){
        return 1 + lcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
    }
    else {
        int ans1 = lcsRec(str1.substr(0, n-1), str2);
        int ans2 = lcsRec(str1, str2.substr(0, m-1));
        return max(ans1, ans2);
    }
}

int cat(int n, vector<int> &dp){
    // if(n==0 || n==1) return 1;
    // int ans=0;
    // if(dp[n] != -1) return dp[n];

    // for(int i=0; i<n; i++){
    //     ans += cat(i, dp) * cat(n-i-1, dp);
    // }
    // return dp[n] = ans;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2,5,1,3,4};
    int n=5;
    int w = 7;
    //vector<vector<int>> dp(n+1, (vector<int>(w+1, 0)));
    vector<int> nums = {2,4,3,1};
    //cout << lcsRec("abcdeg", "abdge");
    vector<int>dp(n+1, -1);
    cout << cat(n, dp);
    return 0;
}