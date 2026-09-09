class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int TotalSum = 0;
        for (auto num : nums)
            TotalSum += num;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            if (i != 0)
                TotalSum -= nums[i - 1];

            if (sum == TotalSum)
                return i;
        }
        return -1;
    }
};