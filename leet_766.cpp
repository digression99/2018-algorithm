#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int M, N;
    vector<vector<int>> * mat;
    
    bool checkDiagonal(int x, int y, int n) {
        if (x >= N || y >= M) return true;
        if ((*mat)[y][x] == n) {
            return checkDiagonal(x + 1, y + 1, n);
        }
        return false;
    }
    
    bool rightRecursive(int x, int y) {
        if (x == N) return true;
        int i = x + 1, j = y + 1;
        while (i < N && j < M) {
            if ((*mat)[y][x] != (*mat)[j][i]) {
                return false;
            }
            ++i, ++j;
        }
        return rightRecursive(x + 1, y);
    }
    
    bool bottomRecursive(int x, int y) {
        if (y == M) return true;
        int i = x + 1, j = y + 1;
        while (i < N && j < M) {
            if ((*mat)[y][x] != (*mat)[j][i]) {
                return false;
            }
            ++i, ++j;
        }
        return bottomRecursive(x, y + 1);
    }
    

    bool recursive(int x, int y) {
        int i = x + 1, j = y + 1;
        while (i < N && j < M) {
            if ((*mat)[y][x] != (*mat)[j][i]) {
                return false;
                break;
            }
            ++i, ++j;
        }
        return rightRecursive(x + 1, y) && bottomRecursive(x, y + 1);
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        M = (int)matrix.size();
        N = (int)matrix[0].size();
        mat = &matrix;
        return recursive(0, 0);
    }
};



int main() {
    vector<vector<int>> matrix{{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    vector<vector<int>> matrix2{{41,12,77,99,16,6,79,89,1,78,8,46,83,38,38,64,17,66,11},
        {42,41,12,77,99,16,6,79,89,1,78,8,46,83,38,38,64,17,66},
        {73,42,41,12,77,99,16,6,79,89,1,78,8,46,83,38,38,64,17},{43,73,42,41,12,77,99,16,6,79,89,1,78,8,46,83,38,38,64},
        {45,43,73,42,41,12,77,99,16,6,79,89,1,78,8,46,83,38,38},{38,45,43,73,42,41,12,77,99,16,6,79,89,1,78,8,46,83,38},
            {4,38,45,43,73,42,41,12,77,99,16,6,79,89,1,78,8,46,83}
            ,{27,4,38,45,43,73,42,41,12,77,99,16,6,79,89,1,78,8,46},
                {74,27,4,38,45,43,73,42,41,12,77,99,16,6,79,89,1,78,8},
                {81,74,27,4,38,45,43,73,42,41,12,77,99,16,6,79,89,1,78}};
    Solution obj = Solution();
    cout << obj.isToeplitzMatrix(matrix2);
    
    

    
    return 0;
}


