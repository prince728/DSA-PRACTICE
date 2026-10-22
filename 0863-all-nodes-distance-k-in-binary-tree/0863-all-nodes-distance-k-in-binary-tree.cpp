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
    void parentMapping(TreeNode* root,
                       unordered_map<TreeNode*, TreeNode*>& parent_map) {
        if (!root)
            return;
        if (root->left)
            parent_map[root->left] = root;
        if (root->right)
            parent_map[root->right] = root;

        parentMapping(root->left, parent_map);
        parentMapping(root->right, parent_map);
    }

    void findNodesAtDistanceK(TreeNode* currentNode, TreeNode* previousNode,
                              int distance,
                              unordered_map<TreeNode*, TreeNode*>& parentMap,
                              vector<int>& result) {
        if (!currentNode) {
            return;
        }

        if (distance == 0) {
            result.push_back(currentNode->val);
            return;
        }

        if (currentNode->left != previousNode) {
            findNodesAtDistanceK(currentNode->left, currentNode, distance - 1,
                                 parentMap, result);
        }
        if (currentNode->right != previousNode) {
            findNodesAtDistanceK(currentNode->right, currentNode, distance - 1,
                                 parentMap, result);
        }
        if (parentMap[currentNode] != previousNode) {
            findNodesAtDistanceK(parentMap[currentNode], currentNode,
                                 distance - 1, parentMap, result);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        parentMapping(root, parent_map);

        vector<int> result;
        findNodesAtDistanceK(target, nullptr, k, parent_map, result);
        return result;
    }
};