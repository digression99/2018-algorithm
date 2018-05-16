// algospot KLIS

// test case
//3
//9 2
//1 9 7 4 2 6 3 11 10
//8 4
//2 1 4 3 6 5 8 7
//8 2
//5 6 7 8 1 2 3 4

// results
//4
//1 2 3 11
//4
//1 3 6 8
//4
//5 6 7 8

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 500;
const int MAXK = 2000000000 + 1;
int N, K;

int seq[MAXN + 2];
int memo[MAXN + 2];
int cnt[MAXN + 2];

int lis(int pos) {

//    if (pos == N) return memo[pos] = 0;

    int & ret = memo[pos + 1];
    if (ret != -1) return ret;
    
    ret = 1;

    for (int i = pos + 1; i < N; ++i) {
        if (pos == -1 || seq[pos] < seq[i]) {
            ret = max(ret, 1 + lis(i));
        }
    }

    return ret;
}

int count(int start) {
    if (lis(start) == 1) return 1;
    int & ret = cnt[start + 1];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = start + 1; i < N; ++i) {
        if ((start == -1 || seq[start] < seq[i]) && lis(start) == lis(i) + 1) {
            ret = min<long long>(MAXK, (long long)ret + count(i));
        }
    }
    return ret;
}

void reconstruct(int start, int skip, vector<int> & res) {
    if (start != -1) res.push_back(seq[start]);
    vector<pair<int, int>> followers;
    
    for (int i = start + 1; i < N; ++i) {
        if ((start == -1 || seq[start] < seq[i]) && lis(start) == lis(i) + 1) {
            followers.push_back({seq[i], i});
        }
    }
    
    sort(followers.begin(), followers.end());
    
    for (int i = 0; i < followers.size(); ++i) {
        int idx = followers[i].second;
        int cnt = count(idx);
        if (cnt <= skip) {
            skip -= cnt;
        } else {
            reconstruct(idx, skip, res);
            break;
        }
    }
}



//
//int countLis(int pos, int maxLen) {
//
//
//
//    if (maxLen == 0) return 1;
//    cnt[pos] = 0;
//
//    for (int i = pos + 1; i <= N; ++i) {
//        if (seq[pos] < seq[i] && lisDp(i) == maxLen - 1) {
//            cnt[pos] += countLis(i, maxLen - 1);
//        }
//    }
//    return cnt[pos];
//}

void driver() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i){
        cin >> N >> K;
        
        memset(memo, -1, sizeof(memo));
        memset(seq, -1, sizeof(seq));
        memset(cnt, -1, sizeof(cnt));
        
        for (int j = 0; j < N; ++j) {
            cin >> seq[j];
        }
        
        lis(-1);
//        cout << "maxLen is : " << maxLen << endl;
        count(-1);
        
        vector<int> res;
        reconstruct(-1, K, res);
        
        for (auto dat : res) cout << dat << " ";
        cout << endl;

//        for (int j = 0; j < N; ++j) {
//            cout << seq[j] << " ";
//        }
//        cout << endl;
//        for (int j = 0; j < N; ++j) {
//            cout << memo[j] << " ";
//        }
//        cout << endl;
//        for (int j = 0; j < N; ++j) {
//            cout << cnt[j] << " ";
//        }
//        cout << endl;
    }
}

int main() {
    driver();
    return 0;
}

