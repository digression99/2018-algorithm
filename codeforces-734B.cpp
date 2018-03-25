#include <iostream>
#include <vector>
using namespace std;

vector<int> input(4);

int solve() {
    int ret = 0;
    while (input[0] > 0 && input[2] > 0 && input[3] > 0) {
        ret += 256;
        --input[0]; --input[2]; --input[3];
    }
    while (input[0] > 0 && input[1] > 0) {
        ret += 32;
        --input[0]; --input[1];
    }
    return ret;
}

int main() {
    for (int i = 0; i < 4; ++i) cin >> input[i];
    cout << solve() << endl;
    return 0;
}

