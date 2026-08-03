class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> count(nums.size()+1, 0);
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (count[nums[i]] == 2)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};