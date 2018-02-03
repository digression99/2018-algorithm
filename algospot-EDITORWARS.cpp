//
// 20180203
// algospot_EDITORWARS
//

/*
 test
 
 4
 4 4
 ACK 0 1
 ACK 1 2
 DIS 1 3
 ACK 2 0
 100 4
 ACK 0 1
 ACK 1 2
 ACK 2 3
 ACK 3 4
 3 3
 ACK 0 1
 ACK 1 2
 DIS 2 0
 8 6
 DIS 0 1
 ACK 1 2
 ACK 1 4
 DIS 4 3
 DIS 5 6
 ACK 5 7
 
 results
 MAX PARTY SIZE IS 3
 MAX PARTY SIZE IS 100
 CONTRADICTION AT 3
 MAX PARTY SIZE IS 5
 
 */


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;

struct BipartiteUnionFind {
    vector<int> parent, enemy, size, rank; // rank 는 최적화를 위한 것. 나중에.
    BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]); // u 의 루트를 u 의 parent 로 두고 그것을 리턴.
    }
    int merge(int u, int v) {
        if (u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        
        if (u == v) return u;
        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
        size[v] += size[u]; // 각 원소들의 개수를 합친다.
        return v;
    }
    bool dis(int u, int v) {
        u = find(u); v = find(v); // root.
        if (u == v) return false;
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        
        enemy[a] = b;
        if (b != -1) enemy[b] = a;
        return true;
    }
    bool ack(int u, int v) {
        u = find(u); v = find(v); // root.
        if (enemy[u] == v) return false;
        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        
        enemy[a] = b;
        if (b != -1) enemy[b] = a;
        return true;
    }
};

int maxParty(BipartiteUnionFind & buf) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (buf.find(i) == i) { // when i is the root
            int enemy = buf.enemy[i];
            if (enemy > i) continue; // to prevent dup.
            int size = buf.size[i];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            ret += max(size, enemySize);
        }
    }
    return ret;
}

int main() {
    int tc = 0;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int m, j;
        cin >> n >> m;
        
        BipartiteUnionFind buf(n);
        
        for (j = 0; j < m; ++j) {
            string action;
            int u, v;
            cin >> action >> u >> v;
            
            if (!action.compare("ACK")) {
                if (!buf.ack(u, v)) break;
            } else {
                if (!buf.dis(u, v)) break;
            }
        }
        if (j != m) cout << "CONTRADICTION AT " << j + 1 << endl;
        else cout << "MAX PARTY SIZE IS " << maxParty(buf) << endl;
    }
    
    return 0;
}

