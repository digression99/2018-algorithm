
// algospot TILING2

#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100;
int memo[MAXN + 1];

int dp(int n) {
    if (n <= 1) return 1;
    int & ret = memo[n];
    if (ret != -1) return ret;
    
    ret = dp(n - 1) % MOD;
    ret += dp(n - 2) % MOD;
    return ret %= MOD;
}

int exhaustive(int n) {
    if (n <= 1) return 1;
    
    int ret = 0;
    ret = exhaustive(n - 1) % MOD;
    ret += exhaustive(n - 2) % MOD;
    return ret % MOD;
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;
        memset(memo, -1, sizeof(memo));
//        cout << exhaustive(n) << endl;
        cout << dp(n) << endl;
    }
}

int main() {
    driver();
    return 0;
}

