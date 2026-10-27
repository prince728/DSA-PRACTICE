class Solution {
public:
    bool checkCols(vector<vector<char>>& board) {
        for (int i = 0; i < board[0].size(); i++) {
            vector<int> num(9, 0);
            for (int j = 0; j < board.size(); j++) {
                if (isdigit(board[j][i])) {
                    num[board[j][i] - '0' - 1]++;
                    if (num[board[j][i] - '0' - 1] > 1)
                        return 0;
                }
            }
        }

        return 1;
    }

    bool checkRows(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<int> num(9, 0);
            for (int j = 0; j < board[i].size(); j++) {
                if (isdigit(board[i][j])) {
                    num[board[i][j] - '0' - 1]++;
                    if (num[board[i][j] - '0' - 1] > 1)
                        return 0;
                }
            }
        }

        return 1;
    }

    bool checkSubBoxes(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> num(9, 0);
            int rowOffset = (i / 3) * 3;
            int colOffset = (i % 3) * 3;

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (isdigit(board[rowOffset + j][colOffset + k])) {
                        num[board[rowOffset + j][colOffset + k] - '0' - 1]++;
                        if (num[board[rowOffset + j][colOffset + k] - '0' - 1] >
                            1)
                            return 0;
                    }
                }
            }
        }

        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        return checkRows(board) && checkCols(board) && checkSubBoxes(board);
    }
};