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
private:
    void inorder(TreeNode* root, TreeNode*& prev, int& currCount, int& maxCount, vector<int>& modes) {
        if (!root) return;

        inorder(root->left, prev, currCount, maxCount, modes);

        if (prev && prev->val == root->val) {
            currCount++;
        } else {
            currCount = 1; 
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();             
            modes.push_back(root->val); 
        } else if (currCount == maxCount) {
            modes.push_back(root->val); 
        }

        prev = root;

        inorder(root->right, prev, currCount, maxCount, modes);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        TreeNode* prev = nullptr;
        int currCount = 0;
        int maxCount = 0;

        inorder(root, prev, currCount, maxCount, modes);
        return modes;
    }
};
