#include <iostream>
using namespace std;

void solve() {
    int t, start, end, mid;
    cin >> t;
    
    mid = t / 2;
    start = 1;
    end = t - 1;
    
    while (start < mid) {
        if (start % 2 && end % 2) {
            cout << "YES" << endl;
            return;
        }
        ++start;
        --end;
    }
    
    cout << "NO" << endl;
}


int main() {
    solve();
    
    return 0;
}

