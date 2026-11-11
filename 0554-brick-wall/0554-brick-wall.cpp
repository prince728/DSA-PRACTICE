class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;
        int n = wall.size();

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                mp[sum]++;
            }
        }
        
        int ans=n;
        for (auto[key,val]:mp){
            ans=min(ans,n-val);
        }

        return ans;
    }
};