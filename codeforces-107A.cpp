
// codeforces 107A

// test case 1
//3 2
//1 2 10
//2 3 20
// result 1
//1
//1 3 10
// test case 2
//3 3
//1 2 20
//2 3 10
//3 1 5
// result 2
// 0
// test case 3
//4 2
//1 2 60
//3 4 50
// result 3
//2
//1 2 60
//3 4 50

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1000;

int inDegree[MAXN + 1], outDegree[MAXN + 1];
//int graph[MAXN + 1][MAXN + 1];
vector<vector<int>> graph;
int diameter[MAXN + 1];
int visited[MAXN + 1];

vector<pair<int, pair<int, int>>> resVec;

void dfs(int u, int d, int parent) {
    for (int i = 0; i < graph[u].size(); ++i) {
        int nowIdx = graph[u][i];
        if (!visited[i] && inDegree[nowIdx] && !outDegree[nowIdx]) {// tab house
            resVec.push_back(make_pair(parent, make_pair(nowIdx, d)));
        }
        dfs(nowIdx, min(d, diameter[nowIdx]), parent);
    }
}

void solve(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && !inDegree[i] && outDegree[i]) dfs(i, diameter[i], i);
    }
    
    cout << resVec.size() << endl;
    for (auto dat : resVec) {
        cout << dat.first << " " << dat.second.first << " " << dat.second.second << endl;
    }
}


void driver() {
    int n, p;
    cin >> n >> p;
    
    graph.resize(n + 1, vector<int>());
    memset(inDegree, 0, sizeof(inDegree));
    memset(outDegree, 0, sizeof(outDegree));
    memset(diameter, 0, sizeof(diameter));
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < p; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        
        // directed.
        graph[a].push_back(b);
        
//        graph[a][b] = 1;
        
        inDegree[b] = 1;
        outDegree[a] = 1;
        diameter[a] = d;
    }
    
    solve(n);
}
int main() {
    driver();
    return 0;
}

