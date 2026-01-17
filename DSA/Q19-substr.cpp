#include <bits\stdc++.h>
using namespace std;

// [Leetcode Premium Qs]
// We are given a string S, we need to find the count of all contiguous substrings starting and ending with the same character.
int countSubstr(string str, int i, int j){
    int n = str.size();

    if(i==n) return 0;
    if(j==n){
        return countSubstr(str, i+1, i+1);
    }
    int count = 0;
    if(str[i] == str[j]){
        count = 1;
    }
    return count + countSubstr(str, i, j+1);
}

// O(3^n)
int countSubstrs(string str, int i, int j, int n)
{
    if (n == 1) return 1;
    if (n <= 0) return 0;

    int res =
        countSubstrs(str, i + 1, j, n - 1) +
        countSubstrs(str, i, j - 1, n - 1) -
        countSubstrs(str, i + 1, j - 1, n - 2);

    if (str[i] == str[j]) {
        res++;
    }

    return res;
}

int main(){
    string str = "aba";
    cout << countSubstr(str,0,0);
}