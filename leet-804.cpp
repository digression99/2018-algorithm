
// leet 804

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string toMorse(const string & str) {
        string res = "";
        for (int i = 0; i < str.length(); ++i) {
            int idx = str[i] - 'a';
            res += morse[idx];
        }
        
        return res;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, int> hash;
        
        for (int i = 0; i < words.size(); ++i) {
            string morsed = toMorse(words[i]);
            hash[morsed]++;
        }
        
        return (int)hash.size();
    }
};

int main() {
    Solution obj;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << obj.uniqueMorseRepresentations(words) << endl;
    
    return 0;
}



