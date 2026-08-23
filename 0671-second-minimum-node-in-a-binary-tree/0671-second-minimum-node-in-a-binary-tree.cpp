class Solution {
public:
    int min_val;
    long long ans = LLONG_MAX;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        if (node->val > min_val) {
            if (node->val < ans) {
                ans = node->val;
            }
            return;
        }

        dfs(node->left);
        dfs(node->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) return -1;

        min_val = root->val;

        dfs(root);

        if (ans == LLONG_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};
