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
    TreeNode* dfs(TreeNode* root, unordered_set<int> mp,
                  vector<TreeNode*>& ans) {
        if (!root)
            return nullptr;
        root->left = dfs(root->left, mp, ans);
        root->right = dfs(root->right, mp, ans);

        if (mp.count(root->val)) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return nullptr;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> mp(to_delete.begin(), to_delete.end());

        if (!mp.count(root->val))
            ans.push_back(root);

        dfs(root, mp, ans);

        return ans;
    }
};