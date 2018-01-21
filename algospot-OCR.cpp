//
// algospot OCR
//

/*
 
 문제 푸는 시간
 얘기하는 시간
 답보는 시간
 코드짜는 시간
 제출하고 디버깅하는 시간
 
 --> 그냥 아예 제출까지 해서 디버깅하고 얘기하기.
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXM = 500 + 1;
const int MAXN = 100 + 1;
const int NEGINF = -99999;
int m, q, n;

string words[MAXM + 1];
double B[MAXM + 1];
double T[MAXM + 1][MAXM + 1];
double M[MAXM + 1][MAXM + 1];

string inputWords[MAXN+ 1];
int sw[MAXM + 1]; // sentence words to index

int memo[MAXN + 1][MAXN + 1];

void inputWordsToIdx() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (words[j] == inputWords[i]) {
                sw[i] = j;
                break;
            }
        }
    }
}

int dp(int pos, int bw) {
    if (pos == n + 1) return 0;
    int & ret = memo[pos][bw];
    
    if (ret != 1) return ret; // intialize to 1
    ret = NEGINF;
    
    int prob = NEGINF;
    
    for (int i = 0; i < m; ++i) {
        prob = M[sw[pos]][i];
        
        if (pos == 0) prob += B[i];
        else prob += T[bw][i];
        
        ret = max(ret, prob + dp(pos + 1, i));
    }
    
    return ret;
}


int main() {
    cin >> m >> q;
    for (int i = 0; i < m; ++i)
        cin >> words[i];
    for (int i = 0; i < m; ++i)
        cin >> B[i];
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> T[i][j];
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> M[i][j];
    
    for (int i = 0; i < q; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> inputWords[j];
        }
        
        // inputWords to sw.
        
        // solve.
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

