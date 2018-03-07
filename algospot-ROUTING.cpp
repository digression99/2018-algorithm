//
// algospot ROUTING
//

// test cases
//1
//7 14
//0 1 1.3
//0 2 1.1
//0 3 1.24
//3 4 1.17
//3 5 1.24
//3 1 2
//1 2 1.31
//1 2 1.26
//1 4 1.11
//1 5 1.37
//5 4 1.24
//4 6 1.77
//5 6 1.11
//2 6 1.2

// result
//1.3200000000

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;


int V;
const int MAX_V = 10000;
const int INF = 987654321;

// adjacent list
vector<vector<pair<int, double>>> adj; // first : index, second : weight.

vector<double> dijkstra(int src) {
    vector<double> dist(V, INF);
    priority_queue<pair<double, int>> pq; // first : weight, second : index.
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int here = pq.top().second;
        double cost = -pq.top().first;
        pq.pop();
        
        if (cost > dist[here]) continue;
        
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            double w = adj[here][i].second;
            double nextDist = cost + w;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    
    return dist;
}

vector<double> dijkstra2(int src) {
    // not using the priority queue.
    vector<double> dist(V, INF); //
    
    vector<bool> visited(V, false);
    
    dist[src] = 0;
    visited[src] = false;
    
    while (true) {
        int closest = INF;
        int here = -1; // to save the closest index.
        for (int i = 0; i < V; ++i) {
            if (dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        }
        
        if (closest == INF) break;
        
        visited[here] = true;
        
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            // check if you already visited there.
            if (visited[there]) continue;
            double nextDist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
    
    return dist;
}

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        int E;
        cin >> V >> E;

        adj.resize(V);

        for (int j = 0 ; j < E; ++j) {
            int first, second;
            double dist;
            cin >> first >> second >> dist;

            double logDist = log(dist);
            adj[first].push_back({second, logDist});
            adj[second].push_back({first, logDist});
        }

//        vector<double> res = dijkstra(0);
        vector<double> res = dijkstra2(0);
        
        cout << fixed << setprecision(10) << exp(res[res.size() - 1]) << endl;
    }
    
    return 0;
}


