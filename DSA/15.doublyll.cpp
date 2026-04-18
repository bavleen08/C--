#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class doublyLL{
public:
    Node* head;
    Node* tail;

    doublyLL(){
        head = tail = NULL;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        } 
        cout << "NULL" << endl;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(int val){
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back(int val){
        if (head == NULL) return;
        Node* temp = head;

        if (temp->next == NULL) { // single node
            delete temp;
            head = NULL;
            return;
        }
        
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
};

int main(){
    doublyLL dbll;
    dbll.push_front(5);
    dbll.push_front(4);
    dbll.printList();
}