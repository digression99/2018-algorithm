//
// algospot_FESTIVAL
//
//
//


#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
int memo[MAXN + 1][MAXN + 1];

int getSum(vector<int> & data, int start, int end) {
    return 0;
}

double solve(vector<int> & data, int n, int l) {
    double minNum = 0;
    for (int i = 0; i < n; ++i) {
        memo[i][i + l] = getSum(data, i, i + l);
        minNum = min(minNum, (double)memo[i][i + l] / l);
    }
    
    for (int i = l + 1; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            memo[j][i] = memo[j][i - 1] + data[j + i];
            minNum = min(minNum, (double)memo[j][i] / i);
        }
    }
    
    return minNum;
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int n = 0, l = 0;
        vector<int> data(n);
        cin >> n >> l;
        for (int j = 0; j < n; ++j) {
            cin >> data[j];
        }
        cout << solve(data, n, l) << endl;
    }
    
    return 0;
}

