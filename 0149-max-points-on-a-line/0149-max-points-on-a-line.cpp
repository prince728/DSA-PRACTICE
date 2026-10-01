class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;

        int global_max = 1;

        for (int i = 0; i < points.size(); i++) {
            map<pair<double, double>, int> slope_counts;
            int local_max = 0;
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                }
                slope_counts[{dx, dy}]++;

                local_max = max(local_max, slope_counts[{dx, dy}]);
            }

            global_max = max(global_max, local_max + 1);
        }

        return global_max;
    }
};