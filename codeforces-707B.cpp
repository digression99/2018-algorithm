
// codeforces 707B

// test case 1
//5 4 2
//1 2 5
//1 2 3
//2 3 4
//1 4 10
//1 5
// result 1
//3
// test case 2
//3 1 1
//1 2 3
//3
// result 2
//-1

// test case 3
//2 3 1
//1 2 3
//1 2 18
//1 2 13
//2
// result 3
//3

// test case 4
//10 10 3
//1 2 1000000000
//2 3 1000000000
//3 4 1000000000
//4 5 1000000000
//5 6 1000000000
//6 7 1000000000
//7 8 1000000000
//8 9 1000000000
//9 10 1000000000
//10 1 1000000000
//1 2 3
// result 4
//1000000000


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//vector<vector<int>> graph;
unordered_map<int, unordered_map<int, int>> graph;
unordered_map<int, int> storages;
//vector<int> storages;
const int MAXINT = 1000000001;

int solve() {
    int minPathNum = MAXINT;
    
    auto storageIt = storages.begin();
    
    while (storageIt != storages.end()) {
        int nowStorage = storageIt->first;
        
        auto it = graph[nowStorage].begin();
        while (it != graph[nowStorage].end()) {
            if (storages.find(it->first) == storages.end()) {
                // if no storage is in that city.
                minPathNum = min(minPathNum, it->second);
            }
            ++it;
        }
        ++storageIt;
    }
    
//
//    for (int i = 0; i < storages.size(); ++i) {
//        int nowStorage = storages[i];
//        auto it = graph[nowStorage].begin();
//        while (it != graph[nowStorage].end()) {
//            if (storages.find(it->first) == storages.end()) {
//                // if no storage is in that city.
//                minPathNum = min(minPathNum, it->second);
//            }
//            ++it;
//        }
//    }
    
    if (minPathNum == MAXINT) return -1;
    return minPathNum;
}

void driver() {
    int n, m, k;
    cin >> n >> m >> k;
    
    if (k == 0) {
        cout << -1 << endl;
        return;
    }
    
//    storages.resize(k, -1);
    
    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        // dealing with multi graph.
        if (graph[u].find(v) != graph[u].end()) {
            graph[u][v] = min(graph[u][v], l);
            graph[v][u] = min(graph[u][v], l);
        } else {
            graph[u][v] = l;
            graph[v][u] = l;
        }
    }
    
    for (int i = 0; i < k; ++i) {
        int tp;
        cin >> tp;
        storages[tp] = 1;
//        cin >> storages[i]; // storages[i] : where the storage located.
    }
    cout << solve() << endl;
}

int main() {
    driver();
    return 0;
}

