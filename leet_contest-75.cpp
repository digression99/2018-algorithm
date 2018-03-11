#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// not mine.
/*
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>result(100, vector<double>(100, -2));
        result[0][0] = poured;
        help(poured, query_row, query_glass, result);
        return min(result[query_row][query_glass], 1.0);
    }
    
    double help(int poured, int query_row, int query_glass, vector<vector<double>> & result) {
        if(query_glass < 0 || query_glass > query_row)
            return 0;
        if(result[query_row][query_glass] != -2)
            return result[query_row][query_glass];
        
        double left = help(poured, query_row-1, query_glass-1, result) - 1;
        if(left < 0) left = 0;
        double right = help(poured, query_row-1, query_glass, result) - 1;
        if(right < 0) right = 0;
        result[query_row][query_glass] = (left + right)/2.;
        
        return result[query_row][query_glass];
    }
};
*/

class Solution {
public:
    
    double memo[100 + 1][100 + 1];
    
    void pour(int row, int col, double amount) {
        
        if (memo[row][col] < 1) {
            memo[row][col] += amount;
            if (memo[row][col] < 1) return;
            amount = memo[row][col] - 1;
        }
//        amount = amount - (memo[row][col] - 1);
        
        pour(row + 1, col, amount / 2);
        pour(row + 1, col + 1, amount / 2);
    }
    
    
    // leet 799
    double champagneTower(int poured, int query_row, int query_glass) {
        // init memo.
        memset(memo, 0, sizeof(memo));
        
        for (int i = 0; i <= 100; ++i)
            for (int j = 0; j <= 100; ++j)
                memo[i][j] = 0;
        
        for(int i = 0; i < poured; ++i) pour(0, 0, 1);
        
        return memo[query_row][query_glass];
    }
    
    void makeGraph(vector<vector<int>> & graph, vector<vector<int>> & hash) {
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                hash[i][graph[i][j]] = 1;
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = (int)graph.size();
//        vector<bool> visited(N, false);
        vector<vector<int>> hash(N, vector<int>(N, 0));
        vector<vector<int>> res;
        queue<pair<int, vector<int>>> q;
        
        makeGraph(graph, hash);
        
        q.push({0, vector<int>()});
        
        while (!q.empty()) {
            pair<int, vector<int>> front = q.front(); q.pop();
            int here = front.first;
//            visited[here] = true;
            
            if (here == N - 1) {
                front.second.push_back(here);
                res.push_back(front.second);
                continue;
            }
            
            front.second.push_back(here);
            for (int i = 0; i < N; ++i) {
                if (hash[here][i]) {
//                    visited[i] = true;
                    q.push({i, front.second});
//                    front.second.pop_back();
                }
            }
        }
        return res;
    }
    
    bool rotateString(string A, string B) {
        int initStart = 0, startA = 0, rest = -1, startB = 0;
        
        while (startA < A.length()) {
            if (A[startA] != B[startB]) {
                ++startA;
                continue;
            }
            initStart = startA;
            
            while (startA < A.length() && startB < B.length() && A[startA] == B[startB]) {
                ++startA;
                ++startB;
            }
            if (startA != A.length()) {
                startB = 0;
                // ++startA;
                continue;
            }
            
            if (initStart == 0 && startA == A.length()) return true;
            
            rest = 0;
            while (rest < initStart && startB < B.length()) {
                if (A[rest] != B[startB]) break;
                ++rest;
                ++startB;
            }
            if (initStart != 0 && rest == initStart) return true;
        }
        
        return false;
    }
};

int main() {
    Solution obj;
    string A = "vcuszhlbtpmksjleuchmjffufrwpiddgyynfujnqblngzoogzg";
    string B = "fufrwpiddgyynfujnqblngzoogzgvcuszhlbtpmksjleuchmjf";
    
    cout << obj.rotateString(A, B) << endl;;
    
    return 0;
}

