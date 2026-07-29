class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int ans = 0, n = nums.size();
        int left = 0, right = 0;
        int mul = 1;

        for (int i = right; right < n; right++) {
            mul *= nums[right];
            while (mul >= k) {
                mul /= nums[left];
                left++;
            }
            ans+= (right-left+1);
        }

        return ans;
    }
};