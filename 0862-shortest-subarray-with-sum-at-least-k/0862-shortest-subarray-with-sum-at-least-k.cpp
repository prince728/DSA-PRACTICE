class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        

        deque<int> dq;
        
        for (int i = 0; i <= n; i++) {

            while (!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front(); 
            }
            
            while (!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
