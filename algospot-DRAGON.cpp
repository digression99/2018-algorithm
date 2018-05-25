// algospot DRAGON

// test case
//4
//0 1 2
//1 1 5
//2 6 5
//42 764853475 30

// results
//FX
//FX+YF
//+FX-Y
//FX-YF-FX+YF+FX-YF-FX+YF-FX-YF-

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string generate(const string & str, int n) {
    
    if (n == 0) return str;
    
    string generated = "";
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'F' || str[i] == '+' || str[i] == '-') {
            generated += str[i];
            continue;
        }
        else if (str[i] == 'X') {
            generated += generate("X+YF", n - 1);
        } else if (str[i] == 'Y') {
            generated += generate("FX-Y", n - 1);
        }
    }
    
    return generated;
}

const int MAXN = 50;
const int MAX = 1000000000;
int memo[MAXN + 1];
int dragonLength[MAXN + 1];

int getLength(const string & str, int n) {
    if (n == 0) return (int)str.length();
    
    int & ret = memo[n];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'X') {
            ret += getLength("X+YF", n - 1);
        } else if (str[i] == 'Y') {
            ret += getLength("FX-Y", n - 1);
        } else ++ret;
        ret = min(MAX, ret);
    }
    
    return ret;
}

char kth(const string & str, int skip, int n) {
    
    if (n == 0) return str[skip - 1];
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'X' || str[i] == 'Y') {
            if (skip <= dragonLength[n]) {
                string dragon = str[i] == 'X' ? "X+YF" : "FX-Y";
                return kth(dragon, skip, n - 1);
            } else
                skip -= dragonLength[n];
        } else {
            --skip;
        }
        
        if (skip == 0) return str[i];
    }
    
    return '#';
}

void driver() {
    
    // init.
    memset(dragonLength, -1, sizeof(dragonLength));
    memset(memo, -1, sizeof(memo));
    
    dragonLength[0] = 2;
    
    for (int i = 0; i <= 50; ++i) {
        memset(memo, -1, sizeof(memo));
        dragonLength[i] = getLength("FX", i) - 1;
    }
    
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int n, p, l;
        cin >> n >> p >> l;
        
        for (int i = p; i < p + l; ++i) {
            cout << kth("FX", i, n);
        }
        cout << endl;
    }
}

int main() {
    
    driver();
    return 0;
}




















