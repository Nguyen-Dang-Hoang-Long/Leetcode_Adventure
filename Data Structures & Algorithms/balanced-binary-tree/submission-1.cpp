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
    int height(TreeNode* root) {
        if (!root) return 0;
        int left = 0, right = 0;
        if (root->left) left = height(root->left);
        if (root->right) right = height(root->right);
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        // Empty tree
        if (!root) return true;
        // Setup height and balance
        bool left, right;
        left = right = true;
        int leftH, rightH;
        leftH = rightH = 0;
        // Check both trees
        if (root->left) {
            left = isBalanced(root->left);
            leftH = height(root->left);
        }
        if (root->right) {
            right = isBalanced(root->right);
            rightH = height(root->right);
        }
        // Check their balance
        if (!isBalanced(root->left) || !isBalanced(root->right)) 
            return false;
        // Check its own balance
        return leftH > rightH ? leftH - rightH <= 1 : rightH - leftH <= 1;
    }
};
