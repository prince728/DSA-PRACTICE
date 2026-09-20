class Solution {
public:
    int r;
    int c;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        r = image.size();
        c = image[0].size();
        int prevCol = image[sr][sc];

        if (prevCol == color) {
            return image;
        }
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                if (valid(i + row[k], j + col[k]) &&
                    image[i + row[k]][j + col[k]] == prevCol) {
                    image[i + row[k]][j + col[k]] = color;
                    q.push({i + row[k], j + col[k]});
                }
            }
        }

        return image;
    }
};