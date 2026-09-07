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
    TreeNode* head = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        root->left = nullptr;

        if (prev != nullptr)
            prev->right = root;
        else
            head = root;

        prev = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return head;
    }
};