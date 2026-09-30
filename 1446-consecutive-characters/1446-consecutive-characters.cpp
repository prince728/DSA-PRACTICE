class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int point = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                point++;
            else {
                ans = max(ans, point);
                point = 1;
            }
        }
        ans = max(ans, point);

        return ans;
    }
};