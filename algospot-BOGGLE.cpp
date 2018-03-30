// algospot BOGGLE

// testcase
//4
//URLPM
//XPRET
//GIAET
//XTNZY
//XOQRS
//10
//PRETTY
//GIRL
//REPEAT
//KARA
//PANDORA
//GIAZAPX
//REPEAT
//KARA
//PANDORA
//URLPMPMPMM
//NNNNS
//NEEEN
//NEYEN
//NEEEN
//NNNNN
//4
//YESR
//SNNNNNNN
//EEEEEEEEE
//NEYN
//NNNNN
//NEEEN
//NEYEN
//NEEEN
//NSNNN
//1
//YES
//AAAAA
//AAAAA
//AAAAA
//AAAAA
//AAAAB
//4
//ABABABABAA
//AAAAAAAAAB
//ABABABABBA
//BAAAAAAABA

// result
//PRETTY YES
//GIRL YES
//REPEAT YES
//KARA NO
//PANDORA NO
//GIAZAPX YES
//REPEAT YES
//KARA NO
//PANDORA NO
//URLPMPMPMM NO
//YESR NO
//SNNNNNNN YES
//EEEEEEEEE YES
//NEYN NO
//YES YES
//ABABABABAA YES
//AAAAAAAAAB YES
//ABABABABBA NO
//BAAAAAAABA YES

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char map[5][5];
int memo[5][5][10];

int n;
string str;
vector<vector<int>> offset = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

int dp(int x, int y, int pos) {
    
    // base case.
    if (pos == str.length()) return 0;
    int & ret = memo[y][x][pos];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 0; i < 8; ++i) {
        int newx = x + offset[i][0], newy = y + offset[i][1];
        if (map[y][x] == str[pos] && (newx >= 0 && newx < 5) && (newy >= 0 && newy < 5))
            ret = max(ret, dp(newx, newy, pos + 1) + 1);
    }
    
    return ret;
}

bool solve() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int res = dp(j, i, 0);
//            cout << "res : " << res << endl;
            if (res == str.length()) return true;
        }
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {

        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                cin >> map[j][k];
        
        cin >> n;
        
        for (int j = 0; j < n; ++j) {
            
            memset(memo, -1, sizeof(memo));
            
            cin >> str;
            
            string output = "";
            
            if (solve()) output = "YES";
            else output = "NO";
            cout << str << " " << output << endl;
        }
    }
    
    return 0;
}

