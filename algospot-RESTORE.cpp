// algospot RESTORE
// 20180605 - not working.

// test case
//3
//3
//geo
//oji
//jing
//2
//world
//hello
//3
//abrac
//cadabra
//dabr

// results
//geojing
//helloworld
//cadabrac

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int K;
const int MAX = 987654321;
vector<string> strs;

bool matchCheck(const string & str, int i, int j, int k) {
    while (j < str.length() && k < strs[i].length()) {
        if (str[j] != strs[i][k]) return false;
        ++j; ++k;
    }
    return true;
}

bool isVisited(int made, int idx) {
    return (made & (1 << idx)) > 0;
}

int exhaustive(const string & nowStr, int made) {
    if (made == (1 << K) - 1) return (int)nowStr.length();
    
    int ret = MAX;
    
    for (int i = 0; i < K; ++i) {
        if (!isVisited(made, i)) {
            if (made == 0) ret = min(ret, exhaustive(strs[i], made | (1 << i)));
            else {
                
                // string match check.
                for (int j = 0; j < nowStr.length(); ++j) {
                    for (int k = 0; k < strs[i].length(); ++k) {
                        if (matchCheck(nowStr, i, j, k)) {
                            string restored = nowStr.substr(0, j) + strs[i].substr(k, strs[i].length());
                            ret = min(ret, exhaustive(restored, made | (1 << i)));
                        }
                    }
                }
            }
        }
    }
    
    return ret;
}

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];

int restore(int last, int used) {
    if (used == (1 << k) - 1) return 0;
    
    int & ret = cache[last][used];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int next = 0; next < k; ++next) {
        if ((used & (1 << next)) == 0) {
            int cand = overlap[last][next] + restore(next, used + (1 << next));
            ret = max(ret, cand);
        }
    }
    return ret;
}

string reconstruct(int last, int used) {
    if (used == (1 << k) - 1) return "";
    
    for (int next = 0; next < k; ++next) {
        if (used & (1 << next)) continue;
        
        int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
        if (restore(last, used) == ifUsed) {
            return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
        }
    }
    return "#";
}

int getOverlap(const string & a, const string & b) {
    for (int len = min((int)a.size(), (int)b.size()); len > 0; --len) {
        if (a.substr(a.size() - len) == b.substr(0, len)) return len;
    }
    return 0;
}

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cin >> k;
//        strs.resize(K);
        for (int j = 0; j < k; ++j) {
            cin >> word[i];
        }
        memset(cache, -1, sizeof(cache));
        
        while (true) {
            bool removed = false;
            
            for (int i = 0; i < k && !removed; ++i) {
                for (int j = 0; j < k; ++j) {
                    if (i != j && word[i].find(word[j]) != -1) {
                        
                        // remove the word.
                        word[j] = word[k - 1];
                        --k;
                        removed = true;
                    }
                }
            }
            
            if (!removed) break;
        }
        
        word[k] = "";
        sort(word, word + k);
        
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                overlap[i][j] = getOverlap(word[i], word[j]);
            }
        }
        
        restore(k, 0);
        cout << reconstruct(k, 0) << endl;
    }
}

int main() {
    driver();
    return 0;
}





































