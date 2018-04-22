// leet 822

#include <utility>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    static const int MAX = 2000;
    
    vector<int> fronts, backs;
    int n;
    int memo[MAX + 1][2];
    int best;
    
    int check() {
        int ret = MAX;
        for (int i = 0; i < n; ++i){
            int j = 0;
            while (j < n) {
                if (backs[i] == fronts[j]) break;
                ++j;
            }
            if (j == n) ret = min(ret, backs[i]);
        }
        
        return ret;
    }
    
    int exhaustive(int pos) {
        if (pos == n) {
            return check();
        }
        int ret = MAX;
        
        // not flip.
        ret = min(ret, exhaustive(pos + 1));
        
        // flip
        swap(fronts[pos], backs[pos]);
        ret = min(ret, exhaustive(pos + 1));
        swap(fronts[pos], backs[pos]);
        
        return ret;
    }
    
    void combinationSearch(int pos) {
        if (pos == n) {
            best = min(best, check());
            return;
        }

        // not flip.
        combinationSearch(pos + 1);
        // pruning
        if (backs[pos] == fronts[pos]) return;
        if (fronts[pos] > best) return;
        
        // flip
        swap(fronts[pos], backs[pos]);
        combinationSearch(pos + 1);
        swap(fronts[pos], backs[pos]);
    }
    
    int dp(int pos, int isFlipped) {
        if (pos == n) {
            return check();
        }
        int & ret = memo[pos][isFlipped];
        if (ret != -1) return ret;
        
        ret = MAX;
        
        // not flip.
        ret = min(ret, dp(pos + 1, 0));
        
        // flip
        swap(fronts[pos], backs[pos]);
        ret = min(ret, dp(pos + 1, 1));
        swap(fronts[pos], backs[pos]);
        
        return ret;
    }
    
    int huristic() {
        int ret = MAX;
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (j < n) {
                if (backs[i] == fronts[j] && fronts[j] == backs[j]) break;
                ++j;
            }
            if (j == n) ret = min(ret, backs[i]);
        }
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (j < n) {
                if (fronts[i] == backs[j] && fronts[j] == backs[j]) break;
                ++j;
            }
            if (j == n) ret = min(ret, fronts[i]);
        }
        return ret;
    }
    
    
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        this->fronts = fronts;
        this->backs = backs;
        this->n = (int)fronts.size();
        
        memset(memo, -1, sizeof(memo));
        best = MAX;
        best = huristic();
        if (best == 2000) return 0;
        return best;
//
//        combinationSearch(0);
//
//        if (best == 2000) return 0;
//        return best;
//        return best;
        
//        return min(dp(0, 0), dp(0, 1));
    }
};

int main() {
    Solution obj;
    vector<int> fronts = {1,2,4,4,7};
    vector<int> backs = {1,3,4,1,3};
    
//    [6,12,7,11,4,14,1,10,2,10,9,7,3,1,11,7,6,8,5,4,2,10,15,3,3,13,8,2,14,3,14,7,10,7,10,12,3,10,5,6,7,15,15,5,15,8,13,5,4,5]
//    [6,13,14,8,4,12,1,9,2,12,15,8,5,4,10,6,10,9,5,14,9,10,15,3,13,4,8,2,14,15,1,2,7,2,11,12,12,8,12,1,7,12,3,6,3,3,7,5,4,9]
    
    cout << obj.flipgame(fronts, backs) << endl;
    
    return 0;
}




























