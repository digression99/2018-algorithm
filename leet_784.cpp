
/*
 
 leetcode 784
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string toOpposite(char c) {
        if (c >= 'a') return string(1, c - ('a' - 'A'));
        return string(1, c + ('a' - 'A'));
    }
    
    vector<string> exhaustive(string & str, int pos) {
        if (pos == str.length()) return vector<string>{""};
        
        vector<string> ret;
        vector<string> arr = exhaustive(str, pos + 1);
    
        for (auto dat : arr) {
            ret.push_back(str[pos] + dat);
            if (!isdigit(str[pos])) ret.push_back(toOpposite(str[pos]) + dat);
        }
        
        return ret;
    }
    
    vector<string> letterCasePermutation(string S) {
        return exhaustive(S, 0);
    }
};

int main () {
//    string ch = "c";
//
//    ch.replace(0, 1, string(1, 'd'));
//
//    cout << ch.c_str()[0] << endl;
//
//    cout << ch + 'd' << endl;
//
//    cout << isdigit('c') << endl;
    
//    Solution obj;
    
    string testcase1 = "a1b2";
    
    testcase1[0] ^= (1 << 5);
    
    cout << testcase1 << endl;
    
    int a = 1;
    a ^= 1;
    
    cout << a << endl;
    
//    vector<string> res = obj.letterCasePermutation(testcase1);
//
//    for (auto str : res) cout << str << endl;
    
    return 0;
}

