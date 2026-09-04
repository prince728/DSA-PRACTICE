class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<m;i++){
            q.push({matrix[i][0],{i,0}});
        }
        for(int i=0;i<n;i++){
            q.push({matrix[0][i],{0,i}});
        }

        while(!q.empty()){
            int val= q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();

            while(i+1<m && j+1<n){
                if(matrix[i+1][j+1]!=val) return 0;
                i++;
                j++;
            }
        }

        return 1;
    }
};