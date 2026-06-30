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
    void rootToLeaf(TreeNode* root, vector<string>& ans, string curr) {
        if (!root)
            return;
        if (!root->left && !root->right) {

            ans.push_back(curr + to_string(root->val));

            return;
        }

        curr += to_string(root->val) + "->";
        if (root->left)
            rootToLeaf(root->left, ans, curr);

        if (root->right)
            rootToLeaf(root->right, ans, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr = "";
        rootToLeaf(root, ans, curr);

        return ans;
    }
};