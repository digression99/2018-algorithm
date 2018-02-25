#include <iostream>
#include <unordered_map>
using namespace std;



class Solution {
public:
    unordered_map<int, int> hash;
    
    int getRotatedNum(int N) {
        int ret = 0;
        int mul = 1;
        int changed = 0;
        
        while (N > 0) {
            int num = N % 10;
            changed = hash[num];
            if (changed == -1) return -1;
            ret += mul * changed;
            N /= 10;
            mul *= 10;
        }
        return ret;
    }
    
    int rotationCheck(int N) {
        
        int res = getRotatedNum(N);
        if (res == -1 || N == res) return 0;
        return 1;
        
//        while (N > 0) {
//            int num = N % 10;
//            if (num == 2 || num == 5 || num == 6 || num == 9) return 1;
//            if (num == 3 || num == 4 || num == 7) return 0;
//            N /= 10;
//        }
//        return 0;
    }
    
    int rotatedDigits(int N) {
        hash[0] = 0;
        hash[1] = 1;
        hash[2] = 5;
        hash[3] = -1;
        hash[4] = -1;
        hash[5] = 2;
        hash[6] = 9;
        hash[7] = -1;
        hash[8] = 8;
        hash[9] = 6;
        int res = 0;
        
        for (int i = 1; i <= N; ++i) {
            res += rotationCheck(i);
        }
        
        return res;
    }
};

int main() {
    
    Solution obj;
    
    cout << obj.rotatedDigits(857) << endl;
    
    return 0;
}























