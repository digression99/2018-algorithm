// algospot OCR

// test case
//5 3
//I am a boy buy
//1.0 0.0 0.0 0.0 0.0
//0.1 0.6 0.1 0.1 0.1
//0.1 0.1 0.6 0.1 0.1
//0.1 0.1 0.1 0.6 0.1
//0.2 0.2 0.2 0.2 0.2
//0.2 0.2 0.2 0.2 0.2
//0.8 0.1 0.0 0.1 0.0
//0.1 0.7 0.0 0.2 0.0
//0.0 0.1 0.8 0.0 0.1
//0.0 0.0 0.0 0.5 0.5
//0.0 0.0 0.0 0.5 0.5
//4 I am a buy
//4 I I a boy
//4 I am am boy

// results
//I am a boy
//I am a boy
//I am a boy


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

const int MAXN = 100; // words in sentence.
const int MAXM = 500; // words that show.
const int INF = 987654321;
string words[MAXM + 1];
string sentence[MAXN + 1];
double initProbs[MAXM + 1];
double classProbs[MAXM + 1][MAXM + 1];
double nextProbs[MAXM + 1][MAXM + 1];
int M, N;

double logInitProbs[MAXM + 1];
double logClassProbs[MAXM + 1][MAXM + 1];
double logNextProbs[MAXM + 1][MAXM + 1];

double memo[MAXN + 1][MAXM + 1];
int choice[MAXN + 1][MAXM + 1];

unordered_map<string, int> hashTable;

vector<string> result;

double exhaustive(int pos, int prev) {
    
    if (pos == N) return 0;
    
    int nowIdx = hashTable[sentence[pos]];
    double ret = -INF;
    int maxIdx = -1;
    
    for (int i = 0; i < M; ++i) {
        // p1 : possibility that nowIdx word can be present as some other words.
        // p2 : possibility of the next words.
        double p1 = 0, p2 = 0;
        
        if (logClassProbs[nowIdx][i] > -INF) {
            // if there's possibility that this words could be classified as some other words.
            if (prev == 0) {
                p1 = logInitProbs[i];
            } else {
                p1 = logNextProbs[prev][i];
            }
            
            p2 = exhaustive(pos + 1, i);
            maxIdx = ret < p1 + p2 ? i : maxIdx;
            ret = max(ret, p1 + p2);
        }
    }
    
    if (maxIdx != -1) result.push_back(words[maxIdx]);
    
    return ret;
}

double dp(int pos, int prev) {
    // pos starts from 0, prev starts from 0, but 0 means it's first.
    if (pos == N) return 0;
    
    double & ret = memo[pos][prev];
    if (ret != 1) return ret;
    
    ret = -1e200;
    int nowIdx = hashTable[sentence[pos]];
    int & choose = choice[pos][prev];
    
    for (int i = 1; i <= M; ++i) {
        double p1 = -INF, p2 = -INF;
        
        if (logClassProbs[i][nowIdx] > -INF) {
            if (prev == 0) {
                p1 = logInitProbs[i];
            } else {
                p1 = logNextProbs[prev][i];
            }
            p1 += logClassProbs[i][nowIdx];
            
            p2 = dp(pos + 1, i);
            choose = ret < p1 + p2 ? i : choose;
            ret = max(ret, p1 + p2);
        }
    }
    
    return ret;
}

//
//void reconstruct(int pos, int prev, vector<string> & res) {
//    if (pos == N) return;
//    int nowIdx = hashTable[sentence[pos]];
//
//    int maxIdx = -1;
//    double minVal = -INF;
//
//    for (int i = 1; i <= M; ++i) {
//        if (logClassProbs[nowIdx][i] > -INF) {
//            if (prev == 0) {
//                if (minVal < dp(pos, prev) + dp(pos, i)) {
//                    minVal = dp(pos, i);
//                    maxIdx = i;
//                }
//            } else {
//                if (minVal) {}
//
//            }
//        }
//    }
//}

string reconstruct(int pos, int prev) {
    int choose = choice[pos][prev];
    string ret = words[choose];
    if (pos < N - 1) ret = ret + " " + reconstruct(pos + 1, choose);
    return ret;
}

void driver() {
    
    int Q;
    cin >> M >> Q;
    
    // inupt words.
    for (int j = 1; j <= M; ++j) {
        cin >> words[j];
        hashTable[words[j]] = j;
    }
    
    // input init probs.
    for (int j = 1; j <= M; ++j) {
        cin >> initProbs[j];
        
        logInitProbs[j] = initProbs[j] > 0 ? log(initProbs[j]) : -INF;
    }
    
    // input next probs.
    for (int j = 1; j <= M; ++j) {
        for (int k = 1; k <= M; ++k) {
            cin >> nextProbs[j][k];
            
            logNextProbs[j][k] = nextProbs[j][k] > 0 ? log(nextProbs[j][k]) : -INF;
        }
    }
    
    // input classifying probs.
    for (int j = 1; j <= M; ++j) {
        for (int k = 1; k <= M; ++k) {
            cin >> classProbs[j][k];
            logClassProbs[j][k] = classProbs[j][k] > 0 ? log(classProbs[j][k]) : -INF;
        }
    }
    
    for (int j = 0; j < Q; ++j) {
        cin >> N;
        
        for (int k = 0; k < MAXN + 1; ++k) {
            for (int l = 0; l < MAXM + 1; ++l) {
                memo[k][l] = 1;
                choice[k][l] = -1;
            }
        }
        
        for (int k = 0; k < N; ++k) {
            cin >> sentence[k];
        }
        
        dp(0, 0);
        cout << reconstruct(0, 0) << endl;
    }
}

void test() {
    cout << log(0.9) << endl;
    cout << log(0.1) << endl;
    cout << log(0) << endl;
    cout << log(1) << endl;
}

int main() {
//    test();
    driver();
    return 0;
}

