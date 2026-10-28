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
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Return null if empty
        if (!root) return nullptr;
        // Pre-traverse swap
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->right = left;
        root->left = right;
        // Return
        return root;
    }
};
