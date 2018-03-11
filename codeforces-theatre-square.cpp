#include <iostream>
using namespace std;

int solve(int n, int m, int a) {
    int row = n / a, col = m / a;
    if (n / a < (double)n / a) ++row;
    if (m / a < (double)m / a) ++col;
    
    return row * col;
}

int main() {
    int n, m, a;
    cin >> n >> m >> a;
    
    cout << solve(n, m, a) << endl;
    
    return 0;
}

