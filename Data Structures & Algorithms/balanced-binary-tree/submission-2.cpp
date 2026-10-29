/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int check(TreeNode* root) {
        // empty
        if (!root) return 0; // not -1 means true, 0 just means height, and true, not false
        // check both subtree, return -1 if either not balance
        int left = 0; int right = 0;
        if (root->left) {
            left = check(root->left);
            if (left == -1) return -1;
        }
        if (root->right) {
            right = check(root->right);
            if (right == -1) return -1;
        }
        // check balance of self
        if (abs(left - right) > 1) return -1;
        // else, return height
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
