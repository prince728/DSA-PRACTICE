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
    int maxDiameter(TreeNode*root,int& Diameter){
        if(!root) return 0;

        int Lheight =maxDiameter(root->left,Diameter);
        int Rheight =maxDiameter(root->right,Diameter);
        Diameter = max(Diameter ,Lheight+Rheight);
        return 1+max(Lheight,Rheight);

    }


    int diameterOfBinaryTree(TreeNode* root) {
        int Diameter = 0;
        maxDiameter(root,Diameter);
        return Diameter;
    }
};