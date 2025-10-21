#include <iostream>
#include <string.h> // for strlen
#include <cstring> // char arrays
#include <string>
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

// Reverse a char array

void reverseArr(char work[], int n){
    int st=0, end=n-1;
    while(st < end){
        swap(work[st++], work[end--]);
    }
}

// Valid Palindrome
bool validPalindrome(char work[], int n){
    int st = 0, end = n-1;
    while(st < end){
        if(work[st++] != work[end--]){
            return false;
        }
    }
    return true;
}
int main(){
       // creation
    //char work[] = "code"; // string literals
    //char work[5] = "code";
    //char work[] = {'a', 'b', 'c', 'd', '\0'};
    //char work[20] = {'a', 'b', 'c', 'd', '\0'};
    //cout << work;

      // input
    //char arr[10];
    //cin >> arr; // ignores the whitespaces
    //cout << arr;
    // char sentence[50];
    // cin.getline(sentence, 50, '.');
    // cout << sentence;
    
      // strings functions
    char str1[50] = "abc";
    char str2[50];
    char str3[50] = "xyz";
    //strcpy(str2, str1);
    //cout << strcat(str1,str3)<< endl;
    //cout << strcmp(str1,str3)<< endl;

       // for each loop
    string str = "hellohi";
    //cout << str[1] << endl;
    for(int i=0; i<str.length(); i++){
        cout << str[i] << ",";
    }
    cout << endl;

    for(char ch : str){
        cout << ch << "-";
    }
    cout << endl;

    // memeber functions
    cout << str.at(1) << endl;
    cout << str.find("h",3) << endl;
    cout << str.substr(2, str.length()) << endl;
    return 0;
}