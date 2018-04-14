// algospot PI

// test case
//10
//12341234
//11111222
//12122222
//22222222
//12673939
//12341234
//11111222
//12122222
//22222222
//12673939

// results
//4
//2
//5
//2
//14
//4
//2
//5
//2
//14

#include <iostream>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAXN = 100000;
string nums;
int N;
int memo[MAXN + 1];

int check(int pos, int len) {
    // if every num is same.
    int i = 1;
    while (i < len && nums[pos + i] == nums[pos]) ++i;
    if (i == len) return 1;
    // if there's seq.
    i = 1;
    int diff = nums[pos + 1] - nums[pos];
    while (i < len && (nums[pos + i] - nums[pos + i - 1]) == diff) ++i;
    if (i == len) {
        if (abs(diff) == 1) return 2;
        return 5;
    }
    // if nums appear dup.
    i = 2;
    while (i < len && nums[pos + i] == nums[pos + i - 2]) ++i;
    if (i == len) return 4;
    // else.
    return 10;
}

int dp(int pos) {
    if (pos == N) return 0;
    if (N - pos < 3) return INF;
    
    int & ret = memo[pos];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 3; i <= 5; ++i) {
        ret = min(ret, check(pos, i) + dp(pos + i));
    }
    return ret;
}

int exhaustive(int pos) {
    if (pos == N) return 0;
    if (N - pos < 3) return INF;
    int ret = INF;
    for (int i = 3; i <= 5; ++i) {
        ret = min(ret, check(pos, i) + exhaustive(pos + i));
    }
    return ret;
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cin >> nums;
        N = (int)nums.length();
        memset(memo, -1, sizeof(memo));
        
        cout << dp(0) << endl;
    }
}


int main() {
    driver();
    return 0;
}

