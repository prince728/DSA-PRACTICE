class Solution {
public:
 void shift(vector<vector<int>>&grid){
    int m=grid.size(),n=grid[0].size(),last =grid[m-1][n-1];
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>0;j--){
            grid[i][j] =grid[i][j-1];
        }
        if(i==0){
            grid[0][0]=last;
        }else
        grid[i][0]=grid[i-1][n-1];  
    }
    
 }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i=0;i<k;i++){
        shift(grid);
        }
        return grid;
    }
};