class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int first=0,second=k-1,sum=0;
        double avg=INT_MIN;

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        while(second<nums.size()){
            double currAvg= (double)sum/k;
            avg=max(avg,currAvg);

            second++;
            if(second<nums.size()){
                sum+=nums[second]-nums[first];
                first++;
            }

        }

        return avg;

    }
};