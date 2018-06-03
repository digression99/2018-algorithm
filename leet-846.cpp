// leet 846

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
//        unordered_map<int, int> hash;
//        vector<pair<int, int>> hash;
        
        if (hand.size() % W) return false;
        map<int, int> hash;
        
        sort(hand.begin(), hand.end());
        
        for (int i = 0; i < hand.size(); ++i) {
            
//            if (hash.find(hand[i]) == hash.end()) hash[hand[i]] = 0;
            
            hash[hand[i]]++;
        }
//        sort(hash.begin(), hash.end());
        
        for (auto dat : hash) {
            cout << dat.first << " " << dat.second << endl;
        }
        
        while (hash.size() >= W) {
            int iterate = W;
            auto it = hash.begin();
            int before = -1;
            while (iterate > 0 && it != hash.end()) {
                int nowVal = it->first;
                
                if (before == -1 || abs(before - nowVal) == 1) {
                    if (it->second == 1) {
                        hash.erase(it++);
                    } else {
                        --it->second;
                        ++it;
                    }
                    --iterate;
                    before = nowVal;
                } else return false;
            }
        }
        
        cout << "remaining" << endl;
        
        for (auto dat : hash) {
            cout << dat.first << " " << dat.second << endl;
        }
        if (hash.size() >= 1) return false;
        return true;
    }
};

void driver() {
    
    
}

void tester() {
    Solution obj;
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    vector<int> hand2 = {5, 1};
    
    cout << obj.isNStraightHand(hand, 3) << endl;
//    cout << obj.is
}

int main() {
    tester();
    return 0;
}

