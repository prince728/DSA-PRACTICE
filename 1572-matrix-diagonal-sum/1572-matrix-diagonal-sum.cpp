class Solution {
public:

    int diagonalSum(vector<vector<int>>& mat) {
        int pri=0,sec=mat[0].size()-1;
        int ans=0;
        for(int i=0;i<mat.size();i++){
            if(pri==sec) ans+=mat[i][pri];
            else ans+=mat[i][pri]+mat[i][sec];
            pri++;
            sec--;
        }

        return ans;
    }
};