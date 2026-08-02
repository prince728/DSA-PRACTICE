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
    void formNums(TreeNode* root, vector<string>& ans, string num) {

        if (!root)
            return;

        num += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(num);
            return;
        }

        if (root->left)
            formNums(root->left, ans, num);
        if (root->right)
            formNums(root->right, ans, num);
    }

    int sumNumbers(TreeNode* root) {
        vector<string> nums;
        string num = "";
        formNums(root, nums, num);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += stoi(nums[i]);
        }
        return ans;
    }
};