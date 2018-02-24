/*
 20180212
 
 algospot SOLONG
 
 * 아직 미완성.
 
 
 */

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_SENTENCE_LEN = 10000;
int res = 0;

struct TreeNode {
    char val;
    vector<TreeNode *> children;
    TreeNode(char ch = '$') : val(ch) {}
};

typedef struct TreeNode TreeNode;

void stringTokenizer(string & sent, vector<string> & strs) {
    int i = 0, l = (int)sent.length();
    while (i < l) {
        if (sent[i] == ' ') {
            strs.push_back(" ");
            ++i;
        } else {
            int start = i;
            while (i < l && sent[i] != ' ') ++i;
            string token = sent.substr(start, i - start);
            strs.push_back(token);
        }
    }
}

void put(string & str, int pos, TreeNode * root) {
    // base case
    if (pos == str.length()) return; // end put.
    
    for (auto child : root->children) {
        if (child->val == str[pos]) { // if there's matching char.
            put(str, pos + 1, child);
        }
    }
    // no matching char in children.
    root->children.push_back(new TreeNode(str[pos]));
    put(str, pos + 1, root->children[root->children.size() - 1]); // check the last one.
    // children's gonna have the last char if it's the last one.
    // don't have to check the value of the root.
}

void makeTrie(TreeNode * root, vector<string> & strs) {
    // after sorting.
    for (auto str : strs) {
        put(str, 0, root);
    }
}

void sortStrs(vector<string> & strs, vector<int> & freq) {
    int l = (int)strs.size();
    
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            if (freq[i] < freq[j]) { // sort by descend.
                swap(strs[i], strs[j]); swap(freq[i], freq[j]);
            } else if (freq[i] == freq[j]) { // sort by reverse alphabetical order.
                if (strs[i] > strs[j]) {
                    swap(strs[i], strs[j]); swap(freq[i], freq[j]);
                }
            }
        }
    }
}

bool trieSearch(string & w, int pos, TreeNode * root) {
    // search trie and check if the trie has the word.
    
    if (pos == w.length()) return true;
    for (auto child : root->children) {
        if (child->val == w[pos]) return trieSearch(w, pos + 1, child);
    }
    return false;
}

int wordSearch(string & w, int pos, TreeNode * root) {
    // actually get the value.
    // if there's no word in the trie, return the whole word len.
    // if there's more than one child, find the last tap pos.
    // if there's only one child, check if w exists and if exists, then add one and return.
    
    // if return true, add 1 and return.
    // if return false, add length and return.
    // repeat.
    
    return 0;
}

int driver(TreeNode * root, vector<string> & sent) {
    int ret = 0;
    
    for (auto w : sent) {
        if (w == " ") {
            ret += 1;
        } else {
            // w is word.
            res = 0;
            wordSearch(w, 0, root);
            ret += res;
        }
    }

    return ret;
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        vector<string> strs;
        vector<int> freq;
        
        int n, m;
        cin >> n >> m;
        strs.resize(n);
        freq.resize(n);
        
        for (int j = 0; j < n; ++j) {
            cin >> strs[j] >> freq[j];
        }
        
        // sort
        sortStrs(strs, freq);
        
        // makeTrie
        TreeNode * root = new TreeNode();
        makeTrie(root, strs);
        
        char temp[MAX_SENTENCE_LEN];
        cin.getline(temp, MAX_SENTENCE_LEN);
        vector<string> sent;
        string str(temp);
        
        stringTokenizer(str, sent); // char arr to vector string.
        
        // root : trie, sent : sentence with space.
        // get the answer.
        
        cout << driver(root, sent) << endl;
    }
    
    return 0;
}

