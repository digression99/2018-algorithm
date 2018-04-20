// algospot ASYMTILING

// test case
//3
//2
//4
//92
// results
//0
//2
//913227494


#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int MOD = 1000000007;
int memo[MAXN + 1];
int asymMemo[MAXN + 1];

int exhaustive(int n) {
    // tiling exhaustive.
    if (n <= 1) return 1;
    int ret = 0;
    ret = exhaustive(n - 1) + exhaustive(n - 2);
    return ret;
}

int dp(int n) {
    if (n <= 1) return 1;
    int & ret = memo[n];
    if (ret != -1) return ret;
    ret = 0;
    ret += dp(n - 1) % MOD;
    ret += dp(n - 2) % MOD;
    return ret %= MOD;
}

int asymExhaustive(int n) {
    if (n <= 2) return 0;
    int & ret = asymMemo[n];
    if (ret != -1) return ret;
    ret = dp(n) % MOD;
    
    if (n % 2) {
        // if n is odd.
        ret += (MOD - dp((n - 1) / 2));
//        ret -= dp((n - 1) / 2);
    } else {
        // if n is even.
        ret += (MOD - dp(n / 2));
        ret %= MOD;
        ret += (MOD - dp((n - 2) / 2));
//        ret -= dp(n / 2);
//        ret -= dp((n - 2) / 2);
    }
    return ret %= MOD;
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;
        memset(memo, -1, sizeof(memo));
        memset(asymMemo, -1, sizeof(asymMemo));
        cout << asymExhaustive(n) << endl;
    }
}

int main() {
    driver();
    return 0;
}

