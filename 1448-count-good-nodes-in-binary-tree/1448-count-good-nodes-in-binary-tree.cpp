/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int maxSoFar) {
        if (!root) return 0;
        
        int goodNodeCount = 0;
        
       
        if (root->val >= maxSoFar) {
            goodNodeCount = 1;
            maxSoFar = root->val; 
        }
        
        
        goodNodeCount += dfs(root->left, maxSoFar);
        goodNodeCount += dfs(root->right, maxSoFar);
        
        return goodNodeCount;
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val);
    }
};
