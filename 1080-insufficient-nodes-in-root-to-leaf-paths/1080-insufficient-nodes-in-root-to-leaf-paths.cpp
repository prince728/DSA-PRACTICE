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
    pair<TreeNode*, bool> dfs(TreeNode* root, int sum, int limit) {
        if (!root)
            return {nullptr, 0};
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum >= limit)
                return {root, 1};
            else
                return {nullptr, 0};
        }

        auto [left, Leftcheck] = dfs(root->left, sum, limit);
        if (Leftcheck) {
            root->left = left;
        } else
            root->left = nullptr;

        auto [right, Rightcheck] = dfs(root->right, sum, limit);
        if (Rightcheck) {
            root->right = right;
        } else
            root->right = nullptr;

        bool isSufficient =
            Leftcheck || Rightcheck;

            return {isSufficient ? root : nullptr, isSufficient};
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int currentSum = 0;
        return dfs(root, currentSum, limit).first;
    }
};