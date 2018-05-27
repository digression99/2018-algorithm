// leet 841

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>> & graph, vector<bool> & visited, int now) {
        
        visited[now] = true;
        
        for (int i = 0; i < graph[now].size(); ++i) {
            int idx = graph[now][i];
            if (!visited[idx]) {
                dfs(graph, visited, idx);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        
        for (int i = 0; i < visited.size(); ++i)
            if (!visited[i]) return false;
        return true;
    }
};

int main() {
    return 0;
}

