
// codeforces 604B

// test case 1
//2 1
//2 5
// result 1
//7

// test case 2
//4 3
//2 3 5 9
// result 2
//9

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//const int MAXN =
vector<int> S;
vector<bool> visited;
int N;

bool check(int sum, int boxNum, int remain) {
    // base case.
    if (remain == 0 && boxNum > 0) return false;
//    if (boxNum == 0 && remain == 0) return true;
    
    int unchecked = -1;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            unchecked = i;
            break;
        }
    }
//
//    if (unchecked == -1 && boxNum == 0) return true; // true condition.
    
    if (remain == 1) {
        if ((S[unchecked] <= sum) && (boxNum - 1 == 0)) return true;
        else
            return false;
    }
    
    visited[unchecked] = true;
    
    for (int i = 0; i < N && i != unchecked; ++i) {
        if (!visited[i] && S[unchecked] + S[i] <= sum) {
            visited[i] = true;
            if (check(sum, boxNum - 1, remain - 2)) return true;
            visited[i] = false;
        }
    }
    
    visited[unchecked] = false;
    return false;
}

int exhaustive(int K) {
    int ret = 987654321;
    
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int sum = S[i] + S[j];
            if (check(sum, K, N)) ret = min(ret, sum);
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (check(S[i], K, N)) ret = min(ret, S[i]);
    }
    
    return ret;
}


void driver() {
    int K;
    cin >> N >> K;
    
    visited.resize(N, false);
    
    for (int i = 0; i < N; ++i) {
        int tp;
        cin >> tp;
        S.push_back(tp);
    }
    cout << exhaustive(K) << endl;
}


int main() {
    driver();
    return 0;
}

