//
// algospot_MORSE
//

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 200;
const int M = 1000000000 + 100;
int memo[MAXN + 1][MAXN + 1];

void calc() {
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i <= 200; ++i) {
        memo[i][0] = memo[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            memo[i][j] = min(M, memo[i - 1][j - 1] + memo[i - 1][j]);
        }
    }
}

int dp(int n, int m) {
//    if (n == 1) return m;
//    if (m == 1) return n;
    
    int & ret = memo[n][m];
    if (ret != -1) return ret;
    
    ret = dp(n - 1, m - 1) + dp(n - 1, m);
    return ret;
}
//
//string kth(int k, int n, int m) {
//
//    if (k <= 0) return "";
//    int skip = dp(n - 1, m);
//
//    if (k < skip) {
//        return "-" + kth(k, n - 1, m);
//    } else {
//        return "o" + kth(k - skip, n, m - 1);
//    }
//    return "#";
//}

string kth(int skip, int n, int m) {
    if (n == 0) return string(m, 'o');
    if (skip < memo[n + m - 1][n - 1])
        return "-" + kth(skip, n - 1, m);
    return "o" + kth(skip - memo[n + m - 1][n - 1], n, m - 1);
}

int main() {
//    memset(memo, -1, sizeof(memo));
//
//    memo[0][0] = 1;
//    memo[1][0] = memo[1][1] = 1;
//    for (int i = 2; i <= 100; ++i) {
//        memo[i][0] = memo[i][i] = 1;
//    }
    
//    for (int i = 1; i <= 99; ++i)
//        dp(100, i);
    calc();
    
    int k, n, m;
    cin >> n >> m >> k;
    
    cout << kth(k, n, m) << endl;
    
    return 0;
}

