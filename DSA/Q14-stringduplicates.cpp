#include <bits/stdc++.h>
using namespace std;

// Remove duplicates from the string   (GOOGLE)  (MICROSOFT)

void removeDUplicates(string str, string ans, int i, bool map[]){
    if(i == str.size()){  // without i -> (str.size() == 0)
        cout << ans << endl;
        return;
    }

    // int n = str.size()
    // char ch = str[n-1]

    int mapIdx = int(str[i] - 'a'); // str[n-1]
    // str = str.substr(0, n-1)
    
    if(map[mapIdx]){ // duplicate exists
        removeDUplicates(str, ans, i+1, map);
    }
    else{ // no duplicates
        map[mapIdx] = true;
        removeDUplicates(str, ans+str[i], i+1, map); // ch + ans
    }
}

int main(){
    string str = "aabbcccc";
    string ans = "";
    bool map[26] = {false};
    removeDUplicates(str, ans, 0, map);
    return 0;
}