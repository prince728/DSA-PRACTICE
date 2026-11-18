class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int first = 0, second = 0, dist = 0;

        while (second < n) {
            while (second < n && seats[second] == 0)
                second++;
            if (seats[first] == 0)
                dist = max(dist, second - first);
            else {
                if (second == n)
                    dist = max(dist, n - first - 1);
                dist = max(dist, (second - first) / 2);
            }
            first = second;
            second++;
        }
        return dist;
    }
};