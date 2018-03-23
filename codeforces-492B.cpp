#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double MIN_DOUBLE = 0.00000001;
vector<int> lanterns;
int n, l;

bool check(double d) {
    vector<double> start(n, 0), end(n, 0);
    
    for (int i = 0; i < n; ++i) {
        start[i] = lanterns[i] - d;
        end[i] = lanterns[i] + d;
    }
    
    // boundary check.
    if (start[0] > 0 || end[n] < l) return false;
    
    for (int i = 0; i < n; ++i)
        if (start[i] < end[i]) return false;
    return true;
}

double bs(double low, double high) {
    double mid = (low + high) / 2;
    
    if (fabs(low - high) < MIN_DOUBLE) return mid;
    if (check(mid)) return bs(mid, high);
    return bs(low, high);
}

int main() {
    cin >> n >> l;
    
    lanterns.resize(n);
    
    for (int i = 0; i < n; ++i) cin >> lanterns[i];
    
    sort(lanterns.begin(), lanterns.end());
    
    cout << bs(0, l) << endl;
    return 0;
}

