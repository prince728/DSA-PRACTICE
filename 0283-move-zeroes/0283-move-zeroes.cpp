class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<2) return;
        int first=0,second=1;

        while(second<nums.size()){
            if(nums[first]==0){
                while(second<nums.size()&&nums[second]==0){
                    second++;
                }
                if(second==nums.size()) break;
                swap(nums[first],nums[second]);
            }
            first++;
            second++;
        }

    }
};