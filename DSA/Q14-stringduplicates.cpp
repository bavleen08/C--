#include <bits/stdc++.h>
using namespace std;

// Remove duplicates from the string

void removeDUplicates(string str, string ans, int i, bool map[]){
    if(i == str.size()){
        cout << ans << endl;
        return;
    }

    int mapIdx = int(str[i] - 'a');
    if(map[mapIdx]){ // duplicate exists
        removeDUplicates(str, ans, i+1, map);
    }
    else{ // no duplicates
        map[mapIdx] = true;
        ans = ans + str[i];
        removeDUplicates(str, ans, i+1, map);
    }
}

int main(){
    string str = "aabbcccc";
    string ans = "";
    bool map[26] = {false};
    removeDUplicates(str, ans, 0, map);
    return 0;
}