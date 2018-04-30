
// algospot PACKING

// test case
//2
//6 10
//laptop 4 7
//camera 2 10
//xbox 6 6
//grinder 4 7
//dumbell 2 5
//encyclopedia 10 4
//6 17
//laptop 4 7
//camera 2 10
//xbox 6 6
//grinder 4 7
//dumbell 2 5
//encyclopedia 10 4

// results
//24 3
//laptop
//camera
//grinder
//30 4
//laptop
//camera
//xbox
//grinder

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N, W;
const int MAXN = 100;
const int MAXW = 1000;
string strs[MAXN + 1];
int weights[MAXN + 1], vals[MAXN + 1];
int memo[MAXN + 1][MAXW + 1];

int exhaustive(int pos, int weight) {
    if (pos == N || weight == 0) return 0;
    
    int ret = exhaustive(pos + 1, weight);
    if (weight - weights[pos] >= 0) {
        ret = max(ret, exhaustive(pos + 1, weight - weights[pos]) + vals[pos]);
    }
    //    for (int i = pos; i < N; ++i) {
    //        if (weight - weights[i] >= 0)
    //            ret = max(ret, exhaustive(i, weight - weights[i]) + vals[i]);
    //    }
    return ret;
}

int dp(int pos, int weight) {
    if (pos == N || weight == 0) return memo[pos][weight] = 0;
    
    int & ret = memo[pos][weight];
    if (ret != -1) return ret;
    
    ret = dp(pos + 1, weight);
    if (weight - weights[pos] >= 0) {
        ret = max(ret, dp(pos + 1, weight - weights[pos]) + vals[pos]);
    }
    return ret;
}

//void reconstruct(int pos, int weight, vector<string> & res) {
//    if (pos + 1 == N) {
//        if (weight >= weights[pos]) {
//            res.push_back(strs[pos]);
//        }
//        return;
//    }
//
//    if (memo[pos + 1][weight - weights[pos]] == memo[pos][weight] - vals[pos]) {
//        res.push_back(strs[pos]);
//        reconstruct(pos + 1, weight - weights[pos], res);
//    } else {
//        reconstruct(pos + 1, weight, res);
//    }
//}

void reconstruct(int idx, int w, vector<string> & res) {
    if (idx == N) return;
    if (dp(idx, w) == dp(idx + 1, w)) {
        reconstruct(idx + 1, w, res);
    } else {
        res.push_back(strs[idx]);
        reconstruct(idx + 1, w - weights[idx], res);
    }
}

void driver() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> N >> W;
        for (int j = 0; j < N; ++j) {
            cin >> strs[j] >> weights[j] >> vals[j];
        }
        
        memset(memo, -1, sizeof(memo));
        
        //        int maxVals = exhaustive(0, W);
        int maxVals = dp(0, W);
        //        cout << maxVals << endl;
        //        for (int j = 0; j < N; ++j) {
        //            for (int k = 0; k <= W; ++k) {
        //                cout << memo[j][k] << " ";
        //            }
        //            cout << endl;
        //        }
        
        vector<string> res;
        reconstruct(0, W, res);
        cout << maxVals << " " << res.size() << endl;
        for (auto dat : res) cout << dat << endl;
    }
}

int main() {
    driver();
    return 0;
}


