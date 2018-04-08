// leet 814

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    bool pruning(TreeNode * root) {
        bool left = false, right = false;
        
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) {
            // leaf.
            return root->val == 1 ? false : true; // false : don't delete. true : delete.
        }
        left = pruning(root->left);
        if (left) root->left = nullptr;
        right = pruning(root->right);
        if (right) root->right = nullptr;
        if ((!left || !right) || root->val == 1) return false;
        return true;
    }
    
    TreeNode* pruneTree(TreeNode * root) {
        bool res = pruning(root);
        if (res) return nullptr;
        return root;
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(0);
    TreeNode n3(0);
    TreeNode n4(1);
    
    n1.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    
    Solution obj;
    
    cout << obj.pruneTree(&n1) << endl;

    return 0;
}


