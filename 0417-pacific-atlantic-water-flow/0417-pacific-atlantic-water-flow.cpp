class Solution {
public:
    int r, c;
    int row[8] = {-1, 0, 1, 0};
    int col[8] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i >= 0 && j >= 0 && i < r && j < c; }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
             vector<vector<bool>>& reachable) {
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];

                if (valid(ni, nj) && !reachable[ni][nj]) {
                    if (heights[ni][nj] >= heights[i][j]) {
                        reachable[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();
        vector<vector<int>> ans;
        if (r == 0 || c == 0)
            return ans;

        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        for (int i = 0; i < r; i++) {
            pacificQueue.push({i, 0});
            pacific[i][0] = true;

            atlanticQueue.push({i, c - 1});
            atlantic[i][c - 1] = true;
        }

        for (int j = 0; j < c; j++) {
            pacificQueue.push({0, j});
            pacific[0][j] = true;

            atlanticQueue.push({r - 1, j});
            atlantic[r - 1][j] = true;
        }

        bfs(heights, pacificQueue, pacific);
        bfs(heights, atlanticQueue, atlantic);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};