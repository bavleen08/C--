#include <bits\stdc++.h>
#include <vector>
using namespace std;

class Job{
public:
    int index;
    int deadline;
    int profit;

    Job(int index, int deadline, int profit){
        this->index = index;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int W){
    int ans = 0;
    int n = val.size();
    vector<pair<double, int>> ratio((n), make_pair(0.0, 0));
    for(int i=0; i<n; i++){
        double r = val[i]/(double) wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);

    for(int i=0; i<n; i++){
        int idx = ratio[i].second;
        if(wt[idx] <= W){
            ans += val[idx];
            W -= wt[idx];
        } else {
            ans += (ratio[i].first  *  W);
            W = 0;
            break;
        }
    }
    return ans;
}

int minDiff(vector<int> a, vector<int> b){
    int n = a.size();
    int diff = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0; i<n; i++){
        diff += abs(a[i]- b[i]);
    }

    return diff;
}

int getMinChange(vector<int> coins, int V){
    int ans = 0; 
    int n = coins.size();
    for(int  i= n-1; i>=0 && V > 0; i--){
        if(V >= coins[i]){
            ans += V / coins[i];
            V = V % coins[i];
        }
    }
    return ans;
}

// int maxProfit(vector<pair<int, int>> jobs){
//     sort(jobs.begin(), jobs.end(), compare);
//     int profit = jobs[0].second;
//     int safeDeadline = 2;

//     for(int i=1; i<jobs.size(); i++){
//         if(jobs[i].first >= safeDeadline){
//             profit += jobs[i].second;
//             safeDeadline++;
//         }
//     }
//     return profit; 
// }

int maxProfit(vector<pair<int, int>> pairs){
    int n = pairs.size();
    vector<Job> jobs;
    for(int i=0; i<n; i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){ // lambda function
        return a.profit > b.profit;
    });

    cout << "Selecting job " << jobs[0].index << endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for(int i=1; i<n; i++){
        if(jobs[i].deadline >= safeDeadline){
            cout << "selecting job " << jobs[i].index << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }
    return profit; 
}
    

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    // cout << fractionalKnapsack(val, wt, W);

    vector<int> a = {4,1,8,7};
    vector<int> b = {2,3,6,5};
    // cout << minDiff(a,b);

    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int V = 50;
    // cout << getMinChange(coins, V);

    int n = 4;
    vector<pair<int, int>> pairs(n, make_pair(0,0));
    pairs[0] = make_pair(4,20);
    pairs[1] = make_pair(1,10);
    pairs[2] = make_pair(1,40);
    pairs[3] = make_pair(1,30);

    cout << maxProfit(pairs);

    return 0;
}