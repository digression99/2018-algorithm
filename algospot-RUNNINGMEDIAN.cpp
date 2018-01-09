//
// algospot_RUNNINGMEDIAN
//

/*
 testcase
3
10 1 0
10 1 1
10000 1273 4936
 */


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

int tc, n, a, b;
const int MOD = 20090711;

void pushHeap(vector<long long> & heap, int pos, long long d) {
    heap[pos] = d;
    while (pos > 0 && heap[(pos - 1) / 2] > heap[pos]) { // min heap.
        swap(heap[(pos - 1) / 2], heap[pos]);
        pos = (pos - 1) / 2;
    }
}

long long getMedian(vector<long long> & heap, int n) {
    if (n % 2 || heap[(n - 1) / 2] < heap[(n - 1) / 2 + 1])
        return heap[(n - 1) / 2];
    return heap[(n - 1) / 2 + 1];
}

long long solve() {
    vector<long long> heap(n); // resize to n.
    long long median = heap[0] = 1983;
    
    for (int i = 1; i < n; ++i) {
        long long nextValue = ((heap[i - 1] * a) % MOD + b) % MOD;
//        long long nextValue = (heap[i - 1] * a + b) % 20090711;
        pushHeap(heap, i, nextValue);
        median += (getMedian(heap, i + 1) % MOD);
        median %= MOD;
    }
    return median;
}

struct RNG {
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next() {
        int ret = seed;
        seed = ((seed * (long long) a) + b) % MOD;
        return ret;
    }
};

int runningMedian(int n, RNG rng) {
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int ret = 0;
    for (int cnt = 1; cnt <= n; ++cnt) {
        if (maxHeap.size() == minHeap.size())
            maxHeap.push(rng.next());
        else
            minHeap.push(rng.next());
        
        if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int a = maxHeap.top(), b = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        
        ret = (ret + maxHeap.top()) % MOD;
    }
    return ret;
}

int main() {
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n >> a >> b;
        cout << runningMedian(n, RNG(a, b));
    }
    
    return 0;
}

