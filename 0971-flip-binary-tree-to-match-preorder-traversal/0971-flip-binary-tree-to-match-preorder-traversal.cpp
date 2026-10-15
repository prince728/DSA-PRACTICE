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
    bool dfs(TreeNode* root, vector<int>& voyage, int& index, vector<int>& ans) {
        if (!root) return true;
        
        if (index >= voyage.size() || root->val != voyage[index]) {
            return false;
        }
        
        index++; 

        if (root->left && index < voyage.size() && root->left->val != voyage[index]) {
            ans.push_back(root->val);
            return dfs(root->right, voyage, index, ans) && dfs(root->left, voyage, index, ans);
        }
        
        return dfs(root->left, voyage, index, ans) && dfs(root->right, voyage, index, ans);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int index = 0;
        
        if (dfs(root, voyage, index, ans)) {
            return ans;
        }
        
        return {-1};
    }
};
