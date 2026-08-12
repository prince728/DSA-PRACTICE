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
    unordered_map<long long, int> prefix;
    int ans = 0;

    void dfs(TreeNode* root, long long sum, int target) {
        if (!root)
            return;

        sum += root->val;

        ans += prefix[sum-target];
        prefix[sum]++;

        dfs(root->left, sum, target);
        dfs(root->right, sum, target);

        prefix[sum]--;
    }

    int pathSum(TreeNode* root, int target) {
        prefix[0] = 1;
        dfs(root, 0, target);
        return ans;
    }
};