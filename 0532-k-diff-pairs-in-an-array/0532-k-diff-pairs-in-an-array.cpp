class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int first = i + 1, last = nums.size() - 1;

            while (first <= last) {
                long long mid = first + (last - first) / 2;
                if (nums[mid] - nums[i] == k) {
                    ans++;
                    break;
                } else if (nums[mid] - nums[i] > k)
                    last = mid - 1;
                else
                    first = mid + 1;
            }
        }

        return ans;
    }
};