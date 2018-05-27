// leet 840

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> offsets = {
        {0, 1}, {1, 1}, {2, 1},
        {0, 2}, {1, 2}, {2, 2},
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2},
        {0, 0}, {1, 1}, {2, 2},
        {0, 2}, {1, 1}, {2, 0}
    };
    
    bool gridCheck(vector<vector<int>> & grid, int row, int col) {
        
        // sum check.
        int initSum = grid[col][row] + grid[col][row + 1] + grid[col][row + 2];
        for (int i = 0; i < offsets.size(); i += 3) {
            int s = 0;
            for (int j = 0; j < 3; ++j) {
                int nowX = row + offsets[i + j][1];
                int nowY = col + offsets[i + j][0];
                s += grid[nowY][nowX];
            }
            if (initSum != s) return false;
        }
        
        // number check.
        bool check[10] = { false, };
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int nowNum = grid[col + i][row + j];
                if (nowNum >= 1 && nowNum <= 9) check[nowNum] = true;
            }
        }
        for (int i = 1; i <= 9; ++i) {
            if (!check[i]) return false;
        }
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int N = (int)grid.size(), M = (int)grid[0].size();
        int ret = 0;
        
        for (int i = 0; i < N - 2; ++i) {
            for (int j = 0; j < M - 2; ++j) {
                if (gridCheck(grid, j, i)) ++ret;
            }
        }
        return ret;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> testcase1 = {
        {4,3,8,4},
        {9,5,1,9},
        {2,7,6,2}
    };
    
    obj.numMagicSquaresInside(testcase1);
    
    return 0;
}

