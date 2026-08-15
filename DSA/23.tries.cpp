#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;
    Node(){
        endOfWord = false;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
        root->freq = -1; // for prefix problem
    }

    void insert(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children[key[i]] == 0){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1; // for prefix problem
            }
            else{  // for prefix problem
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children[key[i]] != 0){
                temp = temp->children[key[i]];
            }
            else {
                return false;
            }
        }
        return temp->endOfWord;
    }

    string getPrefix(string key){ // O(L)
        Node* temp = root;
        string prefix = "";
        for(int i=0; i<key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1) break;
            temp = temp->children[key[i]];
        }
        return prefix;
    }

    bool startsWith(string prefix){
        Node* temp = root;
        for(int i=0; i<prefix.size(); i++){
            if(temp->children[prefix[i]]){
                temp = temp->children[prefix[i]];
            } else{
                return false;
            }
        }
        return true;
    }

    int countNodes(Node* root){
        int ans = 0;
        for(pair<char, Node*> child: root->children){
            ans += countNodes(child.second);
        }
        return ans+1;
    }

    void longestHelper(Node* root, string &ans, string temp){
        for(pair<char, Node*> child: root->children){
            if(child.second->endOfWord == true){
                temp += child.first;
                if(temp.size() == ans.size() && temp < ans || temp.size() > ans.size()){
                    ans = temp;
                }
                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    } 

};

bool helper(Trie &trie, string key){
    if(key.size() == 0) return true;
    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)) return true;
    }
    return false;
}
bool wordBreak(vector<string> words, string key){
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }
    return helper(trie, key);
}

void prefixProblem(vector<string> words){  // O(n*L)
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }
    for(int i=0; i<words.size(); i++){
        cout << trie.getPrefix(words[i]) << " ";
    }
}

int countUniqueSubstrings(string str){
    // find suffix
    Trie trie;
    for(int i=0; i<str.size(); i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    // count nodes of suffix tree
    return trie.countNodes(trie.root);
}

string longestString(vector<string> words){
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }
    string ans = "";

    trie.longestHelper(trie.root, ans, "" );
    return ans;
}
int main(){
    vector<string> words = {"banana", "a", "app", "ap", "appl", "apple", "apply"};
    // Trie trie;
    // for(int i=0; i<words.size(); i++){
    //     trie.insert(words[i]);
    // }
    cout << longestString(words);
}