class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int index = 0;

        while (index < nums.size()) {
            int start = nums[index];
            while (index < nums.size() - 1 &&
                   nums[index + 1] == nums[index] + 1)
                index++;
            int last = nums[index];
            string elem = "";
            if (start == last)
                elem += to_string(start);
            else {
                elem += to_string(start);
                elem += "->";
                elem += to_string(last);
            }
            ans.push_back(elem);
            index++;
        }

        return ans;
    }
};