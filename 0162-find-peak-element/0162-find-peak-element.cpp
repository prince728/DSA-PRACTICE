class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int first = 0, second = nums.size() - 1;

        while (first < second) {
            int mid = first + (second - first) / 2;
            if (nums[mid] < nums[mid+1])
                first = mid+1 ;
            else {

                second = mid;
            }
        }
        return first;
    }
};