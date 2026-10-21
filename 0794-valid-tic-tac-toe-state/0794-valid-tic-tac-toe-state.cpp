class Solution {
public:
    int checkNoOfWinner(vector<string> board) {
        char winner = 'A';
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (winner == 'A')
                    winner = board[i][0];
                else if (winner != board[i][0])
                    return 0;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (winner == 'A')
                    winner = board[0][i];
                else if (winner != board[0][i])
                    return 0;
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
            board[1][1] == board[2][2]) {
            if (winner == 'A')
                winner = board[0][0];
            else if (winner != board[0][2])
                return 0;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] &&
            board[1][1] == board[2][0]) {
            if (winner == 'A')
                winner = board[0][2];
            else if (winner != board[0][2])
                return 0;
        }

        if (winner == 'X')
            return 1;
        if (winner == 'O')
            return 2;
        return 3;
    }

    bool validTicTacToe(vector<string>& board) {
        int winner = checkNoOfWinner(board);
        if (winner == 0)
            return 0;

        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X')
                    count++;
                if (board[i][j] == 'O')
                    count--;
            }
        }

        if (winner == 1 && count == 1)
            return 1;
        if (winner == 2 && count == 0)
            return 1;

        if (winner == 3)
            return count == 0 || count == 1;

        return 0;
    }
};