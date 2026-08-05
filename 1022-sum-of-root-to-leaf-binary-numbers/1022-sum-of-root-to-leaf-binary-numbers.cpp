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
    void DFS(TreeNode* root, int sum, int& ans) {
        if (!root) {
            return;
        }
        sum = (sum << 1) | root->val;
        if (!root->left && !root->right) {
            ans += sum;
            return;
        }
        DFS(root->left, sum, ans);
        DFS(root->right, sum, ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0, sum = 0;
        DFS(root, sum, ans);
        return ans;
    }
};