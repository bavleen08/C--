#include <iostream>
#include <string>
using namespace std;

// Count how many times lowercase vowels occurred in a String entered by the user

int vowCount(string str1){       // O(n*n)
    string str2 = "aeiou";
    int count = 0;
    for(int i=0; i<str1.length(); i++){
        for(int j=0; j<str2.length(); j++){
            if(str1[i] == str2[j]){
                count++;
            }
        }
    }

// another way  O(n)
    for(int i=0; i<str1.length(); i++){
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u'){
            count++;
        }
    }
    return count;
}

int main(){
    string str1;
    getline(cin, str1);
    cout << vowCount(str1);
    return 0;
}