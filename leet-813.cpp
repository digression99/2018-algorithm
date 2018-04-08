// leet 813

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    
    static const int MAX_N = 10000 + 1;
    static const int MAX_K = 100 + 1;
    vector<int> A;
    vector<int> partSum;
    vector<vector<double>> memo;
    
    int N, K;
    
    void calcPartSum() {
        partSum[0] = 0;
        for (int i = 1; i <= N; ++i) partSum[i] = partSum[i - 1] + A[i - 1];
    }
    
    double getPartSum(int start, int end) {
        if (end - start == 1) return A[start];
        return partSum[end] - partSum[start];
    }
    
    double dp(int pos, int cnt) {
        if (pos == N) return 0;
        if (cnt == K - 1) {
            if (N - pos != 0) return getPartSum(pos, N) / (N - pos);
        }
        double & ret = memo[pos][cnt];
        if (ret != -1) return ret;
        
        for (int i = pos; i < N; ++i) {
            double average = getPartSum(pos, i + 1) / (i - pos + 1);
            double res = average + dp(i + 1, cnt + 1);
            if (res > ret ) ret = res;
        }
        return ret;
    }
    
    
    double largestSumOfAverages(vector<int>& A, int K) {
        this->A = A;
        this->K = K;
        this->N = A.size();
        partSum.resize(N + 1, 0);
        calcPartSum();
        memo.resize(N + 1, vector<double>(K + 1, -1));
//        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};

int main() {
    Solution obj;
    vector<int> A = {9, 1, 2, 3, 9};
    int K = 3;
    vector<int> A2 = {4,1,7,5,6,2,3};
    int K2 = 4;
    
//    cout << obj.largestSumOfAverages(A, K) << endl;
    cout << obj.largestSumOfAverages(A2, K2) << endl;
    
    return 0;
}

