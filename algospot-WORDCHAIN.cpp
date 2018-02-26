/*
 
 algospot_WORDCHAIN
 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_MAX = 26;

vector<vector<int>> adj;

vector<string> graph[ALPHABET_MAX][ALPHABET_MAX];

vector<int> indegree, outdegree;

void makeGraph(const vector<string> & words) {
    for (int i = 0; i < ALPHABET_MAX; ++i)
        for(int j = 0; j < ALPHABET_MAX; ++j)
            graph[i][j].clear();
    
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);
    
    for (int i = 0; i < words.size(); ++i) {
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size() - 1] - 'a';
        
        // directed graph
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

void getEulerCircuit(int here, vector<int> & circuit) {
    for(int there = 0; there < adj.size(); ++there) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;
    
    // if there's start point for euler trail
    for (int i = 0; i < ALPHABET_MAX; ++i) {
        if (outdegree[i] == indegree[i] + 1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    // if not, it's circuit or nothing.
    for (int i = 0; i < ALPHABET_MAX; ++i) {
        if (outdegree[i]) { // this means that it's not the last word.
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    return circuit;
}

string solve(const vector<string> & words) {
    makeGraph(words);
    
    vector<int> circuit = getEulerTrailOrCircuit();
    
    if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";
    
    reverse(circuit.begin(), circuit.end());
    string ret;
    
    for (int i = 1; i < circuit.size(); ++i) {
        int a = circuit[i - 1], b = circuit[i];
        if (ret.size())  ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}

int main() {
    
    vector<string> words{"need", "dragon", "god", "dog"};
    
    cout << solve(words) << endl;
    
    return 0;
}
















