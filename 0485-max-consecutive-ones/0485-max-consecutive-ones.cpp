class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int index = 0;
        while (index < nums.size()) {
            while (index < nums.size() && nums[index] != 0) {
                count++;
                index++;
            }
            ans = max(ans, count);
            count = 0;
            index++;
        }

        return ans;
    }
};