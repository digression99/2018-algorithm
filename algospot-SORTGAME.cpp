#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// test case
//3
//8
//1 2 3 4 8 7 6 5
//4
//3 4 1 2
//3
//1 2 3

// result
//1
//2
//0


map<vector<int>, int> toSort;

void precalc(int n) {
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    queue<vector<int>> q;
    q.push(perm);
    toSort[perm] = 0;
    
    while (!q.empty()) {
        vector<int> here = q.front(); q.pop();
        int cost = toSort[here];
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j <= n; ++j) {
                reverse(here.begin() + i, here.begin() + j);
                if (toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

int solve(const vector<int> & perm) {
    int n = (int)perm.size();
    vector<int> fixed(n);
    
    for (int i = 0; i < n; ++i) {
        int smaller = 0;
        for (int j = 0; j < n; ++j) if (perm[j] < perm[i]) ++smaller;
        fixed[i] = smaller;
    }
    return toSort[fixed];
}

int main() {
    
    for (int i = 1; i <= 8; ++i) precalc(i);
    
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;
        vector<int> input(n);
        
//        precalc(n);
        
        for (int j = 0; j < n; ++j) {
            cin >> input[j];
        }
        cout << solve(input) << endl;
//        toSort.clear();
    }
    return 0;
}

