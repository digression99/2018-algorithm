//
// 20180204
// leetcode contest 70
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> len;
    const string EXPAND_0 = "#01";
    const string EXPAND_1 = "#10";
    
    void precalc(int N) {
        for (int i = 2; i <= N; ++i) {
            len[i] = len[i - 1] * 2;
        }
    }
    
    char kth(const string & binary, int n, int skip) {
//        if (n == 1 && skip == 1) return '1';
        if (n == 1) {
//            if (skip > len[n]) return '#';
            return binary[skip];
        }
        
        for (int i = 1; i <= binary.length(); ++i) {
            if (skip > len[n]) skip -= len[n];
            else if (binary[i] == '0')
                return kth(EXPAND_0, n - 1, skip);
            else if (binary[i] == '1')
                return kth(EXPAND_1, n - 1, skip);
            else
                return binary[skip];
        }
        return '#';
    }
    
    char kthGrammar(int N, int K) {
        if (N == 1 && K == 1) return '0';
        // precalc
        len.resize(N + 1);
        len[0] = 1;
        len[1] = 1;
        precalc(N);
        
        return char(kth("#0", N, K));
    }
};

vector<int> input1Vec = {1, 2, 2, 4};
vector<int> input2Vec = {1, 1, 2, 5};
vector<char> resVec = {'0', '0', '1', '1'};

void TEST() {
    Solution obj;
    
    auto resIt = resVec.begin();
    auto input2It = input2Vec.begin();
    auto input1It = input1Vec.begin();
    char res = '#';
    
    while (input1It != input1Vec.end()) {
        res = obj.kthGrammar(*input1It++, *input2It++);
        if (*resIt++ != res) break;
    }
    
    if (input1It != input1Vec.end()) {
        cout << "Error occured in " << input1It - input1Vec.begin() << "th testcase." << endl;
        cout << "Expected : " << --(*resIt) << " Got : " << res << endl;
    } else {
        cout << "TEST finished." << endl;
    }
    
//    for(auto input1It = input1Vec.begin(); input1It != input1Vec.end(); ++input1It) {
//        if (*resIt++ != obj.kthGrammar(*input1It, *input2It++)) {
//            cout << "Error occured in " << input1It - input1Vec.begin() << "th testcase." << endl;
//        }
//    }
    
    
    return;
}

void DRIVER() {
    TEST();
    
    return;
}

int main() {
//    TEST();
    DRIVER();
    
    return 0;
}

