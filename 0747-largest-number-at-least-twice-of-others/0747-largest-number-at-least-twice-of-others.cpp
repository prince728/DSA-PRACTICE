class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest=0, secLargest=0,index=0;

        for(int i=0;i<nums.size();i++){
            if(largest< nums[i]){
                index=i;
                secLargest= largest;
                largest=nums[i];
            }
            else if(secLargest<nums[i]){
                secLargest= nums[i];
            }
        }

        return secLargest*2<=largest?index:-1;

    }
};