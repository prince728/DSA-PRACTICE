class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = 1440;
        int n = timePoints.size();

        sort(timePoints.begin(), timePoints.end());
        for (int i = 0; i < n - 1; i++) {
            int first = 60 * stoi(timePoints[i % n].substr(0, 2)) +
                        stoi(timePoints[i % n].substr(3, 2));
            int second = 60 * stoi(timePoints[(i + 1)].substr(0, 2)) +
                         stoi(timePoints[(i + 1)].substr(3, 2));

            int diff = second - first;
            ans = min(ans, diff);
        }

        int first = 60 * stoi(timePoints[0].substr(0, 2)) +
                    stoi(timePoints[0].substr(3, 2));
        int last = 60 * stoi(timePoints[n-1].substr(0, 2)) +
                     stoi(timePoints[n-1].substr(3, 2));

        int diff = 1440 + first - last;
        ans = min(ans, diff);

        return ans;
    }
};