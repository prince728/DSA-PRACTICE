class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int second = bookings[i][1];
            int seat = bookings[i][2];

            for (int j = first; j <= second; j++)
                ans[j-1] += seat;
        }

        return ans;
    }
};