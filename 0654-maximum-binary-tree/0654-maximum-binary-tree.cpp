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
    int findMax(vector<int>& nums, int start, int end) {
        int maxEle = nums[start];
        int index = start;

        for (int i = start + 1; i <= end; i++) {
            if (maxEle < nums[i]) {
                maxEle = nums[i];
                index = i;
            }
        }

        return index;
    }

    TreeNode* binaryTree(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        int maxEle = findMax(nums, start, end);
        TreeNode* root = new TreeNode(nums[maxEle]);
        root->left = binaryTree(nums, start, maxEle - 1);
        root->right = binaryTree(nums, maxEle + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return binaryTree(nums, 0, nums.size() - 1);
    }
};