class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n= coordinates.size();
        int dx= coordinates[0][0]-coordinates[1][0];
        int dy= coordinates[0][1]-coordinates[1][1];

        for(int i=2;i<n;i++){
            int new_dx= coordinates[0][0]-coordinates[i][0];
            int new_dy= coordinates[0][1]-coordinates[i][1];

            if(dx*new_dy-dy*new_dx != 0) return 0;
        }

        return 1;
    }
};