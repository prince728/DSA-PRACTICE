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
    void sumLeft(TreeNode* root, int& sum,bool indicate) {
        if (root == nullptr)
            return;
        
        if(!root->left&&!root->right){
            if(indicate) sum+=root->val;
            return;
        }
        sumLeft(root->left,sum,1);
        sumLeft(root->right,sum,0);

    }


    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumLeft(root->left, sum,1);
        sumLeft(root->right, sum,0);

        return sum;
    }
};