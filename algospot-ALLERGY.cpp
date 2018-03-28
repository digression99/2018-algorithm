
// algospot ALLERGY

// test case
//3
//4 6
//cl bom dara minzy
//2 dara minzy
//2 cl minzy
//2 cl dara
//1 cl
//2 bom dara
//2 bom minzy
//10 7
//a b c d e f g h i j
//6 a c d h i j
//3 a d i
//7 a c f g h i j
//3 b d g
//5 b c f h i
//4 b e g j
//5 b c g h i
//2 3
//a b
//0
//0
//2 a b

// result
// 2
// 3
// 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;


const int MAX_DEPTH = 20 + 1;
int n, m;
int best;

unordered_map<int, vector<int>> foods;
unordered_map<int, vector<int>> friends;

void sortFoods() {
    map<int, int> foodsSorted;
    for (auto dat : foods) {
        int key = (int)dat.second.size();
        foodsSorted[dat.first] = key;
    }
    unordered_map<int, vector<int>> orderedFoods;
    
    for (auto dat : foodsSorted) {
        int idx = dat.first;
        orderedFoods[idx] = foods[idx];
    }
    foods = orderedFoods;
    
    //    return orderedFoods;
}

void sortFriends() {
    map<int, int, less<int>> friendsSorted;
    for (auto dat : friends) {
        int key = (int)dat.second.size();
        friendsSorted[dat.first] = key;
    }
    unordered_map<int, vector<int>> orderedFriends;
    for (auto dat : friendsSorted) {
        int idx = dat.first;
        orderedFriends[idx] = friends[idx];
    }
    friends = orderedFriends;
    
    //    return orderedFriends;
}

void combinationSearch(vector<int> & edible, int chosen) {
    if (chosen >= best) return;
    
    int first = 0;
    while (first < n && edible[first] > 0) ++first;
    
    if (first == n) {
        best = chosen;
        return;
    }
    
    for (int i = 0; i < friends[first].size(); ++i) {
        int foodIdx = friends[first][i];
        //        cout << "size is : " << foods[foodIdx].size() << endl;
        for (int j = 0; j < foods[foodIdx].size(); ++j) {
            ++edible[foods[foodIdx][j]];
        }
        combinationSearch(edible, chosen + 1);
        for (int j = 0; j < foods[foodIdx].size(); ++j) {
            --edible[foods[foodIdx][j]];
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        best = MAX_DEPTH;
        
        cin >> n >> m;
        
        // init
        for (int i = 0; i < n; ++i) friends[i] = vector<int>();
        for (int i = 0; i < m; ++i) foods[i] = vector<int>();
        
        unordered_map<string, int> names;
        
        vector<int> edible(n, 0); // check if every friend has something to eat.
        
        for (int j = 0; j < n; ++j) {
            string str;
            cin >> str;
            names[str] = j; // hash.
        }
        
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            
            for (int k = 0; k < t; ++k) {
                string str;
                cin >> str;
                int idx = names[str];
                
                // food setting.
                foods[j].push_back(idx);
                // friend setting.
                friends[idx].push_back(j);
            }
        }
        
        //        for (auto dat : foods) {
        //            cout << "idx is : " << dat.first << endl;
        //            for (int i = 0; i < dat.second.size(); ++i) {
        //                cout << dat.second[i] << endl;
        //            }
        //        }
        
        sortFriends();
        sortFoods();
        
        combinationSearch(edible, 0);
        
        cout << best << endl;
        
        foods.clear();
        friends.clear();
    }
    
    return 0;
}

namespace try1 {
    const int MAX_DEPTH = 20 + 1;
    vector<vector<int>> foods;
    //unordered_map
    
    int best;
    int m, n;
    
    bool visitedCheck(vector<bool> & visited) {
        // true : all checked.
        for (int i = 0; i < n; ++i) if (!visited[i]) return false;
        //    for (auto dat : visited) if (!dat) return false;
        return true;
    }
    
    void selectFoods(vector<bool> & visited, int idx, int delta) {
        bool offset = delta == 1 ? true : false;
        for (int i = 0; i < foods[idx].size(); ++i) {
            int personIdx = foods[idx][i];
            visited[personIdx] = offset;
        }
    }
    
    void search(int cnt, int pos, vector<bool> & visited, vector<bool> & selected) {
        if (pos > m) return;
        
        if (visitedCheck(visited)) { // if all checked
            if (best > cnt) {
                best = cnt;
            }
            return;
        }
        
        search(cnt, pos + 1, visited, selected);
        
        for (int i = pos; i < m; ++i) {
            if (cnt + 1 >= best) return;
            if (!selected[i]) {
                selected[i] = true;
                
                selectFoods(visited, i, 1);
                search(cnt + 1, i + 1, visited, selected);
                selected[i] = false;
                selectFoods(visited, i, 0);
            }
        }
    }
    
    int main() {
        int tc;
        cin >> tc;
        
        for (int i = 0; i < tc; ++i) {
            best = MAX_DEPTH;
            
            cin >> n >> m;
            
            unordered_map<string, int> names;
            
            //        names.resize(m);
            //        vector<string, int> names(m);
            vector<bool> visited(n, false), selected(m, false);
            
            // init.
            foods.resize(m);
            
            for (int j = 0; j < n; ++j) {
                string str;
                cin >> str;
                names[str] = j; // hash.
            }
            
            for (int j = 0; j < m; ++j) {
                int t;
                cin >> t;
                for (int k = 0; k < t; ++k) {
                    string str;
                    cin >> str;
                    int idx = names[str];
                    foods[j].push_back(idx);
                }
            }
            
            search(0, 0, visited, selected);
            
            cout << best << endl;
            
            foods.clear();
        }
        
        return 0;
    }
};


