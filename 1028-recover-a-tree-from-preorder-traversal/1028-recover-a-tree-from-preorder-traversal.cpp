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
    TreeNode* preorder(vector<int>& nums, vector<int>& depth, int& index,
                       int currentDepth) {
        if (index >= nums.size())
            return nullptr;

         if (depth[index] == currentDepth) {
            TreeNode* root = new TreeNode(nums[index]);
            index++;
            root->left = preorder(nums, depth, index, currentDepth + 1);
            root->right = preorder(nums, depth, index, currentDepth + 1);

            return root;
        }

        return nullptr;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        vector<int> depth;
        depth.push_back(0);
        vector<int> nums;
        int num = 0;
        int count = 0;

        for (int i = 0; i < traversal.size(); i++) {
            if (traversal[i] == '-') {
                count++;
                if (num) {
                    nums.push_back(num);
                    num = 0;
                }
            } else {
                num = num * 10 + (traversal[i] - '0');
                if (count) {
                    depth.push_back(count);
                    count = 0;
                }
            }
        }

        if (num) {
            nums.push_back(num);
        }

        int index = 0;
        return preorder(nums, depth, index, 0);
    }
};