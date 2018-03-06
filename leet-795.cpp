//
// leet 795
//

//We are given an array A of positive integers, and two positive integers L and R (L <= R).
//
//Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.
//
//Example :
//Input:
//A = [2, 1, 4, 3]
//L = 2
//R = 3
//Output: 3
//Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
//Note:
//
//L, R  and A[i] will be an integer in the range [0, 10^9].
//The length of A will be in the range of [1, 50000].

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    
    int L, R;
    // 2 1 4 3 2
    // greedy solution
    int greedy(vector<int> & A) {
        int cnt = 0;
        int start = -1, end = -1;
        int mx = -1;
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R || A[i] < L) {
                start = end = i;
                continue;
            }
            mx = max(mx, A[i]);
            if (mx != A[i])
            
            end = i;
            cnt += end - start;
        }
        
        return cnt;
    }
    
    
    int numSubarrayBoundedMax(vector<int>& A, int l, int r) {
//        int L, R;
        
        L = l, R = r;
        
        return greedy(A);
    }
};

int main() {
    Solution obj;
    
    vector<int> v1 = {2, 1, 4, 3};
    cout << obj.numSubarrayBoundedMax(v1, 2, 3) << endl;
    
    
    
    return 0;
}

