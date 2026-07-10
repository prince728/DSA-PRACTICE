class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        for(int i=n-1;i>=n-k;i--){
            if(i==n-k) return nums[i];
        }
        return 0;
    }
};