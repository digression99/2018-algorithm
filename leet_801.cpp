#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// pos, changed 가 그 구분자다. changed 면 그 전에 애를 알 수 있다.


// recursive 하려면 뒤에서부터 내려가야?
// not mine.
class Solution {
public:
    int calc(vector<vector<int>>& dp, vector<int>& A, vector<int>& B, int pos, int changed) {
        if (pos < 0)
            return 0;
        if (dp[pos][changed] != -1)
            return dp[pos][changed];
        dp[pos][changed] = 1<<28;
        int prevA = changed ? B[pos + 1] : A[pos + 1];
        int prevB = changed ? A[pos + 1] : B[pos + 1];
        if (A[pos] < prevA && B[pos] < prevB) {
            int v = calc(dp, A, B, pos - 1, 0);
            if (v < dp[pos][changed])
                dp[pos][changed] = v;
        }
        if (B[pos] < prevA && A[pos] < prevB) {
            int v = 1 + calc(dp, A, B, pos - 1, 1);
            if (v < dp[pos][changed])
                dp[pos][changed] = v;
        }
        return dp[pos][changed];
    }
    int minSwap(vector<int>& A, vector<int>& B) {
        if (A.size() == 1)
            return 0;
        vector<vector<int>> dp(A.size(), vector<int>(2, -1));
        int a = calc(dp, A, B, A.size() - 2, 0);
        int b = 1 + calc(dp, A, B, A.size() - 2, 1);
        if (a < b)
            return a;
        return b;
    }
};

class Solution {
public:
    
    static const int MAX_SWAP = 1000 + 1;
    int n;
    int memo[1000 + 1];
    vector<int> A, B;
    
    int dp(int pos) {
        if (pos == n) return MAX_SWAP;
        
        int & ret = memo[pos];
        if (ret != -1) return ret;
        
        ret = MAX_SWAP;
    
        // not swap
        if (pos == 0 || !(A[pos - 1] > A[pos] || B[pos - 1] > B[pos])) {
            ret = min(ret, dp(pos + 1) + 1);
        }
        
//        ret = min(ret, dp(pos + 1));
        // swap
        swap(A[pos], B[pos]);
        if (pos == 0 || !(A[pos - 1] > A[pos] || B[pos - 1] > B[pos])) {
            ret = min(ret, dp(pos + 1) + 1);
        }
        swap(A[pos], B[pos]);
        
        return ret;
    }
    
    int minSwap(vector<int>& first, vector<int>& second) {
        
        memset(memo, -1, sizeof(memo));
        
        n = (int)first.size();
        A = first;
        B = second;
        
        return dp(0);
        
//        return exhaustive(A, B, 0);
    }
};

int main() {
    Solution obj;
    vector<int> first = {1, 3, 5, 7};
    vector<int> second = {1, 2, 3, 4};
    
    cout << obj.minSwap(first, second) << endl;
    
    return 0;
}

