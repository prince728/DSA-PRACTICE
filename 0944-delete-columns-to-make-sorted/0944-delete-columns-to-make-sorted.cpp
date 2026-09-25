class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty())
            return 0;

        int deletion_count = 0;
        int num_rows = strs.size();
        int num_cols = strs[0].size();

        for (int col = 0; col < num_cols; col++) {
            for (int row = 0; row < num_rows - 1; row++) {
                if (strs[row][col] > strs[row + 1][col]) {
                    deletion_count++;
                    break;
                }
            }
        }

        return deletion_count;
    }
};
