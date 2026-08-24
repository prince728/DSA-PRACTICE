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
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        inorder(root, nums);

        for (auto q : queries) {
            vector<int> elem(2, -1);
            int first = 0, last = nums.size() - 1;
            int index = 0;

            while (first <= last) {
                int mid = first + (last - first) / 2;

                if (nums[mid] == q) {
                    elem[0] = nums[mid];
                    elem[1] = nums[mid];
                    break;
                }

                else if (nums[mid] > q) {
                    elem[1] = nums[mid];
                    last = mid - 1;
                } else {
                    elem[0] = nums[mid];
                    first = mid + 1;
                }
            }

            ans.push_back(elem);
        }

        return ans;
    }
};