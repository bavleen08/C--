#include <iostream>
#include <climits>
using namespace std;

// 121. Best Time to Buy and Sell Stock

void maxProfit(int *prices, int n){
    int bestBuy[100000];
    bestBuy[0] =INT_MAX;
    for(int i=1; i<n; i++){   // TC = O(n)
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }
    int maxProfit = 0;
    for(int i=0; i<n; i++){    // TC = O(n)
        int currprofit = prices[i] - bestBuy[i];
        maxProfit = max(currprofit, maxProfit);
    }
    cout << "maximum profit: "<< maxProfit<< endl;
    // TC = O(n+n) = O(2n) = O(n)
}
int main(){
    int prices[6] = {7,1,5,3,6,4};
    int n = sizeof(prices) / sizeof(int);
    maxProfit(prices, n);
    return 0;
}