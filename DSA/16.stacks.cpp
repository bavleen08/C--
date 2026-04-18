#include <bits\stdc++.h>
using namespace std;

// Stack implementation using vectors

// template<class T>
// class Stack{
//     // vector<T> vec;
//     T arr[4] = {0};
// public:
//     int size = 0;
//     void push(T val){
//         // vec.push_back(val);
//         arr[size++] = val;
//     }

//     T pop(){
//         // if(isEmpty()){
//         //     cout << "Stack is empty\n";
//         // }
//         // vec.pop_back();
//         if(size == 0) return -1;
//         return arr[--size];
//     }

//     T top(){
//         if(isEmpty()){
//             cout << "Stack is empty\n";
//             return -1;
//         }
//         // int lastIdx = vec.size()-1;
//         // return vec[lastIdx];
//         return arr[size-1];
//     }

//     bool isEmpty(){
//         // return (vec.size()==0);  
//         return size == 0;
//     }

//     void printArr(T arr[]){
//         for(int i=0; i<4; i++){
//             cout << (arr[i]) << " ";
//         }
//     }

//     void callArr(){
//         return printArr(arr);
//     }
// };

// Stack implementation using linked list

template<class T>
class Node{
public:
    T data;
    Node* next;
    Node(T val){
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack{
    Node<T>* head; // List<T>ll;

public:
    Stack(){
        head = NULL;
    }
    void push(T val){
        // push front
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        // pop front
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top(){
        return head->data; // ll.front
    }

    bool isEmpty(){
        return head == NULL;
    }

};

void pushAtBottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

string reverseString(string str){
    string ans;
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s){
    while(!s.empty()){ 
        cout << s.top() << " ";
        s.pop();
    }
}

void stockSpanProblem(vector<int> stock, vector<int> span){
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i=1; i<stock.size(); i++){
        int currprice = stock[i];
        while(!s.empty() && currprice >= stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i + 1;
            s.push(i);
        }else{
            int prevhigh = s.top();
            span[i] = i - prevhigh;
            s.push(i);
        }
    }
    for(int i=0; i<span.size(); i++){
        cout << span[i] << " ";
    }
    cout << endl;
}
int main(){

    // pushAtBottom(s, 5);
    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    vector<int> stock = {90,80,70,100,60};
    vector<int> span = {0,0,0,0,0};
    stockSpanProblem(stock, span);


    return 0;
}