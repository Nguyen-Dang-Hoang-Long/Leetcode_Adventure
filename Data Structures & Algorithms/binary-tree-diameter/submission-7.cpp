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
    int height (TreeNode* root, int* maxDiameter) {
        if (!root) return 0;
        int left = 0, right = 0;
        if (root->left) left = height(root->left, maxDiameter);
        if (root->right) right = height(root->right, maxDiameter);
        *maxDiameter = max(*maxDiameter, left + right);
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        height(root, &maxDiameter);
        return maxDiameter;
    }
};
