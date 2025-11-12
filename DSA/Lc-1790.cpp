#include <iostream>
#include <string>
using namespace std;

// 1790. Check if One String Swap Can Make Strings Equal

// Approach 1                O(n)
bool areAlmostEqual(string s1, string s2) {
    if(s1.length() != s2.length()){
        return false;
    }
    int diffCount = 0;
    int count1[26] = {0};
    int count2[26] = {0};
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != s2[i]){
            diffCount++;
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;

            if(diffCount > 2){
                return false;
            }
        }
    }
    for(int i=0; i<26; i++){
        if(count1[i] != count2[i]){
            return false;
        }
    }
    return true;
} 

// Approach 2              O(n*n)
bool isSame(string str1, string str2){
    if(str1.length() != str2.length()){
        cout << "Not Same";
        return false;
    }
    string temp = str1;
    for(int i=0; i<str1.length(); i++){
        for(int j=i+1; j<str1.length(); j++){
            swap(str1[i], str1[j]);
            if(str1 == str2){
                cout << "Same";
                return true;
            }
            str1 = temp;
        }
    }
    cout << "Not Same";
    return false;
}

// Approach 3               O(n)
bool sameString(string str1, string str2){
    if(str1.length() != str2.length()){
        cout << "Not Same";
        return false;
    }

    int charDiff1, charDiff2;
    int diff = 0;
    for(int i=0; i<str1.length(); i++){
        if(str1[i] != str2[i]){
            if(!diff){
                charDiff1 = str1[i];
                charDiff2 = str2[i];
            } 
            else{
                if(str1[i] != charDiff2 || str2[i] != charDiff1){
                    return false;
                }
            }

            diff++;

        }

        if(diff > 2){
            return false;
        }        
    }

    if(diff == 1){
        return false;
    }
    cout << "Same";
    return true;    
}

// Approach 4              O(n)
bool areEqual(string str1, string str2){
    int idx1 = -1, idx2 = -1;
    for(int i=0; i<str1.length(); i++){
        if(str1[i] != str2[i]){
            if(idx1 == -1){
                idx1 = i;
            } else{
                if(idx2 == -1){
                    idx2 = i;
                    break;
                }
            }
        }
    }
    swap(str2[idx1], str2[idx2]);
    if(str1 == str2){
        cout << "Same";
        return true;
    }
    cout << "Not Same";
    return false;
}

int main(){
    string str1 = "ansh";
    string str2 = "anhs";
    //isSame(str1, str2);
    //sameString(str1, str2);
    areEqual(str1, str2);
    return 0;
}