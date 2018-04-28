// algospot NUMB3RS

// test case
//2
//5 2 0
//0 1 1 1 0
//1 0 0 0 1
//1 0 0 0 0
//1 0 0 0 0
//0 1 0 0 0
//3
//0 2 4
//8 2 3
//0 1 1 1 0 0 0 0
//1 0 0 1 0 0 0 0
//1 0 0 1 0 0 0 0
//1 1 1 0 1 1 0 0
//0 0 0 1 0 0 1 1
//0 0 0 1 0 0 0 1
//0 0 0 0 1 0 0 0
//0 0 0 0 1 1 0 0
//4
//3 1 2 6

// results
//0.83333333 0.00000000 0.16666667
//0.43333333 0.06666667 0.06666667 0.06666667

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int N, D, P;
vector<vector<int>> graph;
vector<double> probs;
vector<vector<double>> memo;
vector<int> edgeCnt;

void exhaustive(double prob, int nowCity, int nowD) {
    if (nowD == D) {
        probs[nowCity] += prob;
        return;
    }
    
    int edgeNum = 0;
    
    // edge count.
    for (int i = 0; i < N; ++i) {
        if (graph[nowCity][i]) ++edgeNum;
    }
    
//    int edgeNum = (int)graph[nowCity].size();
    
    for (int i = 0; i < N; ++i) {
        if (graph[nowCity][i]) {
            double p = prob * (1 / (double)edgeNum);
            exhaustive(p, i, nowD + 1);
        }
    }
}

double dp(int nowCity, int nowD) {
    if (nowD == 0) {
//        if (nowCity == P) return 1 / (double)edgeCnt[nowCity];
        if (nowCity == P) return 1;
        return 0;
    }
    
    double & ret = memo[nowCity][nowD];
    if (ret != -1) return ret;
    
    ret = 0;
    int edgeNum = edgeCnt[nowCity];
    
    for (int i = 0; i < N; ++i) {
        if (graph[nowCity][i]) {
            ret += dp(i, nowD - 1);
        }
    }
    return ret *= (1 / (double)edgeNum);
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cin >> N >> D >> P;
        graph.resize(N, vector<int>(N, 0));
        probs.resize(N, 0);
        memo.resize(N + 1, vector<double>(D + 1, -1));
        edgeCnt.resize(N, 0);
        
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                cin >> graph[j][k];
                if (graph[j][k]) ++edgeCnt[j];
            }
        }
        int temp = 0;
        cin >> temp;
        for (int j = 0; j < temp; ++j) {
            int city;
            cin >> city;
            
            double res = 0;
            
            for (int k = 0; k < N; ++k) {
                if (graph[city][k]) {
                    res += dp(k, D - 1);
                }
            }
            cout << setprecision(8) << res * (1 / (double)edgeCnt[P]) << " ";
        }
        cout << endl;
        
        graph.clear();
        probs.clear();
        memo.clear();
        edgeCnt.clear();
    }
}

int main() {
    driver();
    return 0;
}



