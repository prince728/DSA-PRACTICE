/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool preorder(TreeNode* root, int val) {
        if (!root)
            return 1;
        if (root->val != val)
            return 0;
        return preorder(root->left, val) && preorder(root->right, val);
    }
    bool isUnivalTree(TreeNode* root) { return preorder(root, root->val); }
};