class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int left = 0, right = n - 1, top = 0, bottom = n - 1, val = 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = val++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = val++;
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = val++;
                }
                bottom--;
                for (int i = bottom; top <= i; i--) {
                    ans[i][left] = val++;
                }
                left++;
            }
        }

        return ans;
    }
};