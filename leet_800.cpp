#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> table;
    unordered_map<char, int> hexVal = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'a', 10},
        {'b', 11},
        {'c', 12},
        {'d', 13},
        {'e', 14},
        {'f', 15}
    };
    
    string toStringHex(int n) {
        int first = n / 16;
        char firstChar = 0;
        if (first > 9) firstChar = 'a' + (first - 10);
        else firstChar = '0' + first;
        return string(2, firstChar);
    }
    
    int bs(int start, int end, int n) {
        int mid = (start + end) / 2;
        
        if (start < end) {
            // if you find the exact value, return it.
            if (table[mid] == n) return mid;
            else if (table[mid] < n) return bs(mid + 1, end, n);
            else if (table[mid] > n) return bs(start, mid, n);
        }
        
        int leftVal = start > 0 ? abs(n - table[start - 1]) : n;
        int rightVal = end <= table.size() - 1 ? abs(n - table[end]) : n;
        
        int closest = start - 1;
        if (rightVal < leftVal) closest = end;
//        if (abs(rightVal - n) < abs(leftVal - n)) closest = end;
        return closest;
    }
    
    string similarRGB(string color) {
        string ret = "#";
        vector<int> candidates;
        // make table.
        table.resize(16, 0);
        for (int i = 0; i < 16; ++i) {
            table[i] = 16 * i + i;
        }
        
        candidates.resize(3, 0);
        for (int i = 1; i < 7; i += 2) {
            string hex = color.substr(i, 2);
            int target = 16 * hexVal[hex[0]] + hexVal[hex[1]];
            int idx = bs(0, 15, target);
            ret += toStringHex(table[idx]);
        }
        
        return ret;
    }
};

int main() {
    Solution obj;
    
//    cout << obj.similarRGB("#09f166") << endl;
    cout << obj.similarRGB("#22f966") << endl;
    
    return 0;
}






















