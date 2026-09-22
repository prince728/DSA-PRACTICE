class Solution {
public:
    int r;
    int c;
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i ,int j){
        return i>=0&&i<r&&j>=0&&j<c;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        r=grid.size();
        c= grid[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int area=0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]=0;

                    while(!q.empty()){
                        int new_i= q.front().first;
                        int new_j= q.front().second;
                        q.pop();
                        area++;

                        for(int k=0;k<4;k++){
                            if(valid(new_i+row[k],new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]){
                                 grid[new_i+row[k]][new_j+col[k]]=0;
                                 q.push({new_i+row[k],new_j+col[k]});
                            }
                        }

                    }

                    ans=max(area,ans);

                }
            }

        }

        return ans;
    }
};