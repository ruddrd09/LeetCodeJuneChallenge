/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode* root, int& s, int n) {
        if(!root->left && !root->right) {
            s += (n*10 + root->val);
            return;
        } else if(!root->left) {
            rec(root->right, s, n*10 + root->val);
        } else if(!root->right) {
            rec(root->left, s, n*10 + root->val);   
        } else {
            rec(root->left, s, n*10 + root->val);
            rec(root->right, s, n*10 + root->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int s = 0;
        rec(root, s, 0);
        return s;
    }
};