#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> block[4];
int h, w, r, c;
int best = -1;

const int BLOCK_FIGURE = 4;

bool blockCheck(int x, int y, int blockNum) {
    return false;
}

void makeMap(int x, int y, int blockNum) {
    return;
}

void returnMap(int x, int y, int blockNum) {
    return;
}

int search(int x, int y, int res) {
    
    
    if (x > w) {
        if (y > h) return best = max(best, res);
        return search(0, y + 1, res);
    }
    
    // if there's a wall.
    if (map[y][x]) return search(x + 1, y, res);
    
    for (int i = 0; i < BLOCK_FIGURE; ++i) {
        if (blockCheck(x, y, i)) {
            // if block can fit into the pos.
            makeMap(x, y, i);
            search(x + 1, y, res + 1);
            returnMap(x, y, i);
        }
    }
    return res;
}

int main() {
    int tc;
    char ch;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> h >> w >> r >> c;
        map = vector<vector<int>>(h, vector<int>(w));
        block[0] = vector<vector<int>>(r, vector<int>(c));
        block[1] = vector<vector<int>>(c, vector<int>(r));
        block[2] = vector<vector<int>>(r, vector<int>(c));
        block[3] = vector<vector<int>>(c, vector<int>(r));
        
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                cin >> ch;
                map[j][k] = ch == '#' ? 1 : 0;
            }
        }
        
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < c; ++k) {
                cin >> ch;
                int dat = ch == '#' ? 1 : 0;
                
                block[0][j][k]
                = block[2][r - j - 1][c - k - 1]
                = block[1][k][r - j - 1]
                = block[3][c - k - 1][j] = dat;
            }
        }
        search(0, 0, 0);
        cout << best << endl;
        best = 0;
    }
    
    return 0;
}

