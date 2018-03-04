#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_X = 3, MAX_Y = 3, OFFSET_LEN = 8;

//["OXX",
// "XOX",
// "OXO"]

class Solution {
public:
    
//    int memo[50000][50000]; // 너무 길어서 안됨.
    // memo 는 int memo[50000]; 이어야.
    int memo[50000];
    int L = 0, R = 0;
    
    bool isInBoundary(vector<int> & A, int l, int r) {
        for (int i = l; i < r; ++i)
            if (A[i] > R || A[i] < L) return false;
        return true;
    }
    
    
    int exhaustive1(vector<int> & A, int pos) {
        
        int ret = 0;
        
        for (int i = pos + 1; i < A.size(); ++i) {
            for (int j = i + 1; j <= A.size(); ++j) {
                if (isInBoundary(A, i, j)) ret += 1;
            }
            
            
//            ret += exhaustive(A, i);
        }
        
        return ret;
    }
    
//    int cnt = 0;
    
    int exhaustive2(vector<int> & A, int pos) {
        
        if (A[pos] > R || A[pos] < L) return 0;
        
        int cnt = 0;
        
        
        
        for (int i = pos + 1; i < A.size(); ++i) {
            
            
            cnt += exhaustive2(A, i);
        }
        return cnt;
    }
    
    
    int dp(vector<int> & A, int pos) {
        int & ret = memo[pos];
        if (ret != -1) return ret;
        
        ret = 0;
        
//        for ()
        
        return ret;
    }
    
    
    int numSubarrayBoundedMax(vector<int>& A, int l, int r) {
        // leet 795
        // * 아이디어
        // - L, R 은 전역으로 두고, 어떤 부분 subarray 의 시작과 끝이 idx 로 dp.
        // - 하나씩 늘려갈 때 마다
        L = l, R = r;
        memset(memo, -1, sizeof(memo));
        
        
        return 0;
    }
    
    int numMatchingSubseq(string S, vector<string>& words) {
        // leet 792
        // aho-corasik ?
        // words 정렬, hash화.
        // 매칭되는 캐릭터가 나오면 어디까지 매칭인지 체크.
        // 마지막 캐릭터에 다다르면 끝까지 매칭된 words 의 개수 세어 리턴.
        
        return 0;
    }
    
    int isFinished[MAX_Y][MAX_X][2][4]; // y, x, (x or o), (cnt)
    int offset[OFFSET_LEN][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        // diagonals
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1}
    };
    int checkArr[2]{0,};
    
    bool isXFinished = false, isOFinished = false;
    
    bool finishUtil(vector<string> & board, int x, int y, int ch, int cnt) {
        
        // base case
        int & ret = isFinished[y][x][ch][cnt];
        if (ret != -1) return ret;
        
        // finish case
        if (cnt == 3) {
            if (ch == 0) isOFinished = true;
            else isXFinished = true;
            return ret = true;
        }
        
//        if (board[y][x] == ' ') return false; // no more hope here.
        for (int i = 0; i < OFFSET_LEN; ++i) {
            int nowX = x + offset[i][0];
            int nowY = y + offset[i][1];
            if (nowX >= 0 && nowX < MAX_X && nowY >= 0 && nowY < MAX_Y &&
                board[nowY][nowX] == (ch == 0 ? 'O' : 'X'))
//                if (ret = (int)finishUtil(board, nowX, nowY, ch, cnt + 1)) return ret;
                ret = max(ret, (int)finishUtil(board, nowX, nowY, ch, cnt + 1)); // if there is true, ret will be true.
        }
        return ret;
    }
    
    bool finishCheck(vector<string> & board) {
        memset(isFinished, -1, sizeof(isFinished));
        
        for (int i = 0; i < MAX_X; ++i)
            for (int j = 0; j < MAX_Y; ++j)
                if (board[j][i] == 'X' || board[j][i] == 'O') {
                    int ch = board[j][i] == 'O' ? 0 : 1;
                    ++checkArr[ch];
                    isFinished[j][i][ch][1] = finishUtil(board, i, j, ch, 1);
                }
        
        // 어디에서 끝났다면 valid check.
        if (isOFinished && isXFinished) return false;
        if (!(checkArr[0] == checkArr[1] || checkArr[0] + 1 == checkArr[1])) return false;
        if (isOFinished && (checkArr[0] < checkArr[1])) return false;
        if (isXFinished && (checkArr[0] >= checkArr[1])) return false;
        
        return true;
    }
    
    bool validTicTacToe(vector<string>& board) {
        // leet 794
        // * 조건
        // - valid 가 되려면, 어느것 하나도 먼저 row, col, diag 를 먼저 채우면 안됨.
        // - 항상 x 부터 시작.
        // * 아이디어
        // - finishCheck
        //      일단 끝났는지 체크한다.
        //      만일 x, o 중 하나가 끝났다면 상대도 끝났는지 체크.
        //      둘다 끝나면 invalid.
        // - validCheck
        //      x, o 를 하나씩 지워나가면서 개수를 센다.
        //      num of o == num of x || num of o == num of - 1인지 확인?
        
        // or
        // 모든 valid 한 경우를 precalc.
        
        // * algorithm
        // - 거꾸로 올라간다.
        // - 먼저 x가 3개가 있는지, o 가 3개가 있는지 체크.
        //      - 이 경우는 어떻게 체크해야?
        
        return finishCheck(board);
    }
};

void validTicTacToeDriver() {
    Solution obj;
//    vector<string> map1{"O  ", "   ", "   "};
    vector<string> map2{"XXX", "   ", "OOO"};
    vector<string> map3{"OXX",
                         "XOX",
                         "OXO"};
    
    cout << obj.validTicTacToe(map3) << endl;
}

int main() {
    validTicTacToeDriver();
    
    return 0;
}


