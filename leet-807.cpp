
// leet 807

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> row, col;
    
    void makeSkyline(vector<vector<int>> & grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ret = 0;
        row.resize(grid.size(), -1);
        col.resize(grid[0].size(), -1);
        
        makeSkyline(grid);
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                ret += min(row[i], col[j]) - grid[i][j];
            }
        }
        
        return ret;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0} };
    
    cout << obj.maxIncreaseKeepingSkyline(grid) << endl;
    
    return 0;
}



