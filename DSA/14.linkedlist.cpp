#include <bits/stdc++.h>
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

    void printList(Node*head){
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
        List* ans = new List();
        Node* i = left;  // temp variables
        Node* j = right;

        while(i != NULL && j != NULL){
            if(i->data <= j->data){
                ans->push_back(i->data);
                i = i->next;
            }
            else{
                ans->push_back(j->data);
                j = j->next;
            }
        }

        while(i != NULL){
            ans->push_back(i->data);
            i = i->next;
        }

        while(j != NULL){
            ans->push_back(j->data);
            j = j->next;
        }

        return ans->head;
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

// Zig Zag LL
    Node* alternateMerge(Node*left, Node* right){
        Node* tail = right;
        while(left != NULL && right != NULL){
            Node* nextLeft = left->next;
            Node* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;
            tail = right;

            left = nextLeft;
            right = nextRight;   
        }
        if(right != NULL){
            tail->next = right;
        }
        return head;
    }

    Node* zigZagll(Node* head){
        Node* leftHead = head;
        Node* rightHead = splitAtMid(head);

        Node* prev = NULL;
        Node* curr = rightHead;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node* rightHeadRev = prev;

        return alternateMerge(leftHead, rightHeadRev);
    }

    int findInter(Node* headA, Node* headB){
        Node*listAhead = headA;
        Node*listBhead = headB;

        while(headA != headB){
            if(headA == NULL){
                headA = listBhead;
            }else{
                headA = headA->next;
            }
            headB = (headB == NULL)? listAhead : headB->next;
        }
        return headA->data;
    }

    Node* retMdelN(Node* head, int m, int n){
        if(head == NULL || m == 0) return NULL;

        Node *ptr = head;
        Node *prev = NULL;

        while(ptr != NULL){
            // retain m nodes
            for(int i = 1; i <= m && ptr != NULL; i++){
                prev = ptr;
                ptr = ptr->next;
            }

            // delete next n nodes
            for(int i = 1; i <= n && ptr != NULL; i++){ //If list ends early, you stop deleting safely.
                Node* temp = ptr;
                ptr = ptr->next;
                delete temp;
            }

            if(prev != NULL){  //Connect last kept node → next remaining node.
            prev->next = ptr;
            }
        }
        return head;
    }

    Node* swapNodes(Node* head, int x, int y){
        if(x == y){
            return head;
        }
        Node* currX = head;
        Node* currY = head;
        Node* prevX = NULL;
        Node* prevY = NULL;

        while(currX && currX->data != x){
            prevX = currX;
            currX = currX->next;
        }

        while(currY && currY->data != y){
            prevY = currY;
            currY = currY->next;
        }

        if (currX == NULL || currY == NULL)
        return head;

     // If X is not head
        if (prevX != NULL)
            prevX->next = currY;
        else
            head = currY;

    // If Y is not head
        if (prevY != NULL)
            prevY->next = currX;
        else
            head = currX;

        Node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
    
        return head;
    }

    Node* oddEven(Node* head){
        if (!head) return NULL;
        
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* curr = head;

    

        while(curr != NULL){
            if(curr->data % 2 == 0){
                if(!evenHead){
                    evenHead = evenTail = curr;
                }
                else{
                    evenTail->next = curr;
                    evenTail = curr;
                }
                
            }else{
                if(!oddHead){
                    oddHead = oddTail = curr;
                }
                else{
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
            curr = curr->next;
        }
        if(evenTail) evenTail->next = oddHead;
        if(oddTail) oddTail->next = NULL;

        return evenHead ? evenHead: oddHead;
    }
};

int main(){
    List ll;
    
    // ll.push_front(10);
    // ll.push_front(9);
    // ll.push_front(8);
    // ll.push_front(7);
    // ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // ll.head = ll.mergeSort(ll.head);
    // ll.zigZagll(ll.head);

    // Node* shared = new Node(3);
    // shared->next = new Node(4);
    // Node* headA = new Node(1);
    // headA->next = new Node(2);
    // headA->next->next = shared;
    // Node* headB = new Node(8);
    // headB->next = shared;
    // ll.printList(headA);
    // cout << ll.findInter(headA, headB);

    ll.printList(ll.head);
    // ll.retMdelN(ll.head, 2, 2);
    // ll.head = ll.swapNodes(ll.head, 1, 4); // if Function returns new head
    ll.head = ll.oddEven(ll.head);
    ll.printList(ll.head);

    return 0;   
}