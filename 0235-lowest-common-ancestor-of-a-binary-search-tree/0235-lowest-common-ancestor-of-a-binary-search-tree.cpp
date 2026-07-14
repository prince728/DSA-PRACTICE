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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *temp=root;
        int data1 =p->val ,data2 =q->val;
        while(temp){
            if(temp->val >data1 && temp->val >data2) temp= temp->left;
            else if(temp->val <data1 && temp->val <data2) temp= temp->right;
            else return temp;
        }
        return nullptr;
    }
};