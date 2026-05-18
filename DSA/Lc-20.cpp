#include <iostream>
#include <stack>
using namespace std;

// 20. Valid Parenthesis


bool isValid(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i]== '['){
            st.push(s[i]);
        }
        else{
            if(st.empty() == true){  //insufficient no. of opening brackets
                return false;
            } else if((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}')){
                st.pop();
            }
            else{
                return false;  //insufficient no. of closing brackets
            }
        }
    }
    return(st.empty() == true);
}

int main(){
    cout << isValid("([]");
}