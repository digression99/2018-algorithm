
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = (int)dominoes.length();
        bool isChanged = true;
        vector<int> domino(N, 0);
        
        for (int i = 0; i < N; ++i) {
            if (dominoes[i] == 'L') domino[i] = -1;
            else if (dominoes[i] == 'R') domino[i] = 1;
        }
        
        while (isChanged) {
            isChanged = false;
            vector<int> changed(domino);
            
            for (int i = 0; i < N; ++i) {
                if (domino[i] == -1) { // L
                    if (i - 1 >= 0 &&
                        domino[i - 1] <= 0 &&
                        (i - 2 < 0 || domino[i - 2] <= 0)) {
                        changed[i - 1] = -1;
                        isChanged = true;
                    }
                } else if (domino[i] == 1) {// R
                    if (i + 1 < N &&
                        domino[i + 1] >= 0 &&
                        (i + 2 >= N ||
                         domino[i + 2] >= 0)) {
                            changed[i + 1] = 1;
                            isChanged = true;
                        }
                } // don't care .
            }
            domino.assign(changed.begin(), changed.end());
        }
        
        string ret = string(N, '.');
        for (int i = 0; i < N; ++i) {
            if (domino[i] == 1) ret[i] = 'R'; // is this possible?
            else if (domino[i] == -1) ret[i] = 'L';
        }
        return ret;
    }
};

int main() {
    Solution obj;
    cout << obj.pushDominoes(".L.R...LR..L..") << endl;
    
    return 0;
}

