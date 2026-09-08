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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int>nums;
            bool px=0,py=0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                nums.push_back(node->val);
                if(node->left && node->right){
                    if(node->left->val==x || node->left->val==y)
                    if(node->right->val==x || node->right->val==y) return 0;
                }
                if(node->val==x ) px=1;
                else if(node->val==y) py=1;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(px && py) return 1;
        }

        return 0;
    }
};