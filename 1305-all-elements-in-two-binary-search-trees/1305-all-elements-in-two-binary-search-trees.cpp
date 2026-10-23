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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;

        if (root->left)
            inorder(root->left, ans);
        ans.push_back(root->val);
        if (root->right)
            inorder(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2, ans;
        inorder(root1, list1);
        inorder(root2, list2);

        int index1 = 0, index2 = 0;

        while (index1 < list1.size() && index2 < list2.size()) {

            if (list1[index1] <= list2[index2]) {
                ans.push_back(list1[index1]);
                index1++;
            } else {
                ans.push_back(list2[index2]);
                index2++;
            }
        }

        while (index1 < list1.size()) {
            ans.push_back(list1[index1]);
            index1++;
        }

        while (index2 < list2.size()) {
            ans.push_back(list2[index2]);
            index2++;
        }

        return ans;
    }
};