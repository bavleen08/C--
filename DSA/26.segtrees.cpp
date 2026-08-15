#include <bits\stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> tree;
    int n;
    void buildTree(vector<int> &arr, int st, int end, int node){
        if(st == end){
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end-st)/2;
        buildTree(arr, st, mid, 2*node+1);
        buildTree(arr, mid+1, end, 2*node+2);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int rangeSum(int qi, int qj, int si, int sj, int node){
        // no overlap
        if(qj < si || qi > sj){
            return 0;
        }

        // complete overlap
        if(si >= qi && sj <= qj){
            return tree[node];
        }

        // partial overlap
        int mid = si + (sj-si)/2;
        return rangeSum(qi, qj, si, mid, 2*node+1) + rangeSum(qi, qj, mid+1, sj, 2*node+2);
    }

    void update(int idx, int val, int st, int end, int node){
        if(st == end){
            tree[node] = val;
            return;
        }

        int mid = st + (end-st)/2;
        if(st <= idx && idx <= end){
            update(idx, val, st, mid, 2*node+1);
        } else{
            update(idx, val, mid+1, end, 2*node+2);
        }

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

public:
    SegmentTree(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
        buildTree(arr, 0, n-1, 0);
    }


    void print(){
        for(int i=0; i<tree.size(); i++){
            cout << tree[i] << " ";
        }
    }

    int rangeQuery(int qi, int qj){
        return rangeSum(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int val){
        update(idx, val, 0, n-1, 0);
    }
};
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    SegmentTree st(arr);
    
    cout << st.rangeQuery(0,3);
    st.updateQuery(2,3);
    cout << st.rangeQuery(0,3);
    return 0;
}