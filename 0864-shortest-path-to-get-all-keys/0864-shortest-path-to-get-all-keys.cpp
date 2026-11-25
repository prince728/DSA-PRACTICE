
class Solution {
public:
    int m, n;

    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool valid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

    int shortestPathAllKeys(vector<string>& mat) {
        m = mat.size();
        n = mat[0].size();

        int startR = 0, startC = 0;
        int targetMask = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char ch = mat[r][c];

                if (ch == '@') {
                    startR = r;
                    startC = c;
                }

                if (islower(ch)) {
                    targetMask |= (1 << (ch - 'a'));
                }
            }
        }

        queue<pair<pair<int, int>, int>> q;

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(1 << 6, false)));

        q.push({{startR, startC}, 0});
        visited[startR][startC][0] = true;
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {

                int i = q.front().first.first;
                int j = q.front().first.second;
                int key = q.front().second;

                q.pop();

                if (key == targetMask) {
                    return step;
                }

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if (!valid(ni, nj) || mat[ni][nj] == '#') {
                        continue;
                    }

                    char ch = mat[ni][nj];
                    if (isupper(ch) && !(key & (1 << (ch - 'A')))) {
                        continue;
                    }
                    int nextKey = key;
                    if (islower(ch)) {
                        nextKey |= (1 << (ch - 'a'));
                    }

                    if (!visited[ni][nj][nextKey]) {
                        visited[ni][nj][nextKey] = true;
                        q.push({{ni, nj}, nextKey});
                    }
                }
            }

            step++;
        }

        return -1;
    }
};
