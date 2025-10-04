#include <iostream>
#include <string.h>
using namespace std;

// Convert to uppercase and lowercase

void toUppercase(char word[], int n){
    for(int i=0; i<n; i++){
        int ch = word[i];
        if(ch >= 'A' && ch <= 'Z'){
            continue; // already in UPPERCASE
        } else{ // lowercase
            word[i] = ch - 'a' + 'A';
        }
    }
}

void toLowercase(char word[], int n){
    for(int i=0; i<n; i++){
        int ch = word[i];
        if(ch >= 'a' && ch <= 'z'){
            continue; // already in lowercase
        } else{ // UPPERCASE
            word[i] = ch - 'A' + 'a';
        }
    }
}
int main(){
       // creation
    //char work[] = "code"; // string literals
    //char work[5] = "code";
    //char work[] = {'a', 'b', 'c', 'd', '\0'};
    char work[20] = {'a', 'b', 'c', 'd', '\0'};
    //cout << work;

      // input
    char arr[10];
    //cin >> arr; // ignores the whitespaces
    //cout << arr;

    char sentence[50];
    cin.getline(sentence, 50, '.');
    cout << sentence;
    
    return 0;
}