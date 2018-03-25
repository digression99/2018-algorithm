// leet 805

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//// not mine
//class Solution {
//public:
//    bool splitArraySameAverage(vector<int>& A) {
//        int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
//        for (int i = 1; i <= m; ++i)
//            if (totalSum*i%n == 0 && totalSum*(n-i)%n == 0 && combinationSum(A, 0, i, totalSum*i/n)) return true;
//        return false;
//    }
//    bool combinationSum(vector<int>& nums, int idx, int k, int tar) {
//        if (k == 0) return tar == 0;
//        for (int i = idx; i <= nums.size()-k; ++i)
//            if (nums[i] <= tar && combinationSum(nums, i+1, k-1, tar-nums[i])) return true;
//        return false;
//    }
//};

class Solution {
public:
    unordered_map<int, vector<int>> memo;
    int n;
    vector<int> input;
    
    bool isSameAverage(int bitset) {
        int bCnt = 0, cCnt = 0, bSum = 0, cSum = 0;
        for (int i = 0; i < n; ++i) {
            int check = 1 << i;
            
            if ((bitset & check) > 0) {
                // if it's B
                bSum += input[i];
                ++bCnt;
            } else {
                cSum += input[i];
                ++cCnt;
            }
        }
        
        if (cCnt == 0 || bCnt == 0) return bSum == 0 && cSum == 0;
        
        return ((double)bSum / bCnt) == ((double)cSum / cCnt);
    }
    
    bool dp(int bitset, int pos) {
        auto ret = memo.find(bitset);
        if (ret != memo.end() && pos < n && ret->second[pos] != -1) {
            return ret->second[pos];
        }
        
        if (ret == memo.end()) {
            memo[bitset] = vector<int>(n, -1);
            ret = memo.find(bitset);
        }
        if (pos == n) {
            return ret->second[pos - 1] = isSameAverage(bitset);
        }
        
        int mask = 1 << pos;
        
        return ret->second[pos] = dp(bitset, pos + 1) || dp(bitset | mask, pos + 1);
    }

    bool splitArraySameAverage(vector<int>& A) {
        n = (int)A.size();
        input = A;
        return dp(0, 0);
    }
};

int main() {

    Solution obj;
//    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> A2 = {33,86,88,78,21,76,19,20,88,76,10,25,37,97,58,89,65,59,98,57,50,30,58,5,61,72,23,6};
//
////    cout << obj.splitArraySameAverage(A) << endl;
    cout << obj.splitArraySameAverage(A2) << endl;
    
    
    return 0;
}



