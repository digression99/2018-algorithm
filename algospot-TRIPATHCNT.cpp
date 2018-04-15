
// algospot TRIPATHCNT

// test case
//2
//4
//1
//1 1
//1 1 1
//1 1 1 1
//4
//9
//5 7
//1 3 2
//3 5 5 6
// results
//8
//3

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
int N;
int boards[MAXN + 1][MAXN + 1];
int memo[MAXN + 1][MAXN + 1];
int pathMemo[MAXN + 1][MAXN + 1];

int exhaustive(int row, int col) {
    // base case
    if (row == N - 1) return boards[row][col];
    int ret = -1;
    ret = max(ret, exhaustive(row + 1, col));
    ret = max(ret, exhaustive(row + 1, col + 1));
    return ret + boards[row][col];
}

int dp(int row, int col) {
    // base case
    if (row == N - 1) {
//        memo[row][col] = 0;
        return memo[row][col] = boards[row][col];
    }
    int & ret = memo[row][col];
    if (ret != -1) return ret;
    
    ret = -1;
    ret = max(ret, dp(row + 1, col));
    ret = max(ret, dp(row + 1, col + 1));
    return ret += boards[row][col];
}

int findPath(int row, int col) {
    // base case
    if (row == N - 1) return 1;
    
    int now = memo[row][col];
    int ret = 0;
    if (row + 1 < N) {
        if (boards[row + 1][col] + memo[row + 1][col] == now)
            ret += findPath(row + 1, col);
        if (boards[row + 1][col + 1] + memo[row + 1][col + 1] == now)
            ret += findPath(row + 1, col + 1);
    }
    return ret;
}

int findPathDp(int row, int col) {
    // base case
    if (row == N - 1) return 1;
    int & ret = pathMemo[row][col];
    if (ret != -1) return ret;
    
    int now = memo[row][col];
    ret = 0;
    if (row + 1 < N) {
        if (boards[row][col] + memo[row + 1][col] == now)
            ret += findPathDp(row + 1, col);
        if (boards[row][col] + memo[row + 1][col + 1] == now)
            ret += findPathDp(row + 1, col + 1);
    }
    return ret;
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cin >> N;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k <= j; ++k) {
                cin >> boards[j][k];
            }
        }
        
        memset(memo, -1, sizeof(memo));
        memset(pathMemo, -1, sizeof(pathMemo));
        dp(0, 0);
        
//        for (int j = 0; j < N; ++j) {
//            for (int k = 0; k <= j; ++k) {
//                cout << memo[j][k] << " ";
//            }
//            cout << endl;
//        }
        
        cout << findPathDp(0, 0) << endl;
//        cout << pathExhaustive(0, 0, 0) << endl;
    }
}

int main() {
    driver();
    return 0;
}

