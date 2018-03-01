/*
 
 algospot GALLERY
 
 */

// test case
//3
//6 5
//0 1
//1 2
//1 3
//2 5
//0 4
//4 2
//0 1
//2 3
//1000 1
//0 1

// result
//3
//2
//999

#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 1000;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int V;
vector<int> adj[MAX_V]; // adjacent list
vector<bool> visited;
int installed;

int dfs(int here) {
    visited[here] = true;
    
    int children[3] = {0,};
    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visited[there]) ++children[dfs(there)];
    }
    
    if (children[UNWATCHED]) {
        ++installed;
        return INSTALLED;
    }
    
    if (children[INSTALLED]) return WATCHED;
    return UNWATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(V, false);
    for (int u = 0; u < V; ++u) {
        if (!visited[u] && dfs(u) == UNWATCHED) ++installed;
    }
    return installed;
}

int main() {
    int tc, h;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {

        cin >> V >> h;
        for (int j = 0; j < h; ++j) {
            int u, v;
            cin >> u >> v;
            // undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        cout << installCamera() << endl;
        
        // init
        for (int i = 0; i < MAX_V; ++i) adj[i].clear();
//        for (auto v : adj)
//            while (!v.empty()) v.clear();
    }
    
    return 0;
}
























