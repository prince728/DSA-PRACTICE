class Solution {
public:
    int r;
    int c;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i < r && i >= 0 && j >= 0 && j < c; }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        r = grid.size();
        c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int next_i = new_i + row[k];
                            int next_j = new_j + col[k];

                            if (!valid(next_i, next_j) ||
                                grid[next_i][next_j] == 0) {
                                perimeter += 1;
                            } else if (grid[next_i][next_j] == 1) {
                                grid[next_i][next_j] = -1;
                                q.push({next_i, next_j});
                            }
                        }
                    }
                    return perimeter;
                }
            }
        }

        return perimeter;
    }
};