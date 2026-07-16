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
    int find(vector<int>&inorder ,int start,int end,int &target){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target) return i;
        }
        return 0;
    }
    TreeNode *tree(vector<int>& preorder, vector<int>& inorder,int start,int end,int &index){
        if(start>end) return nullptr;

        TreeNode *root =new TreeNode(preorder[index]);
        int  i= find(inorder,start,end, preorder[index]);
        index++;
        root->left =tree(preorder,inorder,start,i-1,index);
        root->right =tree(preorder,inorder,i+1,end,index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index =0;
        return tree(preorder,inorder,0,preorder.size()-1,index);
    }
};