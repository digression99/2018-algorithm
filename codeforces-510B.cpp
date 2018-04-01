
// codeforces 510B
// test case
//3 4
//AAAA
//ABCA
//AAAA
//3 4
//AAAA
//ABCA
//AADA
//2 13
//ABCDEFGHIJKLM
//NOPQRSTUVWXYZ
//4 4
//YYYR
//BYBY
//BBBY
//BBBY


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <map>
#include <cstring>
using namespace std;

int n, m;
int initx, inity;
int offset[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

char board[50 + 1][50 + 1];
int visited[50 + 1][50 + 1];
int memo[50 + 1][50 + 1][50 + 1];

bool isRange(int x, int y) {
    if ((x >= 0 && x < m) && (y >= 0 && y < n)) return true;
    return false;
}

bool search(int x, int y, int cnt) {
    // base case.
//    if (board[y][x] != board[inity][initx]) return false;
    
    
    // end case.
    if (cnt >= 4 && (x == initx && y == inity)) return true;
    
    for (int i = 0; i < 4; ++i) {
        int newx = x + offset[i][0], newy = y + offset[i][1];
        
        if (isRange(newx, newy) && (visited[newy][newx] == 0) && (board[inity][initx] == board[newy][newx])) {
            visited[newy][newx] = 1;
            if (search(newx, newy, cnt + 1)) return true;
            visited[newy][newx] = 0;
        }
    }
    return false;
}

bool dfs(int x, int y, int cnt) {
    
    if (board[y][x] != board[inity][initx]) return false;
    
//    if (cnt >= 4 && (x == initx && y == inity)) {
////        visited[y][x] = 0;
//        return true;
//    }
    
    for (int i = 0; i < 4; ++i) {
        int newx = x + offset[i][0], newy = y + offset[i][1];
        
        if (isRange(newx, newy) && board[newy][newx] == board[inity][initx]) {
            if ((newx != initx || newy != inity) && visited[newy][newx] == 0) {
                visited[newy][newx] = 1;
                if (dfs(newx, newy, cnt + 1)) return true;
                visited[newy][newx] = 0;
            } else if (newx == initx && newy == inity && cnt >= 4) return true;
        }
        
//        if (visited[newy][newx] == 0 && board[newy][newx] == board[inity][initx]) {
//            visited[newy][newx] = 1;
//            bool res = dfs(newx, newy, cnt + 1);
//            if (res) {
//                //                visited[y][x] = 0;
//                return true;
//            }
//            visited[newy][newx] = 0;
//        } else if (newx == initx && newy == inity && board[newy][newx] == board[inity][initx]) return true;
    }
    
//    visited[y][x] = 0;
    return false;
}

int dp(int x, int y, int cnt) {
    // base case check.
    if (cnt >= 4 && (x == initx && y == inity)) return 1;
    
    // memo check.
    int & ret = memo[y][x][cnt];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 0; i < 4; ++i) {
        int newx = x + offset[i][0], newy = y + offset[i][1];
        if (!visited[newy][newx] && isRange(newx, newy) && (board[inity][initx] == board[newy][newx])) {
            visited[newy][newx] = 1;
            ret = dp(newx, newy, cnt + 1);
            if (ret == 1) return ret;
            visited[newy][newx] = 0;
        }
    }
    return ret;
}

bool solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = 1;
            initx = j, inity = i;
            if(dfs(j, i, 1)) return true;
            visited[i][j] = 0;
//            visited[i][j] = 0;
//            if (dp(i, j, 0) == 1) return true;
//            if (search(i, j, 1)) return true;
        }
    }
    
    return false;
}

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    memset(memo, -1, sizeof(memo));
    memset(visited, 0, sizeof(visited));
    
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

