
// leet 806

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1, nowUnit = 0, idx = -1;
        
        for (int i = 0; i < S.length(); ++i) {
            idx = S[i] - 'a';
            if (nowUnit + widths[idx] > 100) {
                ++lines;
                nowUnit = widths[idx];
            } else {
                nowUnit += widths[idx];
            }
        }
        
        return vector<int>{lines, nowUnit};
    }
};

int main() {
    Solution obj;
    vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S = "abcdefghijklmnopqrstuvwxyz";
    vector<int> widths2 = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S2 = "bbbcccdddaaa";
    
    
    vector<int> res = obj.numberOfLines(widths, S);
    
    for (auto dat : res) cout << dat << endl;
    
    vector<int> res2 = obj.numberOfLines(widths2, S2);
    
    for (auto dat : res2) cout << dat << endl;
    
    return 0;
}



