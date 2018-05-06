// leet 830
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ret;
        
        int end = 1, start = 0, l = (int)S.length();
        S.push_back('$');
        
        while (end <= l) {
//            if (start == end) {
//                ++end;
//                continue;
//            } else
            if (S[start] != S[end]) {
                if (end - start >= 3) ret.push_back(vector<int>{start, end - 1});
                start = end;
            }
            ++end;
        }
        
        return ret;
    }
};

int main () {
    Solution obj;
//    vector<vector<int>> ret = obj.largeGroupPositions("abbxxxxzzy");
    vector<vector<int>> ret = obj.largeGroupPositions("aaa");
    
    for (auto dat : ret) {
        cout << dat[0] << " " << dat[1] << endl;
//        for (auto d : dat) cout << (*d)[0] << " " << (*d)[1] << endl;
    }
    
    return 0;
}

