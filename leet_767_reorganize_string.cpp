#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    
    bool check(vector<char> & v) {
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] == v[i + 1]) return false;
        }
        return true;
    }
    
    bool exhaustive(vector<char> & v, int pos) {
        if (pos == v.size()) return check(v);
        if (check(v)) return true;
        
        for (int i = pos + 1; i < v.size(); ++i) {
            if (exhaustive(v, i)) return true; // no change.
            for (int j = i + 1; j < v.size(); ++j) {
                swap(v[i], v[j]);
                if (exhaustive(v, i)) return true;
                swap(v[j], v[i]);
            }
        }
        return false;
    }
    
    string reorganizeString(string S) {
        vector<char> v;
        string ret = "";
        for (auto c : S) v.push_back(c);
        if (exhaustive(v, 0)) {
            for (auto d : v) ret += d;
        }
        return ret;
    }
};

int main() {
    Solution obj;
    cout << obj.reorganizeString("aab") << endl;
    cout << obj.reorganizeString("aaab") << endl;
    cout << obj.reorganizeString("aaabbcccc") << endl;
    
    return 0;
}

