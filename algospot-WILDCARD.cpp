// algospot WILDCARD

// test case
//3
//he?p
//3
//help
//heap
//helpp
//*p*
//3
//help
//papa
//hello
//*bb*
//1
//babbbc

// results
//heap
//help
//help
//papa

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string pat, str;
int N, W;
int memo[100 + 1][100 + 1];

bool exhaustive(int pLen, int sLen) {
    if (pLen == W && sLen == N) return true;
//    if (sLen == N && pat[pLen] == '*') return true;
//    if (!(pLen < W && sLen < N)) return false;

    if (pat[pLen] == '?') return exhaustive(pLen + 1, sLen + 1);
    else if (pat[pLen] == '*') {
        for (int i = 0; i + sLen <= N; ++i) {
            if (exhaustive(pLen + 1, sLen + i)) return true;
        }
    } else if (pat[pLen] == str[sLen]) return exhaustive(pLen + 1, sLen + 1);
    return false;
}

int dp(int pLen, int sLen) {
    if (pLen == W && sLen == N) return 1;
    int & ret = memo[pLen][sLen];
    if (ret != -1) return ret;
    
    ret = 0;
    if (pat[pLen] == '?') return ret = dp(pLen + 1, sLen + 1);
    else if (pat[pLen] == '*') {
        for (int i = 0; i + sLen <= N; ++i) {
            ret = dp(pLen + 1, sLen + i);
            if (ret == 1) return ret;
        }
    } else if (pat[pLen] == str[sLen]) return ret = dp(pLen + 1, sLen + 1);
    return ret = 0;
}

void driver() {
    int tc, n;
    vector<string> ans;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> pat;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> str;
            memset(memo, -1, sizeof(memo));
            W = (int)pat.length();
            N = (int)str.length();
            if (dp(0, 0) == 1) ans.push_back(str);
//            if (exhaustive(0, 0)) ans.push_back(str);
        }
        sort(ans.begin(), ans.end());
        for (auto dat : ans) cout << dat << endl;
        ans.clear();
    }
}

int main() {
    driver();
    
    
    
    return 0;
}

