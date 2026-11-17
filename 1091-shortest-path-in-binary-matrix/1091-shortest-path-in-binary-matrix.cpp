class Solution {
public:
    int n;
    int row[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int col[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    bool valid(int i, int j) { return i < n && i >= 0 && j < n && j >= 0; }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int steps = 1;
        n = grid.size();
        if(n==1) return 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
      

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 8; k++) {
                    if (valid(i + row[k], j + col[k]) &&
                        grid[i + row[k]][j + col[k]] == 0) {
                        if (i + row[k] == n - 1 && j + col[k] == n - 1)
                            return steps+1;
                        grid[i + row[k]][j + col[k]] = 1;
                        q.push({i + row[k], j + col[k]});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};