#include <bits\stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Info{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root->data > val){
        root->left = insert(root->left, val);
    } else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;
    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key){
    if(root == NULL) return false;

    if(root->data == key) return true;
    if(root->data > key) return search(root->left, key);
    else return search(root->right, key);

    return false;
}

Node* getInorderSucc(Node* root){
    while(root->left!= NULL){
        root = root->left;
    }
    return root; //IS
}
Node* delNode(Node* root, int val){
    if(root == NULL) return NULL;
    if(root->data > val){
        root->left = delNode(root->left, val);
    } else if(root->data < val){
        root->right = delNode(root->right, val);
    } else { // root == val
        // case1: 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        } else{ 
            //case2" 1 child
            if(root->left == NULL || root->right == NULL){
                return root->left == NULL ? root->right: root->left;
            }
        }

        // case3: 2 child
        Node* IS = getInorderSucc(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); // case 1 case 2
        return root;
    }
    return root;
}

void printInRange(Node* root, int start, int end){
    if(root == NULL) return;
    if(root->data >= start && root->data <= end){
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if(root->data < start){
        printInRange(root->right, start, end);
    } else{
        printInRange(root->left, start, end);
    }
}

void rootToLeaf(Node* root, vector<int> &path){
    if(root == NULL) return;
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        for(int i=0; i<path.size(); i++){
            cout << path[i] << " ";
        }
        cout << endl;
        path.pop_back();
        return;
    } 

    rootToLeaf(root->left, path);
    rootToLeaf(root->right, path);
    path.pop_back();
    
    return;
}

bool validateHelper(Node* root, Node* min, Node* max){
    if(root == NULL) return true;
    if(min != NULL && root->data < min->data){
        return false;
    }
    if(max != NULL && root->data > max->data){
        return false;
    }

    return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
}
bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
}

Node* builtBSTfromSorted(vector<int> vec, int st, int end){
    if(st > end) return NULL;

    int mid = st + (end-st)/2;
    Node* curr = new Node(vec[mid]);
    curr->left = builtBSTfromSorted(vec, st, mid-1);
    curr->right = builtBSTfromSorted(vec, mid+1, end);

    return curr;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void getInorder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    getInorder(root->left, ans);
    ans.push_back(root->data);
    getInorder(root->right, ans);
}

void balancedHelper(Node* root, vector<int> &nodes){
    if(root == NULL) return;
    balancedHelper(root->left, nodes);
    nodes.push_back(root->data);
    balancedHelper(root->right, nodes);
}
Node* BSTtoBalanced(Node* root){
    vector<int> nodes;
    balancedHelper(root, nodes);

    return builtBSTfromSorted(nodes, 0, nodes.size()-1);
}

static int maxSz;
Info* largestBST(Node* root){
    // if(root == NULL){
    //     return new Info(true, INT_MAX, INT_MIN, 0);
    // }

    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min){
        maxSz = max(currSz, maxSz);
        return new Info(true, currMin, currMax, currSz);
    } 

    return new Info(false, currMin, currMax, currSz);
}

Node* mergeBSTs(Node* root1, Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i=0, j=0;
    while(i < nodes1.size() && j < nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            merged.push_back(nodes1[i++]);
        } else{
            merged.push_back(nodes2[j++]);
        }
    }

    while (i < nodes1.size())
    {
        merged.push_back(nodes1[i++]);
    }

    while (j < nodes2.size())
    {
        merged.push_back(nodes2[j++]);
    }

    return builtBSTfromSorted(merged, 0, merged.size()-1);  
}


int main(){
    // int arr[9] = {8,5,3,1,4,6,10,11,14};
    // Node* root = buildBST(arr, 9);
    // vector<int> path;
    // rootToLeaf(root, path);

    // vector<int> vec = {3,4,5,6,7,8,9};
    // Node* root = builtBSTfromSorted(vec, 0, 6);
    // preorder(root);

    // Node* root = new Node(50);
    // root->left = new Node(30);
    // root->left->left = new Node(5);
    // root->left->right = new Node(20);

    // root->right = new Node(60);
    // root->right->left = new Node(45);
    // root->right->right = new Node(70);
    // root->right->right->left = new Node(65);
    // root->right->right->right = new Node(80);

    // largestBST(root);
    // cout << maxSz;

    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* finalRoot = mergeBSTs(root1, root2);
    preorder(finalRoot);
    return 0;
}