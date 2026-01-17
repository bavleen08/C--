#include <bits\stdc++.h>
using namespace std;

// 1930. Unique Length-3 Palindromic Subsequences (Medium)

int countUniquePalindromicSubsequences(string s) {
    vector<int> first_occur(26, -1);
    vector<int> last_occur(26, -1);

    for(int i=0; i < s.length(); i++){
        int char_idx = s[i] - 'a';
        if(first_occur[char_idx] == -1){
            first_occur[char_idx] = i;
        }
        last_occur[char_idx] = i;
    }
    int total_palindromes = 0;
    for(int char_val = 0; char_val < 26; char_val++){
        int i_first = first_occur[char_val];
        int i_last = last_occur[char_val];
        if(i_first == -1 || i_first == i_last){
            continue;
        }
        unordered_set<char> unique_middle_val;
        for(int j = i_first + 1; j < i_last; j++){
            unique_middle_val.insert(s[j]);
        }
        total_palindromes += unique_middle_val.size();
    }
    return total_palindromes;
}

int main(){
    string str = "acbac";
    cout << "Unique Palindromes of length-3 are: " << countUniquePalindromicSubsequences(str);
    return 0;
}