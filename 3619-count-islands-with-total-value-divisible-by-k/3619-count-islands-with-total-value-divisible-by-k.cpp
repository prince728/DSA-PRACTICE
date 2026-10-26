class Solution {
public:
    int rows, cols;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i < rows & i >= 0 & j < cols & j >= 0; }

    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0)
                    continue;
                int sum = 0;
                queue<pair<int, int>> q;
                if (grid[i][j] != 0)
                    q.push({i, j});

                sum += grid[i][j];
                grid[i][j] = 0;

                while (!q.empty()) {
                    int X = q.front().first;
                    int Y = q.front().second;
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        if (valid(X + row[d], Y + col[d]) &&
                            grid[X + row[d]][Y + col[d]] != 0) {
                            q.push({X + row[d], Y + col[d]});
                            sum += grid[X + row[d]][Y + col[d]];
                            sum %= k;
                            grid[X + row[d]][Y + col[d]] = 0;
                        }
                    }
                }

                if (sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};