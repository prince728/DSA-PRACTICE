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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);

        int first = 0, second = arr.size() - 1;
        while (first < second) {
            if (arr[first] + arr[second] == k)
                return 1;
            if (arr[first] + arr[second] > k) {
                second--;
            } else
                first++;
        }
        return 0;
    }
};