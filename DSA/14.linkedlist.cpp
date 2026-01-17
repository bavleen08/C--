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
    friend class List;

    ~Node(){
        // cout << "~Node " << data << endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
public:
    Node* head;
    Node* tail;


    List(){
        head = NULL;
        tail = NULL;
    }

    ~List(){
        // cout << "~List" << endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp ->next;
        }
        cout << "Null" <<endl;
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node *temp = head;
        for(int i=0; i<(pos-1); i++){
            if(temp == NULL){
                cout << "Position is INVALID !" <<  endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head== NULL){
            cout << "LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int searchItr(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int helper(Node* temp, int key){
        if(temp == NULL){
            return -1;
        }
        if(temp->data == key){
            return 0;
        }
        int idx = helper(temp->next, key);
        if(idx == -1){
            return -1;
        }
        return idx + 1;
    }

    int searchRec(int key){
        return helper(head, key);
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        tail = head;

        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize(){
        Node* ptr = head;
        int sz = 0;
        while(ptr != NULL){
            ptr = ptr->next;
            sz++;
        }
        return sz;
    }
    void removeNthNode(int n){
        int size = getSize();
        Node* prev = head;
        for(int i=1; i<(size-n); i++){   // prev => deletion node prev
            prev = prev->next;
        }
        prev->next = prev->next->next;
    }

    bool isPalindrome(){
        Node* slow = head;
        Node* fast = head;
        if(!head || !head->next) return true;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL){
            slow = slow->next;
        }
        Node* curr = slow;
        Node* prev = nullptr;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node* first_half = head;
        Node* second_half = prev;
        while(second_half != NULL){
            if(first_half->data != second_half->data){
                return false;
            }
            first_half = first_half->next;
            second_half = second_half->next;
        }
        return true;
    }

    bool iscycle(Node* head){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                cout << "cycle exists\n";
                return true;
            }
        }
        cout << "cycle doesn't exists\n";
        return false;
    }

    void removeCycle(Node* head){
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                cout << "cycle exists\n";
                isCycle = true;
                break;
            }
        }
        if(!isCycle){
            cout << "cycle doesn't exists\n";
            return;   
        }
        slow = head;
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = NULL;
        }else{
            Node* prev = fast;
            while(slow != fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
        }
    }

    // MERGE SORT ON LL
    Node* merge(Node*left, Node*right){
        List ans;
        Node* i = left;  // temp variables
        Node* j = right;

        while(i != NULL && j != NULL){
            if(i->data <= j->data){
                ans.push_back(i->data);
                i = i->next;
            }
            else{
                ans.push_back(j->data);
                j = j->next;
            }
        }

        while(i != NULL){
            ans.push_back(i->data);
            i = i->next;
        }

        while(j != NULL){
            ans.push_back(j->data);
            j = j->next;
        }

        return ans.head;
    }

    Node* splitAtMid(Node*head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != NULL){  //for 1 size list
            prev->next = NULL;  //split
        }
        
        return slow;
    }

    Node* mergeSort(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* rightHead = splitAtMid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        return merge(left, right);
    }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.printList();
    ll.head = ll.mergeSort(ll.head);
    ll.printList();
    return 0;   
}