class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> count_map;
        for (int num : nums) {
            count_map[num]++;
        }

        int triplets = 0;
        int left = 0;
        int right = nums.size();

        for (auto& [num, mid] : count_map) {
            right -= mid;
            triplets += left * mid * right;
            left += mid;
        }

        return triplets;
    }
};
