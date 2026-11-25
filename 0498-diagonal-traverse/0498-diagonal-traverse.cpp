class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int i = 0, j = 0;
        bool down = 0;
        int size = m * n;

        while (size) {
            if (!down) {
                while (i >= 0 && j < n) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                    size--;
                }
                if (j == n) {
                    i += 2;
                    j = n - 1;
                } else if (i < 0) {
                    i = 0;
                }

            } else {
                while (i < m && j >= 0) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                    size--;
                }
                if (i == m) {
                    j += 2;
                    i = m - 1;
                } else if (j < 0) {
                    j = 0;
                }

            }
            down = (!down);
        }

        return ans;
    }
};