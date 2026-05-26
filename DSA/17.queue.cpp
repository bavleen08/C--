#include <bits\stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
    friend class Queue;

    ~Node(){
        // cout << "~Node " << data << endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class Queue{
public:
    Node* head;
    Node* tail;

    Queue(){
        head = NULL;
        tail = NULL;
    }

    ~Queue(){
        // cout << "~List" << endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    int front(){
        return head->data;
    }

    void push(int val){
        Node* newNode = new Node(val);
        Node* curr = head;
        while(curr != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
        curr = newNode;
    }
    // void push(int val){
    //     Node* newNode = new Node(val);
    //    if(head == NULL) {
    //     head = tail = newNode;
    //    }
    //    else{
    //     tail->next = newNode;
    //     tail = newNode;
    //    }
    // }

    void pop(){
        Node* temp = head;
        head = head->next;
        temp = NULL;
        delete temp;
    }
    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}