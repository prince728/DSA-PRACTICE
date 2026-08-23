class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            count++;
            if (nums[i] >= nums[i + 1]) {
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count+1);

        return ans;
    }
};