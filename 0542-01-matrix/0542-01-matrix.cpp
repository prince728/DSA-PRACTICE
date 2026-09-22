class Solution {
public:
    int r, c;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i >= 0 && j >= 0 && i < r && j < c; }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(r, vector<int>(c, -1));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                if (valid(i + row[k], j + col[k]) &&
                    ans[i + row[k]][j + col[k]] == -1) {
                        ans[i + row[k]][j + col[k]]=ans[i][j]+1;
                        q.push({i + row[k], j + col[k]});
                }
            }
        }

        return ans;
    }
};