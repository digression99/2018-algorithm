// algospot MORSE

// test case
//3
//2 2 4
//4 8 13
//6 4 1

// results
//o--o
//--o-ooo-oooo
//------oooo

#include <iostream>
using namespace std;

const int MAX_MOD = 1000 * 1000 * 1000;
const int MAXN = 100;

int memo[2 * MAXN + 1][MAXN + 1];
int N, M, K;

void calc() {
    for (int i = 0; i <= 2 * MAXN; ++i) {
        memo[i][0] = memo[i][i] = 1;
        for (int j = 1; j <= i; ++j) {
            if (i < 2 * MAXN && j <= 100) {
                memo[i + 1][j] = memo[i][j - 1] + memo[i][j];
                if (memo[i + 1][j] >= MAX_MOD) memo[i + 1][j] = MAX_MOD;
            }
        }
    }
}

string kth(int n, int m, int skip) {
    // base case
    if (skip == 0 || n == 0 || m == 0) {
        return string(n, '-') + string(m, 'o');
    }
    
    if (memo[n + m - 1][m] < skip) {
        skip -= memo[n + m - 1][m];
        return "o" + kth(n, m - 1, skip);
    } else if (memo[n + m - 1][m] >= skip) {
        return "-" + kth(n - 1, m, skip);
    }
    
    return "#";
}

void driver() {
    
    calc();
    
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> N >> M >> K;
        
        cout << kth(N, M, K) << endl;
    }
}

void test() {
    
//    calc();
    
//    for (int i = 0; i < 2 * MAXN + 1; ++i) {
//        for (int j = 0; j < 2 * MAXN + 1; ++j) {
//            cout << memo[i][j] << " ";
//        }
//        cout << endl;
//    }
    
//    cout << string(1, '-') + string(10, ) << endl;

}

int main () {
//    test();
    driver();
    return 0;
}

