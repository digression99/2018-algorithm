// leet 821

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ret;
        vector<int> epos;
        
        for (int i = 0; i < S.length(); ++i) if (S[i] == C) epos.push_back(i);
        
        int first = -1, next = epos[0], eposIdx = 0;
        int pos = 0;
        int mid = (first + next + 1) / 2;
        
        while (pos < S.length()) {
            if (pos == next) {
                eposIdx += 1;
                first = epos[eposIdx - 1];
                if (eposIdx >= epos.size()) {
                    next = S.length();
                } else {
                    next = epos[eposIdx];
                }
                
                mid = (first + next + 1) / 2;
            }
            if (first != -1 && mid - pos > 0) {
                // if still far, increase the offset.
                ret.push_back(pos - first);
            } else {
                // if it's closing, decrease the offset.
                if (next != S.length()) ret.push_back(next - pos);
                else ret.push_back(abs(pos - first));
            }
            ++pos;
        }
        return ret;
    }
};

int main () {
    Solution obj;
    
//    vector<int> res = obj.shortestToChar("loveleetcode", 'e');
    vector<int> res = obj.shortestToChar("abaa", 'b');
    
    
    return 0;
}

