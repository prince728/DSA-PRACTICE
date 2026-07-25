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
    int checkBalanced(TreeNode* root, bool& ans) {
        if (!root)
            return 0;
        int leftHeight = checkBalanced(root->left, ans);
        int rightHeight = checkBalanced(root->right, ans);

        if (leftHeight - rightHeight > 1 || leftHeight - rightHeight < -1) {
            ans = 0;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = 1;
        checkBalanced(root, ans);
        return ans;
    }
};