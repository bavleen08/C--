#include <bits\stdc++.h>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data<<endl;
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data<<endl;
}

void levelOrder(Node* root){
    if(root == NULL) return;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){
                cout << endl;
                if(q.empty()){
                    break;
                }
                q.push(NULL); // to track next line
            } else{ // otherwise code can crash when NULL->data
                cout << curr->data << " ";
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
        }
}

int height(Node* root){
    if(root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    return currHt;
}

int count(Node* root){
    if(root == NULL) return 0;
    int leftC = count(root->left);
    int rightC = count(root->right);

    return leftC + rightC + 1;
}

int sum(Node* root){
    if(root == NULL) return 0;
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

int diameter1(Node* root){
    if(root == NULL) return 0;
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diameter1(root->left);
    int rightDiam = diameter1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

pair<int, int> diameter2(Node* root){
    if(root == NULL) return make_pair(0,0);

    // pair -> (diameter, height)
    pair<int, int> leftInfo = diameter2(root->left); // (ld, lh)
    pair<int, int> rightInfo = diameter2(root->right);

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHeight);
}
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;

    if(root1->data != root2->data) return false;
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSub(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL) return true;
    else if(root == NULL || subRoot == NULL) return false;


    if(root->data == subRoot->data){
        // check sub tree
        if(isIdentical(root, subRoot)) return true;
    }
    int leftSubtree = isSub(root->left, subRoot);
    if(!leftSubtree){
        return isSub(root->right, subRoot);
    }
    return true;
}

void topView(Node* root){
    queue<pair<Node*, int>> Q; // (node, HD)
    map<int, int> output; // (HD, node->data)
    Q.push(make_pair(root, 0));
    output[0] = root->data;

    while(!Q.empty()){
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(!output.count(currHD)){
            output[currHD] = currNode->data;
        }

        if(currNode->left != NULL) Q.push(make_pair(currNode->left, currHD-1));
        if(currNode->right != NULL) Q.push(make_pair(currNode->right, currHD+1));
    }

    for(auto it: output){
        cout << it.second << " ";
    }
}

void kthLevel1(Node* root, int k){
    int count = 1;
    if(root == NULL) return;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){
                if(q.empty()){
                    break;
                }
                q.push(NULL);
                count++; // to track next line
            } else{ // otherwise code can crash when NULL->data
                if(k == count) cout << curr->data << " ";
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
        }
}

void kthLevel2(Node* root, int k, int level){
    if(root == NULL) return;
    if(k == level) {
        cout << root->data << " ";
        return;
    }
    kthLevel2(root->left, k, level+1);
    kthLevel2(root->right, k, level+1);
}

bool rootToNode(Node* root, int n, vector<int> &path){
    if(root == NULL) return false;
    path.push_back(root->data);

    if(root->data == n) return true;

    int isleft = rootToNode(root->left, n, path);
    int isright = rootToNode(root->right, n, path);

    if(isleft || isright) return true;
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int>path1;
    vector<int>path2;

    rootToNode(root, n1, path1);
    rootToNode(root, n2, path2);
    
    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++){
        if(path1[i] != path2[i]){
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2) return root;

    Node* leftLca = LCA2(root->left, n1, n2);
    Node* rightLca = LCA2(root->right, n1, n2);

    if(leftLca != NULL && rightLca != NULL) return root;

    return leftLca == NULL ? rightLca : leftLca;
}

int distance(Node* root, int n){
    if(root == NULL) return -1;

    if(root->data == n) return 0;

    int leftDis = distance(root->left, n);

    if( leftDis != -1) return 1 + leftDis;

    int rightDis = distance(root->right, n);
    if(rightDis != -1) return rightDis + 1;
    return -1;
}

int minDis(Node* root, int n1, int n2){
    Node* lca = LCA2(root, n1, n2);

    int dist1 = distance(lca, n1);
    int dist2 = distance(lca, n2);

    return dist1 + dist2;
}

int kthAnces(Node* root, int node, int k){
    if(root == NULL) return -1;
    if(root->data == node) return 0;
    int leftDis = kthAnces(root->left, node, k);
    int rightDis = kthAnces(root->right, node, k);

    if(rightDis == -1 && leftDis == -1) return -1;

    int validVal = leftDis == -1? rightDis: leftDis;

    if(validVal + 1 == k) cout << root->data;

    return validVal+1;
}

int transform(Node* root){
    if(root == NULL) return 0;
    int leftold = transform(root->left);
    int rightold = transform(root->right);

    int currold = root->data;
    
    root->data = leftold + rightold;
    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
    return currold;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    // cout << root->data;
    // postorder(root);
    // levelOrder(root);
    // cout << height(root);
    // cout << diameter2(root).first;

    // Node* subRoot = new Node(2);
    // subRoot->left = new Node(4);
    // subRoot->right = new Node(2);
    // cout << isSub(root, subRoot);

    // vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    // Node* root = buildTree(nodes);
    // cout << LCA2(root, 6, 3)->data;
    transform(root);
    levelOrder(root);
    return 0;
}