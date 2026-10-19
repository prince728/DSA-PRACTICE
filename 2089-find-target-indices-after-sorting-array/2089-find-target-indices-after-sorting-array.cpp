class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int Tcount = 0;
        int Scount = 0;
        int n= nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==target) Tcount++;
            if(nums[i]<target) Scount++;
        }

        vector<int>ans;

        while(Tcount--){
            ans.push_back(Scount++); 
        }

        return ans;

    }
};