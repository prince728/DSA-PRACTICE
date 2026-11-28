class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int x = 0;
        vector<bool> ans(nums.size()); 
        
        for (int i = 0; i < nums.size(); i++) {
            x = ((x << 1) + nums[i]) % 5; 
            ans[i] = (x == 0);
        }
        
        return ans;
    }
};
