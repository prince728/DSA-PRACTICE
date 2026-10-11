class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int steps = 0;

        for(int i=0;i<n-1;i++){
            int x= points[i][0];
            int y= points[i][1];

            int targetX = points[i+1][0];
            int targetY = points[i+1][1];

            while(x!=targetX || y!=targetY){
                if(x-targetX>0)x--;
                else if(x-targetX<0) x++;

                if(y-targetY>0) y--;
                else if(y-targetY<0) y++;

                steps++;
            }
        }

        return steps;
    }
};