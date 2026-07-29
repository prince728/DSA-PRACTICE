class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int mul = 1;
            for (int j = i ; j < n; j++) {
                mul *= nums[j];

                if (mul < k)
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};