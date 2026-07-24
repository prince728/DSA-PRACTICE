class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int ans = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (!s.empty() && s.top() > prices[i]) {
                int low =s.top();
                int high = s.top();
                while (!s.empty() ) {
                    low = s.top();
                    s.pop();
                }
                ans += high - low;
            }
            s.push(prices[i]);
        }

        if (!s.empty()) {
            int high = s.top();
            int low = s.top();
            while (!s.empty()) {
                low = s.top();
                s.pop();
            }
            ans += high - low;
        }

        return ans;
    }
};