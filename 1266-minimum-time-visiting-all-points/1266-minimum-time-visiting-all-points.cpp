class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        int n = points.size();
        for(int i=1;i<n;++i){
            int v1 = points[i][1], v0 = points[i][0];
            int u1 = points[i-1][1], u0 = points[i-1][0];
            int diff1 = abs(v1-u1), diff2 = abs(v0-u0);
            if(diff1==diff2) sum+=diff1;
            else sum+=(max(diff1,diff2));
        }
        return sum;
    }
};