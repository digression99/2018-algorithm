// leet 833

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    
    void sortData(vector<int> & indexes, vector<string> & sources, vector<string> & targets) {
        
        for (int i = 0; i < indexes.size(); ++i) {
            for (int j = 0; j < indexes.size(); ++j) {
                if (indexes[i] < indexes[j]) {
                    swap(indexes[i], indexes[j]);
                    swap(sources[i], sources[j]);
                    swap(targets[i], targets[j]);
                }
            }
        }
    }
    
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        sortData(indexes, sources, targets);
        
        string ret = "";
        int l = (int)indexes.size();
        int orgLen = S.length();
        int prev = 0;
        
        for (int i = 0; i < l; ++i) {
            int nowIdx = indexes[i];
            
            // add org str that is not substituted.
            ret += S.substr(prev, nowIdx - prev);
            prev = nowIdx;
            
            // check match.
            int offset = 0;
            int strLen = (int)sources[i].length();
            while (offset < strLen && sources[i][offset] == S[nowIdx]) {
                ++offset; ++nowIdx;
            }
            
            // substitute.
            if (offset == strLen) {
                // matched.
                ret += targets[i];
                prev += strLen;
            }
        }
        if (prev < orgLen) ret += S.substr(prev, orgLen - prev);
        return ret;
    }
};

int main() {
    
    Solution obj;
    
    string org = "abcd";
    vector<int> indexes = {0, 2};
    vector<string> sources = {"a", "cd"};
    vector<string> targets = {"eee", "ffff"};
    
    cout << obj.findReplaceString(org, indexes, sources, targets) << endl;
    
    return 0;
}

