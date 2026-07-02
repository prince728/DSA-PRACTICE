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
    int maxPath(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;

        int leftGain = max(maxPath(root->left, maxSum), 0);
        int rightGain = max(maxPath(root->right, maxSum), 0);


        int currentPathSum = leftGain + rightGain + root->val;
        maxSum = max(maxSum, currentPathSum);
        
       
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN; 
        maxPath(root, maxSum);
        return maxSum;
    }
};
