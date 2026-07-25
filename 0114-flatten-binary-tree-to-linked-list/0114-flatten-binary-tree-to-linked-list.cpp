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
    TreeNode* rightMost(TreeNode* root) {

        while (root && root->right) {
            root = root->right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        while (root) {
            if (!root->right) {
                root->right = root->left;
                root->left =nullptr;
            }
            if (root->left && root->right) {
                TreeNode* right = root->right;
                root->right = root->left;
                root->left = nullptr;
                TreeNode* lastright = rightMost(root->right);
                if (lastright)
                    lastright->right = right;
            }
            root = root->right;
        }
    }
};