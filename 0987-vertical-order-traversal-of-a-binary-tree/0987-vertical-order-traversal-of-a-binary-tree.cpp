class Solution {
public:
    void find(TreeNode* root, int pos, int &l, int &r) {
        if (!root) return;

        l = min(pos, l);
        r = max(pos, r);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {

        if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        int size = r - l + 1;

        // {level, value}
        vector<vector<pair<int, int>>> ans(size);

        // {node, column, level}
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, -l, 0});

        while (!q.empty()) {

            auto [node, index, level] = q.front();
            q.pop();

            ans[index].push_back({level, node->val});

            if (node->left) {
                q.push({node->left, index - 1, level + 1});
            }

            if (node->right) {
                q.push({node->right, index + 1, level + 1});
            }
        }

        vector<vector<int>> result;

        for (auto &column : ans) {

            sort(column.begin(), column.end());

            vector<int> temp;

            for (auto &p : column) {
                temp.push_back(p.second);
            }

            result.push_back(temp);
        }

        return result;
    }
};