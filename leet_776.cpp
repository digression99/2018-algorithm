//
// 20180204
// leetcode contest 70
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    TreeNode * getSplitTree(TreeNode * root, int V, TreeNode * parent) {
        if (root == nullptr) return nullptr;
        
        // diffrent between left and right.
        // but how can you differentiate btw left and right? flag? or parent value?
        
        if (V == root->val) {
            if (root->right != nullptr) {
                parent->left = root->right;
                root->right = nullptr;
            }
            else
                parent->left = nullptr;
            return root;
        } else if (V < root->val) return getSplitTree(root->left, V, root);
        else return getSplitTree(root->right, V, root);
        
        return nullptr;
    }
    
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) return vector<TreeNode*>{root, root};
        if (root->left == nullptr && root->right == nullptr) return vector<TreeNode *>{root, nullptr};
        
        return vector<TreeNode*>{getSplitTree(root, V, root), root};
    }
};


vector<int> input1Vec = {1, 2, 2, 4};
vector<int> input2Vec = {1, 1, 2, 5};
vector<char> resVec = {'0', '0', '1', '1'};

void TEST() {
    Solution obj;

    auto resIt = resVec.begin();
    auto input2It = input2Vec.begin();
    auto input1It = input1Vec.begin();
    char res = '#';

    while (input1It != input1Vec.end()) {
//        res = obj.kthGrammar(*input1It++, *input2It++);
        if (*resIt++ != res) break;
    }

    if (input1It != input1Vec.end()) {
        cout << "Error occured in " << input1It - input1Vec.begin() << "th testcase." << endl;
        cout << "Expected : " << --(*resIt) << " Got : " << res << endl;
    } else {
        cout << "TEST finished." << endl;
    }

//    for(auto input1It = input1Vec.begin(); input1It != input1Vec.end(); ++input1It) {
//        if (*resIt++ != obj.kthGrammar(*input1It, *input2It++)) {
//            cout << "Error occured in " << input1It - input1Vec.begin() << "th testcase." << endl;
//        }
//    }


    return;
}

void DRIVER() {
//    TEST();
    
    return;
}

int main() {
//    TEST();
    DRIVER();
    
    return 0;
}

