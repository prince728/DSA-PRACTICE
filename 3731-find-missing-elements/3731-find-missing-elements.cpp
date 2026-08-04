class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<int> ans;
        int mini = INT_MAX; 
        int maxi = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        
        vector<int> count(maxi - mini + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i] - mini]++; 
        }
        
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0) {
                ans.push_back(i + mini); 
            }
        }
        return ans;
    }
};
