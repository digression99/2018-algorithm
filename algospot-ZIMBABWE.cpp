// algospot ZIMBABWE

// test case
//4
//321 3
//123 3
//422 2
//12738173912 7

// result
//5
//0
//2
//11033

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int MAXLEN = 15;
const int MOD = 1000000007;
int N, E;
long num;
string numStr;
int memo[1 << MAXLEN];
unordered_map<long, bool> valMemo;


int dp(int pos, long val, int visited) {
    // base case.
    if (visited == (1 << N) - 1) {
        bool isMod = !(val % E);
        if (val < num && isMod && !valMemo[val]) {
            valMemo[val] = true;
            return 1;
        }
        return 0;
    }
    int & ret = memo[visited];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 0; i < N; ++i) {
        bool isVisited = visited & (1 << i);
        
        if (!isVisited) {
            int checkNum = (numStr[i] - '0') * pow(10, N - pos - 1);
            val += checkNum;
            if (val < num) {
                visited += (1 << i);
                ret += dp(pos + 1, val, visited);
                ret %= MOD;
                visited -= (1 << i);
            }
            val -= checkNum;
        }
    }
    return ret %= MOD;
}

int exhaustive(int pos, long val, int visited) {
    // base case.
    if (visited == (1 << N) - 1) {
        bool isMod = !(val % E);
        if (val < num && isMod) return 1;
        return 0;
    }
    
    int ret = 0;
    
    for (int i = 0; i < N; ++i) {
        bool isVisited = visited & (1 << i);
        //        if (!(visited & 1 << i) && nowPosNum >= checkNum) {
        
        if (!isVisited) {
            int checkNum = (numStr[i] - '0') * pow(10, N - pos - 1);
            val += checkNum;
            if (val < num) {
//                int mask = !(1 << i);
                visited += (1 << i);
                ret += exhaustive(pos + 1, val, visited);
                visited -= (1 << i);
            }
            val -= checkNum;
        }
//        if (!isVisited && val + checkNum * pow(10, N - pos - 1) < num) {
//            // if not checked.
//            val += checkNum * pow(10, N - (pos + 1));
//            visited |= 1 << i;
//
//            ret += exhaustive(pos + 1, val, visited);
//
//            val -= checkNum * pow(10, N - (pos + 1));
//            visited &= 0 << i;
//        }
    }
    
    return ret;
}

// not mine.
string e, digits;
int n, m;
int cache[1 << 14][20][2];

int price(int index, int taken, int mod, int less) {
    if (index == n) {
        return (less && mod == 0) ? 1 : 0;
    }
    
    int & ret = cache[taken][mod][less];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int next = 0; next < n; ++next) {
        if ((taken & (1 << next)) == 0) {
            //if the price is higher than the original one.
            if (!less && e[index] < digits[next]) continue;
            
            // should choose same digits once.
            if (next > 0 && digits[next - 1] == digits[next] &&
                (taken & (1 << (next - 1))) == 0) continue;
            
            int nextTaken = taken | (1 << next);
            int nextMod = (mod * 10 + digits[next] - '0') % m;
            int nextLess = less || e[index] > digits[next];
            
            ret += price(index + 1, nextTaken, nextMod, nextLess);
            ret %= MOD;
        }
    }
    return ret;
}


void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
//        memset(memo, -1, sizeof(memo));
        
//        cin >> num >> E;
//        numStr = to_string(num);
//        N = (int)numStr.length();
//        cout << exhaustive(0, 0, 0) << endl;
//        cout << dp(0, 0, 0) << endl;
        
        memset(cache, -1, sizeof(cache));
        cin >> e >> m;
        n = (int)e.length();
        digits = e;
        sort(digits.begin(), digits.end());
        cout << price(0, 0, 0, 0) << endl;
    }
}

void test() {
    long num = 123123;
    string strNum = to_string(num);
    
    cout << num << endl;
    cout << strNum << endl;
    cout << strNum[0] << endl;
    cout << strNum[1] << endl;

}

int main() {
//    test();
    driver();
    return 0;
}

