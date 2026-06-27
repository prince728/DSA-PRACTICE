class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> count;
        for(int i=0;i<nums.size();i++){
            if(!count.contains(nums[i])) count[nums[i]]=1;
            else return true;
        }
        return false;
    }
};