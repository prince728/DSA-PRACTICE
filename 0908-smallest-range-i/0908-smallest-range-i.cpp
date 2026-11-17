class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        
        return max(0, (maxVal - minVal) - 2 * k);
    }
};
