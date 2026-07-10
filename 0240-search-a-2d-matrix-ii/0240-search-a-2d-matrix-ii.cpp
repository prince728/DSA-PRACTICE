class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, left = n-1;

        while (top < m && left >= 0) {
            if(target==matrix[top][left]) return 1;
            else if(target<matrix[top][left]) left--;
            else top++;
        }
        return 0;
    }
};