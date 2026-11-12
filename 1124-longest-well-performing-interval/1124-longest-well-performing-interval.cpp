class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += (hours[i] > 8) ? 1 : -1;

            if (prefixSum > 0) {
                ans = i + 1;
            } else {
                if (mp.count(prefixSum - 1)) {
                    ans = max(ans, i - mp[prefixSum - 1]);
                }
            }
            
            if (!mp.count(prefixSum))
                mp[prefixSum] = i;
        }

        return ans;
    }
};