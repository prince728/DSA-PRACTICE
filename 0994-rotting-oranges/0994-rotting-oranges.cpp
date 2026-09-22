class Solution {
public:
    int r, c;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i >= 0 && j >= 0 && i < r && j < c; }

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int time = 0;
        int fresh = 0; 

        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++; 
                }
            }
        }

        if (fresh == 0) return 0;

        while (!q.empty()) {
            time++;
            int n = q.size();
            for (int m = 0; m < n; m++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if (valid(ni, nj) && grid[ni][nj] == 1) {
                        q.push({ni, nj});
                        grid[ni][nj] = 2;
                        fresh--; 
                    }
                }
            }
        }

        return fresh == 0 ? time - 1 : -1;
    }
};
