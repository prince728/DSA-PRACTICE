class Solution {
public:
    int r, c;
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i,int  j){
        return i>=0&&j>=0&&i<r&&j<c;
    }


    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 1; i < r - 1; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'R';
            }
            if (board[i][c - 1] == 'O') {
                q.push({i, c - 1});
                board[i][c - 1] = 'R';
            }
        }

        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'R';
            }
            if (board[r - 1][i] == 'O') {
                q.push({r - 1, i});
                board[r - 1][i] = 'R';
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                if (valid(i + row[k], j + col[k]) &&
                    board[i + row[k]][j + col[k]] == 'O') {
                    q.push({i + row[k], j + col[k]});
                    board[i + row[k]][j + col[k]] = 'R';
                }
            }
        }


        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='R') board[i][j]='O';
            }
        }

    }
};