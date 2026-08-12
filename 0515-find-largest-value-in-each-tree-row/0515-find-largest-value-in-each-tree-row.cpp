/**
https://leetcode.com/problems/find-largest-value-in-each-tree-row/$0 * Definition for a binary tree node.
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;

        while(!q.empty()){
            int n=q.size();
            int maxElem=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode*curr= q.front();
                q.pop();
                maxElem =max(maxElem,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(maxElem);
        }

        return ans;
    }
};