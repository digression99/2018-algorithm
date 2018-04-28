// algospot POLY

#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int dp(int n, int first) {
    if (n == first) return 1;
    
    int & ret = cache[n][first];
    if (ret != -1) return ret;
    ret = 0;
    for (int second = 1; second <= n - first; ++second) {
        int add = second + first - 1;
        add *= dp(n - first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int exhaustive(int n) {
    
    if (n <= 1) return 1;
    int ret = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; n - i - j >= 0; ++j) {
            ret += (i + j - 1) * exhaustive(n - i - j);
        }
    }
    return ret;
}

void driver() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        
        
        cout << (MOD + dp(n + 1, 1) - dp(n, 0)) % MOD << endl;
//        cout << exhaustive(n) << endl;
    }
}

int main() {
    
    driver();
    
    return 0;
}

