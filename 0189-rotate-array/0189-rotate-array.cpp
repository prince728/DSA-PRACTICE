class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0)
            return;

        int first = 0, last = n - 1;
        while (first < last) {
            swap(nums[first], nums[last]);
            first++;
            last--;
        }

        first=0,last=k-1;
        while (first < last) {
            swap(nums[first], nums[last]);
            first++;
            last--;
        }

        first=k,last=n-1;
        while (first < last) {
            swap(nums[first], nums[last]);
            first++;
            last--;
        }

    }
};