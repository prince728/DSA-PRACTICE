/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isPresent(TreeNode* root, int& val1, int& val2) {
        if (!root)
            return 0;
        if (root->val == val1 || root->val == val2)
            return 1;

        return isPresent(root->left, val1, val2) ||
               isPresent(root->right, val1, val2);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if(root->val== p->val  || root->val ==q->val) return root;
            else if (isPresent(root->left, p->val, q->val) &&
                isPresent(root->right, p->val, q->val))
                return root;
            else if (!isPresent(root->left, p->val, q->val)){
                root = root->right;
            }
            else if (!isPresent(root->right, p->val, q->val)){
                root = root->left;
            }
        }
        return nullptr;
    }
};