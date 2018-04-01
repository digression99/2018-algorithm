// algospot PICNIC
// test case
//3
//2 1
//0 1
//4 6
//0 1 1 2 2 3 3 0 0 2 1 3
//6 10
//0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

// result
//1
//3
//4

#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt;
vector<int> graph[10];

bool isVisited(int visited, int idx) {
    return (visited & (1 << idx)) > 0;
}

int setVisited(int visited, int idx) {
    return visited | (1 << idx);
}

int unsetVisited(int visited, int idx) {
    int mask = (1 << 11) - 1;
    mask ^= (1 << idx);
    return visited & mask;
}

void exhaustive(int visited) {
    if (visited == ((1 << n) - 1)) {
        ++cnt;
        return;
    }
    
    // find first.
    
    int first = -1;
    for (int i = 0; i < n; ++i) {
        if (!isVisited(visited, i)) {
            first = i;
            break;
        }
    }
//    if (first == -1) return;
    
    visited = setVisited(visited, first);
    
    for (int i = 0; i < graph[first].size(); ++i) {
        int v = graph[first][i];
        if (!isVisited(visited, v)) {
            visited = setVisited(visited, v);
            exhaustive(visited);
            visited = unsetVisited(visited, v);
        }
    }
    
//    visited = unsetVisited(visited, first);
//    exhaustive(visited);
}

void driver() {
    
    int tc, u, v;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n >> m;
        
        // init.
        for (int i = 0; i < 10; ++i) graph[i].clear();
//        for (auto v : graph) v.clear();
        cnt = 0;
        
        for (int j = 0; j < m; ++j) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // result.
        exhaustive(0);
        cout << cnt << endl;
    }
}

void test() {
    
    int visited = 0;
    
    visited |= (1 << 3);
    
    cout << isVisited(visited, 3) << endl;
    cout << isVisited(visited, 2) << endl;
}

int main() {
    
//    test();
    driver();
    
    return 0;
}

