#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;


const int MAX_NUM = 1000000;

int memo[MAX_NUM];

void precalc() {
    
    memo[0] = memo[1] = 1;
    
    for (long long i = 2; i < MAX_NUM; ++i) {
        if (memo[i] == 0) {
            for (long long j = i * i; j < MAX_NUM; j += i) {
                memo[j] = 1;
            }
        }
    }
}

bool isPerfectSquare(long long n) {
    double sq = sqrt(n);
    return sq == int(sq);
}
//
//bool solve(long long n) {
//    if (n == 1) return false;
//
//    long long end = floor(sqrt(n)) + 1;
//
//    if (memo.find(end) != memo.end()) return memo[end];
//    int cnt = 0;
//
//    for (int i = 2; i <= end; ++i) {
//        if (i != n && n % i == 0) {
//            ++cnt;
//            if (cnt > 1) return memo[end] = false;
//        }
//    }
//    if (cnt == 1) return memo[end] = true;
//    return memo[end] = false;
//}

int main() {
    int n, idx;
    long long t;
    cin >> n;
    
    precalc();
    
    for (int i = 0; i < n; ++i) {
        cin >> t;
        idx = int(sqrt(t));
        bool ispf = isPerfectSquare(t);
        
        if (t == 4) cout << "YES" << endl;
        else if (t % 2 == 0) cout << "NO" << endl;
        else if (ispf && memo[idx] == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

bool solve(long long n) {
    if (n == 1) return false;
    long long end = ceil(sqrt(n));
    int cnt = 0;
    
    for (int i = 2; i <= end; ++i) {
        if (n % i == 0) {
            ++cnt;
            if (cnt > 1) return false;
        }
    }
    if (cnt == 1) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        long long t;
        cin >> t;
        if (solve(t)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

