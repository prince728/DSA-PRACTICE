class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index1 = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index1 = i;
                break;
            }
        }
        if (index1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[index1]) {
                swap(nums[index1], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + index1 + 1, nums.end());
    }
};