#include <bits\stdc++.h>
using namespace std;

// unweighted, adjacency list
class Graph{
    int V;
    list<int>* l;
    bool isUndir;
public:
    Graph(int V, bool isUndir=true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);  // for directed u--->v
        if(isUndir) l[v].push_back(u); // for undirected   u---v
    }

    void print(){
        for(int u=0; u<V; u++){
            list<int> neighbors = l[u];
            cout << u << "-> ";
            for(int v: neighbors){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfsHelper(int st, vector<bool> &vis){
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout << u << " ";
            list<int> neighbors = l[u];
            for(int v: neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    void bfs(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){  // for disjoint components
            if(!vis[i]){     
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout << u << " ";
        list<int> neighbors = l[u];
        for(int v : neighbors){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }
    void dfs(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){     // for disjoint components
            if(!vis[i]){
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    bool pathHelper(int src, int dest, vector<bool> &vis){

        // using DFS

        // if(src == dest) return true;
        // vis[src] = true;
        // list<int> neighbors = l[src];
        // for(int v : neighbors){
        //     if(!vis[v]){
        //         if(pathHelper(v, dest, vis)) return true;
        //     }
        // }
        // return false; 

        // using BFS
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(q.size() > 0){
            src = q.front();
            q.pop();
            if(src == dest) return true;
            list<int> neighbors = l[src];
            for(int v: neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    bool hasPath(int src, int dest){
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }

    bool undirectedCycleHelper(int src, int par, vector<bool> &vis){
// DFS
        // vis[src] = true;
        // list<int> neighbors = l[src];
        // for(int v : neighbors){
        //     if(!vis[v]){
        //         if(undirectedCycleHelper(v, src, vis)) return true;
        //     } else{
        //         if(v != par){
        //             return true;
        //         }
        //     }
        // }
        // return false;

// BFS
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            list<int> neighbors = l[u];
            for(int v: neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }else{
                    if(v != u) return true;
                }
            }
        }
    }
    bool undirectedCycleDfs(){
        vector<bool> vis(V, false);
        return undirectedCycleHelper(0, -1, vis);
    }
    bool undirectedCycleBfs(){
        vector<bool> vis(V, false);
        return undirectedCycleHelper(0, -1, vis);
    }

    bool directedCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(directedCycleHelper(v, vis, recPath)) return true;
            } else{
                if(recPath[v]) return true;
            }
        }
        recPath[src] = false;
        return false; 
    }
    bool directdCycleDfs(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                if(directedCycleHelper(0, vis, recPath)) return true;
            }
        }
        return false;
    }

    bool isBipartiteBfs(){
        vector<int> color(V, -1);
        queue<int> q;
        q.push(0);
        color[0] = 0;  // 0=blue 1=black
        while(q.size() > 0){
            int u = q.front();
            q.pop();
            list<int> neighbors = l[u];
            for(int v : neighbors){
                if(color[v] == -1){ // unvisited
                    q.push(v);
                    color[v] = !color[u];
                } else{
                    if(color[v] == color[u]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void allPathsHelper(int src, int dest, vector<bool> &vis, string &path){
        // if(src == dest){
        //     cout << path << dest << endl;
        //     return;
        // }
        // vis[src] = true;
        // path += to_string(src);
        // list<int> neighbors = l[src];
        // for(int v: neighbors){
        //     if(!vis[v]){
        //         allPathsHelper(v, dest, vis, path);
        //     }
        // }
        // path.pop_back();
        // vis[src] = false;


        queue<int> q;
        q.push(src);
        vis[src] = true;
        //path += to_string(src);

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            path += to_string(u);
            if(u == dest){
                cout << path << endl;
                vis[u] = false;
                path.pop_back();
            }
            list<int> neighbors = l[u];
            for(int v: neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    break;
                }
            }
        }
    }

    void allPaths(int src, int dest){
        vector<bool> vis(V, false);
        string path = "";
        allPathsHelper(src, dest, vis, path);
    }

    void topoSortHelper(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true;
        list<int> neighbors = l[src];
        for(int v: neighbors){
            if(!vis[v]){
                topoSortHelper(v, vis, s);
            }
        }
        s.push(src);
    }
    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoSortHelper(i, vis, s);
            }
        }

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }

    void calIndegree(vector<int> &indeg){
        for(int i=0; i<V; i++){
            list<int> neigh = l[i];
            for(int v: neigh){
                indeg[v]++;
            }
        }
    }

    void topoSort2(){
        queue<int> q;
        vector<int> indeg(V, 0);
        calIndegree(indeg);
        for(int i=0; i<V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            list<int> neigh = l[curr];
            for(int v: neigh){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            } 
        }
    }
};

// class Edge{
// public:
//     int u;
//     int v;
//     int wt;
//     Edge(int u, int v, int wt){
//         this->u = u;
//         this->v = v;
//         this->wt = wt;
//     }
// };
class Edge{
public:
    int v;
    int wt;
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};
// class Graph3{
//     int n;
//     vector<Edge> edges;
//     vector<int> par;
//     vector<int>rank;
// public:
//     Graph3(int n){
//         this->n = n;
//         for(int i=0; i<n; i++){
//             par.push_back(i);
//             rank.push_back(0);
//         }
//     }

//     void addEdge(int u, int v, int wt){
//         edges.push_back(Edge(u, v, wt));
//     }

//     int find(int x){
//         if(par[x] == x) return x;
//         return par[x] = find(par[x]);
//     }

//     void unionByRank(int u, int v){
//         int parU = find(u);
//         int parV = find(v);

//         if(rank[parU] == rank[parV]){
//             par[parU] = parV;
//             rank[parV]++;
//         } else if(rank[parU] > rank[parV]){
//             par[parU] = parV;
//         } else if(rank[parU] < rank[parV]){
//             par[parV] = parU;
//         }
//     }

//     void kruskals(){
//         sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});
//         int minCost = 0;
//         int count = 0;

//         for(int i=0; i<edges.size() && count <= n-1; i++){
//             Edge e = edges[i];
//             int parU = find(e.u);
//             int parV = find(e.v);

//             if(parU != parV){
//                 unionByRank(parU, parV);
//                 minCost += e.wt;
//                 count++;
//             }
//         }

//         cout << minCost;
//     }

// };
void dijkstra(int src, vector<vector<Edge>> graph, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    // pq-> dist[v], v.....sorting based on distance
    pq.push(make_pair(0, src));
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();
        vector<Edge> edges = graph[u];
        for(Edge e: edges){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }
    for(int d: dist){
        cout << d << " ";
    }
}

void bellmanFord(int src, vector<vector<Edge>> graph, int V){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){
            vector<Edge> edges = graph[u];
            for(Edge e: edges){
                if(dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int d: dist){
        cout << d << " ";
    }
}

// // weighted
class Graph2{
    int V;
    list<pair<int, int>>* l;
    bool isUndir;
public:
    Graph2(int V, bool isUndir=true){
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v, wt));
        if(isUndir)
        l[v].push_back(make_pair(u, wt));
    }

    void print(){
        for(int u=0; u<V; u++){
            list<pair<int,int>> neighbors = l[u];
            cout << u << "-> ";
            for(pair<int,int> v: neighbors){
                cout  << "(" << v.first << "," << v.second << ") ";
            }
            cout << endl;
        }
    }

    void primsAlgo(int src){
        vector<bool> mstSet(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // (wt, v)
        int ans = 0;
        pq.push(make_pair(0, src));
        vector<pair<int, int>> edges;

        while(pq.size() > 0){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(!mstSet[u]){
                mstSet[u] = true;
                ans += wt;
                edges.push_back(make_pair(u, wt));
                list<pair<int,int>> neigh = l[u];
                for(pair<int, int> v : neigh){
                    pq.push(make_pair(v.second, v.first));
                }
            }
        }
        cout << ans << endl;
        for(pair<int, int> u : edges){
            cout << u.first << "->" << u.second << endl;
        }
    }
};

class Disjoint{
    int n;
    vector<int> par;
    vector<int> rank;
public:
    Disjoint(int n){
        this->n = n;
        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        } 
        else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }
        else if(rank[parA] < rank[parB]){
            par[parA] = parB;
        }
    }
};

int main(){
    int V=6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(3,7));
    graph[1].push_back(Edge(2,1));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(5,5));
    graph[4].push_back(Edge(3,2));

    //bellmanFord(1, graph, V);
    //dijkstra(1,graph,V); 

    // Disjoint dj(6);
    // dj.unionByRank(0,2);
    // cout << dj.find(2);

    // Graph2 g(4);
    // Graph3 g(4);
    // g.addEdge(0,1,10);
    // g.addEdge(0,3,30);
    // g.addEdge(0,2,15);
    // g.addEdge(1,3,40);
    // g.addEdge(2,3,50);

    //g.kruskals();

    // g.primsAlgo(0);

    return 0;
}





// COURSES SCHEDULE 2 lc-210
// class Solution {
// public:

//     bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &graph){
//         vis[src]= true;
//         rec[src] = true;
//         for(int i=0; i<graph.size(); i++){
//             int u = graph[i][1];
//             int v = graph[i][0];
//             if(u==src){
//                 if(!vis[v]){
//                     if(isCycle(v, vis, rec, graph)){
//                         return true;
//                     }
//                 } else{
//                     if(rec[v]){
//                         return true;
//                     }
//                 }
//             }
//         }
//         rec[src] = false;
//         return false;
//     }


//     void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &graph){
//         vis[src] = true;
//         for(int i=0; i<graph.size(); i++){
//             int u = graph[i][1];
//             int v = graph[i][0];
//             if(u==src){
//                 if(!vis[v]){
//                     topoSort(v, vis, s, graph);
//                 }
//             }
//         }
//         s.push(src);
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
//         int V = numCourses;
//         vector<bool> vis(V, false);
//         vector<bool> rec(V, false);
//         vector<int> ans;
//         for(int i=0; i<V; i++){
//             if(!vis[i]){
//                 if(isCycle(i, vis, rec, graph)){
//                     return ans;
//                 }
//             }
//         }


//         // topological sorting
//         vector<bool> vis2(V, false);
//         stack<int> s;
//         for(int i=0; i<V; i++){
//             if(!vis2[i]){
//                 topoSort(i, vis2, s, graph);
//             }
//         }


//         // print topo sort from stack
//         while(!s.empty()){
//             ans.push_back(s.top());
//             s.pop();
//         }

//         return ans;
//     }
// };



// class Solution {
// public:
//     string alienOrder(vector<string>& words) {

//         unordered_map<char, unordered_set<char>> adj;
//         unordered_map<char, int> indegree;

//         // Step 1: Create all unique characters
//         for (auto &word : words) {
//             for (char c : word) {
//                 indegree[c] = 0;
//             }
//         }

//         // Step 2: Build the graph
//         for (int i = 0; i < words.size() - 1; i++) {
//             string &w1 = words[i];
//             string &w2 = words[i + 1];

//             // Invalid case: ["abc", "ab"]
//             if (w1.size() > w2.size() &&
//                 w1.substr(0, w2.size()) == w2)
//                 return "";

//             int len = min(w1.size(), w2.size());

//             for (int j = 0; j < len; j++) {
//                 if (w1[j] != w2[j]) {

//                     // Avoid duplicate edge
//                     if (!adj[w1[j]].count(w2[j])) {
//                         adj[w1[j]].insert(w2[j]);
//                         indegree[w2[j]]++;
//                     }
//                     break; // Only first difference matters
//                 }
//             }
//         }

//         // Step 3: Kahn's Algorithm
//         queue<char> q;

//         for (auto &it : indegree) {
//             if (it.second == 0)
//                 q.push(it.first);
//         }

//         string ans;

//         while (!q.empty()) {
//             char node = q.front();
//             q.pop();

//             ans += node;

//             for (char nei : adj[node]) {
//                 indegree[nei]--;
//                 if (indegree[nei] == 0)
//                     q.push(nei);
//             }
//         }

//         if (ans.size() != indegree.size())
//             return ""; // Cycle exists

//         return ans;
//     }
// };