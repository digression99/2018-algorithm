/*
 
 algospot DICTIONARY
 
 */

// test case
//3
//3
//ba
//aa
//ab
//5
//gg
//kia
//lotte
//lg
//hanhwa
//6
//dictionary
//english
//is
//ordered
//ordinary
//this

//



#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

const int ALPHABET_MAX = 26;
const string INVALID_HYPOTHESIS = "INVALID HYPOTHESIS";

int edges[ALPHABET_MAX][ALPHABET_MAX];
bool hasEdges[ALPHABET_MAX];
bool visited[ALPHABET_MAX];

void makeGraph(vector<string> & words) {
    
    for (int i = 1; i < words.size(); ++i) {
        int j = 0, k = 0;
        
        while (words[i - 1].length() > j && words[i].length() > k) {
            char front = words[i - 1][j], back = words[i][k];
            
            if (front == back) {
                ++j; ++k;
                continue;
            }
            
            front -= 'a'; back -= 'a';
            
            hasEdges[front] = true;
            
            edges[front][back] = 1;
            break;
        }
    }
}

bool topologicalSortUtil(int v, vector<int> & st) {
    visited[v] = true;
    
    if (hasEdges[v]) {
        for (int i = 0; i < ALPHABET_MAX; ++i) {
            if (edges[v][i]) {
                if (!visited[i]) // return false;
                    topologicalSortUtil(i, st);
//                if (!topologicalSortUtil(i, st)) return false;
            }
        }
//        st.push(v);
    }
    st.push_back(v);
    return true;
}

string topologicalSort() {
    vector<int> st;
    
    for (int i = 0; i < ALPHABET_MAX; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, st);
//            if (!topologicalSortUtil(i, st)) return INVALID_HYPOTHESIS;
        }
    }
    string ret = "";
    
    reverse(st.begin(), st.end());
    
    for (auto n : st) ret += (n + 'a');
    
//    while (!st.empty()) {
//        ret += (st.top() + 'a');
//        st.pop();
//    }
    
    return ret;
}

void solve() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;
        
        vector<string> words(n);
        
        for (int j = 0; j < n; ++j) cin >> words[j];
        
        // init
        for (int j = 0; j < ALPHABET_MAX; ++j) {
            hasEdges[j] = false;
            visited[j] = false;
            for (int k = 0; k < ALPHABET_MAX; ++k) edges[j][k] = 0;
        }
        
        makeGraph(words);
        
        // cycle check
        
        string res = topologicalSort();
        
//        reverse(res.begin(), res.end());
        
        cout << res << endl;
    }
}


int main() {
    
    solve();
    return 0;
}

