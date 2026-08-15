#include <bits\stdc++.h>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;
        for(int i=0; i<key.size(); i++){
            idx = idx + (key[i] * key[i]) % totSize;
        }
        return idx%totSize;
    }

    void rehash(){    // O(n)
        Node** oldTable = table;
        int oldSize = totSize;
        totSize = 2*totSize;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }

        // copy old values
        for(int i=0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size=5){
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFunction(key);
        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;
        double lambda = currSize/(double)totSize;
        if(lambda > 1){
            rehash();
        }
    }

    bool exists(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){ // found
                return true;
            } 
            temp = temp->next;
        }
        return false;
    }

    int search(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){ // found
                return temp->val;
            } 
            temp = temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;
        while(temp != NULL){
            if(temp->key == key){ // found
                if(prev == temp){
                    table[idx] = temp->next;
                } else{
                    prev->next = temp->next;
                }
                break;
            } 
            prev = temp;
            temp = temp->next;
        }
    }

    void print(){
        for(int i=0; i<totSize; i++){
            cout << "idx" << i << " ->";
            Node* temp = table[i];
            while(temp != NULL){
                cout << "(" << temp->key << "," << temp->val << ") ->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

void findUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int>s;
    for(int el: arr1){
        s.insert(el);
    }
    for(int el: arr2){
        s.insert(el);
    }
    for(int el: s){
        cout << el << " ";
    }
}

void findIntersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int>s;
    for(int el: arr1){
        s.insert(el);
    }
    for(int i=0; i<arr2.size(); i++){
        if(s.find(arr2[i]) != s.end()){
            cout << arr2[i] << " ";
            s.erase(arr2[i]);
        }
    }
}

void printItinerary(unordered_map<string, string> tickets){
    unordered_set<string> to;
    for(pair<string, string>ticket: tickets){
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string, string>ticket : tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }
    }
    cout << start << "->";
    while(tickets.count(start)){
        cout << tickets[start] << "->";
        start = tickets[start];
    }
    cout << "destination";
}

int largestSubarray0Sum(vector<int> arr){
    unordered_map<int, int> m;
    int sum=0; 
    int ans=0;
    for(int j=0; j<arr.size(); j++){
        sum += arr[j];
        if(m.count(sum)){
            int currlen = j-m[sum];
            ans = max(ans, currlen);
        } else{
            m[sum] = j;
        }
    }
    return ans;
}

int subarrayEqualsK(vector<int> arr, int k){
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;
    for(int j=0; j<arr.size(); j++){
        sum += arr[j];
        if(m.count(sum-k)){
            ans += m[sum-k];
        }
        if(m.count(sum)){
            m[sum]++;
        }
        else{
            m[sum] = 1;
        }
    }
    return ans;
}

int main(){
    // HashTable ht;
    // ht.insert("Italy", 100);
    // ht.insert("Nepal", 150);
    // ht.insert("China", 1000);
    // ht.insert("USA", 300);

    // ht.print();
    // // if(ht.exists("Nepal")){
    // //     cout << "population of nepal is " << ht.search("Nepal");
    // // }
    // ht.remove("China");
    // ht.print();

    // pair sum

    // int arr[7] = {1,2,7,14,5,9,11};
    // int n = 7;
    // int target = 9;
    // unordered_map<int, int> m;
    // for(int i=0; i<n; i++){
    //     int comp = target - arr[i];
    //     if(m.count(comp)){
    //         cout << "ans: " << m[comp] << "," << i;
    //     }
    //     m[arr[i]] = i;
    // }

    // vector<int> arr1 = {7,3,9};
    // vector<int> arr2 = {2,6,3,9,4,5};
    // findIntersection(arr1, arr2);

    // unordered_map<string, string> tickets;
    // tickets["Chennai"] = "Bengaluru";
    // tickets["Mumbai"] = "Delhi";
    // tickets["Delhi"] = "Goa";
    // tickets["Goa"] = "Chennai";
    // printItinerary(tickets);

    vector<int> arr = {10, 2, -2, -20, 10};
    cout << subarrayEqualsK(arr, -10);


}