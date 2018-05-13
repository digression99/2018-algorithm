// leet 832

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        int l = A.size();
        
        for (int i = 0; i < l; ++i) {
            int start = 0, end = l - 1;
            while (start <= end) {
                swap(A[i][start], A[i][end]);
                A[i][start] = !A[i][start];
                if (start == end) break;
                A[i][end] = !A[i][end];
                ++start; --end;
            }
        }
        
        return A;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> A = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    };
    
    vector<vector<int>> res = obj.flipAndInvertImage(A);
    
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res.size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

