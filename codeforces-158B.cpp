
// codeforces 158B
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <map>
using namespace std;

int n;
vector<int> nums;

//int solve(int n, vector<int> & nums) {
//
//    int remain = 4, ret = 0;
//
//    sort(nums.begin(), nums.end(), greater<int>());
//
//    for (int i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
//
//    int i = 0;
//
//    while (i < n) {
//        if (remain - nums[i] > 0) {
//            remain -= nums[i];
//            ++i;
//        }
//        else {
//            remain = 4;
////            remain = 4 - nums[i];
//            ++ret;
////            ++i;
//        }
//        ++i;
//    }
//
////    for (int i = 0; i < n; ++i) {
////        if (remain - nums[i] > 0) remain -= nums[i];
////        else {
////            remain = 4;
////            ++ret;
////        }
////    }
//    return ret;
//}

int solve() {
    map<int, int, greater<int>> hash;
    int ret = 0;
    
    for (int i = 0; i < n; ++i) {
        hash[nums[i]]++;
    }
    
    for (auto dat : hash) {
        if (dat.first == 4) ret += dat.second;
        else if (dat.first == 3) {
            if (hash[1] > 0) {
                int mn = min(hash[3], hash[1]);
                ret += mn;
                hash[3] -= mn;
                hash[1] -= mn;
            }
            
            // if still remains, add it.
            if (hash[3] > 0) ret += hash[3];
        }
        else if (dat.first == 2) {
            int div = dat.second / 2;
            
            ret += div;
            dat.second %= 2;
            
            if (dat.second > 0 && hash[1] >= 2) {
                ret += 1;
                hash[1] -= 2;
            }
        } else if (dat.first == 1) {
            ret += floor(hash[1] / 4);
            hash[1] %= 4;
            if (hash[1] > 0) {
                if (hash[2] > 0 && hash[1] >= 2) {
                    ret += 1;
                    hash[2] -= 1;
                    hash[1] -= 2;
                }
                ret += 1;
            }
        }
    }
    
    return ret;
}


int main() {
//    int n;
//    vector<int> nums;
    cin >> n;
    
    nums.resize(n);
    
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << solve() << endl;
    
    return 0;
}

