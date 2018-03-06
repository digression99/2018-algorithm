//
// algospot HANOI4
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// test case
//3
//5
//1 1
//1 3
//2 5 4
//1 2
//3
//1 2
//0
//2 3 1
//0
//10
//2 8 7
//2 5 4
//3 6 3 2
//3 10 9 1

// results
//10
//4
//24

const int MAX_DISCS = 12;
int c[1 << (MAX_DISCS * 2)];
int finals[MAX_DISCS + 1];

int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int sgn(int x) {
    if (!x) return 0; // if x is 0, then return 0.
    
    return x > 0 ? 1 : -1;
}

int incr(int x) {
    if (x < 0) return x - 1;
    return x + 1;
}

int getFinal(int discs) {
    return finals[discs];
}

void initFinals() {
    for (int i = 1; i <= MAX_DISCS; ++i) {
        // do something
        for (int j = 0; j < i; ++j) {
            // set the final state.
            // set all numbers to value of 3. (means the last poll)
            finals[i] = set(finals[i], j, 3);
        }
    }
}

int bfs(int discs, int begin, int end) {
    if (begin == end) return 0;
    
    queue<int> q;
    memset(c, 0, sizeof(c));
    
    q.push(begin);
    c[begin] = 0;
    
    while (!q.empty()) {
        int here = q.front(); q.pop();
        
        int top[4] = {-1, -1, -1, -1}; // get the top disc.
        
        for (int i = discs - 1; i >= 0; --i) top[get(here, i)] = i;
        for (int i = 0; i < 4; ++i)
        {
            if (top[i] != -1) {
                for (int j = 0; j < 4; ++j) {
                    if (i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        if (c[there] != -1) continue;
                        c[there] = c[here] + 1;
                        if (there == end) return c[there];
                        q.push(there);
                    }
                }
            }
        }
    }
    
    return -1;
}

int bidir(int discs, int begin, int end) {
    
    if (begin == end) return 0;
    
    queue<int> q;
    memset(c, 0, sizeof(c));
    
    q.push(begin); c[begin] = 1;
    q.push(end); c[end] = -1;
    
    while (!q.empty()) {
        int here = q.front(); q.pop();
        int top[4] = {-1, -1, -1, -1};
        // get the top discs.
        for (int i = discs - 1; i >= 0; --i) top[get(here, i)] = i;
        
        for (int i = 0; i < 4; ++i) {
            if (top[i] != -1) {
                for (int j = 0; j < 4; ++j) {
                    if (i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        // if not yet visited.
                        if (c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        } else if (sgn(c[there]) != sgn(c[here])) {
                            // if the sign is different, then we found the mid point.
                            return abs(c[there]) + abs(c[here]) - 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int tc;
    cin >> tc;
    
    initFinals();
    
    for (int i = 0; i < tc; ++i) {
        int n, first = 0, discs;
        cin >> n;
        for (int j = 0; j < 4; ++j) {
            cin >> discs; // get the disc num.
            for (int k = 0; k < discs; ++k) {
                int value; cin >> value; // get the value.
                first = set(first, value - 1, j);
            }
        }
        
        cout << bidir(n, first, getFinal(n)) << endl;
    }
    return 0;
}

