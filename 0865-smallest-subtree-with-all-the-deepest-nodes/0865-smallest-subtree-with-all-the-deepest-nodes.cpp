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
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root)
            return {nullptr, 0};

        auto [leftSubtree, leftDepth] = dfs(root->left);
        auto [rightSubtree, rightDepth] = dfs(root->right);

        if (leftDepth > rightDepth) {
            return {leftSubtree, leftDepth + 1};
        }
        if (leftDepth < rightDepth) {
            return {rightSubtree, rightDepth + 1};
        }

        return {root, leftDepth + 1};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).first; }
};