#include <bits\stdc++.h>
using namespace std;

// 757. Set Intersection Size Atleast Two (Hard)

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });

    int a = -1, b = -1; 
    int ans = 0;

    for (auto &it : intervals) {
        int start = it[0], end = it[1];

        bool hasA = (a >= start);
        bool hasB = (b >= start);

        if (hasA && hasB) {
            continue;
        }
        else if (hasA || hasB) {
            ans++;
            if (hasA) {
                b = end;
            } else {
                a = end;
            }
        }
        else {
            ans += 2;
            a = end - 1;
            b = end;
        }
    }
    return ans;
}
