

// algospot QUANTIZE

// test case
//3
//10 3
//3 3 3 1 2  3 2 2 2 1
//9 3
//1 744 755 4 897 902 890 6 777
//1
//3 3
//1 2 3
// results
//0
//651
//0

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAXN = 100;
const int MAXS = 10;
int N;
int memo[MAXN + 1][MAXS + 1];

//int nums[MAXN + 1];
vector<int> nums;
int partSums[MAXN + 1];

int getMeanError(int pos, int len) {
    int mFloor = floor((partSums[pos + len] - partSums[pos]) / (double)len);
    int mCeil = ceil((partSums[pos + len] - partSums[pos]) / (double)len);
    
//    int m = (partSums[pos + len] - partSums[pos]) / len;
    int eFloor = 0;
    int eCeil = 0;
    for (int i = pos; i < pos + len; ++i) {
        eFloor += (nums[i] - mFloor) * (nums[i] - mFloor);
        eCeil += (nums[i] - mCeil) * (nums[i] - mCeil);
    }
    return min(eFloor, eCeil);
}

int dp(int pos, int remain) {
    // base case
    if (pos == N) return 0;
    if (remain == 0) return INF;
    
    int & ret = memo[pos][remain];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 1; i <= N - pos; ++i) {
        int m = getMeanError(pos, i);
        ret = min(ret, m + dp(pos + i, remain - 1));
    }
    return ret;
}

int exhaustive(int pos, int remain) {
    // base case
    if (pos == N) return 0;
    if (remain == 0) return INF;
    
    int ret = INF;
    for (int i = 1; i <= N - pos; ++i) {
        int m = getMeanError(pos, i);
        ret = min(ret, m + exhaustive(pos + i, remain - 1));
    }
    return ret;
}

void partSumCalc() {
    partSums[0] = 0;
    for (int i = 1; i <= N; ++i) partSums[i] = partSums[i - 1] + nums[i - 1];
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int s;
        cin >> N >> s;
        
        memset(memo, -1, sizeof(memo));
        nums.resize(N);
        for (int j = 0; j < N; ++j) cin >> nums[j];
        
        sort(nums.begin(), nums.end());
        partSumCalc();
        
//        cout << exhaustive(0, s) << endl;
        cout << dp(0, s) << endl;
    }
}

int main() {
    driver();
    return 0;
}


