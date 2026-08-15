#include <bits\stdc++.h>
using namespace std;

class Heap{
    vector<int> vec;
public:
    void push(int val){
        vec.push_back(val);
        int child = vec.size()-1;
        int par = (child-1)/2;

        while( par >= 0 && vec[child] > vec[par]){
            swap(vec[child], vec[par]);
            child = par;
            par = (child-1)/2;
        }
    }

    void heapify1(int i){
        if(i >= vec.size()) return; // if vec is empty
        int l = 2*i+1;
        int r = 2*i+2;
        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]){
            maxIdx = l;
        }
        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }

        swap(vec[maxIdx], vec[i]); // will give error if vec is empty
        if(maxIdx != i){
            heapify1(maxIdx);
        }
    }
    void pop(){
        swap(vec[0], vec[vec.size()-1]);
        vec.pop_back();
        heapify1(0); //root idx
    }

    int top(){
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }
};

// class Student{
// public:
//     string name;
//     int marks;

//     Student(string name, int marks){
//         this->name = name;
//         this->marks = marks;
//     }

//     bool operator < (const Student &obj) const {
//         return this->marks < obj.marks; // maxheap
//     }
// };

struct ComparePair{
    bool operator()(pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second;
    }
};

// HEAP SORT
void heapify2(int i, vector<int> &vec, int n ){
    int left = 2*i+1;
    int right = 2*i+2;
    int maxI = i;

    if(left < n && vec[left] > vec[maxI]){
        maxI = left;
    }
    if(right < n && vec[right] > vec[maxI]){
        maxI = right;
    }

    if(maxI != i){
        swap(vec[maxI], vec[i]);
        heapify2(maxI, vec, n);
    }
    return;
}

void heapSort(vector<int> &vec){
    int n = vec.size();
    for(int i=n/2-1; i>=0; i--){
        heapify2(i, vec, n);
    }
    for(int i=n-1; i>=0; i--){
        swap(vec[0], vec[i]);
        heapify2(0, vec, i);
    }
}

// NEARBY CARS
class Car{
public:
    int idx;
    int disSq;
    Car(int idx, int disSq){
        this->idx = idx;
        this->disSq = disSq;
    }

    bool operator  < (const Car &obj) const {
        return this->disSq > obj.disSq; // min heap
    }
};

void nearbyCars(vector<pair<int, int>> pos, int k){
    // idx, dis
    vector<Car> cars;
    for(int i = 0; i<pos.size(); i++){
        int disSq = (pos[i].first * pos[i].first)  + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, disSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());
    for(int i=0; i<k; i++){
        cout << "car: " << pq.top().idx << endl;
        pq.pop();
    }
}

// CONNECT N ROPES
int connectRopes(vector<int>ropes){
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());
    while(pq.size() != 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        cost += min1 + min2;
        pq.push(min1 + min2);
    }
    return cost;
}

// WEAKEST SOLDIER
class Row{
public:
    int count;
    int idx;
    Row(int count, int idx){
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const{
        if(this->count == obj.count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};
void weakSol(vector<vector<int>> matrix, int k){
    vector<Row> rows;
    for(int i=0; i<matrix.size(); i++){
        int count = 0;
        for(int j=0; j< matrix[i].size() && matrix[i][j] == 1; j++){
            count++;
        }
        rows.push_back(Row(count, i));
    }
    priority_queue<Row> pq(rows.begin(), rows.end());
    for(int i=0; i<k; i++){
        cout << pq.top().idx << endl;
        pq.pop();
    }
}

// SLIDING WINDOW
void slidingWindowMax(vector<int> vec, int k){
    priority_queue<pair<int , int>> pq; 
    
    // 1st window
    for(int i=0; i<k; i++){
        pq.push(make_pair(vec[i], i));
    }

    cout << pq.top().first << " ";

    for(int i=k; i<vec.size(); i++){
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }
        pq.push(make_pair(vec[i], i));
        cout << pq.top().first << " ";
    }
}
int main(){
    // Heap h;
    // h.push(5);
    // h.push(4);
    // h.push(3);

    // cout << h.top();
    // h.pop();
    // cout << h.top();

    // priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
    // pq.push(make_pair("bav", 87));
    // pq.push(make_pair("prabh", 98));
    // pq.push(make_pair("jane", 67));

    // while(!pq.empty()){
    //     cout << pq.top().first << "," << pq.top().second << endl;
    //     pq.pop();
    // }

    // vector<int> vec = {1,4,2,5,3};
    // heapSort(vec);
    // for(int i=0; i<vec.size(); i++){
    //     cout << vec[i] << " ";
    // }

    // vector<pair<int, int>> pos;
    // pos.push_back(make_pair(3,3));
    // pos.push_back(make_pair(5,-1));
    // pos.push_back(make_pair(-2,4));
    // nearbyCars(pos, 2);

    // vector<int> ropes = {4,3,2,6};
    // cout << connectRopes(ropes);

    // vector<vector<int>> matrix = {{1,0,0,0}, {1,1,1,1}, {1,0,0,0}, {1,0,0,0}};
    // weakSol(matrix, 2);

    vector<int> vec = {1,3,-1,3,5,3,6,7};
    slidingWindowMax(vec, 3);
}