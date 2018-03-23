#include <iostream>
#include <unordered_map>
using namespace std;

void solve() {
    unordered_map<int, int> hash;

    int n;
    
    cin >> n;
    
    for (int j = 0; j < n; ++j) {
        int t;
        cin >> t;
        hash[t]++;
    }
    unordered_map<int, int> secondHash;
    
    for (int i = 0; i < 2; ++i) {
//        unordered_map<int, int> secondHash;
        for (int j = 0; j < n - (i + 1); ++j) {
            int t;
            cin >> t;
            secondHash[t]++;
            hash[t]--;
        }
        
        for (auto d : hash) {
            if (d.second > 0) {
                cout << d.first << endl;
                break;
            }
        }
        hash = secondHash;
        secondHash.clear();
    }
}

void test() {
    unordered_map<int, int> hash;
    for (int i = 0; i < 5; ++i) {
        int t;
        cin >> t;
        hash[t]++;
    }
    
    for (auto d : hash) cout << d.first << " " << d.second << endl;
    
    for (int i = 0; i < 4; ++i) {
        hash[i]--;
    }
    for (auto d : hash) cout << d.first << " " << d.second << endl;
}


int main() {
    
    solve();
    
//    test();

    
    
    return 0;
}

