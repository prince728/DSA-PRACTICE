class Solution {
public:
    int r, c;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i >= 0 && j >= 0 && i < r && j < c; }

    int minimumEffortPath(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();

        vector<vector<int>> efforts(r, vector<int>(c, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        while (!pq.empty()) {
            int current_effort = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (i == r - 1 && j == c - 1) {
                return current_effort;
            }

            if (current_effort > efforts[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                if (valid(i + row[k], j + col[k])) {
                    int next_effort = max(
                        current_effort,
                        abs(heights[i][j] - heights[i + row[k]][j + col[k]]));
                    
                    if (next_effort < efforts[i+row[k]][j+col[k]]) {
                        efforts[i+row[k]][j+col[k]] = next_effort;
                        pq.push({next_effort, {i+row[k], j+col[k]}});
                    }
                }
            }
        }

        return 0;
    }
};