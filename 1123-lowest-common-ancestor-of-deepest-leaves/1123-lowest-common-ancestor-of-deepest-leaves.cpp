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
pair<TreeNode*, int> dfs(TreeNode*root){
    if(!root) return {nullptr,0};

    auto[left,leftDepth]= dfs(root->left);
    auto[right,rightDepth]= dfs(root->right);

    if(leftDepth>rightDepth)return {left,leftDepth+1};
    if(leftDepth<rightDepth)return {right,rightDepth+1};

    return {root,leftDepth+1};
}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};